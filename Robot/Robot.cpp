// Do not remove the include below
#include "Robot.h"
#include "NewPing.h"



NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
	scan_time = FAST_SCAN_TIME;

	Serial.begin(9600);
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	pinMode(IN3, OUTPUT);
	pinMode(IN4, OUTPUT);
	analogWrite(ENAL,128);
	analogWrite(ENAR,128);
	stop();
}

void loop() {
	unsigned int cm = DistanceSensor.ping_cm();
	Serial.print("Distance: ");
	Serial.print(cm);
	Serial.println("cm");

	delay(scan_time);
	if(cm < 5){
		spin_random();
		scan_time = NORMAL_SCAN_TIME;
	}else if (cm < 20) {
		stop();
		spin_random();
		scan_time = FAST_SCAN_TIME;
	} else if(cm == 30){
		Serial.print("DANS!");
		stop();
		delay(1000);
		spin_left();
		delay(3000);
		spin_right();
		delay(3000);
		stop();
	}else {
		go_forward();
		scan_time = FAST_SCAN_TIME;
	}
}

void left_forward() {
	digitalWrite(IN1, HIGH);
	digitalWrite(IN2, LOW);
}
void left_stop() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, LOW);
}
void left_backward() {
	digitalWrite(IN1, LOW);
	digitalWrite(IN2, HIGH);
}
void right_forward() {
	digitalWrite(IN3, HIGH);
	digitalWrite(IN4, LOW);
}
void right_stop() {
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, LOW);
}
void right_backward() {
	digitalWrite(IN3, LOW);
	digitalWrite(IN4, HIGH);
}

void stop() {
	left_stop();
	right_stop();
}

void go_forward(){
	Serial.println("Forward");
	left_forward();
	right_forward();
}

void go_backward(){
	Serial.println("Backward");
	left_backward();
	right_backward();
}
void go_left(){
	right_stop();
	left_forward();
}

void go_right(){
	left_stop();
	right_forward();
}

void spin_left(){
	Serial.println("Spin left");
	left_forward();
	right_backward();
}

void spin_right(){
	Serial.println("Spin right");

	right_forward();
	left_backward();
}

void spin_random(){
	if(random(1,10)>5){
		spin_right();
	}else{
		spin_left();
	}
}
