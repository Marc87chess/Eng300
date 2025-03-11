/*
 * File:   newavr-main.c
 * Author: i-no-like-crappy-os
 *
 * Created on March 8, 2025, 6:59 PM
 */



/// DISTANCE CENSORT CODE
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
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
    
     PORTA.DIRSET |= 0b00000101;
     PORTA.DIRSET &= 0b11111101;
     EVSYS.CHANNEL0 = 0x41;
     EVSYS.USERTCB2CAPT = 0x01;//PA1
     TCB2.INTCTRL = 0x01;
     TCB2.EVCTRL = 0x01;
     TCB2.CTRLB = 0x04;
     TCB2.CTRLA = 0x01;
     sei();
     
    while (1) {
        
       ultra_trig();
       
       _delay_us(2000);
       
       if (value[0] >= 2000){
            PORTA.OUT |= 0b00000100;
            
       }
       else PORTA.OUT &= 0b11111011;
    }
}
ISR(TCB2_INT_vect){
    TCB2.INTFLAGS = 0x01;
    value[count]= TCB2.CCMP;
    //count ++;
    
    
}