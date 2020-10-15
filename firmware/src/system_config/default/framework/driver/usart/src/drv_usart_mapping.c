/*******************************************************************************
  USART Driver Dynamic to Static mapping

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart_mapping.c

  Summary:
    Source code for the USART driver dynamic APIs to static API mapping.

  Description:
    This file contains code that maps dynamic APIs to static whenever
    the static mode of the driver is selected..

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

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "system_config.h"
#include "system_definitions.h"


SYS_MODULE_OBJ DRV_USART_Initialize(const SYS_MODULE_INDEX index,const SYS_MODULE_INIT * const init)
{
    SYS_MODULE_OBJ returnValue;

    switch(index)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Initialize();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_Initialize();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_Initialize();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_Initialize();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_Initialize();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_Initialize();
            break;
        }
        default:
        {
            returnValue = SYS_MODULE_OBJ_INVALID;
            break;
        }
    }
    return returnValue;
}

void DRV_USART_Deinitialize( SYS_MODULE_OBJ object)
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_Deinitialize();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_Deinitialize();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_Deinitialize();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_Deinitialize();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_Deinitialize();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_Deinitialize();
            break;
        }
        default:
        {
            break;
        }
    }
}

SYS_STATUS DRV_USART_Status( SYS_MODULE_OBJ object)
{
    SYS_STATUS returnValue;

    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Status();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_Status();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_Status();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_Status();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_Status();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_Status();
            break;
        }
        default:
        {
            returnValue = SYS_STATUS_ERROR;
            break;
        }
    }
    return returnValue;
}

void DRV_USART_TasksTransmit ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksTransmit();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_TasksTransmit();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_TasksTransmit();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_TasksTransmit();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_TasksTransmit();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_TasksTransmit();
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_TasksReceive ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksReceive();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_TasksReceive();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_TasksReceive();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_TasksReceive();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_TasksReceive();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_TasksReceive();
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_TasksError ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksError();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_TasksError();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_TasksError();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_TasksError();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_TasksError();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_TasksError();
            break;
        }
        default:
        {
            break;
        }
    }
}


//client interface
DRV_HANDLE DRV_USART_Open( const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent)
{
    DRV_HANDLE returnValue;

    switch(index)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Open(index,ioIntent);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_Open(index,ioIntent);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_Open(index,ioIntent);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_Open(index,ioIntent);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_Open(index,ioIntent);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_Open(index,ioIntent);
            break;
        }
        default:
        {
            returnValue = DRV_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

void DRV_USART_Close( const DRV_HANDLE handle)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_Close();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_Close();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_Close();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_Close();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_Close();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_Close();
            break;
        }
        default:
        {
            break;
        }
    }
}

DRV_USART_CLIENT_STATUS DRV_USART_ClientStatus ( DRV_HANDLE handle )
{
    uintptr_t instance;
    DRV_USART_CLIENT_STATUS returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ClientStatus();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_ClientStatus();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_ClientStatus();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_ClientStatus();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_ClientStatus();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_ClientStatus();
            break;
        }
        default:
        {
            returnValue = DRV_CLIENT_STATUS_ERROR;
            break;
        }
    }
    return returnValue;
}

DRV_USART_TRANSFER_STATUS DRV_USART_TransferStatus( const DRV_HANDLE handle )
{
    uintptr_t instance;
    DRV_USART_TRANSFER_STATUS returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_TransferStatus();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_TransferStatus();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_TransferStatus();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_TransferStatus();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_TransferStatus();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_TransferStatus();
            break;
        }
        default:
        {
            returnValue = (DRV_USART_TRANSFER_STATUS)NULL;
            break;
        }
    }
    return returnValue;
}

DRV_USART_ERROR DRV_USART_ErrorGet(const DRV_HANDLE handle)
{
    uintptr_t instance;
    DRV_USART_ERROR returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ErrorGet();
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_ErrorGet();
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_ErrorGet();
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_ErrorGet();
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_ErrorGet();
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_ErrorGet();
            break;
        }
        default:
        {
            returnValue = (DRV_USART_ERROR)NULL;
            break;
        }
    }
    return returnValue;
}

//Buffer Queuing Model Interface
void DRV_USART_BufferAddWrite(const DRV_HANDLE handle,DRV_USART_BUFFER_HANDLE * bufferHandle, void * buffer, const size_t size)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_BufferAddWrite (bufferHandle, buffer, size);
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_BufferAddRead(const DRV_HANDLE handle,DRV_USART_BUFFER_HANDLE * const bufferHandle,void * buffer,const size_t size)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_BufferAddRead (bufferHandle, buffer, size);
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_BufferEventHandlerSet (const DRV_HANDLE handle,const DRV_USART_BUFFER_EVENT_HANDLER eventHandler,const uintptr_t context)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            DRV_USART1_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            DRV_USART2_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            DRV_USART3_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            DRV_USART4_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            DRV_USART5_BufferEventHandlerSet (eventHandler, context);
            break;
        }
        default:
        {
            break;
        }
    }
}

extern DRV_USART_BUFFER_OBJ gDrvUSARTBufferObj[DRV_USART_QUEUE_DEPTH_COMBINED];

DRV_USART_BUFFER_RESULT DRV_USART_BufferRemove( DRV_USART_BUFFER_HANDLE bufferHandle )
{
    uintptr_t instance;
    DRV_USART_BUFFER_OBJ * bufferObj;
    
    /* Get the driver instance to which this buffer handle belongs to */
    bufferObj = &gDrvUSARTBufferObj[bufferHandle & 0xFFFF];
    instance = bufferObj->drvInstance;

    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            return DRV_USART0_BufferRemove (bufferHandle);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            return DRV_USART1_BufferRemove (bufferHandle);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            return DRV_USART2_BufferRemove (bufferHandle);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            return DRV_USART3_BufferRemove (bufferHandle);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            return DRV_USART4_BufferRemove (bufferHandle);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            return DRV_USART5_BufferRemove (bufferHandle);
            break;
        }
        default:
        {
            return DRV_USART_BUFFER_RESULT_HANDLE_INVALID;
        }
    }
}

