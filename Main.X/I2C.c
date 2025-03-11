#define F_CPU 16000000UL  

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



#define DISPLAY_ADDR 0x3c

void TWIinit(void){
    // -- Initialization --

  // Set internal clock frequency, fClk = 16e6 (Hz)
 
  
 
  TWI0.MBAUD = 67;
          
  // Enable TWI main.
  TWI0.MCTRLA |= 0x01;
  
  // Force bus state machine to idle.
  TWI0.MSTATUS = 0x01;
}
void sendCommand(uint8_t address, uint8_t data) {

  // Set secondary device address and trigger the bus start condition.
  TWI0.MADDR = address << 1;
    
  // Wait until the address has been transmitted out of the data register.
  while( !(TWI0.MSTATUS & 0b01000000) ){
    ;
  }
  
  // Write the data byte.
  TWI0.MDATA = data;
    
  // Wait until the address has been transmitted out of the data register.
  while( !(TWI0.MSTATUS & 0b01000000) ){
    ;
  }
  
  // Send stop condition
  TWI0.MCTRLB = 0x03;
  
  /*
   * Really not sure why I need this delay.  Without it, the display behaves
   * randomly, sometimes working sometimes not.  That *usually* means something
   * is being driven too fast but the data sheets say I'm easily within timing
   * requirements.  Possibly there's a more efficient way to write to the LCD
   * RAM that isn't as fussy but I couldn't find it. 
   */
  _delay_ms(1);
}
void initSSD1306() {
    sendCommand(0xAE); // Display OFF

    sendCommand(0xD5); // Set display clock divide ratio/oscillator frequency
    sendCommand(0x80); // Suggested value

    sendCommand(0xA8); // Set multiplex ratio
    sendCommand(0x3F); // 0x3F = 64 rows (for 128x64)

    sendCommand(0xD3); // Set display offset
    sendCommand(0x00); // No offset

    sendCommand(0x40); // Set start line at 0

    sendCommand(0x8D); // Enable charge pump regulator
    sendCommand(0x14); // Enable charge pump

    sendCommand(0x20); // Set memory addressing mode
    sendCommand(0x00); // Horizontal addressing mode

    sendCommand(0xA1); // Set segment re-map to normal (flip horizontally if needed)

    sendCommand(0xC8); // Set COM output scan direction (flip vertically if needed)

    sendCommand(0xDA); // Set COM pins hardware configuration
    sendCommand(0x12); // Alternative COM pins configuration, disable left/right remap

    sendCommand(0x81); // Set contrast control
    sendCommand(0xCF); // Contrast value (0x00 to 0xFF)

    sendCommand(0xD9); // Set pre-charge period
    sendCommand(0xF1); // Phase 1 = 15 DCLKs, Phase 2 = 1 DCLK

    sendCommand(0xDB); // Set VCOMH deselect level
    sendCommand(0x40); // 0.77 x Vcc

    sendCommand(0xA4); // Entire display ON (resume from RAM content)

    sendCommand(0xA6); // Normal display (0xA7 = Inverted display)

    sendCommand(0xAF); // Display ON
}
const uint8_t font5x8[][5] = {
    {0x3E, 0x51, 0x49, 0x45, 0x3E},  // '0'
    {0x00, 0x42, 0x7F, 0x40, 0x00},  // '1'
    {0x62, 0x51, 0x49, 0x49, 0x46},  // '2'
    {0x22, 0x49, 0x49, 0x49, 0x36},  // '3'
    {0x18, 0x14, 0x12, 0x7F, 0x10},  // '4'
    {0x27, 0x45, 0x45, 0x45, 0x39},  // '5'
    {0x3C, 0x4A, 0x49, 0x49, 0x31},  // '6'
    {0x01, 0x71, 0x09, 0x05, 0x03},  // '7'
    {0x36, 0x49, 0x49, 0x49, 0x36},  // '8'
    {0x46, 0x49, 0x49, 0x29, 0x1E}   // '9'
};



int main(void) {
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
      
    }
    TWIinit();
    initSSD1306();
    
    while (1) {
    }
}
