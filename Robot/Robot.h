// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _Robot_H_
#define _Robot_H_
#include "Arduino.h"
//add your includes for the project Robot here

#define TRIGGER_PIN  7
#define ECHO_PIN     8
#define MAX_DISTANCE 200

#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENAL 11
#define ENAR 10

#define NORMAL_SCAN_TIME 500
#define FAST_SCAN_TIME 100

int scan_time;

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project Robot here

void left_forward();
void left_stop();
void left_backward();
void right_forward();
void right_stop();
void right_backward();

void turn_left();
void turn_right();
void go_forward();
void go_backward();
void go_left();
void go_right();
void spin_left();
void spin_right();
void spin_random();
void stop();


//Do not add code below this line
#endif /* _Robot_H_ */
