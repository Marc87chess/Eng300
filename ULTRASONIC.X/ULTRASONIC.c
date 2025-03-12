/// DISTANCE CENSORT CODE
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define CLKSCALE 4
uint16_t value[5] = {0};
uint8_t count = 0;
uint8_t duty = 250;
void ultra_trig(void);

void ultra_trig(void){
   
    PORTA.OUT |= 0b00000001;
    _delay_us(35);
    PORTA.OUT &= 0b11111110;
    
    
}

int main(void) {
     //CCP = 0xd8;
     //CLKCTRL.OSCHFCTRLA = 0b00011100;
     PORTA.DIRSET |= 0b00001101;
     PORTA.DIRSET &= 0b11111101;
     EVSYS.CHANNEL0 = 0x41;
     EVSYS.USERTCB2CAPT = 0x01;//PA1 0x02 would be PA2
     TCB2.INTCTRL = 0x01; // CAPTURE INPUT ENABLE
     TCB2.EVCTRL = 0x01; // ENABLE CAPTURE INPUT EVENT ASWELL?
     TCB2.CTRLB = 0x04;// pulse width mode 0x03 for frequncy
     TCB2.CTRLA = 0x01;// ENABLE THE  TCB TIMER AS A WHOLE
     sei();
     double dist = 0;
    while (1) {
        
       ultra_trig();
       
       _delay_us(2000);
       dist =  (((value[0]*(1/CLKSCALE))*0.0343)/2); //cm
       if (value[0] >= 2000){
            PORTA.OUT |= 0b00000100;
            
       }
       if (dist >= 8.75){
            PORTA.OUT |= 0b0001000;
            
       }
       else PORTA.OUT &= 0b11110011;
    }
}
ISR(TCB2_INT_vect){
    TCB2.INTFLAGS = 0x01;
    value[count]= TCB2.CCMP;
    //count ++;
    
    
}