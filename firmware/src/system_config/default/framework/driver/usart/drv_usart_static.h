/*******************************************************************************
  USART Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart_static.h

  Summary:
    USART driver interface declarations for the static single instance driver.

  Description:
    The USART device driver provides a simple interface to manage the USART
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the USART static driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

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
//DOM-IGNORE-END

#ifndef _DRV_USART_STATIC_H
#define _DRV_USART_STATIC_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "driver/usart/src/drv_usart_static_local.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 0 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART0_Initialize(void);
void  DRV_USART0_Deinitialize(void);
SYS_STATUS DRV_USART0_Status(void);
void DRV_USART0_TasksTransmit(void);
void DRV_USART0_TasksReceive(void);
void DRV_USART0_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 0 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART0_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART0_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART0_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART0_TransferStatus(void);
DRV_USART_ERROR DRV_USART0_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 0 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART0_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART0_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART0_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART0_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART0_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART0_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 0 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART0_Read( void * buffer,const size_t numbytes);
size_t DRV_USART0_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 0 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART0_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART0_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 1 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART1_Initialize(void);
void  DRV_USART1_Deinitialize(void);
SYS_STATUS DRV_USART1_Status(void);
void DRV_USART1_TasksTransmit(void);
void DRV_USART1_TasksReceive(void);
void DRV_USART1_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 1 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART1_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART1_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART1_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART1_TransferStatus(void);
DRV_USART_ERROR DRV_USART1_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 1 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART1_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART1_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART1_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART1_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART1_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART1_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 1 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART1_Read( void * buffer,const size_t numbytes);
size_t DRV_USART1_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 1 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART1_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART1_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 2 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART2_Initialize(void);
void  DRV_USART2_Deinitialize(void);
SYS_STATUS DRV_USART2_Status(void);
void DRV_USART2_TasksTransmit(void);
void DRV_USART2_TasksReceive(void);
void DRV_USART2_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 2 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART2_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART2_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART2_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART2_TransferStatus(void);
DRV_USART_ERROR DRV_USART2_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 2 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART2_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART2_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART2_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART2_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART2_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART2_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 2 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART2_Read( void * buffer,const size_t numbytes);
size_t DRV_USART2_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 2 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART2_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART2_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 3 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART3_Initialize(void);
void  DRV_USART3_Deinitialize(void);
SYS_STATUS DRV_USART3_Status(void);
void DRV_USART3_TasksTransmit(void);
void DRV_USART3_TasksReceive(void);
void DRV_USART3_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 3 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART3_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART3_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART3_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART3_TransferStatus(void);
DRV_USART_ERROR DRV_USART3_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 3 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART3_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART3_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART3_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART3_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART3_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART3_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 3 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART3_Read( void * buffer,const size_t numbytes);
size_t DRV_USART3_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 3 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART3_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART3_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 4 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART4_Initialize(void);
void  DRV_USART4_Deinitialize(void);
SYS_STATUS DRV_USART4_Status(void);
void DRV_USART4_TasksTransmit(void);
void DRV_USART4_TasksReceive(void);
void DRV_USART4_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 4 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART4_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART4_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART4_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART4_TransferStatus(void);
DRV_USART_ERROR DRV_USART4_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 4 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART4_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART4_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART4_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART4_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART4_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART4_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 4 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART4_Read( void * buffer,const size_t numbytes);
size_t DRV_USART4_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 4 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART4_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART4_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// *********************************************************************************************
// *********************************************************************************************
// Section: System Interface Headers for the Instance 5 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

SYS_MODULE_OBJ DRV_USART5_Initialize(void);
void  DRV_USART5_Deinitialize(void);
SYS_STATUS DRV_USART5_Status(void);
void DRV_USART5_TasksTransmit(void);
void DRV_USART5_TasksReceive(void);
void DRV_USART5_TasksError(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: General Client Interface Headers for the Instance 5 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

DRV_HANDLE DRV_USART5_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent);
void DRV_USART5_Close(void);
DRV_USART_CLIENT_STATUS DRV_USART5_ClientStatus(void);
DRV_USART_TRANSFER_STATUS DRV_USART5_TransferStatus(void);
DRV_USART_ERROR DRV_USART5_ErrorGet(void);

// *********************************************************************************************
// *********************************************************************************************
// Section: Buffer Queue Model Client Interface Headers for the Instance 5 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

void DRV_USART5_BufferAddWrite (DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size);
void DRV_USART5_BufferAddRead(DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size);
void DRV_USART5_BufferEventHandlerSet(const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context);
size_t DRV_USART5_BufferCompletedBytesGet(DRV_USART_BUFFER_HANDLE bufferHandle );
DRV_USART_BUFFER_RESULT DRV_USART5_BufferRemove(DRV_USART_BUFFER_HANDLE bufferHandle);
/* The following function will be deprecated */
size_t DRV_USART5_BufferProcessedSizeGet(DRV_USART_BUFFER_HANDLE bufferHandle );

// *********************************************************************************************
// *********************************************************************************************
// Section: Read Write Model Client Interface Headers for the Instance 5 of USART static driver
// *********************************************************************************************
// *********************************************************************************************

size_t DRV_USART5_Read( void * buffer,const size_t numbytes);
size_t DRV_USART5_Write( void * buffer, const size_t numbytes);

// *********************************************************************************************
// *********************************************************************************************
// Section: Set up Client Interface Headers for the Instance 5 of USART static driver
// *********************************************************************************************
// *********************************************************************************************
DRV_USART_BAUD_SET_RESULT DRV_USART5_BaudSet(uint32_t baud);
DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART5_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode);

// DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
// DOM-IGNORE-END

#endif // #ifndef _DRV_USART_STATIC_H
/*******************************************************************************
 End of File
*/
