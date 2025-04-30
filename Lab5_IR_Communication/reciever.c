#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000UL
#define Collector    LATCbits.LATC0



// PIC Configuration
#pragma config FOSC   = INTRCIO   // 4 MHz internal OSC, RA4/OSC2 & RA5/OSC1 as I/O
#pragma config WDTE   = OFF       // Watchdog Timer disabled
#pragma config PWRTE  = OFF       // Power-up Timer disabled
#pragma config MCLRE  = OFF       // RA3/MCLR pin enabled as digital input
#pragma config BOREN  = OFF       // Brown-out Reset disabled
#pragma config CPD    = OFF       // Data EEPROM Code Protection disabled
#pragma config CP     = OFF       // Flash Program Memory Code Protection disabled

// Function Prototypes


//main
void main(void){
    _init_control_();
    
    while(1){
        
    }
    
}
// Initialize PORTA pins 0–3 as digital inputs, RC0 as output
void _init_control_(void) {
    ANSEL   = 0x00;       // disable analog on RA0–RA2
    CMCON   = 0x07;       // disable comparators
    VRCON   = 0x00;       // disable voltage reference

    // RA0–RA3 as outputs
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    
    // RC0 as output for IR pulse
    TRISCbits.TRISC0 = 0;
    COLLECTOR = 0;
}