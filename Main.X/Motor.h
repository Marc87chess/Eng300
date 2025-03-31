/* 
 * File:  USB_IO.H
 * Author: marcy marc and the funky bunch
 * Comments: have mercy
 * Revision history:V0.1
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#include <util/delay.h>

#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H
#endif 
#define F_CPU 16000000UL
#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation
struct Pod {
    
    int dirtop;
    int dirbottom;
    
    int pwmtop;
    int pwmbottom;
    
    uint8_t* pwm1;
    uint8_t* pwm2;
    
    uint8_t adirtop;
    uint8_t adirbottom;
    
    uint8_t pos;
    
    
    uint8_t* port_registerdir;
};

int zerospeed(struct Pod * pod1, struct Pod * pod2,struct Pod * pod3);

int innit_pins(void);

void pwm_init(void);

void PWM(int duty);

int innit_pods(struct Pod **p1,struct Pod **p2,struct Pod **p3);

void pwm_split_init(void);

int MovetoTarget(struct Pod * podn, int Target,int speed);

int simpleMovetoTarget(struct Pod * podn, int Target,int speed,int mode);

int TESTMOVE(struct Pod * podn, int Target,int speed,int head);

int innit_pod(struct Pod **p1, struct Pod **p2, struct Pod **p3);