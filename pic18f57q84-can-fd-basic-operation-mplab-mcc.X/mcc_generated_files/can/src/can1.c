/**
 * CAN1 Generated Driver Source File
 * 
 * @file can1.c
 *            
 * @ingroup can_driver
 *            
 * @brief Contains the implementation file for the CAN1 driver.
 *            
 * @version CAN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <string.h>
#include "../can1.h"
#include "../../../mcc_generated_files/system/pins.h"
/**  
 * @name CAN Bus Receive FIFO Memory information
 * Macros for the CAN Bus Receive FIFO Memory.
 */
///@{
#define CAN1_NUM_OF_RX_FIFO            (2U)    // No of RX FIFOs configured
#define CAN1_RX_FIFO_MSG_DATA          (32U)   // CAN1 RX FIFO Message object data field size
///@}

/**  
 * @name CAN1 Message object arbitration and control field information
 * Macros for the CAN1 Message object arbitration and control field.
 */
///@{
#define CAN_MSG_OBJ_SID_LOW_WIDTH          (0x8U) 
#define CAN_MSG_OBJ_SID_LOW_MASK           (0xFFU) 
#define CAN_MSG_OBJ_SID_HIGH_WIDTH         (0x3U) 
#define CAN_MSG_OBJ_SID_HIGH_MASK          (0x7U)  
#define CAN_MSG_OBJ_EID_LOW_WIDTH          (0x5U) 
#define CAN_MSG_OBJ_EID_LOW_MASK           (0xF8U)  
#define CAN_MSG_OBJ_EID_LOW_POSN           (0x3U)
#define CAN_MSG_OBJ_EID_MID_WIDTH          (0x8U) 
#define CAN_MSG_OBJ_EID_MID_MASK           (0xFFU)  
#define CAN_MSG_OBJ_EID_HIGH_WIDTH         (0x5U) 
#define CAN_MSG_OBJ_EID_HIGH_MASK          (0x1FU) 
#define CAN_MSG_OBJ_IDE_POSN               (0x4U)   
#define CAN_MSG_OBJ_RTR_POSN               (0x5U)     
#define CAN_MSG_OBJ_BRS_POSN               (0x6U) 
#define CAN_MSG_OBJ_FDF_POSN               (0x7U)  
#define CAN_MSG_OBJ_DLC_FIELD_MASK         (0xFU)  
#define CAN_MSG_OBJ_ID_TYPE_FIELD_MASK     (0x10U)
#define CAN_MSG_OBJ_FRAME_TYPE_FIELD_MASK  (0x20U)
#define CAN_MSG_OBJ_BRS_FIELD_MASK         (0x40U)
#define CAN_MSG_OBJ_FDF_FIELD_MASK         (0x80U)
#define CAN_STD_MSG_ID_SIZE                (CAN_MSG_OBJ_SID_LOW_WIDTH + CAN_MSG_OBJ_SID_HIGH_WIDTH)
///@}

/**
 @ingroup  can_driver
 @struct   CAN1_FIFOREG
 @brief    Defines a structure to access CAN1 FIFO Registers.
*/
struct CAN1_FIFOREG
{
    uint8_t CONL;
    uint8_t CONH;
    uint8_t CONU;
    uint8_t CONT;
    uint8_t STAL;
    uint8_t STAH;
    uint8_t STAU;
    uint8_t STAT;
    uint32_t UA;
};

// CAN1 Driver Interface 
const struct CAN_INTERFACE CAN_FD1 = {
    .Initialize = CAN1_Initialize,
    .Deinitialize = CAN1_Deinitialize,
    .OperationModeSet = CAN1_OperationModeSet,
    .OperationModeGet = CAN1_OperationModeGet,
    .Transmit = CAN1_Transmit,
    .TransmitFIFOStatusGet = CAN1_TransmitFIFOStatusGet,
    .IsTxErrorPassive = CAN1_IsTxErrorPassive,
    .IsTxErrorWarning = CAN1_IsTxErrorWarning,
    .IsTxErrorActive = CAN1_IsTxErrorActive,
    .Receive = CAN1_Receive,
    .ReceiveMessageGet = CAN1_ReceiveMessageGet,
    .ReceivedMessageCountGet = CAN1_ReceivedMessageCountGet,
    .ReceiveFIFOStatusGet = CAN1_ReceiveFIFOStatusGet,
    .IsRxErrorPassive = CAN1_IsRxErrorPassive,
    .IsRxErrorWarning = CAN1_IsRxErrorWarning,
    .IsRxErrorActive = CAN1_IsRxErrorActive,
    .IsBusOff = CAN1_IsBusOff,
    .SleepMode = CAN1_Sleep,
    .InvalidMessageCallbackRegister = CAN1_InvalidMessageCallbackRegister,
    .BusWakeUpActivityCallbackRegister = CAN1_BusWakeUpActivityCallbackRegister,
    .BusErrorCallbackRegister = CAN1_BusErrorCallbackRegister,
    .ModeChangeCallbackRegister = CAN1_ModeChangeCallbackRegister,
    .SystemErrorCallbackRegister = CAN1_SystemErrorCallbackRegister,
    .TxAttemptCallbackRegister = CAN1_TxAttemptCallbackRegister,
    .RxBufferOverFlowCallbackRegister = CAN1_RxBufferOverFlowCallbackRegister,
    .Tasks = CAN1_Tasks
};

