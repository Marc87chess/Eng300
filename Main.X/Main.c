#include "USBIO.h"
#include "Motor.h"
#include <util/delay.h>
#include <avr/io.h>
#include <xc.h>

int start(void);
int recive_and_ecexucte_command(struct Pod **podn);
int start(void){
    pwm_split_init();
    adc_init(0x00);
    USART_Init(1540);
    return 0;
}

int main(void) {
    pwm_split_init();
    static struct Pod pod1 = {0,0,0,0, (&TCA0.SPLIT.HCMP0), &TCA0.SPLIT.HCMP1, 0b00000010, 0b00000100, 0x07, &(PORTD.OUT)};
    static struct Pod pod2 = {0,0,0,0, &TCA0.SPLIT.HCMP2, &TCA0.SPLIT.LCMP1, 0b00001000, 0b00010000, 0x10, &(PORTD.OUT)};
    static struct Pod pod3 = {0,0,0,0, &TCA0.SPLIT.LCMP2, &TCA0.SPLIT.LCMP0, 0b00100000, 0b01000000, 0x11, &(PORTD.OUT)};
    struct Pod *p1, *p2, *p3;
    p1 = &pod1;
    p2 = &pod2;
    p3 = &pod3;

    simpleMovetoTarget(p1, 0, 255, 0);
   simpleMovetoTarget(p2, 0, 255, 0);
    simpleMovetoTarget(p3, 0, 255, 0);
   
    int i = 0;
    
    
    
   
    while (1){
        i++;
        if (i>255){
            i = 0;
        }
       //simpleMovetoTarget(p1, 245, i, 245);
      //  simpleMovetoTarget(p2, 245, i, 245);
      // simpleMovetoTarget(p3, 245, i, 245);
        _delay_us(100000);
    }
}
int recive_and_ecexucte_command(struct Pod **podn) {
    char commandstr[64] = "";
    char command[5] = {'s','h','l'};
    USART_ReadString(commandstr, 63);
    int pod,cmdcharpos,cmd,cmdheading,cmdspeed;
    int len = 3;
    int leave = 0;
    int c = 0;
    while(commandstr[c] != 0){
        for (int i =0;i < len; i++)
            if (commandstr[c] == command[i]){
                cmdcharpos =c;
                cmd = i;
                leave = 1;
                break;
            }
        c++;
        if (leave) break;
        
                
    }
    if (cmd < 2){
        cmdcharpos ++;
        pod = (commandstr[cmdcharpos]-48);
        cmdspeed = ((commandstr[cmdcharpos+1]-48)*100 + (commandstr[cmdcharpos+2]-48)*10 + (commandstr[cmdcharpos+3]-48));
        cmdheading = ((commandstr[cmdcharpos+4]-48)*100 + (commandstr[cmdcharpos+5]-48)*10 + (commandstr[cmdcharpos+6]-48));
        MovetoTarget(podn[pod],cmdheading,cmdspeed);
        
    }
}