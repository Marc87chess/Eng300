#include "USBIO.h"
#include "Motor.h"
#include "LEDM.h"
#include <util/delay.h>
#include <avr/io.h>
#include <xc.h>

int start(void);
int recive_and_ecexucte_command(struct Pod **podn);
int start(void){
    int baud = 0;
    USART_Init(baud);
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    adc_init(0x10);
    pwm_split_init();
}

int main(void) {
    
    
    
    char rec[10];
    int sum = 0;
    int valid = 0;
    int pod_number = 0;
    int adjust_speed =0;
    int adjust_heading = 0;
    int Head = 0;
    int Speed = 0;
    int fast_turn = 0;
    struct Pod *p1, *p2, *p3;
    int Hl = 5;
    int Bl = 25;
    
    start();
    innit_pod(&p1, &p2, &p3);
    lights(5,Hl,25,Bl,55);
      

    
   

    
   
    while (1){
        sum = 0;
        valid = -1;
        valid = receive_until_null(rec);
        adjust_speed =0;
        adjust_heading = 0;
        
        if (valid == 0){
          Speed = (rec[2]-48)*100 + (rec[3]-48)*10 + (rec[4]-48);
          Head = (rec[5]-48)*100 + (rec[6]-48)*10 + (rec[7]-48);
          pod_number = rec[0]-48;
          fast_turn = 0;
          if ((rec[1]-ASCIICON) == 2){
                Speed = Speed-128;
                Head = Head-128;
          }
          else if ((rec[1]-ASCIICON) == 3){
                Speed = Speed-128;
                Head = Head-128;
          }
          else if ((rec[1]-ASCIICON) == 4){
              fast_turn = 1 ;
              Speed = Speed-128;
              Head = Head-128;
          }
          
          
          
        
          
              
          if((rec[0]-ASCIICON) == 4){
             simpleMovetoTarget(p1,Head,Speed,fast_turn); // THIS WILL NOT WORK WITHOUT FUTHER ADJUSTMENT
             simpleMovetoTarget(p2,Head,Speed,fast_turn); // REMEBER TO TAKE THE HEADING OF LEAD POD AND
             simpleMovetoTarget(p3,Head,Speed,fast_turn); // USE PID TO KEEP OTHER PODS IN TOW
          }
          else if ((rec[0]-ASCIICON) == 5){
               int Hl = 15;
               int Bl = 35;
              lights(5,Hl,25,Bl,55);
              
          }
          else if ((rec[0]-ASCIICON) == 6){
               int Hl = 5;
               int Bl = 25;
              lights(5,Hl,25,Bl,55);
              
          }
           
           
           
        
             
        }
        else zerospeed(p1,p2,p3);
     
        
       


        //_delay_us(50);

    }
}
