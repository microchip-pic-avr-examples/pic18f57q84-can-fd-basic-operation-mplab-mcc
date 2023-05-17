/**
 * CAN Generated Driver Types Header File
 * 
 * @file can_types.h
 * 
 * @ingroup can_driver
 * 
 * @brief This is the generated driver types header file for the CAN driver.
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

#ifndef CAN_TYPES_H
#define CAN_TYPES_H

#include <stdint.h>

/**
 @ingroup  can_driver
 @enum     CAN_TX_FIFO_CHANNELS
 @brief    Defines the CAN FIFOs configured as transmit.

*/
enum CAN_TX_FIFO_CHANNELS
{
    CAN1_TXQ = 0,   /**< CAN1 Transmit FIFO TXQ */
    CAN_TX_FIFO_MAX /**< This is added to avoid empty enum */
}; 

/**
 @ingroup  can_driver
 @enum     CAN_RX_FIFO_CHANNELS
 @brief    Defines the CAN FIFOs configured as receive.
*/
enum CAN_RX_FIFO_CHANNELS
{
    CAN1_FIFO_1 = 1,  /**< CAN1 Receive FIFO 1 */
    CAN1_FIFO_2 = 2,  /**< CAN1 Receive FIFO 2 */
    CAN_RX_FIFO_MAX /**< This is added to avoid empty enum */
};

/**
 @ingroup  can_driver
 @struct   CAN_MSG_FIELD
 @brief    Used to configure the message fields of CAN frame. 
*/
struct CAN_MSG_FIELD
{
    uint8_t idType:1;       /**< Defines the message ID type as Standard ID or Extended ID (width: 1 bit) */
    uint8_t frameType:1;    /**< Defines the message frame type as Data Frame or RTR Frame (1 bit) */
    uint8_t dlc:4;          /**< Defines the size of the data bytes in a message frame. The maximum DLC is 8 for CAN 2.0 and 64 for CAN FD (width: 4 bit) */ 
    uint8_t formatType:1;   /**< Defines the message type as CAN 2.0 Format or CAN_FD Format (width: 1 bit) */
    uint8_t brs:1;          /**< Enables or Disables the Bit Rate Switch (width:1 bit) */
};

/**
 @ingroup  can_driver
 @struct   CAN_MSG_OBJ
 @brief    Used to configure the message object of CAN frame.
*/
struct CAN_MSG_OBJ
{
    uint32_t msgId;          /**< Set the CAN Message ID (EID <17:0> | SID <10:0>) */ 
    struct CAN_MSG_FIELD field;     /**< For CAN TX/RX Message Object Control */
    uint8_t *data;           /**< Pointer to message data */
};   

/**
 @ingroup  can_driver
 @enum     CAN_MSG_OBJ_BRS_MODE
 @brief    Defines if the bit rate switching is enabled or disabled in the CAN message object. 
*/
enum CAN_MSG_OBJ_BRS_MODE
{   
    CAN_NON_BRS_MODE    = 0,    /**< Disable BRS Mode (Supported only in CAN FD mode) */
    CAN_BRS_MODE        = 1     /**< Enable BRS Mode (Supported only in CAN FD mode) */
};

/**
 @ingroup  can_driver
 @enum     CAN_MSG_OBJ_ID_TYPE
 @brief    Defines if the message ID is Standard ID or Extended ID in CAN message object.
*/
enum CAN_MSG_OBJ_ID_TYPE
{   
    CAN_FRAME_STD       = 0,    /**< Standard ID CAN message object */
    CAN_FRAME_EXT       = 1     /**< Extended ID CAN message object */
};

/**
 @ingroup  can_driver
 @enum     CAN_MSG_OBJ_FRAME_TYPE
 @brief    Defines if the frame type is Data frame or Remote Transmit Request frame in CAN message object. 
*/
enum CAN_MSG_OBJ_FRAME_TYPE
{   
    CAN_FRAME_DATA      = 0,    /**< Data Frame CAN message object */
    CAN_FRAME_RTR       = 1     /**< Remote Transmit Request Frame CAN message object (Supported only in CAN 2.0 mode) */
};

/**
 @ingroup  can_driver
 @enum     CAN_MSG_OBJ_TYPE
 @brief    Defines if the CAN message object is in CAN FD format or CAN 2.0 format.
*/
enum CAN_MSG_OBJ_TYPE
{   
    CAN_2_0_FORMAT      = 0,    /**< CAN 2.0 Message format */
    CAN_FD_FORMAT       = 1     /**< CAN FD Message format (Supported only in CAN FD mode)*/     
};

