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
#define F_CPU 16000000UL
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
int adc_init(void);

int DAC_init(void);

uint16_t ADC_read();

static void DAC0_setVal(uint16_t value);

void USART_Init(uint16_t baud);


void USART_Transmit(uint8_t data);

uint8_t USART_Receive(void);