// CAN1 Default Callback Handler
static void (*CAN1_InvalidMessageHandler)(void) = NULL;
static void (*CAN1_BusWakeUpActivityHandler)(void) = NULL;
static void (*CAN1_BusErrorHandler)(void) = NULL;
static void (*CAN1_ModeChangeHandler)(void) = NULL;
static void (*CAN1_SystemErrorHandler)(void) = NULL;
static void (*CAN1_TxAttemptHandler)(void) = NULL;
static void (*CAN1_RxBufferOverFlowHandler)(void) = NULL;

static void (*CAN1_FIFO1NotEmptyHandler)(void) = NULL;
static void (*CAN1_FIFO2NotEmptyHandler)(void) = NULL;

static uint8_t rxMsgData[CAN1_RX_FIFO_MSG_DATA]; // CAN1 Receive FIFO Message object data field


static void CAN1_FIFO1DefaultHandler(void)
{
    struct CAN_MSG_OBJ EchoMessage;  //create a message object for holding the data
    while(1)
    {
        if(CAN1_ReceivedMessageCountGet() > 0) //check for received message
        {
            if(true == CAN1_Receive(&EchoMessage)) //receive the message
            {
                break;
            }
        }
    }
    EchoMessage.msgId=0x222; //Change the ID to 0x222 then echo the message back out
    if(CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(CAN1_TXQ) & CAN_TX_FIFO_AVAILABLE))
    {
        CAN1_Transmit(CAN1_TXQ, &EchoMessage); //Send the message
    }
}

static void CAN1_FIFO2DefaultHandler(void)
{
    struct CAN_MSG_OBJ InternalMessage; //create a message object for holding data
    while(1)
    {
        if(CAN1_ReceivedMessageCountGet() > 0) //check for received message
        {
            if(true == CAN1_Receive(&InternalMessage)) //receive the message
            {
                break;
            }
        }
    }
    IO_RF3_LAT = ~(InternalMessage.data[0] & 0b1); // set if fist bit is 1 or 0

}

/**
 @ingroup  can_driver
 @struct   CAN1_RX_FIFO_MSG
 @brief    CAN1 Receive FIFO Message Object head count information maintenance data structure.
*/
struct CAN1_RX_FIFO_MSG
{
    const enum CAN_RX_FIFO_CHANNELS channel;
    uint8_t headCount;
};

static volatile struct CAN1_RX_FIFO_MSG rxFIFOMsg[CAN1_NUM_OF_RX_FIFO] = 
{
    // Receive FIFO, FIFO head count
    {CAN1_FIFO_1, 0U},
    {CAN1_FIFO_2, 0U},
};

// Defining a structure to access FIFO registers.
static volatile struct CAN1_FIFOREG * const FIFO = (struct CAN1_FIFOREG *)&C1TXQCONL;

/**
 * @ingroup can_driver
 * @brief Get the DLC enum based data byte value.
 * @param [in] dlc - DLC value as described in CAN_DLC.
 * @return The data byte value coresponding to DLC.
*/
static uint8_t CAN1_DlcToDataBytesGet(const enum CAN_DLC dlc)
{
    static const uint8_t dlcByteSize[] = {0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 12U, 16U, 20U, 24U, 32U, 48U, 64U};
    return dlcByteSize[dlc];
}

/**
 * @ingroup can_driver
 * @brief Get the Payload size in bytes for PLSIZE register value.
 * @param [in] plsize - The value in PLSIZE register.
 * @return The number of data bytes corresponding to PLSIZE register value.
*/
static uint8_t CAN1_PLSIZEToPayloadBytesGet(uint8_t plsize)
{
    return CAN1_DlcToDataBytesGet(8U + plsize);
}

/**
 * @ingroup can_driver
 * @brief Check if a valid channel is configured as transmitter or not.
 * @param [in] channel - Transmit FIFO channel as described in CAN_TX_FIFO_CHANNELS.
 * @retval True - FIFO channel is configured as transmitter.
 * @retval False - FIFO channel is not configured as transmitter.
*/
static bool CAN1_IsTxChannel(uint8_t channel) 
{
    return ((channel < 4U) && (FIFO[channel].CONL & _C1FIFOCON1L_TXEN_MASK));
}

/**
 * @ingroup can_driver
 * @brief Returns the CAN1 transmit FIFO status.
 * @param [in] channel - Transmit FIFO channel as described in CAN_TX_FIFO_CHANNELS.
 * @return Status of the CAN1 Transmit FIFO as described in CAN_TX_FIFO_STATUS.
*/
static enum CAN_TX_FIFO_STATUS CAN1_GetTxFifoStatus(uint8_t validChannel)
{
    return (FIFO[validChannel].STAL & _C1FIFOSTA1L_TFNRFNIF_MASK);
}

