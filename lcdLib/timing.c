#include <msp430.h>
#include "globals.h"

// Set up Timer A to run in up mode
void timerAUpmode()
{
    TA0CCR0 = 0;  // Initialize counter to 0
    TA0CCR1 = 0;  // Initialize duty cycle to 0%
    TA0CTL |= TASSEL_2 + MC_1;  // Source: SMCLK, Mode: Up to CCR0
    TA0CCTL1 |= OUTMOD_7;  // Output mode: Reset on CCR1, set on CCR0
}

// Delay for a specified number of milliseconds
void delay_ms(int ms)
{
    while (ms--)
    {
        __delay_cycles(SMCLK_FREQ / 1000);  // 1 ms delay
    }
}