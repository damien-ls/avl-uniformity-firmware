/* 
 * File:   usb.h
 * Author: Damien
 *
 * Created on October 30, 2018, 12:22 PM
 */

#ifndef USB_H
#define	USB_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "system_config.h"
#include "system_definitions.h"
    


typedef struct
{
   /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE usbDevHandle;

    /* Application state*/
    APP_STATES state;

    /* Track device configuration */
    bool deviceIsConfigured;

    /* Configuration value */
    uint8_t configValue;

    /* speed */
    USB_SPEED speed;

    /* ep data sent */
    bool epDataWritePending;

    /* ep data received */
    bool epDataReadPending;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE writeTranferHandle;

    /* Transfer handle */
    USB_DEVICE_TRANSFER_HANDLE readTranferHandle;

    /* The transmit endpoint address */
    USB_ENDPOINT_ADDRESS endpointTx;

    /* The receive endpoint address */
    USB_ENDPOINT_ADDRESS endpointRx;

    /* Tracks the alternate setting */
    uint8_t altSetting;


} USB_APP_DATA;


void USB_Tasks ();
void USB_Initialize ();

#ifdef	__cplusplus
}
#endif

#endif	/* USB_H */

