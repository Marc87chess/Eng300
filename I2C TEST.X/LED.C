







#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LED.h"

#define F_CPU 16000000UL
#define LED_PORT PORTA
#define LED_PIN PIN5_bm 
#define HH 1.65
#define HL 2.7
#define LH 0.72
#define LL 11.5
void sendB(void){
         // Example: Set color to RED
    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
     //-----------------------
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
    
    //-----------------------
   
    
    
}
void sendG(void){
         // Example: Set color to RED
     
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
    
    //-----------------------

    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
     //-----------------------
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    
    
}

void sendR(void){
         // Example: Set color to RED
    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    
    
    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
    
    //-----------------------
    
    
    
    
    
    
    
    
     //-----------------------
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    

     
        
    
}
void sendD(void){
         // Example: Set color to RED
    
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
     LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    
    
    
    
    
    
    
    
    
    
     //-----------------------
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);

    LED_PORT.OUTSET = LED_PIN;
    _delay_us(LH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(LL);
    
    
    

     
        
    
}

void sendW(void){
         // Example: Set color to RED
  
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
     
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
     
    LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);

     LED_PORT.OUTSET = LED_PIN;
    _delay_us(HH*6);
    LED_PORT.OUTCLR = LED_PIN;
    _delay_us(HL);
 

     
        
    
}

void lights(int frontl,int fronth,int backl, int backh,int max){
    for (int i = 0; i < frontl; i++){
        sendD();
    }
    for (int i = frontl; i < fronth; i++){
        sendW();
    }
    for (int i = fronth; i < backl; i++){
        sendD();
    }
    for (int i = backl; i < backh; i++){
        sendR();
    }
    for (int i = backh; i < max; i++){
        sendD();
    }
    _delay_us(1000);
    
    
}


