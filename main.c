#include "setting.h"
#include <stdlib.h>
#include "stdio.h"
#include "string.h"
#include <xc.h>
#include <pic18f4520.h>
#define _XTAL_FREQ 8000000

char str[20];

void main(void){
    SYSTEM_INIT();
    while(1) {
        strcpy(str, GetString());
        switch(str[0]){
            case 'f':
                H_ctrl('f');
                PWM_Modify(1000);
                break;
            case 's':
                H_ctrl('s');
                PWM_Modify(0);
                break;
            case 'b':
                H_ctrl('b');
                PWM_Modify(1000);
                break;
        }
        ClearBuffer();
        __delay_ms(100);
    }
    return;
}