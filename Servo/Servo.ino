#include <Servo.h>
Servo myservo;
int waterSensor = A0;
int pos = 0;

void setup() {
Serial.begin(9600); 
myservo.attach(9);

}

void loop() {

}
