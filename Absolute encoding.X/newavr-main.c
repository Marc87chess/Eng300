#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#define NOP() __asm__("nop")
#define LED_PIN PIN0_bm  // Define LED pin (PA0)
#define LED_PORT PORTA   // Use PORTA
int x =0;

#define F_CPU 16000000UL  // Set the clock frequency to 16 MHz
int main(void) {
    int x =0;
    LED_PORT.DIRSET = LED_PIN;  // Set PA0 as output
    CLKCTRL.MCLKCTRLA = (1 << CLKCTRL_CLKSEL_gp); // Set the clock source to the internal 16 MHz oscillator
    // Wait for the oscillator to stabilize
    //while (!(CLKCTRL.MCLKSTATUS & CLKCTRL_OSC16MS_bm));
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b10011000;  // Set FRQSEL to 16MHz (0x7)
    /*while(1){
   for (int i = 7; i >= 0; i--) {
        uint8_t bit  = ((0b11111111>> i) & 1);
        
        if (bit) {
        // Send '1': 800ns HIGH, 450ns LOW
        PORTA.OUTSET = (1 << 0);  // PA0 HIGH

        __asm__ __volatile__("nop\n\tnop\n\tnop\n\tnop\n\tnop"); 
        PORTA.OUTCLR = (1 << 0);
       __asm__ __volatile__("nop\n\tnop\n\tnop"); 
    } else {
        // Send '0': 400ns HIGH, 850ns LOW
        LED_PORT.OUTSET = LED_PIN;
        NOP(); NOP(); NOP(); NOP();    
        LED_PORT.OUTCLR = LED_PIN;
        NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP();
    }
      
    }
     for (int i = 7; i >= 0; i--) {
        uint8_t bit  = ((0b00000000>> i) & 1);
        if (bit) {
        // Send '1': 800ns HIGH, 450ns LOW
        LED_PORT.OUTSET = LED_PIN;
        __asm__ __volatile__("nop\n\tnop\n\tnop\n\tnop\n\tnop"); 
        LED_PORT.OUTCLR = LED_PIN;
       __asm__ __volatile__("nop\n\tnop\n\tnop"); 
    } else {
        // Send '0': 400ns HIGH, 850ns LOW
        LED_PORT.OUTSET = LED_PIN;
        NOP(); NOP(); NOP(); NOP();    
        LED_PORT.OUTCLR = LED_PIN;
        NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP(); NOP();
    }
    }
    
     for (int i = 7; i >= 0; i--) {
        uint8_t bit  = ((0b00000000>>i & 1));
        if (bit) {
        // Send '1': 800ns HIGH, 450ns LOW
        LED_PORT.OUTSET = LED_PIN;
        _delay_us(2.7);
        LED_PORT.OUTCLR = LED_PIN;
        _delay_us(0.1);
    } else {
        // Send '0': 400ns HIGH, 850ns LOW
        LED_PORT.OUTSET = LED_PIN;
        _delay_us(0.1);
        LED_PORT.OUTCLR = LED_PIN;
        _delay_us(0.1);
    }
    }

    _delay_us(208);
    }*/
    while(1){
        _delay_us(208);
       
        
        /*PORTA.OUTSET = (1 << 0);// bit 1 // 1
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);*/
        //--------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
         
        
        
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        //---------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        //------
       /* PORTA.OUTSET = (1 << 0);// bit 1 // 1
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        //--------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        //---------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
          
        PORTA.OUTSET = (1 << 0);// bit 1 // 1
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        //--------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        //---------------
                
        PORTA.OUTSET = (1 << 0);// 1
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 2
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
                 
        PORTA.OUTSET = (1 << 0);// 3
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 4
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
         PORTA.OUTSET = (1 << 0);// 5
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 6
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
                 
        PORTA.OUTSET = (1 << 0);// 7
        PORTA.OUTSET = (1 << 0); 
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        
        PORTA.OUTSET = (1 << 0);// 8
        PORTA.OUTSET = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);
        PORTA.OUTCLR = (1 << 0);*/
        
    }
}
