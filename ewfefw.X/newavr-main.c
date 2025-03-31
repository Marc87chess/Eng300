//#define PART1
//#define PART2
#define PART3
#define PART4
#ifdef PART1
/*
 * File:   square-wave.c
 * Author: gmessier
 *
 * Created on November 21, 2021, 9:08 AM
 */


#include <avr/io.h>

int main(void) {
    
    // The oscillator config registers are protected.  Writing this to
    // CCP allows us to change them.
    CCP = 0xd8;
    
    // Set the internal oscillator frequency.
    CLKCTRL.OSCHFCTRLA = 0b00000000;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }

    // Configure our output pin.
    PORTA.DIRSET = 0b00010000;

    // Generate a "square wave" on our output pin.
    while (1) {
        PORTA.OUT &= 0b11101111;
        PORTA.OUT |= 0b00010000;
    }
    
}
#endif
#ifdef PART2
/*
 * File:   variable-square-wave.c
 * Author: gmessier
 *
 * Created on February 13, 2023, 9:10 AM
 */


#include <avr/io.h>

int main(void) {
  

    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    
    TCA0.SINGLE.CTRLA = 0b000000001;
    
    // We will manually check the timer and reset the timer
    // so set the period to its max value to avoid an automatic
    // reset.
    TCA0.SINGLE.PER = 0xffff;

    unsigned int timerThreshold = 1000;

    PORTA.DIRSET = 0b00010000;

    while (1) {

        PORTA.OUT &= 0b11101111;
        
        while( TCA0.SINGLE.CNT <= timerThreshold) ;        
        TCA0.SINGLE.CNT = 0;

        PORTA.OUT |= 0b00010000;
        
        while( TCA0.SINGLE.CNT <= timerThreshold) ;        
        TCA0.SINGLE.CNT = 0;
        
        
    }
    
}
#endif 
#ifdef PART3
/*
 * File:   variable-square-wave.c
 * Author: gmessier
 *
 * Created on February 13, 2023, 9:10 AM
 */


#include <avr/io.h>

int main(void) {
  
    int count =0;
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00010100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
   

    unsigned int timerThresholdhigh = 750;// 1000 would be 2ms pulse with current config so 750 is 1.5ms 
    unsigned int timerThresholdlow = 19250; // Period has to be 20ms  so 19250 + 750 = 20000 
    PORTA.DIRSET = 0b00010000;

    while (1) {

        PORTA.OUT &= 0b11101111;
        TCA0.SINGLE.CNT = 0; // resets count
        while( TCA0.SINGLE.CNT <= timerThresholdlow);// hold low until TCA has counted to the threshold low   
        

        PORTA.OUT |= 0b00010000;
        
        while( TCA0.SINGLE.CNT <= timerThresholdhigh) ;   //  hold high until TCA has counted to the threshold high
        TCA0.SINGLE.CNT = 0;
        
        if (count >= 50){ // this count just gives the servo time to move before changing the duty cycle
           // following if logic just makes the duty cycle go from 1.5ms to 2ms which gave us the needed 90 deg of rotation.
            count =0;
            if (timerThresholdlow == 750){ 
                timerThresholdlow = 1250;
                timerThresholdhigh = 18750;
            }
            else{
                timerThresholdlow = 750;
                timerThresholdhigh = 19250;
            }
        }
        count++;
        
    }
    
}
#endif 
#ifdef PART4

/*
 * File:   sawtooh-wave.c
 * Author: Marc
 *
 * Created on March 4, 2025, 3:03 PM
 */


#include <avr/io.h>
#include <util/delay.h>

int wave[] = { 
    0, 13, 26, 39, 52, 66, 79, 92, 105, 118, 
    132, 145, 158, 171, 184, 198, 211, 224, 237, 255 
};// Because we are only writing the DATAH we only get 8 bits so (2^8)-1 is the max we can output to so 255

int main(void) {

    // -- Clock Configuration --
    
    // Set internal clock frequency to 16 MHz.
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }

    // -- DAC Configuration --
    
    // Set PD6 to be the DAC output and enable the DAC.
    DAC0.CTRLA = 0b01000001;
    
    // Configure to use VDD as the reference level.
    VREF.DAC0REF = 0b10000101;
    TCA0.SINGLE.CTRLA = 0b00000001; // no clock division 
    TCA0.SINGLE.PER = 0xffff;
    
    TCA0.SINGLE.CNT = 0;
    unsigned int timerThreshold = 4800;// calculated value for 6ms wave
    
    int n = 0;
    while (1) {
        
        DAC0.DATAH = wave[n];// outputs the sample voltage and holds it until n is incremented
        if (TCA0.SINGLE.CNT >timerThreshold){
            n ++;
            if (n>=20) n=0;// restarts the count after the desired number of samples
            TCA0.SINGLE.CNT = 0; // resets TCA count
        }
       
  
    }
}
#endif