#include "setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include <xc.h>
#include <pic18f4520.h>
#define _XTAL_FREQ 8000000

char str[20];
int speed=0;
void main(void){
    SYSTEM_INIT();
    
    while(1) {
        strcpy(str, GetString());
        switch(str[0]){
            case 'f':
                H_ctrl('f');
                PWM_Modify(1023);
                break;
            case 's':
                H_ctrl('s');
                PWM_Modify(0);
                break;
            case 'b':
                H_ctrl('b');
                PWM_Modify(1023);
                break;
            case 'r':
                H_ctrl('r');
                PWM_Modify(250);
                break;
            case 'l':
                H_ctrl('l');
                PWM_Modify(250);
                break;
            case 'u':
                H_ctrl('f');
                speed+=100;
                if(speed>1023){speed=1023;}
                PWM_Modify(speed);
                break;
            case 'd':
                H_ctrl('r');
                speed-=100;
                if(speed<0){speed=0;}
                PWM_Modify(speed);
                break;
        }
        ClearBuffer();
        __delay_ms(100);
    }
    return;
}