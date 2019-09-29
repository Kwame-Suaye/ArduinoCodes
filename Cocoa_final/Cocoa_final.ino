 #include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 #include <dht.h>
 #define datapin A0
 dht DHT;
 int RainSensor = A1;
 int humidity = A0;
 const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
 const int i2c_addr = 0x3F;
 LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

 #define OPEN 2       // Open
 #define CLOSE  3    // close
 
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(A0,INPUT);         //humidity sensor
  pinMode(A1,INPUT);        //rainsensor
  pinMode(OPEN,INPUT_PULLUP);       //open
  pinMode(CLOSE,INPUT_PULLUP);      //close
  pinMode(7,OUTPUT);       //open
  pinMode(8,OUTPUT);      //close
  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  delay(2000);
  lcd.clear();

}

void loop() {
  int lidopen = digitalRead(2);
  int lidclose = digitalRead(3);
  int readData = DHT.read11(A0);
  RainSensor = analogRead(A1);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\t Humidity = ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("\t RainSensor = ");
  Serial.println(RainSensor);
  delay(1000);

  lcd.setCursor(1,0);
  lcd.print("AUTOMATED COCOA BASKET");
  lcd.setCursor(1,1);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print("% ");
  lcd.scrollDisplayLeft();
  delay(50);

  //Rain
  if(RainSensor > 30){
    digitalWrite(8,HIGH);
  }
  else{
    digitalWrite(8,LOW);
  }

  //MANUAL
  if(lidopen == LOW){     //OPEN
    digitalWrite(7,HIGH);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("OPENING.......");
  }
  else{
    digitalWrite(7,LOW);
  }
  if(lidclose == LOW){  //CLOSE
    digitalWrite(8,HIGH);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("CLOSING.......");
  }
  else{
    digitalWrite(8,LOW);
  }
  
}
