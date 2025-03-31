#include "LED.h"
#define LED_PIN PIN5_bm  // Use PA0

/// DISTANCE CENSORT CODE
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define CLKSCALE 4
#define F_CPU 16000000UL  


void setup() {
    PORTA.DIRSET = LED_PIN;
}



 


#define DISPLAY_ADDR 0x27

uint16_t value[5] = {0};
uint8_t count = 0;
uint8_t duty = 250;
uint16_t ultra = 0;

void ultra_trig(void);



void I2CWrite(uint8_t address, uint8_t data) {

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

/*
 * This function sends a single nibble of data to the LCD in 4 bit mode,
 * sets the RS, R/W lines and turns the display back light on/off.
 *   To follow this section, have a look at the SPLC780D data sheet sections
 *   5.2 to get an idea of some LCD commands and section 6.5.6 to see the
 *   timing requirements for the LCD lines.
 */
void LCDWrite(uint8_t nibble, uint8_t rs, uint8_t rw, uint8_t ledOn){
  
  // Prepare the 8 bits that will be sent over I2C.  The wiring diagram on
  // page 2 of the LCD1602 tutorial shows how these bits are mapped to the 
  // LCD control lines.
  uint8_t data = nibble << 4;
  data |= ledOn << 3;
  data |= rw << 1;
  data |= rs;
  
  // Set the data lines, RS and RW.
  I2CWrite(DISPLAY_ADDR,data);
  
  // Pulse E to trigger the SPLC780D to read the data nibble.
  data |= 0b00000100;
  I2CWrite(DISPLAY_ADDR,data);  
  data &= 0b11111011;
  I2CWrite(DISPLAY_ADDR,data);
  
}

void displayDigit(int digit) {
    // Check for valid digit (0-9)
    if (digit == 1) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '1'
        LCDWrite(0b0001, 1, 0, 1); // Lower nibble of '1'
    } else if (digit == 2) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '2'
        LCDWrite(0b0010, 1, 0, 1); // Lower nibble of '2'
    } else if (digit == 3) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '3'
        LCDWrite(0b0011, 1, 0, 1); // Lower nibble of '3'
    } else if (digit == 4) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '4'
        LCDWrite(0b0100, 1, 0, 1); // Lower nibble of '4'
    } else if (digit == 5) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '5'
        LCDWrite(0b0101, 1, 0, 1); // Lower nibble of '5'
    } else if (digit == 6) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '6'
        LCDWrite(0b0110, 1, 0, 1); // Lower nibble of '6'
    } else if (digit == 7) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '7'
        LCDWrite(0b0111, 1, 0, 1); // Lower nibble of '7'
    } else if (digit == 8) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '8'
        LCDWrite(0b1000, 1, 0, 1); // Lower nibble of '8'
    } else if (digit == 9) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '9'
        LCDWrite(0b1001, 1, 0, 1); // Lower nibble of '9'
    } else if (digit == 0) {
        LCDWrite(0b0011, 1, 0, 1); // Upper nibble of '0'
        LCDWrite(0b0000, 1, 0, 1); // Lower nibble of '0'
    }
}
void ultra_trig(void){
   
    PORTA.OUT |= 0b00000001;
    _delay_us(35);
    PORTA.OUT &= 0b11111110;
    
    
}


ISR(TCB1_INT_vect){
    TCB1.INTFLAGS = 0x01;
    ultra= TCB1.CCMP;// NOT TAKING THE AVERAGE RIGHT NOW
    //count ++;
    
    
}

ISR(TCB2_INT_vect){
    TCB2.INTFLAGS = 0x01;
    value[1]= TCB2.CCMP;// NOT TAKING THE AVERAGE RIGHT NOW
    count ++;
    if (count >30) count = 0;
    
    
}
int main(void) {
  
  
  // -- Initialization --

  // Set internal clock frequency, fClk = 16e6 (Hz)
  CCP = 0xd8;
  CLKCTRL.OSCHFCTRLA = 0b00011100;
  while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
      ;
  }
  //PORTA.DIRSET &= 0b00000000;// set PA2 (SDA as input) aswell as PA3(SCL)
  // From the PCF8574 data sheet:
  //   Serial Clock Freq, fSCL = 100e3 (Hz)
  //   Bus Rise Time, Tr = 1e-6 (sec)
  // From the AVR data sheet:
  //   BAUD = fClk/(fSCL*2) - (5+fCLK*Tr/2)
  //        = 67
  TWI0.MBAUD = 67;
          
  // Enable TWI main.
  TWI0.MCTRLA |= 0x01;
  
  // Force bus state machine to idle.
  TWI0.MSTATUS = 0x01;

  
  /*
   * The following init sequence comes from page 16 of the LCD1602
   * data sheet.  Basically, you can't know for sure if the LCD controller
   * will boot up in 8 or 4 bit mode.  So, these three commands are meant to
   * switch it over to 8 bit mode first.  The delays are from the data sheet
   * (with some extra buffer time added).
   */
  
  LCDWrite(0b0011,0,0,1);
  _delay_ms(5);
  LCDWrite(0b0011,0,0,1);
  _delay_ms(5);
  LCDWrite(0b0011,0,0,1);
  _delay_ms(5);
 
  /*
   * The following init sequence is from section 5.5 from the SPLC780D data
   * sheet with an extra clear screen command thrown in.  Check out the 
   * earlier sections of that same data sheet to understand each command
   * in detail.
   */
  
  // Switch from 8 bit to 4 bit mode.
  LCDWrite(0b0010,0,0,1);
    
  // Set to 4 bit operation with 1 display line. 
  LCDWrite(0b0010,0,0,1);
  LCDWrite(0b0000,0,0,1);
  
  // Display on, cursor on, cursor flash off.
  LCDWrite(0b0000,0,0,1);
  LCDWrite(0b1110,0,0,1);
  
  // Cursor increment when write on, display shift off.
  LCDWrite(0b0000,0,0,1);
  LCDWrite(0b0110,0,0,1);
  
  // clear screen
  LCDWrite(0b0000,0,0,1);
  LCDWrite(0b0001,0,0,1);
  
  
  // Write 'W'.
  LCDWrite(0b0101,1,0,1);
  LCDWrite(0b0111,1,0,1);
  
  // Main loop
 
  while (1) {
       //displayDigit(1);
       //displayDigit(2);
  }

  return 0;
}