size_t DRV_USART_BufferCompletedBytesGet( DRV_USART_BUFFER_HANDLE bufferHandle )
{
    /* This function is independent of instance or client */
    return DRV_USART0_BufferCompletedBytesGet (bufferHandle);
}

size_t DRV_USART_BufferProcessedSizeGet( DRV_USART_BUFFER_HANDLE bufferHandle )
{
    /* This function will be deprecated */
    return DRV_USART0_BufferProcessedSizeGet(bufferHandle);
}

//File System Model
size_t DRV_USART_Read(const DRV_HANDLE handle,void * buffer, const size_t numbytes)
{
    uintptr_t instance;
    size_t returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Read(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_Read(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_Read(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_Read(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_Read(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_Read(buffer, numbytes);
            break;
        }
        default:
        {
            returnValue = DRV_USART_READ_ERROR;
            break;
        }
    }
    return returnValue;
}

size_t DRV_USART_Write(const DRV_HANDLE handle,void * buffer,const size_t numbytes)
{
    uintptr_t instance;
    size_t returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Write(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_Write(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_Write(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_Write(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_Write(buffer, numbytes);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_Write(buffer, numbytes);
            break;
        }
        default:
        {
            returnValue = DRV_USART_WRITE_ERROR;
            break;
        }
    }
    return returnValue;
}



DRV_USART_BAUD_SET_RESULT DRV_USART_BaudSet(const DRV_HANDLE handle, uint32_t baud)
{
    uintptr_t instance;
    DRV_USART_BAUD_SET_RESULT returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_BaudSet(baud);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_BaudSet(baud);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_BaudSet(baud);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_BaudSet(baud);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_BaudSet(baud);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_BaudSet(baud);
            break;
        }
        default:
        {
            returnValue = DRV_USART_BAUD_SET_ERROR;
            break;
        }
    }
    return returnValue;
}

DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART_LineControlSet(const DRV_HANDLE handle,const DRV_USART_LINE_CONTROL lineControl)
{
    uintptr_t instance;
    DRV_USART_LINE_CONTROL_SET_RESULT returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_LineControlSet(lineControl);
            break;
        }
        case DRV_USART_INDEX_1:
        {
            returnValue = DRV_USART1_LineControlSet(lineControl);
            break;
        }
        case DRV_USART_INDEX_2:
        {
            returnValue = DRV_USART2_LineControlSet(lineControl);
            break;
        }
        case DRV_USART_INDEX_3:
        {
            returnValue = DRV_USART3_LineControlSet(lineControl);
            break;
        }
        case DRV_USART_INDEX_4:
        {
            returnValue = DRV_USART4_LineControlSet(lineControl);
            break;
        }
        case DRV_USART_INDEX_5:
        {
            returnValue = DRV_USART5_LineControlSet(lineControl);
            break;
        }
        default:
        {
            returnValue = DRV_USART_LINE_CONTROL_SET_ERROR;
            break;
        }
    }
    return returnValue;
}


/*******************************************************************************
 End of File
*/
