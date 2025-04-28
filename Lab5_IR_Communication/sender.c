// File: tx_ir.c
// Target: PIC16F676 @ 4 MHz internal oscillator
// Infrared 4-bit transmitter (no PWM)

#include <xc.h>
#include <stdint.h>

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

// I/O definitions
#define TX_PORT     PORTA
#define TX_TRIS     TRISA
#define TX_MASK     0x0F        // RA0..RA3 inputs
#define IR_TX_LAT   LATAbits.LATA5
#define IR_TX_TRIS  TRISAbits.TRISA5

// Timing (µs)
#define START_PULSE_US 1000
#define START_GAP_US    500
#define BIT0_PULSE_US   250
#define BIT1_PULSE_US   500
#define BIT_GAP_US      500

// prototypes
void init_ports(void);
void send_frame(uint8_t data);

void main(void) {
    init_ports();

    while (1) {
        uint8_t data = TX_PORT & TX_MASK;
        send_frame(data);
        __delay_ms(50);        // small pause between frames
    }
}

void init_ports(void) {
    ANSEL = 0x00;     // all digital
    CMCON = 0x07;     // comparators off
    VRCON = 0x00;     // voltage ref off

    // inputs RA0..RA3
    TX_TRIS |= TX_MASK;
    // IR drive RA5
    IR_TX_TRIS = 0;
    IR_TX_LAT  = 0;
}

void send_frame(uint8_t data) {
    uint8_t i;

    // 1) Start pulse
    IR_TX_LAT = 1;
    __delay_us(START_PULSE_US);
    IR_TX_LAT = 0;
    __delay_us(START_GAP_US);

    // 2) 4 data bits, MSB first
    for (i = 0; i < 4; i++) {
        IR_TX_LAT = 1;
        if (data & (1 << (3 - i))) {
            __delay_us(BIT1_PULSE_US);
        } else {
            __delay_us(BIT0_PULSE_US);
        }
        IR_TX_LAT = 0;
        __delay_us(BIT_GAP_US);
    }
}
