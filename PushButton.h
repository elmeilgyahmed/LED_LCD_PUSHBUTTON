/**
 * PushButton.h
 * Description : Header File for PushButton.c to implement ......
 */


#ifndef PUSHBUTTON_H  // THIS is a Header Guard. Please read more at https://en.wikipedia.org/wiki/Include_guard
#define PUSHBUTTON_H


#ifdef __cplusplus // Added to write c code in c++ environment
extern "C" {
#endif



typedef enum {
  RELEASED=0,
  PRESSING,
  PRESSED,
  RELEASING
} PB_State;


//add description
PB_State PushButton_GetState(int ID);


//add description
void  PushButton_Init();

//add description
void  PushButton_Update();



#ifdef __cplusplus
} // extern "C"
#endif



#endif //PUSHBUTTON_H