/**
 @ingroup  can_driver
 @enum     CAN_TX_MSG_REQUEST_STATUS
 @brief    Defines the CAN transmit API return status.
*/
enum CAN_TX_MSG_REQUEST_STATUS
{ 
    CAN_TX_MSG_REQUEST_SUCCESS = 0,             /**< Transmit message object successfully placed into Transmit FIFO */
    CAN_TX_MSG_REQUEST_DLC_EXCEED_ERROR = 1,    /**< Transmit message object DLC size is more than the Transmit FIFO configured DLC size */
    CAN_TX_MSG_REQUEST_BRS_ERROR = 2,           /**< Transmit FIFO is configured as Non BRS mode and CAN TX Message object has BRS enabled */
    CAN_TX_MSG_REQUEST_FIFO_FULL = 3            /**< Transmit FIFO is Full */
};

/**
 @ingroup  can_driver
 @enum     CAN_OP_MODES
 @brief    Defines the CAN operation modes that are available for the module to use.
*/
enum CAN_OP_MODES
{
    CAN_NORMAL_FD_MODE = 0x0,           /**< CAN FD Normal Operation Mode (Supported only in CAN FD mode) */
    CAN_DISABLE_MODE = 0x1,             /**< CAN Disable Operation Mode */               
    CAN_INTERNAL_LOOPBACK_MODE = 0x2,   /**< CAN Internal Loopback Operation Mode */
    CAN_LISTEN_ONLY_MODE = 0x3,         /**< CAN Listen only Operation Mode */
    CAN_CONFIGURATION_MODE = 0x4,       /**< CAN Configuration Operation Mode */
    CAN_EXTERNAL_LOOPBACK_MODE = 0x5,   /**< CAN External Loopback Operation Mode */
    CAN_NORMAL_2_0_MODE = 0x6,          /**< CAN 2.0 Operation Mode */
    CAN_RESTRICTED_OPERATION_MODE =0x7  /**< CAN Restricted Operation Mode */
};   

/**
 @ingroup  can_driver
 @enum     CAN_OP_MODE_STATUS
 @brief    Defines the return status of CAN operation mode set API.
*/
enum CAN_OP_MODE_STATUS
{
    CAN_OP_MODE_REQUEST_SUCCESS,     /**< The requested operation mode set successfully */
    CAN_OP_MODE_REQUEST_FAIL,        /**< The requested operation mode set failure */
    CAN_OP_MODE_SYS_ERROR_OCCURED    /**< The system error occurred while setting operation mode. */
};

/**
 @ingroup  can_driver
 @enum     CAN_TX_FIFO_STATUS
 @brief    Defines the status of CAN FD transmit FIFO.
*/
enum CAN_TX_FIFO_STATUS
{
    CAN_TX_FIFO_FULL = 0x0,       /**< Transmit FIFO is full */                 
    CAN_TX_FIFO_AVAILABLE = 0x1  /**< Transmit FIFO is available */          
};

/**
 @ingroup  can_driver
 @enum     CAN_RX_FIFO_STATUS
 @brief    Defines the CAN FD receive FIFO status bit mask values.
*/
enum CAN_RX_FIFO_STATUS 
{
    CAN_RX_MSG_NOT_AVAILABLE = 0x0, /**< Message is not available in receive FIFO */
    CAN_RX_MSG_AVAILABLE = 0x1, /**< Message is available in receive FIFO */   
    CAN_RX_MSG_OVERFLOW = 0x8 /**< Receive FIFO has overflowed */
};

/**
 @ingroup  can_driver
 @enum     CAN_DLC
 @brief    Defines the CAN message payload sizes that are available for the mode to use.
*/
enum CAN_DLC
{
    DLC_0, /**< Data length count 0 */
    DLC_1, /**< Data length count 1 */
    DLC_2, /**< Data length count 2 */
    DLC_3, /**< Data length count 3 */
    DLC_4, /**< Data length count 4 */
    DLC_5, /**< Data length count 5 */
    DLC_6, /**< Data length count 6 */
    DLC_7, /**< Data length count 7 */
    DLC_8, /**< Data length count 8 */
    DLC_12, /**< Data length count 12 (Supported only in CAN FD mode) */
    DLC_16, /**< Data length count 16 (Supported only in CAN FD mode) */
    DLC_20, /**< Data length count 20 (Supported only in CAN FD mode) */
    DLC_24, /**< Data length count 24 (Supported only in CAN FD mode) */
    DLC_32, /**< Data length count 32 (Supported only in CAN FD mode) */
    DLC_48, /**< Data length count 48 (Supported only in CAN FD mode) */
    DLC_64  /**< Data length count 64 (Supported only in CAN FD mode) */
};

#endif  //CAN_TYPES_H
