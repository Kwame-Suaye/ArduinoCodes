
#include <Servo.h>

Servo myservo1;// create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 180;
void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(11);
}

void loop() {
  for (pos1 = 0; pos1 <= 180; pos1 += 1) {    
    // in steps of 1 degree
    myservo2.write(pos2);              
    delay(15);                      
  }
  for (pos2 = 180; pos2 <= 0; pos2 -= 1) { 
    // in steps of 1 degree
    myservo2.write(pos2);              
    delay(15);                      
                         
  }
  
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
    myservo1.write(pos1);              
    delay(15);                       
  }
   for (pos2 = 0; pos2 <= 180; pos2 += 1) { 
    // in steps of 1 degree
    myservo2.write(pos2);              
    delay(15);                      
  }
}
