#include "LED.h"
#include "Arduino.h"
#include "PushButton.h"
#include "PWM.h"


#define LED_PIN 5
int ledbrightness=0;

void  LED_Init()

{
  pinMode(LED_PIN,OUTPUT);
  
}


int  LED_Update(int ID)
{
if(ID==0)
{
  PB_State state= PushButton_GetState(ID);
  if(state == PRESSED)
  {
	  ledbrightness=ledbrightness+25;
	  PWM1_SetDutyCycle(ledbrightness);
    analogWrite(LED_PIN,ledbrightness);

    return ledbrightness;
  }
}
if(ID==1)
{
  PB_State state= PushButton_GetState(ID);
  if(state == PRESSED)
  {
  	ledbrightness=ledbrightness-25;
	  PWM1_SetDutyCycle(ledbrightness);
    analogWrite(LED_PIN,ledbrightness);
    return ledbrightness;
	
  }
}
}
