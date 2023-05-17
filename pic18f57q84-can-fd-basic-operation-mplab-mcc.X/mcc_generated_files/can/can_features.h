/**
 * CAN Generated Feature Header File
 * 
 * @file can_features.h
 *            
 * @ingroup can_driver
 *            
 * @brief This is the generated module feature header file for CAN driver. 
 * 		  This file provides module feature list available on the selected device. 
 *
 * @note The macros defined in this file provides the flexibility to easily migrate 
 * 	     the user application to other device which might have varied feature list.
 *
 * @note The file has to be manually included in main.c, if the user intends to migrate 
 *		 the application to another device which might have varied feature list.
 *
 * @warning The content in this file is strictly "read only" and should 
 * 			not be altered. Failing to do so, the migration is not guaranteed.     
 * 
 * @version   CAN Driver Version 1.0.0
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

#ifndef CAN_FEATURES
#define CAN_FEATURES
        
/**
  @ingroup  can_driver
  @brief    Defines the CAN FD Message format data update request functionality.
  @note     APIs Supported:
   CAN_TX_MSG_REQUEST_STATUS CANx_Transmit(const CANx_TX_FIFO_CHANNELS fifoChannel, CAN_MSG_OBJ *txCanMsg);
   bool CANx_Receive(CAN_MSG_OBJ *rxCanMsg);
   
   x in CANx denotes the instance number of CAN. 
   Refer to the specific device data sheet to check the number of CAN peripherals present in the device. 
   Refer to the driver header file for detailed description of the APIs.
  
*/
#define CAN_FD_MESSAGE_FORMAT_FEATURE_AVAILABLE  1

/** 
  @ingroup  can_driver
  @brief    Defines the CAN FIFO based transmit priority data update request functionality.
  @note 	APIs Supported:
   CAN_TX_MSG_REQUEST_STATUS CANx_Transmit(const CANx_TX_FIFO_CHANNELS fifoChannel, CAN_MSG_OBJ *txCanMsg);
   CAN_TX_FIFO_STATUS CANx_TransmitFIFOStatusGet(const CANx_TX_FIFO_CHANNELS fifoChannel);
  
   x in CANx denotes the instance number of CAN. 
   Refer to the specific device data sheet to check the number of CAN peripherals present in the device. 
   Refer to the driver header file for detailed description of the APIs.
*/
#define CAN_FIFO_BASED_TRANSMIT_PRIORITY_FEATURE_AVAILABLE  1

/**
  @ingroup  can_driver
  @brief    Defines the CAN 2.0 DMA interface data update request functionality.
*/
#define CAN_DMA_INTERFACE_FEATURE_AVAILABLE  0

#endif //CAN_MODULE_FEATURES
