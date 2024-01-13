#include <xc.h>
#include <pic18f4520.h>

void PWM_INIT(){
    TRISCbits.RC2 = 0; //CCP1 set output
    LATC = 0;
    
    T2CONbits.TMR2ON = 0b1; //Timer2 on
    T2CONbits.T2CKPS = 0b01; //prescaler 1:4
    
    // Internal Oscillator Frequency, Fosc = 8MHz, Tosc = 0.125us
    // PWM mode, P1A, P1C active-high; P1B, P1D active-high
    CCP1CONbits.CCP1M = 0b1100;
    /* 
       PWM period
       = (PR2 + 1) * 4 * Tosc * (TMR2 prescaler)
       = (0xff + 1) * 4 * 0.125us * 4
       = 512us
    */
    PR2 = 0xff; //512us PWM period
    
    //duty cycle
    CCPR1L = 0x00;
    CCP1CONbits.DC1B = 0b00;
    
    return;
}

void PWM_Modify(int num){ // 256 > num >= 0
    CCPR1L = (num >> 2);
    CCP1CONbits.DC1B = num & 0x0003;
    //LATCbits.LATC2 = 1;
}
