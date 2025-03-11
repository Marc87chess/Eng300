#include <avr/io.h>
#include <util/delay.h>
int adc_init(){
    VREF.ADC0REF = 0x05;
    ADC0.CTRLA = 0b10000001;
    ADC0.CTRLB = 0b00000000;
    ADC0.CTRLC = 0b00000111;
    ADC0.MUXPOS = 0x04;
    return 0;
}
uint16_t ADC_read() {
    // Start ADC conversion
    ADC0.COMMAND = ADC_STCONV_bm;

    // Wait for conversion to complete
    while (!(ADC0.INTFLAGS & ADC_RESRDY_bm));

    // Clear the interrupt flag
    ADC0.INTFLAGS = ADC_RESRDY_bm;

    // Return the result
    return ADC0.RES;
}


int main(void) {
  adc_init();
  PORTA.DIRSET = 0b11111111;
  PORTD.DIRSET = 0b00000000;
  while(1){
      _delay_us(1000);
      if (ADC_read() > 2500)
          PORTA.OUT = 0b11111111;
      else PORTA.OUT = 0b00000000;
      
  }
        

    
}
