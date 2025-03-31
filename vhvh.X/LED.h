#ifndef LED_H   // Include guard to prevent double inclusion
#define LED_H

#include <avr/io.h> 
#include <util/delay.h>
void sendB(void);
void sendD(void);
void sendR(void);
void sendW(void);
void lights(int frontl,int fronth,int backl, int backh,int max);

#endif