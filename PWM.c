/**
 * PWM.c
 * Description : Implements PWM Functions.
 */
#include "PWM.h"
#include "Arduino.h" 
/* include arudnio.h for registar definations */

void PWM1_SetFatPWMTopValue(int TOP_value)
{
ICR1=TOP_value;
/*Store the top value in ICR1 registar for mode 14. */
}


void PWM1_SetChannel()
{
/*set the channel to be '1' COM1A1/COM1B1 and '0'COM1A0/COM1B0 for mode */
TCCR1A|= _BV(COM1A1)| _BV(COM1B1); 
TCCR1A &=0b10111111;
TCCR1A &=0b11101111;
}
void PWM1_SetDutyCycle(int duty)
{
/*set the duty value in OCR1A Registar */
OCR1A=duty;
}
