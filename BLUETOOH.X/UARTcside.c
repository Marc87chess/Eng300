/*
 * File:   UART.c
 * Author: i-no-like-crappy-os
 *
 * Created on March 29, 2025, 12:13 AM
 */


#include <xc.h>
#include "UART.h"
#include <util/delay.h>
#include <stdlib.h>  // For itoa()
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
    _delay_us(25);
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
  // Define maximum buffer size
int16_t USART_Receive_Timeout(uint16_t timeout) {
    while (!(USART1.STATUS & USART_RXCIF_bm)) {
        if (timeout-- == 0) return -1;  // Timeout reached
    }
    return USART1.RXDATAL;
}
void receive_until_null(char * buffer) {
    char received_char;
      // Array to store received characters
    uint8_t index = 0;  // Index to keep track of the current position in the buffer

    while (1) {
        received_char = USART_Receive_Timeout(1000);  // Read a byte
        
        if (received_char == 0) {
            break;  // Exit the loop when NULL (end of string) is encountered
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

    // Null-terminate the string (optional, in case you want to work with the buffer as a C string)
    buffer[index] = '\0';

  
}
void USART_SendString(const char* str) {
    uint16_t i = 0;
    
    // Loop through the string until we hit the null terminator
    while (str[i] != '\0') {
        USART_Transmit(str[i]);  // Transmit each character
        i++;  // Move to the next character in the string
    }
}
void USART_SendNumber(int number) {
    char str[6];  // Buffer to hold the string (5 digits the pod speed or heading, val  digits + null terminator)
    
    itoa(number, str);  // Convert the number to a string 
    
    USART_SendString(str);  // Send the string over USART
}
void itoa(int num, char* str) {
    int i = 0;
    int isNegative = 0;

    // Handle 0 explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Handle negative numbers for base 10
    if (num < 0) {
        isNegative = 1;
        num = -num;  // Make the number positive
    }

    // Process each digit of the number
    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';  // Convert digit to character
        num = num / 10;
    }

    // Append negative sign for negative numbers
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';  // Null-terminate the string

    // Reverse the string (since we added digits in reverse order)
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void APS(int speed){ //APs == ALL PODS SPEED
        int h = 0;
        int t = 0;
        int o = 0;
        split_number(speed,&h,&t,&o);
        USART_Transmit(4+48); // 4 denotes all pods
        USART_Transmit(2+48); // 2 denotes speed
        USART_Transmit(h+48);  
        USART_Transmit(t+48);
        USART_Transmit(o+48);
        
        USART_Transmit(0);
}
void APH(int speed){ //APH == ALL PODS HEADING
        int h = 0;
        int t = 0;
        int o = 0;
        split_number(speed,&h,&t,&o);
        USART_Transmit(4+48); // 4 denotes all pods
        USART_Transmit(1+48); // 1 denotes speed
        USART_Transmit(h+48);  
        USART_Transmit(t+48);
        USART_Transmit(o+48);
        USART_Transmit(0);
}
void APA(int speed, int head,int fast_turn){//APA == ALL PODS ALL 
        int h = 0;
        int t = 0;
        int o = 0;
        int h2 = 0;
        int t2 = 0;
        int o2 = 0;
        split_number(speed,&h,&t,&o);
        split_number(head,&h2,&t2,&o2);
        USART_Transmit(4+48); // 4 denotes all pods
        if (fast_turn){
            USART_Transmit(4+48); //  4 denotes both and fast turn
        }else USART_Transmit(3+48); //  3 denotes both
        USART_Transmit(h+48);  
        USART_Transmit(t+48);
        USART_Transmit(o+48);// speed first
        USART_Transmit(h2+48);  
        USART_Transmit(t2+48);
        USART_Transmit(o2+48);
        
        USART_Transmit(0);
}
void Headlights(int on){
    if (on){
       USART_Transmit(5+48); 
    } else USART_Transmit(6+48);
    USART_Transmit(0);
}
void split_number(int num, int *hundreds, int *tens, int *ones) {
    *hundreds = num / 100;  // Extract hundreds place
    *tens = (num / 10) % 10;  // Extract tens place
    *ones = num % 10;  // Extract ones place
}
