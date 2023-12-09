#include <xc.h>
#include <pic18f4520.h>

void H_Bridge_INIT(){
    TRISDbits.TRISD0 = 0; //h_bridge ctrl pin7
    TRISDbits.TRISD1 = 0; //h_bridge ctrl pin2
    LATD = 0;
    return;
}

void H_ctrl(char num){
    switch(num){
        case 'f': //forward
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 1;
            break;
        case 's': //stop
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            break;
        case 'b': //backward
            LATDbits.LATD0 = 1;
            LATDbits.LATD1 = 0;
            break;
    }    
    return;
}