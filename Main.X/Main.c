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
    struct Pod *p1, *p2, *p3;
    innit_pods(&p1, &p2, &p3);  // Pass addresses of the pointers
    simpleMovetoTarget(p1, 225, 20, 245);
    simpleMovetoTarget(p2, 225, 20, 245);
    simpleMovetoTarget(p3, 225, 20, 245);
   
    while (1){
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