#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include <stdlib.h>  // For itoa()
// MARC WHEN YOU COMEBACK TO THIS REMEBER TO CHANGE TO UART1
#define THRES 5
#define BUTTON5 0b10000000
#define BUTTON4 0b01000000
#define BUTTON3 0b00100000  
#define BUTTON2 0b00010000  
//#define TEST
#ifndef TEST 
#define REAL
#endif
 /* THIS ONE GOES ON THE CONTROLLER SORRY FOR THE BAD NAM
  * THE RIGHT JOYSTICK ANALOGx is PD3, Y PD4,BUTTON PA0
  * THE LEFT JOYSTICK ANALOGx is PD2, Y PD1,BUTTON PA1
////////  *  
*/
#ifdef TEST
int main(void) {
    PORTA.DIRSET &= 0b00001111;
    adc_init(0x03);
    int count = 0;
    uint16_t baud = 1700;  // lucky baud rate
    USART_Init(baud);
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    int h = 0;
    int t = 0;
    int o = 0;
    
    while (1) {
        
        
        int received = ADC_readpos(0x03);//USART_Receive();//USART_Receive();  // Receive data
        received = (((received) / 4096.0)*100); 
        if (!(PORTA.IN &0b10000000)){
            USART_Transmit(33+48);  // Echo received data back
            USART_Transmit(t+48);
            USART_Transmit(0);
        }
        if (received > 54){
           //USART_SendNumber(31255);
            received = 310;
        split_number((int)received,&h,&t,&o);
        USART_Transmit(h+48);  // Echo received data back
        USART_Transmit(t+48);
        USART_Transmit(0);
        }
        _delay_ms(10000);
      
    }

    return 0;
}
#endif

#ifdef REAL


int main(void) {
    PORTA.DIRSET &= 0b00001111;
    adc_init(0x03);
    int count = 0;
    uint16_t baud = 1700;  // lucky baud rate
    USART_Init(baud);
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    int h = 0;
    int t = 0;
    int o = 0;
    int pasts=0;
    int pasth=0;
    int speed = 0;
    int head = 0;
    int dh = 0;
    int ds = 0;
    int receivedspeed = 0;
    int receivedhead = 0;
    int fast_turn = 0;
    int old_fast_turn = 0;
    int Hlights = 0;
    int waspressed = 0;
    while (1) {
        
        pasts = speed;
        pasth = head;
        
        speed = ADC_readpos(0x03);//USART_Receive();//USART_Receive();  // Receive data
        head = ADC_readpos(0x04);
        dh = head -pasth;
        ds = speed - pasts;
        if (ds< 0) ds = -1*ds;
        if (dh< 0) dh = -1*dh;
        if (!(PORTA.IN &BUTTON5)){
            fast_turn = 1;
        }else fast_turn = 0;
        if (((dh > THRES) || (ds > THRES)) ||(old_fast_turn!=fast_turn)){
           receivedspeed = ((speed) / 16.0); 
           receivedhead = ((head) / 16.0); 
           APA(receivedspeed,receivedhead,fast_turn);
        }
        
        old_fast_turn = fast_turn;
        
       
        if (!(PORTA.IN &BUTTON4)){
           // IMPLEMENT HEADING LOGIC
        }
        if (!(PORTA.IN &BUTTON3)){
           // IMPLEMENT HEADING LOGIC
        }
        if (!(PORTA.IN &BUTTON2)){
            if (!(waspressed)){
            Hlights = !Hlights;
            Headlights(Hlights);
            }
            waspressed = 1;
        }else waspressed = 0;
       
        _delay_ms(10);
       
      
    }

    return 0;
}
#endif