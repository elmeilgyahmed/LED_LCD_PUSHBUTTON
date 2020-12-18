/**
 * PWM.h
 * Description : Header File for PWM.c to implement ......
 */

#ifndef PWM_H // THIS is a Header Guard. Please read more at https://en.wikipedia.org/wiki/Include_guard
#define PWM_H

#ifdef __cplusplus // Added to write c code in c++ environment
extern "C" {
#endif


/*
* Function: PWM1_SetDutyCycle
* ----------------------------
* Returns: assign OCR1x to   duty cycle
*
* duty: the new duty cycle to be assigned
* 
*
* returns: change duty cycle  
*/
void PWM1_SetDutyCycle(int duty);


/*
* Function: PWM1_SetFatPWMTopValue
* ----------------------------
* Returns: assign the registar ICR1 to TOP_value value for fastPWM14 Mode
*
* TOP_value : Used to determine PWM frequnecy  along with Timer1_SetPrescaler
* 
*
* returns: detremine PWM frequency along with Timer1_SetPrescaler from
*PWM_fequency = clock_speed / [Prescaller_value * (1 +TOP_Value) ] 
*/
void PWM1_SetFatPWMTopValue(int TOP_value);

/*
* Function: PWM1_SetChannel
* ----------------------------
* Returns: adjust the required channel 
*

* 
*
* returns: adjust the required channel 
*/

void PWM1_SetChannel();

#endif //PWM_H


#ifdef __cplusplus
} // extern "C"
#endif
