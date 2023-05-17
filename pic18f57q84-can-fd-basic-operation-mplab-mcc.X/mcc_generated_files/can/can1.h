/**
 * CAN1 Generated Driver Header File
 *
 * @file can1.h
 *
 * @defgroup can_driver CAN FD DRIVER
 *
 * @brief This file contains API prototypes and other data types for the CAN1 driver.
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

#ifndef CAN1_H
#define CAN1_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include "can_types.h"
#include "can_interface.h"

/**
 @ingroup  can_driver
 @brief    Structure object of type CAN_INTERFACE with the custom name given by
           the user. 
*/
extern const struct CAN_INTERFACE CAN_FD1;

/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Initialize() API.
 */
#define CAN_FD1_Initialize CAN1_Initialize
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Deinitialize() API.
 */
#define CAN_FD1_Deinitialize CAN1_Deinitialize
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_OperationModeSet() API.
 */
#define CAN_FD1_OperationModeSet CAN1_OperationModeSet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_OperationModeGet() API.
 */
#define CAN_FD1_OperationModeGet CAN1_OperationModeGet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Transmit() API.
 */
#define CAN_FD1_Transmit CAN1_Transmit
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_TransmitFIFOStatusGet() API.
 */
#define CAN_FD1_TransmitFIFOStatusGet CAN1_TransmitFIFOStatusGet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsTxErrorPassive() API.
 */
#define CAN_FD1_IsTxErrorPassive CAN1_IsTxErrorPassive
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsTxErrorWarning() API.
 */
#define CAN_FD1_IsTxErrorWarning CAN1_IsTxErrorWarning
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsTxErrorActive() API.
 */
#define CAN_FD1_IsTxErrorActive CAN1_IsTxErrorActive
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Receive() API.
 */
#define CAN_FD1_Receive CAN1_Receive
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_ReceiveMessageGet() API.
 */
#define CAN_FD1_ReceiveMessageGet CAN1_ReceiveMessageGet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_ReceivedMessageCountGet() API.
 */
#define CAN_FD1_ReceivedMessageCountGet CAN1_ReceivedMessageCountGet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_ReceiveFIFOStatusGet() API.
 */
#define CAN_FD1_ReceiveFIFOStatusGet CAN1_ReceiveFIFOStatusGet
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsRxErrorPassive() API.
 */
#define CAN_FD1_IsRxErrorPassive CAN1_IsRxErrorPassive
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsRxErrorWarning() API.
 */
#define CAN_FD1_IsRxErrorWarning CAN1_IsRxErrorWarning
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsRxErrorActive() API.
 */
#define CAN_FD1_IsRxErrorActive CAN1_IsRxErrorActive
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_IsBusOff() API.
 */
#define CAN_FD1_IsBusOff CAN1_IsBusOff
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Sleep() API.
 */
#define CAN_FD1_Sleep CAN1_Sleep
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_InvalidMessageCallbackRegister() API.
 */
#define CAN_FD1_InvalidMessageCallbackRegister CAN1_InvalidMessageCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_BusWakeUpActivityCallbackRegister() API.
 */
#define CAN_FD1_BusWakeUpActivityCallbackRegister CAN1_BusWakeUpActivityCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_BusErrorCallbackRegister() API.
 */
#define CAN_FD1_BusErrorCallbackRegister CAN1_BusErrorCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_ModeChangeCallbackRegister() API.
 */
#define CAN_FD1_ModeChangeCallbackRegister CAN1_ModeChangeCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_SystemErrorCallbackRegister() API.
 */
#define CAN_FD1_SystemErrorCallbackRegister CAN1_SystemErrorCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_TxAttemptCallbackRegister() API.
 */
#define CAN_FD1_TxAttemptCallbackRegister CAN1_TxAttemptCallbackRegister
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_RxBufferOverFlowCallbackRegister() API.
 */
