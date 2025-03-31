/* 
 * File:  USB_IO.H
 * Author: marcy marc and the funky bunch
 * Comments: have mercy
 * Revision history:V0.1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#include <util/delay.h>

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#endif 
#define F_CPU 16000000UL
#define MAX_BUFFER_SIZE 100
#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
int adc_init(uint8_t pos);
void receive_until_null(char * buffer);
int16_t USART_Receive_Timeout(uint16_t timeout);
void USART_SendString(const char* str);
void USART_SendNumber(int number);
void itoa(int num, char* str);
void split_number(int num, int *hundreds, int *tens, int *ones);
void APH(int speed);
void APS(int speed);
void APA(int speed, int head, int fast_turn);
void Headlights(int on);
uint16_t ADC_readpos(uint8_t pos);

void USART_Init(uint16_t baud);

void USART_Transmit(uint16_t data);

uint16_t USART_Receive(void);


