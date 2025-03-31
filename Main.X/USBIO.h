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
#define ASCIICON 48
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

int DAC_init(void);


uint16_t ADC_read();

void DAC0_setVal(uint16_t value);


int receive_until_null(char * buffer);

uint16_t ADC_readpos(uint8_t pos);
int16_t USART_Receive_Timeout(uint16_t timeout);
void USART_Init(uint16_t baud);

void USART_Transmit(uint16_t data);

uint16_t USART_Receive(void);