#define CAN_FD1_RxBufferOverFlowCallbackRegister CAN1_RxBufferOverFlowCallbackRegister
/**
 @ingroup  can_driver
 @brief    CAN1 Transmit FIFO TXQ Custom Name.
*/
#define CAN1_TX_TXQ   CAN1_TXQ   /**< Defines the custom name of CAN1_TXQ used for Transmit functionality. */
/**
 @ingroup  can_driver
 @brief    CAN1 Receive FIFO 1 Custom Name.
*/
#define CAN1_RX_FIFO1   CAN1_FIFO_1   /**< Defines the custom name of CAN1_FIFO_1 used for Receive functionality. */
/**
 @ingroup  can_driver
 @brief    CAN1 Receive FIFO 2 Custom Name.
*/
#define CAN1_RX_FIFO2   CAN1_FIFO_2   /**< Defines the custom name of CAN1_FIFO_2 used for Receive functionality. */
/**
 * @ingroup  can_driver
 * @brief    Defines the Custom Name for CAN1_Tasks() API.
 */
#define CAN_FD1_Tasks CAN1_Tasks

/**
 * @ingroup can_driver
 * @brief Initializes the CAN1 module.
 * @param None.
 * @return None.
 */
void CAN1_Initialize(void);

/**
 * @ingroup can_driver
 * @brief Resets the CAN1 registers and settings to their POR values.
 * @param None.
 * @return None.
 */
void CAN1_Deinitialize(void);

/**
 * @ingroup can_driver
 * @brief Sets the CAN1 Operation mode.
 * @pre CAN1_Initialize() function is already called.
 * @param [in] requestMode - CAN1 Operation mode as described in CAN_OP_MODES.
 * @return Status of request to set the CAN1 Operation mode as described in CAN_OP_MODE_STATUS.
 */
enum CAN_OP_MODE_STATUS CAN1_OperationModeSet(const enum CAN_OP_MODES requestMode);

/**
 * @ingroup can_driver
 * @brief Gets the CAN1 Operation mode.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @return The present CAN1 Operation mode as described in CAN_OP_MODES.
 */
enum CAN_OP_MODES CAN1_OperationModeGet(void);

/**
 * @ingroup can_driver
 * @brief Writes the CAN message object to the specified transmit FIFO channel.
 * @pre CAN1_Initialize() function is already called.
 *		CAN1_TransmitFIFOStatusGet function is called to check buffer availability in the Transmit FIFO.
 * @param [in] fifoChannel - Transmit FIFO channel as described in CAN_TX_FIFO_CHANNELS where the message object is to be written.
 * @param [in] txCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @return Status of the CAN1 Transmit operation as described in CAN_TX_MSG_REQUEST_STATUS.
 */
enum CAN_TX_MSG_REQUEST_STATUS CAN1_Transmit(const enum CAN_TX_FIFO_CHANNELS fifoChannel, struct CAN_MSG_OBJ *txCanMsg);

/**
 * @ingroup can_driver
 * @brief Returns the CAN1 transmitter FIFO status.
 * @pre CAN1_Initialize() function is already called.
 * @param [in] fifoChannel - Transmit FIFO channel as described in CAN_TX_FIFO_CHANNELS.
 * @return Status of the CAN1 Transmit FIFO as described in CAN_TX_FIFO_STATUS.
 */
enum CAN_TX_FIFO_STATUS CAN1_TransmitFIFOStatusGet(const enum CAN_TX_FIFO_CHANNELS fifoChannel);

/**
 * @ingroup can_driver
 * @brief Returns the Transmit Error Passive state.
 *        If the Transmit Error Counter is above 127, then the transmitter is in Error Passive state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Transmit Error Passive state.
 * @retval False - CAN1 node is not in Transmit Error Passive state.
 */
bool CAN1_IsTxErrorPassive(void);

/**
 * @ingroup can_driver
 * @brief Returns the Transmit Error Warning state.
 *        If the Transmit Error Counter is above 95 and below 128, then the transmitter is in Error Warning state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Transmit Error Warning state.
 * @retval False - CAN1 node is not in Transmit Error Warning state.
 */
bool CAN1_IsTxErrorWarning(void);

/**
 * @ingroup can_driver
 * @brief Returns the Transmit Error Active state.
          If the Transmit Error Counter is above 0 and below 128, then the transmitter is in Error Active state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Transmit Error Active state.
 * @retval False - CAN1 node is not in Transmit Error Active state.
 */
bool CAN1_IsTxErrorActive(void);

