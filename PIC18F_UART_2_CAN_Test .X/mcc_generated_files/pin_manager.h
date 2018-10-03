/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F26K83
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_0 aliases
#define LED_0_TRIS                 TRISAbits.TRISA0
#define LED_0_LAT                  LATAbits.LATA0
#define LED_0_PORT                 PORTAbits.RA0
#define LED_0_WPU                  WPUAbits.WPUA0
#define LED_0_OD                   ODCONAbits.ODCA0
#define LED_0_ANS                  ANSELAbits.ANSELA0
#define LED_0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_0_GetValue()           PORTAbits.RA0
#define LED_0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LED_0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LED_0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LED_0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISAbits.TRISA1
#define LED_1_LAT                  LATAbits.LATA1
#define LED_1_PORT                 PORTAbits.RA1
#define LED_1_WPU                  WPUAbits.WPUA1
#define LED_1_OD                   ODCONAbits.ODCA1
#define LED_1_ANS                  ANSELAbits.ANSELA1
#define LED_1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_1_GetValue()           PORTAbits.RA1
#define LED_1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define LED_1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set BTN_0 aliases
#define BTN_0_TRIS                 TRISAbits.TRISA4
#define BTN_0_LAT                  LATAbits.LATA4
#define BTN_0_PORT                 PORTAbits.RA4
#define BTN_0_WPU                  WPUAbits.WPUA4
#define BTN_0_OD                   ODCONAbits.ODCA4
#define BTN_0_ANS                  ANSELAbits.ANSELA4
#define BTN_0_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define BTN_0_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define BTN_0_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define BTN_0_GetValue()           PORTAbits.RA4
#define BTN_0_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define BTN_0_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define BTN_0_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define BTN_0_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define BTN_0_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define BTN_0_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define BTN_0_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define BTN_0_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set BTN_1 aliases
#define BTN_1_TRIS                 TRISAbits.TRISA5
#define BTN_1_LAT                  LATAbits.LATA5
#define BTN_1_PORT                 PORTAbits.RA5
#define BTN_1_WPU                  WPUAbits.WPUA5
#define BTN_1_OD                   ODCONAbits.ODCA5
#define BTN_1_ANS                  ANSELAbits.ANSELA5
#define BTN_1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define BTN_1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define BTN_1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define BTN_1_GetValue()           PORTAbits.RA5
#define BTN_1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define BTN_1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define BTN_1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define BTN_1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define BTN_1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define BTN_1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define BTN_1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define BTN_1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/