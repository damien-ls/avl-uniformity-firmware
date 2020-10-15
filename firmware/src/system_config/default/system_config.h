/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.

    Created with MPLAB Harmony Version 2.06
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "2.06"
#define SYS_VERSION               20600

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        120000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            120000000ul
#define SYS_CLK_BUS_PERIPHERAL_2            120000000ul
#define SYS_CLK_BUS_PERIPHERAL_3            120000000ul
#define SYS_CLK_BUS_PERIPHERAL_4            120000000ul
#define SYS_CLK_BUS_PERIPHERAL_5            120000000ul
#define SYS_CLK_BUS_PERIPHERAL_6            30000000ul
#define SYS_CLK_BUS_PERIPHERAL_7            120000000ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       32768ul
   
/*** Ports System Service Configuration ***/
#define SYS_PORT_A_ANSEL        0x226C
#define SYS_PORT_A_TRIS         0xFFFE
#define SYS_PORT_A_LAT          0x0000
#define SYS_PORT_A_ODC          0x0000
#define SYS_PORT_A_CNPU         0x0000
#define SYS_PORT_A_CNPD         0x0000
#define SYS_PORT_A_CNEN         0x0000

#define SYS_PORT_B_ANSEL        0x0000
#define SYS_PORT_B_TRIS         0x0000
#define SYS_PORT_B_LAT          0x0000
#define SYS_PORT_B_ODC          0x0000
#define SYS_PORT_B_CNPU         0x0000
#define SYS_PORT_B_CNPD         0x0000
#define SYS_PORT_B_CNEN         0x0000

#define SYS_PORT_C_ANSEL        0x5038
#define SYS_PORT_C_TRIS         0x543D
#define SYS_PORT_C_LAT          0x0000
#define SYS_PORT_C_ODC          0x0000
#define SYS_PORT_C_CNPU         0x0000
#define SYS_PORT_C_CNPD         0x0000
#define SYS_PORT_C_CNEN         0x0000

#define SYS_PORT_D_ANSEL        0x0E81
#define SYS_PORT_D_TRIS         0x1F9F
#define SYS_PORT_D_LAT          0x0000
#define SYS_PORT_D_ODC          0x0000
#define SYS_PORT_D_CNPU         0x0000
#define SYS_PORT_D_CNPD         0x0000
#define SYS_PORT_D_CNEN         0x0000

#define SYS_PORT_E_ANSEL        0x0FFC
#define SYS_PORT_E_TRIS         0x8FFF
#define SYS_PORT_E_LAT          0x0000
#define SYS_PORT_E_ODC          0x0000
#define SYS_PORT_E_CNPU         0x0000
#define SYS_PORT_E_CNPD         0x0000
#define SYS_PORT_E_CNEN         0x0000

#define SYS_PORT_F_ANSEL        0xCD3C
#define SYS_PORT_F_TRIS         0xCF3C
#define SYS_PORT_F_LAT          0x0000
#define SYS_PORT_F_ODC          0x0000
#define SYS_PORT_F_CNPU         0x0000
#define SYS_PORT_F_CNPD         0x0000
#define SYS_PORT_F_CNEN         0x0000

#define SYS_PORT_G_ANSEL        0x803C
#define SYS_PORT_G_TRIS         0x8BFC
#define SYS_PORT_G_LAT          0x0000
#define SYS_PORT_G_ODC          0x0000
#define SYS_PORT_G_CNPU         0x0000
#define SYS_PORT_G_CNPD         0x0000
#define SYS_PORT_G_CNEN         0x0800


/*** Console System Service Configuration ***/

#define SYS_CONSOLE_OVERRIDE_STDIO
#define SYS_CONSOLE_DEVICE_MAX_INSTANCES        2
#define SYS_CONSOLE_INSTANCES_NUMBER            1
#define SYS_CONSOLE_UART_IDX               DRV_USART_INDEX_0
#define SYS_CONSOLE_UART_BAUD_RATE_IDX     DRV_USART_BAUD_RATE_IDX0
#define SYS_CONSOLE_UART_RD_QUEUE_DEPTH    64
#define SYS_CONSOLE_UART_WR_QUEUE_DEPTH    64
#define SYS_CONSOLE_BUFFER_DMA_READY



/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* USART Driver Configuration Options
*/
#define DRV_USART_INTERRUPT_MODE                    false

#define DRV_USART_BYTE_MODEL_SUPPORT                false

#define DRV_USART_READ_WRITE_MODEL_SUPPORT          true

#define DRV_USART_BUFFER_QUEUE_SUPPORT              true

#define DRV_USART_CLIENTS_NUMBER                    6
#define DRV_USART_INSTANCES_NUMBER                  6

#define DRV_USART_PERIPHERAL_ID_IDX0                USART_ID_1
#define DRV_USART_OPER_MODE_IDX0                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX0               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX0      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX0          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX0       false
#define DRV_USART_INIT_FLAGS_IDX0                   0
#define DRV_USART_BRG_CLOCK_IDX0                    120000000
#define DRV_USART_BAUD_RATE_IDX0                    115200
#define DRV_USART_LINE_CNTRL_IDX0                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX0               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX0                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX0                 INT_SOURCE_USART_1_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX0                  INT_SOURCE_USART_1_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX0                  INT_SOURCE_USART_1_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX0              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX0               10


#define DRV_USART_POWER_STATE_IDX0                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_PERIPHERAL_ID_IDX1                USART_ID_2
#define DRV_USART_OPER_MODE_IDX1                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX1               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX1      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX1          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX1       false
#define DRV_USART_INIT_FLAGS_IDX1                   0
#define DRV_USART_BRG_CLOCK_IDX1                    120000000
#define DRV_USART_BAUD_RATE_IDX1                    115200
#define DRV_USART_LINE_CNTRL_IDX1                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX1               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX1                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX1                 INT_SOURCE_USART_2_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX1                  INT_SOURCE_USART_2_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX1                  INT_SOURCE_USART_2_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX1              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX1               10