/**
 * @ingroup can_driver
 * @brief Reads a message object.
 * @pre CAN1_Initialize() function is already called.
 *      The CAN1_ReceivedMessageCountGet() function is called to check if any CAN message is received.
 * @param [out] rxCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @retval True - CAN1 message read succeeded.
 * @retval False - CAN1 message read failed.
 */
bool CAN1_Receive(struct CAN_MSG_OBJ *rxCanMsg);

/**
 * @ingroup can_driver
 * @brief Reads a message object from the selected CAN1 receive FIFO.
 * @pre CAN1_Initialize() function is already called.
 * 		The CAN1_ReceiveFIFOStatusGet() function is called to check the status of the respective CAN1 receive FIFO.
 * @param [in] fifoChannel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS from where the message object is to be read.
 * @param [out] rxCanMsg - Pointer to the message object of type CAN_MSG_OBJ.
 * @retval True - CAN1 message read succeeded.
 * @retval False - CAN1 message read failed.
 */
bool CAN1_ReceiveMessageGet(const enum CAN_RX_FIFO_CHANNELS fifoChannel, struct CAN_MSG_OBJ *rxCanMsg);

/**
 * @ingroup can_driver
 * @brief Returns the number of CAN messages received in all the FIFOs.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @return Number of messages received.
 */
uint8_t CAN1_ReceivedMessageCountGet(void);

/**
 * @ingroup can_driver
 * @brief Returns the CAN1 receiver FIFO status.
 * @pre CAN1_Initialize() function is already called.
 * @param [in] fifoChannel - Receive FIFO channel as described in CAN_RX_FIFO_CHANNELS.
 * @return Status of the CAN1 Receive FIFO. Refer to CAN_RX_FIFO_STATUS for details.
 */
uint8_t CAN1_ReceiveFIFOStatusGet(const enum CAN_RX_FIFO_CHANNELS fifoChannel);

/**
 * @ingroup can_driver
 * @brief Returns the Receive Error Passive state.
          If the Receive Error Counter is above 127, then the receiver is in Error Passive state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Receive Error Passive state.
 * @retval False - CAN1 node is not in Receive Error Passive state.
 */
bool CAN1_IsRxErrorPassive(void);

/**
 * @ingroup can_driver
 * @brief Returns the Receive Error Warning state.
 *        If the Receive Error Counter is above 95 and below 128, then the receiver is in Error Warning state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Receive Error Warning state.
 * @retval False - CAN1 node is not in Receive Error Warning state.
 */
bool CAN1_IsRxErrorWarning(void);

/**
 * @ingroup can_driver
 * @brief Returns the Receive Error Active state.
          If the Receive Error Counter is above 0 and below 128, then the receiver is in Error Active state.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Receive Error Active state.
 * @retval False - CAN1 node is not in Receive Error Active state.
 */
bool CAN1_IsRxErrorActive(void);

/**
 * @ingroup can_driver
 * @brief Returns the Bus Off status.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @retval True - CAN1 node is in Bus Off state.
 * @retval False - CAN1 node is not in Bus Off state.
 */
bool CAN1_IsBusOff(void);

/**
 * @ingroup can_driver
 * @brief Puts the CAN1 node into Sleep mode.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @return None.
 */
void CAN1_Sleep(void);

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_InvalidMessage callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_InvalidMessageCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_BusWakeUpActivity callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_BusWakeUpActivityCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_BusError callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_BusErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_ModeChange callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_ModeChangeCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_SystemError callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_SystemErrorCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_TxAttempt callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_TxAttemptCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_RxBufferOverFlow callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_RxBufferOverFlowCallbackRegister(void (*handler)(void));

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_FIFO1NotEmpty callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_FIFO1NotEmptyCallbackRegister(void (*handler)(void)); 

/**
 * @ingroup can_driver
 * @brief Setter function for the CAN1_FIFO2NotEmpty callback.
 * @param [in] handler - Pointer to the callback routine.
 * @return None.
 */
void CAN1_FIFO2NotEmptyCallbackRegister(void (*handler)(void)); 

/**
 * @ingroup can_driver
 * @brief Used to implement the tasks for polled implementations.
 * @pre CAN1_Initialize() function is already called.
 * @param None.
 * @return None.
 */
void CAN1_Tasks(void);

#endif  //CAN1_H