/**
 * @ingroup can_driver
 * @brief Reads the message object from user input and updates the CAN1 TX FIFO.
 * @param [out] txFifoObj - Transmit FIFO message object.
 * @param [in] txCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @return None.
*/
static void CAN1_MessageWriteToFifo(uint8_t *txFifoObj, struct CAN_MSG_OBJ *txCanMsg)
{
    uint32_t msgId = txCanMsg->msgId;
 
    if ((uint8_t)CAN_FRAME_EXT == txCanMsg->field.idType)
    {
        /* message is extended identifier */
        
        txFifoObj[1] = (msgId << CAN_MSG_OBJ_EID_LOW_POSN) & CAN_MSG_OBJ_EID_LOW_MASK;
        msgId >>= CAN_MSG_OBJ_EID_LOW_WIDTH;
        
        txFifoObj[2] = msgId & CAN_MSG_OBJ_EID_MID_MASK;
        msgId >>= CAN_MSG_OBJ_EID_MID_WIDTH;
        
        txFifoObj[3] = msgId & CAN_MSG_OBJ_EID_HIGH_MASK;
        msgId >>= CAN_MSG_OBJ_EID_HIGH_WIDTH;
    }
    else
    {
        /* message is standard identifier */
        
        txFifoObj[1] = 0;
        txFifoObj[2] = 0;
        txFifoObj[3] = 0;
    }
    
    txFifoObj[0] =  msgId & CAN_MSG_OBJ_SID_LOW_MASK;
    msgId >>= CAN_MSG_OBJ_SID_LOW_WIDTH;
    
    txFifoObj[1] |= (msgId & CAN_MSG_OBJ_SID_HIGH_MASK);
      
    // DLC <3:0>, IDE <1>, RTR <1>, BRS <1>, FDF <1> 
    txFifoObj[4] = (txCanMsg->field.dlc & CAN_MSG_OBJ_DLC_FIELD_MASK) | 
                   ((uint8_t)(txCanMsg->field.idType << CAN_MSG_OBJ_IDE_POSN) & CAN_MSG_OBJ_ID_TYPE_FIELD_MASK) | 
                   ((uint8_t)(txCanMsg->field.frameType << CAN_MSG_OBJ_RTR_POSN) & CAN_MSG_OBJ_FRAME_TYPE_FIELD_MASK) | 
                   ((uint8_t)(txCanMsg->field.brs << CAN_MSG_OBJ_BRS_POSN) & CAN_MSG_OBJ_BRS_FIELD_MASK) |
                   ((uint8_t)(txCanMsg->field.formatType << CAN_MSG_OBJ_FDF_POSN) & CAN_MSG_OBJ_FDF_FIELD_MASK);

    if ((uint8_t)CAN_FRAME_DATA == txCanMsg->field.frameType)
    {
        /* Data frame message */
		
        // Copying TX message object to FIFO
        (void)memcpy(&txFifoObj[8], txCanMsg->data, CAN1_DlcToDataBytesGet(txCanMsg->field.dlc));
    }
    else
    {
        /* RTR frame message */

        // RTR frame is not supported in CAN FD. Error return type is not supported by driver yet.
    }
}

/**
 * @ingroup can_driver
 * @brief Validates transmission.
 * @param [in] channel - Transmit FIFO channel as described in CAN_TX_FIFO_CHANNELS.
 * @param [in] txCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @return Status of the CAN1 Transmit operation as described in CAN_TX_MSG_REQUEST_STATUS.
*/
static enum CAN_TX_MSG_REQUEST_STATUS CAN1_ValidateTransmission(uint8_t channel, struct CAN_MSG_OBJ *txCanMsg)
{
    enum CAN_TX_MSG_REQUEST_STATUS txMsgStatus = CAN_TX_MSG_REQUEST_SUCCESS;
    uint8_t plsize = (FIFO[channel].CONT & _C1FIFOCON1T_PLSIZE_MASK) >> _C1FIFOCON1T_PLSIZE_POSN;
    
    // If CAN module is configured in Non-BRS mode and TX message object has BRS set
    if (((uint8_t)CAN_BRS_MODE == txCanMsg->field.brs) && ((1U == C1CONHbits.BRSDIS) || (CAN_NORMAL_2_0_MODE == CAN1_OperationModeGet())))
    {
        txMsgStatus |= CAN_TX_MSG_REQUEST_BRS_ERROR;
    }
    
    // If CAN 2.0 mode, TX Message object has more than 8 bytes of DLC Size
    if ((txCanMsg->field.dlc > (uint8_t)DLC_8) && (((uint8_t)CAN_2_0_FORMAT == txCanMsg->field.formatType) || (CAN_NORMAL_2_0_MODE == CAN1_OperationModeGet())))
    {
        txMsgStatus |= CAN_TX_MSG_REQUEST_DLC_EXCEED_ERROR;
    }
    
    // If any CAN TX message object has DLC size more than CAN TX FIFO Payload size
    if (CAN1_DlcToDataBytesGet(txCanMsg->field.dlc) > CAN1_PLSIZEToPayloadBytesGet(plsize))
    {
        txMsgStatus |= CAN_TX_MSG_REQUEST_DLC_EXCEED_ERROR;
    }
    
    // If CAN TX FIFO is full
    if (CAN_TX_FIFO_FULL ==  CAN1_TransmitFIFOStatusGet(channel))
    {
        txMsgStatus |= CAN_TX_MSG_REQUEST_FIFO_FULL;
    }
    
    return txMsgStatus;
}

/**
 * @ingroup can_driver
 * @brief Resets the CAN1 receive message head count.
 * @param None.
 * @return None.
*/
static void CAN1_RX_FIFO_ResetInfo(void)
{
    uint8_t count;
    
    for(count = 0; count < CAN1_NUM_OF_RX_FIFO; count++)
    {
        rxFIFOMsg[count].headCount = 0;
    }
}

/**
 * @ingroup can_driver
 * @brief Checks if a valid channel is configured as receiver or not.
 * @param [in] channel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS.
 * @retval True - FIFO channel is configured as receiver.
 * @retval False - FIFO channel is not configured as receiver.
*/
static bool CAN1_IsRxChannel(uint8_t channel) 
{
    return ((channel < 4U) && !(FIFO[channel].CONL & _C1FIFOCON1L_TXEN_MASK));
}

