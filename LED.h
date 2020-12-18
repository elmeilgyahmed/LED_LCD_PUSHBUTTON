
/**
 * LED.h
 * Description : Header File for LED.c to implement ......
 */

 
#ifndef LED_H  // THIS is a Header Guard. Please read more at https://en.wikipedia.org/wiki/Include_guard
#define LED_H
#define LED_PIN 5


#ifdef __cplusplus // Added to write c code in c++ environment
extern "C" {
#endif


void  LED_Init();
int  LED_Update(int ID);



#ifdef __cplusplus
} // extern "C"
#endif



#endif //LED_H
