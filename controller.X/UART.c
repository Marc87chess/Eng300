/*
 * File:   UART.c
 * Author: i-no-like-crappy-os
 *
 * Created on March 29, 2025, 12:13 AM
 */

#include "UART.h"
#include <xc.h>

#define F_CPU 16000000UL  // Set system clock speed
int adc_init(uint8_t pos){
    VREF.ADC0REF = 0x05;
    ADC0.CTRLA = 0b10000001;
    ADC0.CTRLB = 0b00000000;
    ADC0.CTRLC = 0b00000111;
    
    return 0;
}
uint16_t ADC_read() {
    // Start ADC conversion
    ADC0.COMMAND = ADC_STCONV_bm;

    // Wait for conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));

    // Clear the interrupt flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;

    // Return the result
    return ADC0.RES;
}
uint16_t ADC_readpos(uint8_t pos) {
    // Start ADC conversion
    ADC0.MUXPOS = pos;
    ADC0.COMMAND = ADC_STCONV_bm;

    // Wait for conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));

    // Clear the interrupt flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;

    // Return the result
    return ADC0.RES;
}
void USART_Init(uint16_t baud) {
    // Set baud rate
    //USART1.BAUD = 0000010011100010;
    USART1.BAUD = 6666;
    // Set frame format: 8-bit, no parity, 1 stop bit (8N1)
    USART1.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;
    
    // Set TXD (PC0 and PC1) as output
    PORTC.DIRSET = PIN0_bm;
    PORTC.DIRCLR = PIN1_bm;  
    
    // Enable transmitter and receiver
    USART1.CTRLB = USART_TXEN_bm | USART_RXEN_bm;
}

// Function to send a byte
void USART_Transmit(uint16_t data) {
    while (!(USART1.STATUS & USART_DREIF_bm));  // Wait until buffer is empty
    USART1.TXDATAL = data;  // Send data
}

// Function to receive a byte
uint16_t USART_Receive(void) {
    while (!(USART1.STATUS & USART_RXCIF_bm));  // Wait for data
    return USART1.RXDATAL;  // Return received byte
}
int16_t USART_Receive_Timeout(uint16_t timeout) {
    while (!(USART1.STATUS & USART_RXCIF_bm)) {
        if (timeout-- == 0) return -1;  // Timeout reached
    }
    return USART1.RXDATAL;
}
int receive_until_null(char * buffer) {
    char received_char;
      // Array to store received characters
    uint8_t index = 0;  // Index to keep track of the current position in the buffer

    while (1) {
        received_char = USART_Receive_Timeout(10000);  // Read a byte
         if (received_char == -1) {
            return -1;  // Exit the loop when NULL (end of string) is encountered
        }
        if (received_char == 0) {
            return 0;  // Exit the loop when NULL (end of string) is encountered
        }

        // Append received character to buffer
        if (index < MAX_BUFFER_SIZE - 1) {  // Make sure we don't overflow the buffer
            buffer[index++] = received_char;
        } else {
            // Buffer overflow handling (if necessary)
            // Optionally, you could print an error or handle it differently
            break;
        }
    }

   
    buffer[index] = '\0';

  
}
