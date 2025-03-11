#include <util/delay.h>
#include <avr/io.h>


#define F_CPU 16000000UL  // Set system clock speed

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

int main(void) {
    uint16_t baud = 103;  // Baud rate for 9600bps with 16MHz clock
    USART_Init(baud);

    while (1) {
        uint8_t received = USART_Receive();  // Receive data
        USART_Transmit(received);  // Echo received data back
    }

    return 0;
}