#define DRV_USART_POWER_STATE_IDX1                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_PERIPHERAL_ID_IDX2                USART_ID_3
#define DRV_USART_OPER_MODE_IDX2                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX2               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX2      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX2          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX2       false
#define DRV_USART_INIT_FLAGS_IDX2                   0
#define DRV_USART_BRG_CLOCK_IDX2                    120000000
#define DRV_USART_BAUD_RATE_IDX2                    115200
#define DRV_USART_LINE_CNTRL_IDX2                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX2               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX2                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX2                 INT_SOURCE_USART_3_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX2                  INT_SOURCE_USART_3_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX2                  INT_SOURCE_USART_3_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX2              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX2               10


#define DRV_USART_POWER_STATE_IDX2                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_PERIPHERAL_ID_IDX3                USART_ID_4
#define DRV_USART_OPER_MODE_IDX3                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX3               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX3      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX3          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX3       false
#define DRV_USART_INIT_FLAGS_IDX3                   0
#define DRV_USART_BRG_CLOCK_IDX3                    120000000
#define DRV_USART_BAUD_RATE_IDX3                    115200
#define DRV_USART_LINE_CNTRL_IDX3                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX3               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX3                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX3                 INT_SOURCE_USART_4_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX3                  INT_SOURCE_USART_4_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX3                  INT_SOURCE_USART_4_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX3              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX3               10


#define DRV_USART_POWER_STATE_IDX3                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_PERIPHERAL_ID_IDX4                USART_ID_5
#define DRV_USART_OPER_MODE_IDX4                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX4               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX4      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX4          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX4       false
#define DRV_USART_INIT_FLAGS_IDX4                   0
#define DRV_USART_BRG_CLOCK_IDX4                    120000000
#define DRV_USART_BAUD_RATE_IDX4                    115200
#define DRV_USART_LINE_CNTRL_IDX4                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX4               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX4                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX4                 INT_SOURCE_USART_5_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX4                  INT_SOURCE_USART_5_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX4                  INT_SOURCE_USART_5_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX4              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX4               10


#define DRV_USART_POWER_STATE_IDX4                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_PERIPHERAL_ID_IDX5                USART_ID_6
#define DRV_USART_OPER_MODE_IDX5                    DRV_USART_OPERATION_MODE_NORMAL
#define DRV_USART_OPER_MODE_DATA_IDX5               
#define DRV_USART_INIT_FLAG_WAKE_ON_START_IDX5      false
#define DRV_USART_INIT_FLAG_AUTO_BAUD_IDX5          false
#define DRV_USART_INIT_FLAG_STOP_IN_IDLE_IDX5       false
#define DRV_USART_INIT_FLAGS_IDX5                   0
#define DRV_USART_BRG_CLOCK_IDX5                    120000000
#define DRV_USART_BAUD_RATE_IDX5                    115200
#define DRV_USART_LINE_CNTRL_IDX5                   DRV_USART_LINE_CONTROL_8NONE1
#define DRV_USART_HANDSHAKE_MODE_IDX5               DRV_USART_HANDSHAKE_NONE
#define DRV_USART_LINES_ENABLE_IDX5                 USART_ENABLE_TX_RX_USED
#define DRV_USART_XMIT_INT_SRC_IDX5                 INT_SOURCE_USART_6_TRANSMIT
#define DRV_USART_RCV_INT_SRC_IDX5                  INT_SOURCE_USART_6_RECEIVE
#define DRV_USART_ERR_INT_SRC_IDX5                  INT_SOURCE_USART_6_ERROR

#define DRV_USART_XMIT_QUEUE_SIZE_IDX5              10
#define DRV_USART_RCV_QUEUE_SIZE_IDX5               10


#define DRV_USART_POWER_STATE_IDX5                  SYS_MODULE_POWER_RUN_FULL

#define DRV_USART_QUEUE_DEPTH_COMBINED              120

// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************

/*** USB Driver Configuration ***/


/* Enables Device Support */
#define DRV_USBFS_DEVICE_SUPPORT      true

/* Disable Host Support */
#define DRV_USBFS_HOST_SUPPORT      false

/* Maximum USB driver instances */
#define DRV_USBFS_INSTANCES_NUMBER    1

/* Interrupt mode enabled */
#define DRV_USBFS_INTERRUPT_MODE      true


/* Number of Endpoints used */
#define DRV_USBFS_ENDPOINTS_NUMBER    2




/*** USB Device Stack Configuration ***/










/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      64








/* Endpoint Transfer Queue Size combined for Read and write */
#define USB_DEVICE_ENDPOINT_QUEUE_DEPTH_COMBINED    2



#define APP_READ_BUFFER_SIZE 64
#define APP_MAKE_BUFFER_DMA_READY
/* Number of Endpoints used */    
#define APP_EP_BULK_IN  1

/* Number of Endpoints used */    
#define APP_EP_BULK_OUT 1
    
// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************
/*** Application Defined Pins ***/


/*** Application Instance 0 Configuration ***/
/*
   USART Read Write model constants used by the application:

       APP_DRV_USART  : Identifies the USART Driver instance to use
*/
#define APP_DRV_USART1                 0
#define APP_DRV_USART2                 1
#define APP_DRV_USART3                 2
#define APP_DRV_USART4                 3
#define APP_DRV_USART5                 4
#define APP_DRV_USART6                 5
    
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // _SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/
