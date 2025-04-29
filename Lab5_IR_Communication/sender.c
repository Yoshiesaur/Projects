#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000UL
#define EMITTER    LATCbits.LATC0

// Function Prototypes
uint8_t readData(void);
void sendBits(uint8_t);

// PIC Configuration
#pragma config FOSC   = INTRCIO   // 4 MHz internal OSC, RA4/OSC2 & RA5/OSC1 as I/O
#pragma config WDTE   = OFF       // Watchdog Timer disabled
#pragma config PWRTE  = OFF       // Power-up Timer disabled
#pragma config MCLRE  = OFF       // RA3/MCLR pin enabled as digital input
#pragma config BOREN  = OFF       // Brown-out Reset disabled
#pragma config LVP    = OFF       // Low-Voltage Programming disabled
#pragma config CPD    = OFF       // Data EEPROM Code Protection disabled
#pragma config CP     = OFF       // Flash Program Memory Code Protection disabled

// Initialize PORTA pins 0–3 as digital inputs, RC0 as output
void _init_control_(void) {
    ANSEL   = 0x00;       // disable analog on RA0–RA2
    CMCON   = 0x07;       // disable comparators
    VRCON   = 0x00;       // disable voltage reference

    // RA0–RA3 as inputs
    TRISAbits.TRISA0 = 1;
    TRISAbits.TRISA1 = 1;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA3 = 1;
    
    // RC0 as output for IR pulse
    TRISCbits.TRISC0 = 0;
    EMITTER = 0;
}

void main(void) {
    _init_control_();

    uint8_t read_data;
    while (1) {
        read_data = readData();
        sendBits(read_data);
        __delay_ms(50);    // 50 ms gap between frames
    }
}

// Return only lower nibble of PORTA
uint8_t readData(void) {
    return (PORTA & 0x0F);
}

// Transmit: 1 ms “start”, four data bits (250 µs = 0, 500 µs = 1), then 500 µs “end”
void sendBits(uint8_t beans) {
    // Start pulse: 1 ms
    EMITTER = 1;  
    __delay_us(1000);
    EMITTER = 0;  
    __delay_us(250);

    // Data bits, MSB → LSB
    for (int i = 3; i >= 0; i--) {
        EMITTER = 1;
        if (beans & (1 << i)) {
            __delay_us(500);   // bit = 1
        } else {
            __delay_us(250);   // bit = 0
        }
        EMITTER = 0;
        __delay_us(250);      // inter-bit gap
    }

    // End pulse: 500 µs
    EMITTER = 1;  
    __delay_us(1000);
    EMITTER = 0;
}