/**
 * @ingroup can_driver
 * @brief Returns the CAN1 Receive FIFO status.
 * @param [in] validChannel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS.
 * @return Status of the CAN1 Receive FIFO. Refer CAN_RX_FIFO_STATUS for details. 
*/
static uint8_t CAN1_GetRxFifoStatus(uint8_t validChannel)
{
    return (FIFO[validChannel].STAL & ((uint8_t)CAN_RX_MSG_AVAILABLE | (uint8_t)CAN_RX_MSG_OVERFLOW));
}

/**
 * @ingroup can_driver
 * @brief Returns the CAN1 Receive FIFO depth.
 * @param [in] validChannel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS.
 * @return Depth of the Receive FIFO.
*/
static uint8_t CAN1_GetRxFifoDepth(uint8_t validChannel)
{
    return (1U + (FIFO[validChannel].CONT & _C1FIFOCON1T_FSIZE_MASK));
}

/**
 * @ingroup can_driver
 * @brief Reads the message object from Receive FIFO and updates the user message object.
 * @param [in] rxFifoObj - Receive FIFO message object.
 * @param [out] rxCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @return None.
*/
static void CAN1_MessageReadFromFifo(uint8_t *rxFifoObj, struct CAN_MSG_OBJ *rxCanMsg)
{
    uint8_t index;
	uint32_t msgId;
	
	// DLC <3:0>, IDE <1>, FDF <1> 
    rxCanMsg->field.dlc = rxFifoObj[4];
    rxCanMsg->field.idType = (rxFifoObj[4] & (1UL << CAN_MSG_OBJ_IDE_POSN)) ? CAN_FRAME_EXT : CAN_FRAME_STD;
    rxCanMsg->field.frameType = (rxFifoObj[4] & (1UL << CAN_MSG_OBJ_RTR_POSN)) ? CAN_FRAME_RTR : CAN_FRAME_DATA;
    rxCanMsg->field.brs = (rxFifoObj[4] & (1UL << CAN_MSG_OBJ_BRS_POSN)) ? CAN_BRS_MODE : CAN_NON_BRS_MODE;
    rxCanMsg->field.formatType = (rxFifoObj[4] & (1UL << CAN_MSG_OBJ_FDF_POSN)) ? CAN_FRAME_EXT : CAN_FRAME_STD;
        
    msgId = (uint32_t)(rxFifoObj[1] & CAN_MSG_OBJ_SID_HIGH_MASK);
    msgId <<= CAN_MSG_OBJ_SID_LOW_WIDTH;
    
    msgId |= (uint32_t)(rxFifoObj[0] & CAN_MSG_OBJ_SID_LOW_MASK);
    
    if ((uint8_t)CAN_FRAME_EXT == rxCanMsg->field.idType)
    {
        /* message is extended identifier */
        
        msgId <<= CAN_MSG_OBJ_EID_HIGH_WIDTH;
        msgId |= (uint32_t)(rxFifoObj[3] & CAN_MSG_OBJ_EID_HIGH_MASK);
        
        msgId <<= CAN_MSG_OBJ_EID_MID_WIDTH;
        msgId |= (uint32_t)rxFifoObj[2];
        
        msgId <<= CAN_MSG_OBJ_EID_LOW_WIDTH;
        msgId |= (uint32_t)((rxFifoObj[1] & CAN_MSG_OBJ_EID_LOW_MASK) >> CAN_MSG_OBJ_EID_LOW_POSN);
    }
	
    rxCanMsg->msgId = msgId;
	
    // Copying receive FIFO data starting memory location
	for(index = 0; index < CAN1_DlcToDataBytesGet(rxCanMsg->field.dlc); index++)
    {
        *(rxMsgData + index) = rxFifoObj[8U + index];
    }
	
    rxCanMsg->data = rxMsgData;
}

/**
 * @ingroup can_driver
 * @brief Reads the data object from a particular CAN receive FIFO.
 * @param [in] index - Instance of Receive FIFO.
 * @param [in] channel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS.
 * @param [out] rxCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @retval True - CAN1 message read succeeded.
 * @retval False - CAN1 message read failed.
*/
static bool CAN1_ReceiveFromFiFo(uint8_t index, enum CAN_RX_FIFO_CHANNELS channel, struct CAN_MSG_OBJ *rxCanMsg)
{
    bool status = false;
    uint8_t rxMsgStatus;
    uint8_t *rxFifoObj;

    rxMsgStatus = CAN1_GetRxFifoStatus(channel);
	
    // If message object is available
    if ((uint8_t)CAN_RX_MSG_AVAILABLE == (rxMsgStatus & (uint8_t)CAN_RX_MSG_AVAILABLE))
    {
        rxFifoObj = (uint8_t *) FIFO[channel].UA;

        if (rxFifoObj != NULL)
        {
            CAN1_MessageReadFromFifo(rxFifoObj, rxCanMsg);
			
            // RX FIFO Increment Message Pointer
            FIFO[channel].CONH |= _C1FIFOCON1H_UINC_MASK;

            // Update the RX FIFO Head count for CAN1_ReceivedMessageCountGet function
            rxFIFOMsg[index].headCount += 1U; 
			
            if (rxFIFOMsg[index].headCount >= CAN1_GetRxFifoDepth(channel))
            {
                rxFIFOMsg[index].headCount = 0U; // Reset the read message count
            }

            // Application has to clear RX Overflow status
            if ((uint8_t)CAN_RX_MSG_OVERFLOW == (rxMsgStatus & (uint8_t)CAN_RX_MSG_OVERFLOW))
            {
                // RX FIFO Overflow Status Flag Clear
                FIFO[channel].STAL &= ~_C1FIFOSTA1L_RXOVIF_MASK;
            }

            status = true;
        }
    }
    
    return status;
}

