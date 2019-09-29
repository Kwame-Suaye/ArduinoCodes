#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial GPRS(7,8);
#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#define ONE_WIRE_BUS A2
#include <DallasTemperature.h>
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

  float Celcius=0;
  const int trigPin = A1;
  const int echoPin = A0;
  long duration;
  int distance;
  bool state = false;

   const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
  const int i2c_addr = 0x27;
  LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

void setup() {
  lcd.begin(16,2);
  pinMode(A1,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A2,INPUT_PULLUP);

  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  lcd.setCursor(0,1);
  delay(2000);
  lcd.clear();

  sensors.begin(); 

  sensors.requestTemperatures();
  Celcius=sensors.getTempCByIndex(0);
  GPRS.begin(9600);
  Serial.begin(9600);
  GPRS.println("AT");
  delay(1000);

}

void loop() {
  sensors.requestTemperatures();
  Celcius=sensors.getTempCByIndex(0);
 while(GPRS.available()){
   Serial.write(GPRS.read());
}
  digitalWrite(A1,LOW);
  delay(200);
  digitalWrite(A1,HIGH);
  delay(1000);
  digitalWrite(A1,LOW);
  duration = pulseIn(A0,HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("\t Temperature: ");
  Serial.println(Celcius);
  delay(1000);

  lcd.setCursor(1,0);
  lcd.print("OIL LEVEL INDICATOR");
  lcd.setCursor(1,1);
  lcd.print("TEMPERATURE: ");
  lcd.print(Celcius);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.scrollDisplayLeft();
  delay(50);

   if (distance >= 16 && state == false){
    sendSMS();
    state = true;
  }
delay(500);

 if (distance <= 5 && state == true) {
    sendSMS(String());
    state = false;
    }
}
void sendSMS(){
  Serial.print("minimum");
  GPRS.println("AT+CMGF=1");
  delay(500);
  GPRS.println("AT+CMGS=\"+233243127392\"");
  delay(500);

  GPRS.print("Hello, S/Station 1 transformer oil is at minimum level. Please refill. Thank you.....");
  GPRS.write(0x1a);
  delay(500);
}

void sendSMS(String message){
  Serial.print("maximum");
  GPRS.println("AT+CMGF=1");
  delay(500);
  GPRS.println("AT+CMGS=\"+233243127392\"");
  delay(500);

  GPRS.print("Hello, S/Station 1 transformer oil is at maximum level. Thank you..... ");
  GPRS.write(0x1a);
  delay(500);
}
