#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "USBIO.h"
#include "Motor.h"
#define PWM_PIN PIN0_bm  
#define PERIOD_US 1000  // 1 kHz PWM = 1000 µs period
#define DUTY_CYCLE 50 
#define PER_VALUE = 255

#define PWM_PIN (1 << PIN0)  // CHANGE THIS

// Duty cycle (0 to 255, where 255 is 100%)
volatile uint8_t duty_cycle = 128; // 50% duty cycle initially





int innit_pins(void){
    
    PORTD.DIRSET = 0b11111111;
    PORTC.DIRSET = PIN2_bm;
    PORTC.DIRCLR = PIN3_bm; 
    PORTD.DIRSET = PIN5_bm;
    PORTD.DIRCLR = PIN6_bm; 
    return 0;
}



// Timer0 compare interrupt service routine

int innit_pods(struct Pod **p1, struct Pod **p2, struct Pod **p3) {
    static struct Pod pod1 = {0,0,0,0, (&TCA0.SPLIT.HCMP0), &TCA0.SPLIT.HCMP1, 0b00000010, 0b00000100, 0x07, &(PORTD.OUT)};
    static struct Pod pod2 = {0,0,0,0, &TCA0.SPLIT.HCMP2, &TCA0.SPLIT.LCMP1, 0b00001000, 0b00010000, 0x10, &(PORTD.OUT)};
    static struct Pod pod3 = {0,0,0,0, &TCA0.SPLIT.LCMP2, &TCA0.SPLIT.LCMP0, 0b00100000, 0b01000000, 0x11, &(PORTD.OUT)};
    
    *p1 = &pod1;
    *p2 = &pod2;
    *p3 = &pod3;

    simpleMovetoTarget(*p1, 10, 5, 245);
    simpleMovetoTarget(*p2, 10, 5, 245);
    simpleMovetoTarget(*p3, 10, 5, 245);
    return 0;
}
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
 
int MovetoTarget(struct Pod * podn, int Target,int speed){
    ADC0.MUXPOS = (podn->pos);
    
    uint16_t head = ADC_read();
    //top motor spins direction = 1 and bottom = 0 for "forward"
    
    Target = Target - head;
    //Turn rate of swerve m1 + m2
    //move rate of swerve = m1 - m2
    int mtop = (Target + speed)/2;
    int mbottom = (Target - speed)/2;
    *(podn->port_registerdir) = (*(podn->port_registerdir) & 0b11111000);
    if (mtop < 0){
        mtop = -1*mtop;
        *(podn->port_registerdir) = *(podn->port_registerdir) |(podn->adirtop);
    }else podn->dirtop = 0;
    if (mbottom < 0){
        mbottom = -1*mbottom;
        *(podn->port_registerdir) =  *(podn->port_registerdir) | (podn->adirbottom);
    }else podn->dirbottom = 0;
    
   
    
    
   
    *(podn->pwm1) = mtop;
    *(podn->pwm2) = mbottom;
    if (Target == 0) return 1;
    return 0;
}
int simpleMovetoTarget(struct Pod * podn, int Target,int speed,int head){
    //ADC0.MUXPOS = (podn->pos);
    
    //uint16_t head = ADC_read();
    //top motor spins direction = 1 and bottom = 0 for "forward"
    
    Target = Target - head;
    //Turn rate of swerve m1 + m2
    //move rate of swerve = m1 - m2
    int mtop = (Target + speed)/2;
    int mbottom = (Target - speed)/2;
    *(podn->port_registerdir) = (*(podn->port_registerdir) & 0b11111000);
    if (mtop < 0){
        mtop = -1*mtop;
        *(podn->port_registerdir) = *(podn->port_registerdir) |(podn->adirtop);
    }else podn->dirtop = 0;
    if (mbottom < 0){
        mbottom = -1*mbottom;
        *(podn->port_registerdir) =  *(podn->port_registerdir) | (podn->adirbottom);
    }else podn->dirbottom = 0;
    
   
    
    
   
    *(podn->pwm1) = mtop;
    *(podn->pwm2) = mbottom;
    if (Target == 0) return 1;
    return 0;
}



