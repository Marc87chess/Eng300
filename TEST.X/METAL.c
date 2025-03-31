/// DISTANCE CENSORT CODE
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
uint16_t metal = 0; 
#define THRES 2000



int main(void) {
     //CCP = 0xd8;
     //CLKCTRL.OSCHFCTRLA = 0b00011100;
     PORTA.DIRSET |= 0b10000000;
     PORTA.DIRSET &= 0b10000000;
    
     EVSYS.CHANNEL0 = 0x41;
     EVSYS.USERTCB2CAPT = 0x01;//PA1 IS THE INPUT
     TCB2.INTCTRL = 0x01; // CAPTURE INPUT ENABLE
     TCB2.EVCTRL = 0x01; // ENABLE CAPTURE INPUT EVENT ASWELL?
     TCB2.CTRLB = 0x04;// pulse width mode 0x03 for frequncy
     TCB2.CTRLA = 0x01;// ENABLE THE  TCB TIMER AS A WHOLE
     sei();
    
    while (1) {
        
      
       if (metal < THRES){
            PORTA.OUT |= 0b10000000; // PA7 GOES HIGH IF THERE IS METAL
            
       }
       else PORTA.OUT &= 0b01111111;
    
       
    }
}
ISR(TCB2_INT_vect){
    TCB2.INTFLAGS = 0x01;
    metal = TCB2.CCMP;// NOT TAKING THE AVERAGE RIGHT NOW
    //count ++;
    
    
}
