#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
const int i2c_addr = 0x3F;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

int relay = 9;
int humidity_sensor = A1;

void setup() {
  lcd.begin(16,2);
  pinMode(A1,INPUT_PULLUP);
  pinMode(relay,OUTPUT);
  Serial.begin(9600);
  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  lcd.setCursor(0,1);
  delay(2000); 
  lcd.clear();
}

void loop() {
  lcd.setCursor(1,0);
  lcd.print("AUTOMATIC IRRIGATION SYSTEM");
  lcd.scrollDisplayLeft();
  delay(50);
  int Sensor = analogRead(A1);
  Serial.print("Moisture: ");
  Serial.println(Sensor);
  delay(1000); 

  if (Sensor >= 1000){
   digitalWrite(9,HIGH);
  }
  else{
  digitalWrite(9,LOW);
    } 

}
