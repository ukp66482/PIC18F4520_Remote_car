#include <xc.h>
#include <pic18f4520.h>

void H_Bridge_INIT(){
    TRISDbits.TRISD3 = 0; //h_bridge ctrl pin 10
    TRISDbits.TRISD2 = 0; //h_bridge ctrl pin 15
    TRISCbits.TRISC4 = 0; //h_bridge ctrl pin 2
    TRISCbits.TRISC5 = 0; //h_bridge ctrl pin 7
    LATD = 0;
    return;
}

void H_ctrl(char num){
    switch(num){
        case 'f': //forward
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 1;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 1;
            break;
        case 's': //stop
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 0;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 0;
            break;
        case 'b': //backward
            LATDbits.LATD2 = 1;
            LATDbits.LATD3 = 0;
            LATCbits.LATC4 = 1;
            LATCbits.LATC5 = 0;
            break;
        case 'r': //right
            LATDbits.LATD2 = 1;
            LATDbits.LATD3 = 0;
            LATCbits.LATC4 = 0;
            LATCbits.LATC5 = 1;
            break;
        case 'l': //right
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 1;
            LATCbits.LATC4 = 1;
            LATCbits.LATC5 = 0;
            break;
    }    
    return;
}