#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
// MARC WHEN YOU COMEBACK TO THIS REMEBER TO CHANGE TO UART1


 /*
  * THE RIGHT JOYSTICK ANALOGx is PD3, Y PD4,BUTTON PA0
  * THE LEFT JOYSTICK ANALOGx is PD2, Y PD1,BUTTON PA1
////////  *  
*/
//#define TEST


void pwm_split_init(void){
    // 1. Ensure full-speed clock (Remove prescaler if needed)
    _PROTECTED_WRITE(CLKCTRL.MCLKCTRLB, 0x00);

    // 2. Set PORTMUX to route TCA0 outputs to PORTD
    PORTMUX.TCAROUTEA = 0x00;

    // 3. Set PD0-PD5 as outputs (LOW and HIGH channels)
    PORTA.DIRSET = 0b11111111; // PD0-PD5 as outputs
    PORTD.DIRSET = 0b11111111;
    // 4. Enable Split Mode
    TCA0.SPLIT.CTRLD = TCA_SPLIT_SPLITM_bm;

    // 5. Set period for both lower and upper timers (8-bit max = 255)
    TCA0.SPLIT.LPER = 255;  // Lower 8-bit timer period
    TCA0.SPLIT.HPER = 255;  // Upper 8-bit timer period

    // 6. Set duty cycles for all compare channels
    TCA0.SPLIT.LCMP0 = 128;  // 50% duty cycle on PA0
    TCA0.SPLIT.LCMP1 = 64;   // 25% duty cycle on PA1
    TCA0.SPLIT.LCMP2 = 192;  // 75% duty cycle on PA2
    TCA0.SPLIT.HCMP0 = 32;   // 12.5% duty cycle on PA3
    TCA0.SPLIT.HCMP1 = 160;  // 62.5% duty cycle on PA4
    TCA0.SPLIT.HCMP2 = 224;  // 87.5% duty cycle on PA5

    // 7. Enable all compare channels (LCMP0, LCMP1, LCMP2, HCMP0, HCMP1, HCMP2)
    TCA0.SPLIT.CTRLB = 
        TCA_SPLIT_LCMP0EN_bm | 
        TCA_SPLIT_LCMP1EN_bm | 
        TCA_SPLIT_LCMP2EN_bm | 
        TCA_SPLIT_HCMP0EN_bm | 
        TCA_SPLIT_HCMP1EN_bm | 
        TCA_SPLIT_HCMP2EN_bm;

    // 8. Enable the timer with a prescaler of 64
    TCA0.SPLIT.CTRLA = TCA_SPLIT_CLKSEL_DIV64_gc | TCA_SPLIT_ENABLE_bm;
}
 
#ifndef TEST 
#define REAL
#endif
#ifdef TEST
int main(void) {
    PORTA.DIRSET |= 0b10000000;
    //adc_init(0x03);
    //int count = 0;
    uint16_t baud = 1700;  // lucky baud rate
    USART_Init(baud);
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    char rec[10];
    while (1) {
        
        
        receive_until_null(rec);
        for(int i = 0; i < 5; i++){
        rec[i] = (rec[i] - 48);
        }
        if (rec[0] == 3){
            if (rec[1] == 1){
                PORTA.OUT |= 0b10000000;
            }else PORTA.OUT &= 0b01111111;
        }else PORTA.OUT &= 0b01111111;
        for(int i = 0; i < 5; i++){
        rec[i] = 0;
        }
          // Echo received data back
        
       
       // received = (ADC_readpos(0x02));
        //USART_Transmit(received);
        //_delay_ms(100);
       
    }

    return 0;
}
#endif

#ifdef REAL
int main(void) {
    PORTA.DIRSET |= 0b10000000;
    //adc_init(0x03);
    //int count = 0;
    uint16_t baud = 1700;  // lucky baud rate
    USART_Init(baud);
    CCP = 0xd8;
    CLKCTRL.OSCHFCTRLA = 0b00011100;
    while( CLKCTRL.MCLKSTATUS & 0b00000001 ){
        ;
    }
    char rec[10];
    int sum = 0;
    int valid = 0;
    pwm_split_init();
    while (1) {
        sum = 0;
        valid = 0;
        valid = receive_until_null(rec);
        if (valid == 0){
            sum = (rec[2]-48)*100 + (rec[3]-48)*10 + (rec[4]-48);
            TCA0.SPLIT.LCMP0 = sum;
        }
        for(int i = 0; i < 5; i++){
        rec[i] = (rec[i] - 48);
        }
        if (rec[0] == 3){
            if (rec[1] == 1){
                PORTA.OUT |= 0b10000000;
            }else PORTA.OUT &= 0b01111111;
        }else PORTA.OUT &= 0b01111111;
        for(int i = 0; i < 5; i++){
        rec[i] = 0;
        }
        
          // Echo received data back
        
       
       // received = (ADC_readpos(0x02));
        //USART_Transmit(received);
        //_delay_ms(100);
       
    }

    return 0;
}
#endif