/**
 * @ingroup can_driver
 * @brief Configures the CAN1 TX FIFO settings.
 * @param None.
 * @return None.
*/
static void CAN1_TX_FIFO_Configuration(void)
{
    // TXQNIE disabled; TXQEIE disabled; TXATIE disabled; 
    C1TXQCONL = 0x80;
    // UINC disabled; FRESET enabled; 
    C1TXQCONH = 0x4;
    // TXPRI 0; TXAT Unlimited number of retransmission attempts; 
    C1TXQCONU = 0x60;
    // FSIZE 6; PLSIZE 32; 
    C1TXQCONT = 0xA5;
}

/**
 * @ingroup can_driver
 * @brief Configures the CAN1 Receive FIFO settings.
 * @param None.
 * @return None.
*/
static void CAN1_RX_FIFO_Configuration(void)
{
    // TFNRFNIE enabled; TFHRFHIE disabled; TFERFFIE disabled; RXOVIE disabled; TXATIE disabled; RXTSEN disabled; RTREN disabled; TXEN disabled; 
    C1FIFOCON1L = 0x1;
    // UINC disabled; TXREQ disabled; FRESET enabled; 
    C1FIFOCON1H = 0x4;
    // TXPRI 0; TXAT Disables retransmission attempts; 
    C1FIFOCON1U = 0x0;
    // FSIZE 6; PLSIZE 32; 
    C1FIFOCON1T = 0xA5;
    // TFNRFNIE enabled; TFHRFHIE disabled; TFERFFIE disabled; RXOVIE disabled; TXATIE disabled; RXTSEN disabled; RTREN disabled; TXEN disabled; 
    C1FIFOCON2L = 0x1;
    // UINC disabled; TXREQ disabled; FRESET enabled; 
    C1FIFOCON2H = 0x4;
    // TXPRI 0; TXAT Disables retransmission attempts; 
    C1FIFOCON2U = 0x0;
    // FSIZE 6; PLSIZE 32; 
    C1FIFOCON2T = 0xA5;

    CAN1_FIFO1NotEmptyCallbackRegister(CAN1_FIFO1DefaultHandler);
    CAN1_FIFO2NotEmptyCallbackRegister(CAN1_FIFO2DefaultHandler);
    
	C1INTUbits.RXIE = 1;

    PIR4bits.CANRXIF = 0;
    PIE4bits.CANRXIE = 1;
}

/**
 * @ingroup can_driver
 * @brief Configures the CAN1 RX FIFO filter and mask settings.
 * @param None.
 * @return None.
*/
static void CAN1_RX_FIFO_FilterMaskConfiguration(void)
{
    /* Configure RX FIFO Filter control settings*/
    
    // message stored in FIFO2
    C1FLTCON0Hbits.F1BP =  2;
    // SID 133; 
    C1FLTOBJ1L = 0x85;
    // SID 5; EID 0; 
    C1FLTOBJ1H = 0x5;
    // EID 0; 
    C1FLTOBJ1U = 0x0;
    // EID 0; SID11 disabled; EXIDE disabled; 
    C1FLTOBJ1T = 0x0;
    // MSID 255; 
    C1MASK1L = 0xFF;
    // MSID 7; MEID 0; 
    C1MASK1H = 0x7;
    // MEID 0; 
    C1MASK1U = 0x0;
    // MEID 0; MSID11 disabled; MIDE enabled; 
    C1MASK1T = 0x40;
    // Enable the filter 1
    C1FLTCON0Hbits.FLTEN1 = 1;
    
    // message stored in FIFO1
    C1FLTCON0Lbits.F0BP =  1;
    // SID 17; 
    C1FLTOBJ0L = 0x11;
    // SID 1; EID 0; 
    C1FLTOBJ0H = 0x1;
    // EID 0; 
    C1FLTOBJ0U = 0x0;
    // EID 0; SID11 disabled; EXIDE disabled; 
    C1FLTOBJ0T = 0x0;
    // MSID 255; 
    C1MASK0L = 0xFF;
    // MSID 7; MEID 0; 
    C1MASK0H = 0x7;
    // MEID 0; 
    C1MASK0U = 0x0;
    // MEID 0; MSID11 disabled; MIDE enabled; 
    C1MASK0T = 0x40;
    // Enable the filter 0
    C1FLTCON0Lbits.FLTEN0 = 1;
}

/**
 * @ingroup can_driver
 * @brief Configures the CAN1 Bit rate settings.
 * @param None.
 * @return None.
*/
static void CAN1_BitRateConfiguration(void)
{
    // SJW 15; 
    C1NBTCFGL = 0xF;
    // TSEG2 15; 
    C1NBTCFGH = 0xF;
    // TSEG1 62; 
    C1NBTCFGU = 0x3E;
    // BRP 0; 
    C1NBTCFGT = 0x0;
    // SJW 3; 
    C1DBTCFGL = 0x3;
    // TSEG2 3; 
    C1DBTCFGH = 0x3;
    // TSEG1 14; 
    C1DBTCFGU = 0xE;
    // BRP 0; 
    C1DBTCFGT = 0x0;
    // TDCV 0x0; 
    C1TDCL = 0x0;
    // TDCO 15; 
    C1TDCH = 0xF;
    // TDCMOD Auto; 
    C1TDCU = 0x2;
    // SID11EN disabled; EDGFLTEN disabled; 
    C1TDCT = 0x0;
}


