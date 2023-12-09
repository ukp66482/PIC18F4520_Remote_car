#ifndef SETTING_H
#define	SETTING_H
#include <xc.h>
#include <pic18f4520.h>
#include "uart.h"
#include "interrupt_manager.h"
#include "PWM.h"
#include "h_bridge.h"

void SYSTEM_INIT();
void OSC_INIT(); //OSC = 8Mhz

#endif