#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int trigPin = 12;
const int echoPin = A0;
long duration;
int distance;

const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
const int i2c_addr = 0x3F;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

void setup() {

  lcd.begin(16,2);
  pinMode(12,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);
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
  digitalWrite(12,LOW);
  delay(200);
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);

  duration = pulseIn(A0,HIGH);
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
}