void CAN1_Initialize(void)
{
    /* Enable the CAN1 module */
    C1CONHbits.ON = 1;
	
    // ABAT disabled; TXBWS No delay; 
    C1CONT = 0x4;  
	
    // RTXAT disabled; ESIGM disabled; SERR2LOM disabled; STEF disabled; TXQEN enabled; 
    C1CONU = 0x90;  
    
    // Place CAN1 module in configuration mode
    if (CAN_OP_MODE_REQUEST_SUCCESS == CAN1_OperationModeSet(CAN_CONFIGURATION_MODE))
    {
        // Initialize the CAN1 Message Memory Base Address Register with the start address of the CAN1 FIFO message object area. 
        C1FIFOBAL = (uint8_t)0x3800U; 
        C1FIFOBAH = (uint8_t)(0x3800U >> 8); 
		
        // WAKFIL enabled; WFT T11 Filter; SIDL disabled; FRZ disabled; ON enabled; BRSDIS disabled; 
        C1CONH = 0x87;  
	
        // DNCNT 0x0; CLKSEL0 disabled; ISOCRCEN enabled; PXEDIS enabled; 
        C1CONL = 0x60;  

        // Disabled CAN1 Store in Transmit Event FIFO bit
        C1CONUbits.STEF = 0;
        // Enabled CAN1 Transmit Queue bit
        C1CONUbits.TXQEN = 1;
        
        /* Configure CAN1 Bit rate settings */
        CAN1_BitRateConfiguration();        
        
        /* Configure CAN1 FIFO settings */
        CAN1_TX_FIFO_Configuration();
        CAN1_RX_FIFO_Configuration();
        
        /* Configure Receive FIFO Filter and Mask settings */
        CAN1_RX_FIFO_FilterMaskConfiguration();    
        
        // Reset the CAN1 receive FIFO head count
        CAN1_RX_FIFO_ResetInfo();
        
        /* Place CAN1 module in Normal Operation mode */
        (void)CAN1_OperationModeSet(CAN_NORMAL_FD_MODE);    
    }
}

void CAN1_Deinitialize(void)
{
    /* Place CAN1 module in configuration mode */
    if(CAN_OP_MODE_REQUEST_SUCCESS == CAN1_OperationModeSet(CAN_CONFIGURATION_MODE))
    {        
        C1CONL = 0x60;  
        C1CONH = 0x7;  
        C1CONU = 0x98;  
        C1CONT = 0x4;  
           
        /* Reset bit rate settings to POR*/
        C1NBTCFGL = 0xF;
        C1NBTCFGH = 0xF;
        C1NBTCFGU = 0x3E;
        C1NBTCFGT = 0x0;
        C1DBTCFGL = 0x3;
        C1DBTCFGH = 0x3;
        C1DBTCFGU = 0xE;
        C1DBTCFGT = 0x0;
        C1TDCL = 0x0;
        C1TDCH = 0x10;
        C1TDCU = 0x2;
        C1TDCT = 0x0;
        
        /* Configure CAN1 FIFO settings */
        /* Reset TX FIFO settings to POR*/
        C1TXQCONL = 0x0;
        C1TXQCONH = 0x4;
        C1TXQCONU = 0x60;
        C1TXQCONT = 0x0;
        
        /* Reset RX FIFO settings to POR*/
        C1FIFOCON1L = 0x0;
        C1FIFOCON1H = 0x4;
        C1FIFOCON1U = 0x60;
        C1FIFOCON1T = 0x0;
        C1FIFOCON2L = 0x0;
        C1FIFOCON2H = 0x4;
        C1FIFOCON2U = 0x60;
        C1FIFOCON2T = 0x0;
        
        /* Reset RX FIFO Filter control settings to POR*/
        C1FLTCON0Hbits.F1BP = 0x0;
        C1FLTOBJ1L = 0x0;
        C1FLTOBJ1H = 0x0;
        C1FLTOBJ1U = 0x0;
        C1FLTOBJ1T = 0x0;
        C1MASK1L = 0x0;
        C1MASK1H = 0x0;
        C1MASK1U = 0x0;
        C1MASK1T = 0x0;
        C1FLTCON0Hbits.FLTEN1 = 0x0;
        C1FLTCON0Lbits.F0BP = 0x0;
        C1FLTOBJ0L = 0x0;
        C1FLTOBJ0H = 0x0;
        C1FLTOBJ0U = 0x0;
        C1FLTOBJ0T = 0x0;
        C1MASK0L = 0x0;
        C1MASK0H = 0x0;
        C1MASK0U = 0x0;
        C1MASK0T = 0x0;
        C1FLTCON0Lbits.FLTEN0 = 0x0;

    }
    
    /* Disable the CAN1 module */
    C1CONHbits.ON = 0;
}

enum CAN_OP_MODE_STATUS CAN1_OperationModeSet(const enum CAN_OP_MODES requestMode)
{
    enum CAN_OP_MODE_STATUS status = CAN_OP_MODE_REQUEST_SUCCESS;

