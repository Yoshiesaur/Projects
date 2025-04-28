#include <xc.h>
#include <stdint.h>

// oscillator frequency for __delay_us/__delay_ms
#define _XTAL_FREQ 4000000UL

// CONFIGURATION BITS
#pragma config FOSC   = INTRCIO   // Internal OSC, RA4/OSC2 & RA5/OSC1 as I/O
#pragma config WDTE   = OFF       // Watchdog Timer disabled
#pragma config PWRTE  = OFF       // Power-up Timer disabled
#pragma config MCLRE  = OFF       // RA3/MCLR pin enabled as digital input
#pragma config BOREN  = OFF       // Brown-out Reset disabled
#pragma config LVP    = OFF       // Low-Voltage Programming disabled
#pragma config CPD    = OFF       // Data EEPROM Code Protection disabled
#pragma config CP     = OFF       // Flash Program Memory Code Protection disabled

//Function Protypes


int main(void){

}