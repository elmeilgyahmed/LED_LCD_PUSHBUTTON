#include "PushButton.h"
#include <stdint.h>
#include "Arduino.h"

#define PB_PIN1 3
#define PB_PIN2 4

static uint8_t Button1_Samples[2];
static uint8_t Button2_Samples[2];
static  PB_State Button1_State;
static  PB_State Button2_State;

void  PushButton_Init()
{
  pinMode(PB_PIN1, INPUT_PULLUP);
  pinMode(PB_PIN2, INPUT_PULLUP); // try to use low level registers
}

void  PushButton_Update()
{
    
  // you can loop on many switches here 
  Button1_Samples[0]= Button1_Samples[1]; // shift the sample
  Button1_Samples[1]= digitalRead(PB_PIN1);// read the last sample
  Button2_Samples[0]= Button2_Samples[1]; // shift the sample
  Button2_Samples[1]= digitalRead(PB_PIN2);// read the last sample
  
  switch (Button1_State)
  {
    case RELEASED:
      if(Button1_Samples[0]==0 && Button1_Samples[1]==1)
        {Button1_State=PRESSING;}
      break;
    case PRESSING:
      if(Button1_Samples[1]==1)
        {Button1_State=PRESSED;
        }
      break;
    case PRESSED:
      if(Button1_Samples[1]==0 && Button1_Samples[0]==1)
        {Button1_State=RELEASING;
        }
      break;
    case RELEASING:
        if(Button1_Samples[1]=0)
        {Button1_State=RELEASED;
        }
      break;
    default:
        break;   
  }
  
  switch (Button2_State)
  {
    case RELEASED:
      if(Button2_Samples[0]==0 && Button2_Samples[1]==1)
        {Button1_State=PRESSING;}
      break;
    case PRESSING:
      if(Button2_Samples[1]==1)
        {Button2_State=PRESSED;
        }
      break;
    case PRESSED:
      if(Button2_Samples[1]==0 && Button2_Samples[0]==1)
        {Button2_State=RELEASING;
        }
      break;
    case RELEASING:
        if(Button2_Samples[1]=0)
        {Button2_State=RELEASED;
        }
      break;
    default:
        break;   
  }
  
}

PB_State PushButton_GetState(int ID)
{
    if(ID==0){
	return Button1_State;
	}
	else if(ID==1)
	{
		return Button2_State;
	}
}
