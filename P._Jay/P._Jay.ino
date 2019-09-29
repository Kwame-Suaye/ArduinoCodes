#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int trigPin = 9;
const int echoPin = A0;
long duration;
int distance;
const int en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
const int i2c_addr = 0x3F;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);


void setup() {
  lcd.begin(16,2);
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);//Far
  pinMode(11,OUTPUT);//Closer
  pinMode(12,OUTPUT);//Danger
  Serial.begin(9600);
  
  

}

void loop() {
  digitalWrite(9,LOW);
  delay(200);

  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  lcd.setCursor(1,0);
  lcd.print("CAR REAR DISTANCE CHECKER ");
  lcd.setCursor(1,1);
  lcd.print("Distance = ");
  lcd.print(distance);
  lcd.scrollDisplayLeft();
  delay(50);
  

  duration = pulseIn(A0,HIGH);
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance >=150){
    digitalWrite(10,HIGH);}
    else{
      digitalWrite(10,LOW);
    }
  
}