    if ((CAN1_OperationModeGet() == CAN_CONFIGURATION_MODE)
        || (requestMode == CAN_DISABLE_MODE)
        || (requestMode == CAN_CONFIGURATION_MODE))
    {
        C1CONTbits.REQOP = requestMode;
        
        while (C1CONUbits.OPMOD != requestMode)
        {
            //This condition is avoiding the system error case endless loop
            if (C1INTHbits.SERRIF == 1)
            {
                status = CAN_OP_MODE_SYS_ERROR_OCCURED;
                break;
            }
        }
    }
    else
    {
        status = CAN_OP_MODE_REQUEST_FAIL;
    }

    return status;
}

enum CAN_OP_MODES CAN1_OperationModeGet(void)
{
    return C1CONUbits.OPMOD;
}

enum CAN_TX_MSG_REQUEST_STATUS CAN1_Transmit(const enum CAN_TX_FIFO_CHANNELS fifoChannel, struct CAN_MSG_OBJ *txCanMsg)
{
    uint8_t *txFifoObj;
	
    enum CAN_TX_MSG_REQUEST_STATUS status = CAN_TX_MSG_REQUEST_FIFO_FULL;
    
    status = CAN1_ValidateTransmission(fifoChannel, txCanMsg);
	
    if (CAN_TX_MSG_REQUEST_SUCCESS == status)
    {
        txFifoObj = (uint8_t *) FIFO[fifoChannel].UA;
            
        if (txFifoObj != NULL)
        {
            CAN1_MessageWriteToFifo(txFifoObj, txCanMsg);
			
            // Message Send Request
            FIFO[fifoChannel].CONH |= (_C1FIFOCON1H_TXREQ_MASK | _C1FIFOCON1H_UINC_MASK);
        }
    }
  
    return status;
}

enum CAN_TX_FIFO_STATUS CAN1_TransmitFIFOStatusGet(const enum CAN_TX_FIFO_CHANNELS fifoChannel)
{
    enum CAN_TX_FIFO_STATUS status = CAN_TX_FIFO_FULL;
    
    if (CAN1_IsTxChannel(fifoChannel)) 
    {
        status = CAN1_GetTxFifoStatus(fifoChannel);
    }
    
    return status;
}

bool CAN1_IsTxErrorPassive(void)
{
    return C1TRECUbits.TXBP;
}

bool CAN1_IsTxErrorWarning(void)
{
    return C1TRECUbits.TXWARN;
}

bool CAN1_IsTxErrorActive(void)
{
    bool errorState = false;
	
    if(C1TRECHbits.TERRCNT < 128U) 
    {
        errorState = true;
    }
    
    return errorState;
}

bool CAN1_Receive(struct CAN_MSG_OBJ *rxCanMsg)
{
    uint8_t index;
    bool status = false;
	
    // Iterate all receive FIFOs and read the message object
    for (index = 0; index < CAN1_NUM_OF_RX_FIFO; index++)
    {
        status = CAN1_ReceiveFromFiFo(index, rxFIFOMsg[index].channel, rxCanMsg);
        
        if (status)
        {
            break;
        }
    }
    
    return status;
}

bool CAN1_ReceiveMessageGet(const enum CAN_RX_FIFO_CHANNELS fifoChannel, struct CAN_MSG_OBJ *rxCanMsg)
{
    uint8_t index;
    bool status = false;
    
    for (index = 0; index < CAN1_NUM_OF_RX_FIFO; index++)
    {
        if (fifoChannel == rxFIFOMsg[index].channel)
        {
            status = CAN1_ReceiveFromFiFo(index, fifoChannel, rxCanMsg);
            break;
        }
    }
    
    return status;
}

uint8_t CAN1_ReceivedMessageCountGet(void)
{
    enum CAN_RX_FIFO_CHANNELS fifoChannel;
    uint8_t index = 0;
    uint8_t totalMsgObj = 0;
    uint8_t rxMsgStatus;
    uint8_t numOfMsg = 0;
    uint8_t fifoDepth = 0;
    uint8_t rxfifoMsgTail = 0;

    // Iterate all receive FIFOs and get the message object count
    for (index = 0; index < CAN1_NUM_OF_RX_FIFO; index++)
    {
        fifoChannel = rxFIFOMsg[index].channel;
        rxMsgStatus = CAN1_GetRxFifoStatus(fifoChannel);

        // If message object is available
        if ((uint8_t)CAN_RX_MSG_AVAILABLE == (rxMsgStatus & (uint8_t)CAN_RX_MSG_AVAILABLE))
        {
            fifoDepth = CAN1_GetRxFifoDepth(fifoChannel);
            
            // If receive FIFO overflow has occurred, FIFO is full
            if ((uint8_t)CAN_RX_MSG_OVERFLOW == (rxMsgStatus & (uint8_t)CAN_RX_MSG_OVERFLOW))
            {
                numOfMsg = fifoDepth;
            }
            else
            {
                rxfifoMsgTail = FIFO[fifoChannel].STAH & _C1FIFOSTA1H_FIFOCI_MASK;

                if (rxfifoMsgTail < rxFIFOMsg[index].headCount)
                {
                    numOfMsg = ((rxfifoMsgTail + fifoDepth) - rxFIFOMsg[index].headCount); 
                }
                else if (rxfifoMsgTail > rxFIFOMsg[index].headCount)
                {
                    numOfMsg = rxfifoMsgTail - rxFIFOMsg[index].headCount;
                }
                else
                {
                    numOfMsg = fifoDepth;
                }
            }

            totalMsgObj += numOfMsg;
        }
    }

    return totalMsgObj;
}

