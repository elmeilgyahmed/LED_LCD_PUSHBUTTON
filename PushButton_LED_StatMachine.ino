
#include "LED.h"
#include "Timer.h"
#include "PushButton.h"
#include "PWM.h"
#include <LiquidCrystal.h>
int bright=0;
int prescaled=8;
int TOP_value=40000;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 11, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd_scr(rs, en, d4, d5, d6, d7);

void setup() {
  PushButton_Init();
  LED_Init();
  PWM1_SetChannel();
  PWM1_SetFatPWMTopValue(TOP_value);  
    Timer1_Setup_Interrupt_50HZ();
   lcd_scr.begin(16, 2);
  // Print a message to the LCD.
  lcd_scr.print("MAX:255");
}

void loop() {

  if( PushButton_GetState(0)==PRESSED)
  {
    bright=LED_Update(0);
   delay(50);
  }
   if( PushButton_GetState(1)==PRESSED)
  {
   bright= LED_Update(1);
    delay(50);
  }
    bright = constrain(bright,0,255);
    lcd_scr.setCursor(0, 1);
   // print the number of seconds since reset:
    lcd_scr.print(bright);
  
}
