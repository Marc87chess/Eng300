/*
 * File:   level-switch.c
 * Author: gmessier
 *
 * Created on October 31, 2021, 2:00 PM
 */


#include <avr/io.h>

int main(void) {
    int count = 0;
    // Enable PA4 as an output pin.
    PORTA.DIRSET = 0b00010000;
    
    // Enable PA3 as an output pin.
    PORTA.DIRSET = 0b00001000;
    
    // Enable PA5 as an input pin.
    PORTA.DIRCLR = 0b00100000;
        
    while (1) {
        if(PORTA.IN & 0b00100000)
            while (1) { // wait for pin to fall
                if(!(PORTA.IN & 0b00100000)){
                    count ++;
                    break 
                }
            }
        if(count == 0){
            PORTA.OUT = 0b11110111;
            PORTA.OUT = 0b11101111;
        }
        else if (count == 1){
            PORTA.OUT = 0b00010000;
            PORTA.OUT = 0b11101111;
        }
        else if (count == 2){
            PORTA.OUT = 0b11110111;
            PORTA.OUT = 0b00001000;
        }
        else if (count == 3){
            PORTA.OUT = 0b00010000;
            PORTA.OUT = 0b00001000;
        }
        else if (count == 4){
            PORTA.OUT = 0b11110111;
            PORTA.OUT = 0b11101111;
            count = 0;
        }
       
            
    }
}
