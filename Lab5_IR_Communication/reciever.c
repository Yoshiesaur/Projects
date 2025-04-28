// File: rx_ir.c
// Target: PIC16F676 @ 4 MHz internal oscillator
// Infrared 4-bit receiver (no PWM)

#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 4000000UL

// CONFIGURATION BITS
#pragma config FOSC   = INTRCIO
#pragma config WDTE   = OFF
#pragma config PWRTE  = OFF
#pragma config MCLRE  = OFF
#pragma config BOREN  = OFF
#pragma config LVP    = OFF
#pragma config CPD    = OFF
#pragma config CP     = OFF

// I/O definitions
#define IR_RX_PORT  PORTAbits.RA2
#define IR_RX_TRIS  TRISAbits.TRISA2
#define RX_LED_LAT  LATC
#define RX_LED_TRIS TRISC
#define RX_LED_MASK 0x0F    // RC0..RC3 outputs

// Timing & thresholds (µs)
#define START_PULSE_US   1000
#define START_MIN        800    // acceptable start width range
#define START_MAX       1200
#define BIT_THRESHOLD    375    // mid-point between 250 & 500
#define BIT_GAP_US       500

// prototypes
void init_ports(void);
void init_timers(void);
uint8_t receive_frame(void);

void main(void) {
    uint8_t rx;
    init_ports();
    init_timers();

    while (1) {
        rx = receive_frame();
        if (rx != 0xFF) {
            RX_LED_LAT = (RX_LED_LAT & ~RX_LED_MASK) | (rx & RX_LED_MASK);
        }
    }
}

void init_ports(void) {
    ANSEL = 0x00;
    CMCON = 0x07;
    VRCON = 0x00;

    // RA2 as input
    IR_RX_TRIS = 1;
    // LEDs RC0..RC3 as outputs
    RX_LED_TRIS &= ~RX_LED_MASK;
    RX_LED_LAT  = 0;
}

void init_timers(void) {
    // Timer0: Fosc/4 = 1 MHz, prescaler 1:1 ⇒ 1 µs tick
    OPTION_REG = 0b00000000;  // PSA→TMR0, PS=1:1
    TMR0 = 0;
}

uint8_t receive_frame(void) {
    uint8_t i, bit, data = 0;
    uint8_t width;

    // 1) Wait for start-pulse rising edge
    while (!IR_RX_PORT) { }
    TMR0 = 0;
    // measure high-time
    while (IR_RX_PORT) { }
    width = TMR0;
    if (width < START_MIN || width > START_MAX) {
        return 0xFF;    // invalid frame
    }
    // gap
    __delay_us(BIT_GAP_US);

    // 2) Read 4 bits MSB first
    for (i = 0; i < 4; i++) {
        // wait rising
        while (!IR_RX_PORT) { }
        TMR0 = 0;
        // measure high-time
        while (IR_RX_PORT) { }
        width = TMR0;

        bit = (width > BIT_THRESHOLD) ? 1 : 0;
        data |= (bit << (3 - i));

        // gap
        __delay_us(BIT_GAP_US);
    }

    return data;
}
