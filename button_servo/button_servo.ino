#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;

int angle =0;    // initial angle  for servo
int angleStep =3;

#define LEFT 12   // pin 12 is connected to left button
#define RIGHT  2  // pin 2 is connected to right button

void setup() {
  // Servo button demo by Kwame Robot
  Serial.begin(9600);          //  setup serial
  myservo1.attach(11);// attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
  pinMode(LEFT,INPUT_PULLUP);
  pinMode(RIGHT,INPUT_PULLUP);
 Serial.println("TeachLeadsgh ");
}

void loop() {
  // Servo button demo by Kwame Robot
  while(digitalRead(RIGHT) == LOW){

    if (angle >= 0 && angle <= 180) {
      angle = angle - angleStep;
       if(angle < 0){
        angle = 0;
       }else{
      myservo1.write(angle);// move the servo to desired angle
      myservo2.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    
  delay(100); // waits for the servo to get there
  }
  
  while(digitalRead(LEFT) == LOW){

    if (angle >= 0 && angle <= 180) {
      angle = angle + angleStep;
      if(angle >180){
        angle =180;
       }else{
      myservo1.write(angle); // move the servo to desired angle
      myservo2.write(angle);
      Serial.print("Moved to: ");
      Serial.print(angle);   // print the angle
      Serial.println(" degree");
       }
    }
    
  delay(100); // waits for the servo to get there
  }// 

  
}
