#include "usb.h"
#include "app.h"

#include "system_config.h"
#include "system_definitions.h"
#include "hardwareProfile.h"


#include "Acq.h"

#include <xc.h>

USB_APP_DATA usbAppData;


uint8_t receivedDataBuffer[APP_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;
uint8_t  transmitDataBuffer[APP_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;

#define charToUshort(a,b) (unsigned short)(b << 8 | a)
/* The endpoint size is 64 for FS and 512 for HS */
uint16_t endpointSize;

inline void usbSend(char * ptr, unsigned int size);

unsigned char * acqReadPtr;
void USB_ProcessReveiced()
{
    switch(receivedDataBuffer[0])
    {
        case 0x1:
        {
            setParam(charToUshort(receivedDataBuffer[5], receivedDataBuffer[6]), 
                charToUshort(receivedDataBuffer[1], receivedDataBuffer[2]),
                charToUshort(receivedDataBuffer[3], receivedDataBuffer[4])
                    
                    );
            break;
        }
        case 0x2:
        {
            transmitDataBuffer[0] = hasNewMeasurement();
            usbSend(transmitDataBuffer, 64);
            break;
        }
        case 0x3:
        {
            acqReadPtr = getAcqDataBuf();
            break;
        }
        case 0x4:
        {
            usbSend(acqReadPtr, 1000*15*2);
            acqReadPtr+=64;
            break;
        }
        
        case 0x5:
        {
            acqTrig();
            break;
        }
        
        default:
        {
            strcpy(transmitDataBuffer, "Error unknown request");
            usbSend(transmitDataBuffer, 64);
            break;
        }
    }

}

/*********************************************
 * Application USB Device Layer Event Handler
 *********************************************/

void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * eventData, uintptr_t context)
{
    uint8_t * configurationValue;
    USB_SETUP_PACKET * setupPacket;
    switch(event)
    {
        case USB_DEVICE_EVENT_RESET:
        case USB_DEVICE_EVENT_DECONFIGURED:

            /* Device is reset or deconfigured. Provide LED indication.*/


            usbAppData.deviceIsConfigured = false;

            break;

        case USB_DEVICE_EVENT_CONFIGURED:

            /* Check the configuration */
            configurationValue = (uint8_t *)eventData;
            if(*configurationValue == 1 )
            {
                /* The device is in configured state. Update LED indication */


                /* Reset endpoint data send & receive flag  */
                usbAppData.deviceIsConfigured = true;
            }
            break;

        case USB_DEVICE_EVENT_SUSPENDED:

            /* Device is suspended. Update LED indication */

            break;


        case USB_DEVICE_EVENT_POWER_DETECTED:

            /* VBUS is detected. Attach the device */
            USB_DEVICE_Attach(usbAppData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_POWER_REMOVED:

            /* VBUS is removed. Detach the device */
            USB_DEVICE_Detach (usbAppData.usbDevHandle);
            break;

        case USB_DEVICE_EVENT_CONTROL_TRANSFER_SETUP_REQUEST:
            /* This means we have received a setup packet */
            setupPacket = (USB_SETUP_PACKET *)eventData;
            if(setupPacket->bRequest == USB_REQUEST_SET_INTERFACE)
            {
                /* If we have got the SET_INTERFACE request, we just acknowledge
                 for now. This demo has only one alternate setting which is already
                 active. */
                USB_DEVICE_ControlStatus(usbAppData.usbDevHandle,USB_DEVICE_CONTROL_STATUS_OK);
            }
            else if(setupPacket->bRequest == USB_REQUEST_GET_INTERFACE)
            {
                /* We have only one alternate setting and this setting 0. So
                 * we send this information to the host. */

                USB_DEVICE_ControlSend(usbAppData.usbDevHandle, &usbAppData.altSetting, 1);
            }
            else
            {
                /* We have received a request that we cannot handle. Stall it*/
                USB_DEVICE_ControlStatus(usbAppData.usbDevHandle, USB_DEVICE_CONTROL_STATUS_ERROR);
            }
            break;

        case USB_DEVICE_EVENT_ENDPOINT_READ_COMPLETE:
           /* Endpoint read is complete */
            usbAppData.epDataReadPending = false;
            break;

        case USB_DEVICE_EVENT_ENDPOINT_WRITE_COMPLETE:
            /* Endpoint write is complete */
            usbAppData.epDataWritePending = false;
            break;

        /* These events are not used in this demo. */
        case USB_DEVICE_EVENT_RESUMED:
        case USB_DEVICE_EVENT_ERROR:
        default:
            break;
    }
}


void USB_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    usbAppData.state = APP_STATE_INIT;

    usbAppData.usbDevHandle = USB_DEVICE_HANDLE_INVALID;
    usbAppData.deviceIsConfigured = false;
    usbAppData.endpointRx = (APP_EP_BULK_OUT | USB_EP_DIRECTION_OUT);
    usbAppData.endpointTx = (APP_EP_BULK_IN | USB_EP_DIRECTION_IN);
    usbAppData.epDataReadPending = false;
    usbAppData.epDataWritePending = false;
    usbAppData.altSetting = 0;
}

inline void usbSend(char * ptr, unsigned int size)
{
    USB_DEVICE_EndpointWrite ( usbAppData.usbDevHandle, &usbAppData.writeTranferHandle,
             usbAppData.endpointTx, ptr,
             size,
             USB_DEVICE_TRANSFER_FLAGS_MORE_DATA_PENDING);
}


void USB_Tasks ()
{
    switch(usbAppData.state)
    {
        case APP_STATE_INIT:
            /* Open the device layer */
            usbAppData.usbDevHandle = USB_DEVICE_Open( USB_DEVICE_INDEX_0,
                    DRV_IO_INTENT_READWRITE );

            if(usbAppData.usbDevHandle != USB_DEVICE_HANDLE_INVALID)
            {
                /* Register a callback with device layer to get event notification (for end point 0) */
                USB_DEVICE_EventHandlerSet(usbAppData.usbDevHandle,  APP_USBDeviceEventHandler, 0);

                usbAppData.state = APP_STATE_WAIT_FOR_CONFIGURATION;
            }
            else
            {
                /* The Device Layer is not ready to be opened. We should try
                 * again later. */
            }

            break;

        case APP_STATE_WAIT_FOR_CONFIGURATION:

            /* Check if the device is configured */
            if(usbAppData.deviceIsConfigured == true)
            {
                if (USB_DEVICE_ActiveSpeedGet(usbAppData.usbDevHandle) == USB_SPEED_FULL)
                {
                    endpointSize = 64;
                }
                else if (USB_DEVICE_ActiveSpeedGet(usbAppData.usbDevHandle) == USB_SPEED_HIGH)
                {
                    endpointSize = 512;
                }
                if (USB_DEVICE_EndpointIsEnabled(usbAppData.usbDevHandle, usbAppData.endpointRx) == false )
                {
                    /* Enable Read Endpoint */
                    USB_DEVICE_EndpointEnable(usbAppData.usbDevHandle, 0, usbAppData.endpointRx,
                            USB_TRANSFER_TYPE_BULK, endpointSize);
                }
                if (USB_DEVICE_EndpointIsEnabled(usbAppData.usbDevHandle, usbAppData.endpointTx) == false )
                {
                    /* Enable Write Endpoint */
                    USB_DEVICE_EndpointEnable(usbAppData.usbDevHandle, 0, usbAppData.endpointTx,
                            USB_TRANSFER_TYPE_BULK, endpointSize);
                }
                /* Indicate that we are waiting for read */
                usbAppData.epDataReadPending = true;

                /* Place a new read request. */
                USB_DEVICE_EndpointRead(usbAppData.usbDevHandle, &usbAppData.readTranferHandle,
                        usbAppData.endpointRx, &receivedDataBuffer[0], sizeof(receivedDataBuffer) );

                /* Device is ready to run the main task */
                usbAppData.state = APP_STATE_MAIN_TASK;
            }
            break;

        case APP_STATE_MAIN_TASK:

            if(!usbAppData.deviceIsConfigured)
            {
                /* This means the device got deconfigured. Change the
                 * application state back to waiting for configuration. */
                usbAppData.state = APP_STATE_WAIT_FOR_CONFIGURATION;

                /* Disable the endpoint*/
                USB_DEVICE_EndpointDisable(usbAppData.usbDevHandle, usbAppData.endpointRx);
                USB_DEVICE_EndpointDisable(usbAppData.usbDevHandle, usbAppData.endpointTx);
                usbAppData.epDataReadPending = false;
                usbAppData.epDataWritePending = false;
            }
            else if (usbAppData.epDataReadPending == false)
            {
                USB_ProcessReveiced();
                
                usbAppData.epDataReadPending = true ;

                /* Place a new read request. */
                USB_DEVICE_EndpointRead ( usbAppData.usbDevHandle, &usbAppData.readTranferHandle,
                        usbAppData.endpointRx, &receivedDataBuffer[0], sizeof(receivedDataBuffer) );
            }
            break;

        case APP_STATE_ERROR:
            break;

        default:
            break;
    }
}