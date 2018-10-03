/**
  UART2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    uart2.c

  @Summary
    This is the generated driver implementation file for the UART2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for UART2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K83
        Driver Version    :  2.30
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/
#include <xc.h>
#include "uart2.h"


/**
  Section: UART2 APIs
*/

void UART2_Initialize(void)
{
    // Disable interrupts before changing states

    // Set the UART2 module to the options selected in the user interface.

    // P1L 0; 
    U2P1L = 0x00;

    // P1H 0; 
    U2P1H = 0x00;

    // P2L 0; 
    U2P2L = 0x00;

    // P2H 0; 
    U2P2H = 0x00;

    // P3L 0; 
    U2P3L = 0x00;

    // P3H 0; 
    U2P3H = 0x00;

    // BRGS high speed; MODE Asynchronous 8-bit mode; RXEN enabled; TXEN enabled; ABDEN disabled; 
    U2CON0 = 0xB0;

    // RXBIMD Set RXBKIF on rising RX input; BRKOVR disabled; WUE disabled; SENDB disabled; ON enabled; 
    U2CON1 = 0x80;

    // TXPOL not inverted; FLO off; C0EN Checksum Mode 0; RXPOL not inverted; RUNOVF RX input shifter stops all activity; STP Transmit 1Stop bit, receiver verifies first Stop bit; 
    U2CON2 = 0x00;

    // BRGL 64; 
    U2BRGL = 0x40;

    // BRGH 3; 
    U2BRGH = 0x03;

    // STPMD in middle of first Stop bit; TXWRE No error; 
    U2FIFO = 0x00;

    // ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; ABDIE disabled; 
    U2UIR = 0x00;

    // ABDOVF Not overflowed; TXCIF 0; RXBKIF No Break detected; RXFOIF not overflowed; CERIF No Checksum error; 
    U2ERRIR = 0x00;

    // TXCIE disabled; FERIE disabled; TXMTIE disabled; ABDOVE disabled; CERIE disabled; RXFOIE disabled; PERIE disabled; RXBKIE disabled; 
    U2ERRIE = 0x00;


}

bool UART2_is_rx_ready(void)
{
	return (PIR7bits.U2RXIF);
}

bool UART2_is_tx_ready(void)
{
    return (bool)(PIR7bits.U2TXIF && U2CON0bits.TXEN);
}

bool UART2_is_tx_done(void)
{
    return U2ERRIRbits.TXMTIF;
}

uint8_t UART2_Read(void)
{
    while(!PIR7bits.U2RXIF)
    {
    }

    if(1 == U2ERRIRbits.FERIF)
    {
        // UART2 error - restart

        U2CON1bits.ON = 0; 
        U2CON1bits.ON = 1; 
    }

    return U2RXB;
}

void UART2_Write(uint8_t txData)
{
    while(0 == PIR7bits.U2TXIF)
    {
    }

    U2TXB = txData;    // Write the data byte to the USART.
}

char getch(void)
{
    return UART2_Read();
}

void putch(char txData)
{
    UART2_Write(txData);
}










/**
  End of File
*/