uint8_t CAN1_ReceiveFIFOStatusGet(const enum CAN_RX_FIFO_CHANNELS fifoChannel)
{
    uint8_t status = CAN_RX_MSG_NOT_AVAILABLE;
    
    if (CAN1_IsRxChannel(fifoChannel)) 
    {
        status = CAN1_GetRxFifoStatus(fifoChannel);
    }
    
    return status;
}

bool CAN1_IsRxErrorPassive(void)
{
    return C1TRECUbits.RXBP;
}

bool CAN1_IsRxErrorWarning(void)
{
    return C1TRECUbits.RXWARN;
}

bool CAN1_IsRxErrorActive(void)
{
    bool errorState = false;
	
    if(C1TRECLbits.RERRCNT < 128U) 
    {
        errorState = true;
    }
    
    return errorState;
}

bool CAN1_IsBusOff(void)
{
    return C1TRECUbits.TXBO;
}

void CAN1_Sleep(void)
{
    C1INTHbits.WAKIF = 0;
    C1INTTbits.WAKIE = 1;
	
    // CAN Information Interrupt Enable bit
    PIE0bits.CANIE = 1;  
    
    // put the module in disable mode
    (void)CAN1_OperationModeSet(CAN_DISABLE_MODE);
}

void CAN1_InvalidMessageCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_InvalidMessageHandler = handler;
    }
}

void CAN1_BusWakeUpActivityCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_BusWakeUpActivityHandler = handler;
    }
}

void CAN1_BusErrorCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_BusErrorHandler = handler;
    }
}

void CAN1_ModeChangeCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_ModeChangeHandler = handler;
    }
}

void CAN1_SystemErrorCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_SystemErrorHandler = handler;
    }
}

void CAN1_TxAttemptCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_TxAttemptHandler = handler;
    }
}

void CAN1_RxBufferOverFlowCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_RxBufferOverFlowHandler = handler;
    }
}

void CAN1_FIFO1NotEmptyCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_FIFO1NotEmptyHandler = handler;
    }
}

void CAN1_FIFO2NotEmptyCallbackRegister(void (*handler)(void))
{
    if(handler != NULL)
    {
        CAN1_FIFO2NotEmptyHandler = handler;
    }
}

void __interrupt(irq(CAN),base(8)) CAN1_InformationISR(void)
{
    // Bus Wake-up Activity Interrupt 
    if(1 == C1INTHbits.WAKIF)
    {
        if(CAN1_BusWakeUpActivityHandler != NULL)
        {
            CAN1_BusWakeUpActivityHandler();
        } 
		
        C1INTHbits.WAKIF = 0;
    }
    
    PIR0bits.CANIF = 0;
}

void __interrupt(irq(CANRX),base(8)) CAN1_ReceiveISR(void)
{
	
    if (1 == C1FIFOSTA1Lbits.TFNRFNIF)
    {
	    if(CAN1_FIFO1NotEmptyHandler != NULL)
		{
		    CAN1_FIFO1NotEmptyHandler();
		}
        
        // Read only flag
    }  	
	
    if (1 == C1FIFOSTA2Lbits.TFNRFNIF)
    {
	    if(CAN1_FIFO2NotEmptyHandler != NULL)
		{
		    CAN1_FIFO2NotEmptyHandler();
		}
        
        // Read only flag
    }  	
}

void CAN1_Tasks(void)
{
	
    if(1 == C1INTHbits.IVMIF)
    {
        if(CAN1_InvalidMessageHandler != NULL)
        {
            CAN1_InvalidMessageHandler();
        } 
		
        C1INTHbits.IVMIF = 0;
    }  
	
    if(1 == C1INTHbits.CERRIF)
    {
        if(CAN1_BusErrorHandler != NULL)
        {
            CAN1_BusErrorHandler();
        } 
		
        C1INTHbits.CERRIF = 0;
    }  
	
    if(1 == C1INTLbits.MODIF)
    {
        if(CAN1_ModeChangeHandler != NULL)
        {
            CAN1_ModeChangeHandler();
        } 
		
        C1INTLbits.MODIF = 0;
    }  
	
    if(1 == C1INTHbits.SERRIF)
    {
        if(CAN1_SystemErrorHandler != NULL)
        {
            CAN1_SystemErrorHandler();
        } 
		
        C1INTHbits.SERRIF = 0;
    }  
        
    if(1 == C1TXQSTALbits.TXATIF)
    {
	    if(CAN1_TxAttemptHandler != NULL)
        {
            CAN1_TxAttemptHandler();
        }
		
		C1TXQSTALbits.TXATIF = 0;
    }
	
    if(1 == C1FIFOSTA1Lbits.RXOVIF)
    {
	    if(CAN1_RxBufferOverFlowHandler != NULL)
		{
			CAN1_RxBufferOverFlowHandler();
		} 
		
        C1FIFOSTA1Lbits.RXOVIF = 0;
    }
	
    if(1 == C1FIFOSTA2Lbits.RXOVIF)
    {
	    if(CAN1_RxBufferOverFlowHandler != NULL)
		{
			CAN1_RxBufferOverFlowHandler();
		} 
		
        C1FIFOSTA2Lbits.RXOVIF = 0;
    }
}


