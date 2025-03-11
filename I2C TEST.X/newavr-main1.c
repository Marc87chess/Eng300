#include <avr/io.h>
#include <util/delay.h>
void I2C_init(void) {
    
    PORTA.DIRCLR = PIN2_bm | PIN3_bm; // Set SDA & SCL as inputs
    PORTA.PIN2CTRL = PORT_PULLUPEN_bm; // Enable pull-up on SDA
    PORTA.PIN3CTRL = PORT_PULLUPEN_bm; // Enable pull-up on SCL

    TWI0.MBAUD = (F_CPU / (2 * 100000)) - 10;  // Set baud rate for 100kHz
    TWI0.MCTRLA = TWI_ENABLE_bm;   // Enable I2C master mode
    TWI0.MSTATUS = TWI_BUSSTATE_IDLE_gc;  // Set bus to idle
}
void I2C_write(uint8_t address, uint8_t data) {
    TWI0.MADDR = (address << 1);  // Send address + Write bit
    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for Write Interrupt Flag
    TWI0.MDATA = data;  // Send data
    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for completion
    TWI0.MCTRLB = TWI_MCMD_STOP_gc; // Send STOP condition
}
void I2C_test_signal(void) {
    
    // Send a start condition and a dummy address
    TWI0.MADDR = (0x50 << 1);  // Send address (0x50 is just a test value)

    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for transmission

    TWI0.MDATA = 0xAA;  // Send test data
    while (!(TWI0.MSTATUS & TWI_WIF_bm)); // Wait for transmission

    TWI0.MCTRLB = TWI_MCMD_STOP_gc;  // Send STOP condition
}
int main(void) {
    I2C_init();
   
    while (1) {
        I2C_test_signal();
    }
}
