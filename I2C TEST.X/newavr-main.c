#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>
#define SSD1306_ADDRESS 0x3C  // OLED default I2C address
#define F_CPU 16000000UL
// Function to initialize I2C (TWI)
void I2C_Init(void) {
    TWI0.MBAUD = (uint8_t)(((F_CPU / (2 * 100000UL)) - 10));  // Correct baud rate
    TWI0.MCTRLA = TWI_ENABLE_bm | TWI_SMEN_bm;  // Enable I2C master mode and smart mode
    TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;  // Set bus to idle
}


void I2C_Start(uint8_t address) {
    TWI0.MADDR = (address << 1);  // Send address with write bit
    while (!(TWI0.MSTATUS & (TWI_WIF_bm | TWI_RXACK_bm)));  // Wait for completion
    if (TWI0.MSTATUS & TWI_RXACK_bm) {  // Check for ACK
        TWI0.MCTRLB = TWI_MCMD_STOP_gc;
    }
}

void I2C_Write(uint8_t data) {
    TWI0.MDATA = data;
    while (!(TWI0.MSTATUS & (TWI_WIF_bm | TWI_RXACK_bm)));  // Wait for completion
    if (TWI0.MSTATUS & TWI_RXACK_bm) {  // Check for ACK
        TWI0.MCTRLB = TWI_MCMD_STOP_gc;
    }
}
// Stop I2C communication
void I2C_Stop(void) {
    TWI0.MCTRLB = TWI_MCMD_STOP_gc;
}
void SSD1306_Init(void) {
    
    I2C_Start(SSD1306_ADDRESS);

    I2C_Write(0x00);  // Command mode
    I2C_Write(0xAE);  // Display OFF
    I2C_Write(0xA8);  // Set Multiplex Ratio
    I2C_Write(0x1F);  // Multiplex for 128x32 display
    I2C_Write(0xD3);  // Set Display Offset
    I2C_Write(0x00);  // No offset
    I2C_Write(0x40);  // Set start line to 0
    I2C_Write(0xA1);  // Set segment re-map to normal
    I2C_Write(0xC8);  // Set COM scan direction to remapped
    I2C_Write(0xDA);  // Set COM pins hardware configuration
    I2C_Write(0x02);  // Alternative COM pin config
    I2C_Write(0x81);  // Set contrast
    I2C_Write(0x7F);  // 128 contrast
    I2C_Write(0xA4);  // Enable display GDDRAM
    I2C_Write(0xA6);  // Set normal display (not inverted)
    I2C_Write(0xD5);  // Set clock divide ratio
    I2C_Write(0x80);  // Default clock divide ratio
    I2C_Write(0x8D);  // Enable charge pump regulator
    I2C_Write(0x14);  // Enable charge pump
    I2C_Write(0xAF);  // Turn display ON

    I2C_Stop();
}
void SSD1306_FillScreen(void) {
    I2C_Start(SSD1306_ADDRESS);
    I2C_Write(0x00);  // Command mode
    I2C_Write(0x21);  // Set column address
    I2C_Write(0x00);
    I2C_Write(0x7F);
    I2C_Write(0x22);  // Set page address
    I2C_Write(0x00);
    I2C_Write(0x03);
    I2C_Stop();

    for (uint16_t i = 0; i < 512; i++) {
        I2C_Start(SSD1306_ADDRESS);
        I2C_Write(0x40);  // Data mode
        I2C_Write(0xFF);  // Fill with white pixels
        I2C_Stop();
    }
}


int main(void) {
    PORTC.PIN0CTRL = PORT_PULLUPEN_bm;  // Enable pull-up on SDA (PC0)
    PORTC.PIN1CTRL = PORT_PULLUPEN_bm;
    I2C_Init();
    SSD1306_Init();
    _delay_ms(100);
    SSD1306_FillScreen();

   
    while (1) {
        // Your code here
    }
    return 0;
}
