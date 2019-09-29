#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <dht.h>

const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
const int i2c_addr = 0x3F;
Servo myservo1;  // create servo object to control
Servo myservo2;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

#define datapin A0
dht DHT;

int pos = 165;    // initial angle  for servo
int angleStep = 1;//Speed of Servo

#define OPEN 12   // Open
#define CLOSE  2  // close
int RainSensor = A1;
int LDR1 = A2;   //morning
int LDR2 = A3;   //evening


void setup() {
lcd.begin(16,2); 
pinMode(A0,INPUT_PULLUP);//Humidity Sensor
pinMode(A1,INPUT_PULLUP);//Rain Sensor
pinMode(A2,INPUT_PULLUP);//LDR(Morning)
pinMode(A3,INPUT_PULLUP);//LDR(Evening)
pinMode(OPEN,INPUT_PULLUP);
pinMode(CLOSE,INPUT_PULLUP);
pinMode(A0,INPUT_PULLUP);


myservo1.attach(11);// attaches the servo on pin 9 to the servo object
myservo2.attach(9);
Serial.begin(9600);
lcd.setCursor(3,0);
lcd.print("WELCOME...");
lcd.setCursor(3,1);
delay(2000);
lcd.print("TECHLEADSGH");
delay(5000); 
lcd.clear();
}


void loop() {
  int readData = DHT.read11(A0);
  RainSensor=analogRead(A1);
  LDR1=analogRead(A2);
  LDR2=analogRead(A3);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\t Humidity = ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("\t RainSensor = ");
  Serial.print(RainSensor);
  Serial.print("\t LDR1 = ");
  Serial.print(LDR1);
  Serial.print("\t LDR2 = ");
  Serial.println(LDR2);
  delay(2000);
  lcd.setCursor(1,0);
  lcd.print("AUTOMATED COCOA PROJECT");

  lcd.setCursor(1,1);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print("% ");
  lcd.scrollDisplayLeft();
    //lcd.setCursor(0,1);
  delay(50);
  while(digitalRead(CLOSE) == LOW){   //Close
    if (pos > 15 && pos <= 165) {   
      pos = pos - angleStep;
       if(pos < 15){
        pos = 15;
       }else{
      myservo1.write(pos); // move the servo to desired angle
      myservo2.write(pos);
      Serial.print("Moved to: ");
      Serial.print(pos);   // print the angle
      Serial.println(" degree");
     }}
    delay(100); // waits for the servo to get there
  }
    while(digitalRead(OPEN) == LOW){      //Open
    if (pos >= 15 && pos <= 165) {
      pos = pos + angleStep;
      if(pos > 165){
       pos = 165;
       }else{
      myservo1.write(pos); // move the servo to desired angle
      myservo2.write(pos);
      Serial.print("Moved to: ");
      Serial.print(pos);   // print the angle
      Serial.println(" degree");
       }}
  delay(100);
  }
  
  //Morning
  /*while(analogRead(A1) ==1 ){      //Open
    if (angle >= 15 && angle <= 180) {
      angle = angle + angleStep;
      if(angle > 180){
        angle = 180;
       }
    else{
      myservo1.write(angle);
      myservo2.write(angle);
 }}
  //break;
  }

  //Evening
   while(analogRead(A2) == 0){   //Close
    if (angle > 15 && angle <= 180) {   
      angle = angle - angleStep;
       if(angle < 15){
        angle = 15;
       }else{
      myservo1.write(angle);
      myservo2.write(angle);
      }}
       delay(100); // waits for the servo to get there
  }*/
}
