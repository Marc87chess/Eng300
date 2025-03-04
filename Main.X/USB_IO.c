#include <util/delay.h>
#include "USBIO.h"
#include <avr/io.h>

int adc_init(uint8_t pos){
    VREF.ADC0REF = 0x05;
    ADC0.CTRLA = 0b10000001;
    ADC0.CTRLB = 0b00000000;
    ADC0.CTRLC = 0b00000111;
    ADC0.MUXPOS = pos;
    return 0;
}

int DAC_init(void){ // soon will add non hard coded port
    VREF.DAC0REF = 0x05;
   
    PORTD.PIN6CTRL &= ~PORT_ISC_gm;
    PORTD.PIN6CTRL |= PORT_ISC_INPUT_DISABLE_gc;
    /* Disable pull-up resistor */
    PORTD.PIN6CTRL &= ~PORT_PULLUPEN_bm;
    DAC0.CTRLA = DAC_ENABLE_bm          /* Enable DAC */
                 | DAC_OUTEN_bm           /* Enable output buffer */
                 | DAC_RUNSTDBY_bm;       /* Enable Run in Standby mode */
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
void DAC0_setVal(uint16_t value)
{
  /* Store the two LSbs in DAC0.DATAL */
  DAC0.DATAL = (value & 0x03) << 6;
  /* Store the eight MSbs in DAC0.DATAH */
  DAC0.DATAH = value >> 2;
}
void USART_Init(uint16_t baud) {
    // Set baud rate
    //USART1.BAUD = 0000010011100010;
    USART1.BAUD = 1700;
    // Set frame format: 8-bit, no parity, 1 stop bit (8N1)
    USART1.CTRLC = USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_CHSIZE_8BIT_gc;
    
    // Set TXD (PC0 and PC1) as output
    PORTC.DIRSET = PIN0_bm;
    PORTC.DIRCLR = PIN1_bm;  
    
    // Enable transmitter and receiver
    USART1.CTRLB = USART_TXEN_bm | USART_RXEN_bm;
}

// Function to send a byte
void USART_Transmit(uint8_t data) {
    while (!(USART1.STATUS & USART_DREIF_bm));  // Wait until buffer is empty
    USART1.TXDATAL = data;  // Send data
}

// Function to receive a byte
uint8_t USART_Receive(void) {
    while (!(USART1.STATUS & USART_RXCIF_bm));  // Wait for data
    return USART1.RXDATAL;  // Return received byte
}
void USART_ReadString(char* buffer, uint8_t maxLen) {
    uint8_t i = 0;
    while (i < (maxLen - 1)) {
        buffer[i] = USART_Receive();
        if (buffer[i] == '\n') break;
        i++;
    }
    buffer[i] = '\0';  // Null-terminate
}
