
#include "mcc_generated_files/mcc.h"
#include <string.h>

/******************************************************************************/

// LED_0, LED_1, BTN_0, BTN_1 defined in MPLAB MCC
#define ID_REQUEST_ID_ADDR 0x123 // Standard: 0x0-0x7FF; Extended: 0x800-0xFFF

/******************************************************************************/

/* Functions Prototypes */

bool uart_command_received(char* command_read);
void led_init(uint8_t led_num);
void led_off(uint8_t led_num);
void led_on(uint8_t led_num);
void led_toggle(uint8_t led_num);
void btn_init(uint8_t btn_num);
uint8_t btn_read(uint8_t btn_num);

/******************************************************************************/

void APP_Initialize()
{
    // Initialize LEDs and Buttons pins
    led_init(0);
    led_init(1);
    btn_init(0);
    btn_init(1);
    
    //__nop();
}

void main(void)
{
    // Declare UART data received
    char uart_data_rx[15];
    memset(uart_data_rx, '\0', 15);
    
    // Declare CAN TX/RX packages variables
    uCAN_MSG can_msg_tx;
    uCAN_MSG can_msg_rx;
    
    // Initialize the device
    SYSTEM_Initialize();
    APP_Initialize();
    
    // Enable/Disable global interrupts
    //INTERRUPT_GlobalInterruptEnable();      // Enable global INTS.
    //INTERRUPT_GlobalInterruptDisable();     // Disable global INTS.
    //INTERRUPT_GlobalInterruptHighEnable();  // Enable high priority INTS.
    //INTERRUPT_GlobalInterruptHighDisable(); // Disable high priority INTS.
    //INTERRUPT_GlobalInterruptLowEnable();   // Enable low priority INTS.
    //INTERRUPT_GlobalInterruptLowDisable();  // Disable low priority INTS.
    
    // Enable/Disable peripheral interrupts
    //INTERRUPT_PeripheralInterruptEnable();  // Enable peripherals INTS.
    //INTERRUPT_PeripheralInterruptDisable(); // Disable peripherals INTS.
    
    // Device header
    printf("\n\n");
    printf(" UART to CAN test\n");
    printf("------------------\n");
    printf("Send 14 bytes corresponding to CAN msg frame that going to be " \
           "sent to the CAN bus.\n");
    
    while(1)
    {
        // If a command has been received from the UART Command-Line-Interface
        if(uart_command_received(uart_data_rx))
        {
            printf("\nSending CAN Frame: \"%s\"\n", uart_data_rx);
            
            // Add data to CAN package
            memcpy(can_msg_tx.array, uart_data_rx, 14);
            
            // Try to send the CAN message
            if(CAN_transmit(&can_msg_tx))
            {
                // The CAN MSG was successfully enqueued in the TX buffer
                printf("CAN message successfully sent.\n");
                led_toggle(0);
            }
            else
                printf("CAN message cannot be sent (full Tx Buffer/s).\n");
            
            // Clear UART data received
            memset(uart_data_rx, '\0', 15);
        }
        
        // Check if there is any CAN message received from the bus
        if(CAN_receive(&can_msg_rx))
        {
            printf("\nCAN message received.\n");
            printf("CAN message received of type: %d\n", 
                   can_msg_rx.frame.idType);
            led_toggle(1);
            
            // Check if the CAN message is of expected type (CAN-2.0B)
            if (can_msg_rx.frame.idType == dSTANDARD_CAN_MSG_ID_2_0B)
            {
                printf("CAN message received standard.\n");
                printf("CAN message received frame: %s", can_msg_rx);
                
                // Check if the CAN message is a REQUEST_DEVICE_ID type
                /*if(can_msg_rx.frame.id == ID_REQUEST_ID_ADDR)
                {
                    printf("Received expected CAN message: Request device " \
                           "address.");
                    
                     // Get received MSG data
                     uint8_t a = can_msg_rx.frame.data0;
                     uint8_t b = can_msg_rx.frame.data1;
                }*/
            }
            else
            {
                printf("CAN message received extended.\n");
                printf("CAN message received frame: %s\n", can_msg_rx);
            }
         }
    }
}

/******************************************************************************/

/* Serial Command-Line-Interface manage commands reception function */

bool uart_command_received(char* command_read)
{
    static uint8_t uart_read_byte = 0;
    char uart_char;
    
    // If there is something in the UART RX buffer waiting to be read
    if(UART2_is_rx_ready())
    {
        // Read the character
        uart_char = UART2_Read();

        if(uart_read_byte < 15)
        {
            // If the character received is an EOL, assume end of command
            if(uart_char == '\n')
            {
                // Fill all next frame bytes to '0'
                for(uint8_t i = uart_read_byte; i < 14; i++)
                    command_read[uart_read_byte] = '0';
                command_read[14] = '\0';
                
                uart_read_byte = 0;
                return true;
            }
            else
            {
                command_read[uart_read_byte] = uart_char;
                uart_read_byte = uart_read_byte + 1;
            }
        }
        else
        {
            command_read[14] = '\0';
            
            uart_read_byte = 0;
            return true;
        }
    }
    
    return false;
}

/******************************************************************************/

/* LEDS & BUTTONS HAL Functions */

void led_init(uint8_t led_num)
{
    if(led_num == 0)
    {
        LED_0_SetDigitalOutput();
        LED_0_SetHigh();
    }
    else if(led_num == 1)
    {
        LED_1_SetDigitalOutput();
        LED_1_SetHigh();
    }
}

void led_off(uint8_t led_num)
{
    if(led_num == 0)
        LED_0_SetHigh();
    else if (led_num == 1)
        LED_1_SetHigh();
}

void led_on(uint8_t led_num)
{
    if(led_num == 0)
        LED_0_SetLow();
    else if (led_num == 1)
        LED_1_SetLow();
}

void led_toggle(uint8_t led_num)
{
    if(led_num == 0)
        LED_0_Toggle();
    else if (led_num == 1)
        LED_1_Toggle();
}

void btn_init(uint8_t btn_num)
{
    if(btn_num == 0)
    {
        BTN_0_SetDigitalInput();
        BTN_0_SetPullup();
    }
    else if (btn_num == 1)
    {
        BTN_1_SetDigitalInput();
        BTN_1_SetPullup();
    }
}

uint8_t btn_read(uint8_t btn_num)
{
    uint8_t status;
    
    if(btn_num == 0)
        status = BTN_0_GetValue();
    else if (btn_num == 1)
        status = BTN_1_GetValue();
    
    return status;
}
