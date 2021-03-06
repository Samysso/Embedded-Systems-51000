#include "config.h"

void wait_counts(unsigned int n, unsigned char edge) 
{
    TMR0L = 0;
    T0IF = 0;
    T0SE = edge;
    TMR0ON = 1;
    
    unsigned int overflow = 0;
    
    while(1)
    {
        if(TMR0L + overflow > n)
            break;
            
        if(T0IF == 1)
            {
                T0IF = 0;
                TMR0L  = 0;
                overflow = overflow + 256;
            }
    }
    
    TMR0ON = 0;
    return;
}

void configPIC()
{
    //All analog pins need to be input
    //Output: 0; Input: 1
    
    TRISA = 0b00000000;     //Set all pins of port A as output
    TRISB = 0b00000000;     //Set all pins of port B as output
    TRISC = 0b00000000;     //Set all pins of port C as output
    TRISD = 0b00000000;     //Set all pins of port D as output
    TRISE = 0b00000000;     //Set all pins of part E as output
    
    INTCONbits.GIE = 0;     //Turn off ALL interrupts
    
    
    T0CON = 0b01111000;     // TIMER 0
                            // Timer 0 disabled; configured as 8-bit counter;
                            // T0CKI pin; increment on low to high;
                            // pre-scaler is NOT assigned; pre-scaler is 1:2
    
    
     
    ADCON0 = 0b00000000;    //Left-MSB; Right-LSB
                            //ADC module is off
    
    ADCON1 = 0b00001111;    //All ports set to digital I/O
    

                            
   
    LED_TRIS = OUTPUT;
    SW1_TRIS = INPUT;
   
    
    //CONFIGURATION BITS
    
// CONFIG1L
#pragma config PLLDIV = 1               // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2       // System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])

// CONFIG1H
#pragma config FOSC = HSPLL_HS          // Oscillator Selection bits (EC oscillator, CLKO function on RA6 (EC))
#pragma config FCMEN = OFF              // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)

// CONFIG2L
#pragma config BORV = 3                 // Brown-out Reset Voltage bits (Minimum setting 2.05V)

// CONFIG2H
#pragma config WDT = OFF                // Watchdog Timer Enable bit (WDT enabled)

// CONFIG3H
#pragma config MCLRE = ON               // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config LVP = OFF                // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
}

