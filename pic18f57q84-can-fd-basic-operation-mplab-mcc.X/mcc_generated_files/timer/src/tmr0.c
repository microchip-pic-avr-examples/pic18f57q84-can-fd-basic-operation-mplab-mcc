/**
 * TMR0 Generated Driver File
 * 
 * @file tmr0.c
 * 
 * @ingroup tmr0
 * 
 * @brief  Driver implementation for the TMR0 driver
 *
 * @version TMR0 Driver Version 2.1.1
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

#include <xc.h>
#include "../tmr0.h"
#include "../../system/interrupt.h"

volatile uint16_t timerTMR0ReloadVal16bit;

const struct TMR_INTERFACE timer0 = {
    .Initialize = Timer0_Initialize,
    .Start = Timer0_Start,
    .Stop = Timer0_Stop,
    .PeriodCountSet = Timer0_PeriodCountSet,
    .TimeoutCallbackRegister = Timer0_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*Timer0_OverflowCallback)(void);
static void Timer0_DefaultOverflowCallback(void);

void Timer0_Initialize(void)
{
    //TMR0H 194; 
    TMR0H = 0xC2;

    //TMR0L 247; 
    TMR0L = 0xF7;

    //T0CS HFINTOSC; T0CKPS 1:256; T0ASYNC synchronised; 
    T0CON1 = 0x68;

    //Load TMRTMR0 value to the 16-bit reload variable
    timerTMR0ReloadVal16bit = ((uint16_t)TMR0H << 8) | TMR0L;

    //Set default callback for TMR0 overflow interrupt
    Timer0_OverflowCallbackRegister(Timer0_DefaultOverflowCallback);

    //Clear Interrupt flag before enabling the interrupt
    PIR3bits.TMR0IF = 0;
	
    //Enable TMR0 interrupt.
    PIE3bits.TMR0IE = 1;
	
    //T0OUTPS 1:1; T0EN enabled; T016BIT 16-bit; 
    T0CON0 = 0x90;
}

void Timer0_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void Timer0_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint16_t Timer0_Read(void)
{
    uint16_t readVal;
    uint8_t readValLow;
    uint8_t readValHigh;

    readValLow  = TMR0L;
    readValHigh = TMR0H;
    readVal  = ((uint16_t)readValHigh << 8) + readValLow;

    return readVal;
}

void Timer0_Write(size_t timerVal)
{
    TMR0H = timerVal >> 8;
    TMR0L = (uint8_t) timerVal;
}

void Timer0_Reload(void)
{
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;
}

void Timer0_PeriodCountSet(size_t periodVal)
{
   timerTMR0ReloadVal16bit = (uint16_t) periodVal;
}

void __interrupt(irq(TMR0),base(8)) Timer0_OverflowISR()
{
    //Clear the TMR0 interrupt flag
    PIR3bits.TMR0IF = 0;
    //Write to the TimerTMR0 register
    TMR0H = timerTMR0ReloadVal16bit >> 8;
    TMR0L = (uint8_t) timerTMR0ReloadVal16bit;

    if(Timer0_OverflowCallback)
    {
        Timer0_OverflowCallback();
    }
}

void Timer0_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer0_OverflowCallback = CallbackHandler;
}

static void Timer0_DefaultOverflowCallback(void)
{
    //Add your interrupt code here or
    //Use Timer0_OverflowCallbackRegister function to use Custom ISR
}

