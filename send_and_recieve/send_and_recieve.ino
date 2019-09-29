  #include <SoftwareSerial.h>// Configure software serial port
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  SoftwareSerial GPRS(7, 8);// Variable to store text message
  String textMessage;    // Create a variable to store pump state
  String pumpState = "HIGH";
  const int relay = 12;
  const int trigPin = A1;
  const int echoPin = A0;
  long duration;
  int distance;
  bool pumpStarted = false;
  
  const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
  const int i2c_addr = 0x3F;
  LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
void setup() {
  lcd.begin(16,2);
  pinMode(A1,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);

  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  lcd.setCursor(0,1);
  delay(2000); 
  lcd.clear();
  
  pinMode(relay,OUTPUT);
  digitalWrite(relay,LOW);
  GPRS.begin(9600);
  Serial.begin(9600); 
  GPRS.println("AT");
  delay(1000);

  GPRS.print("AT+CMGF=1\r"); // AT command to set SIM800L to SMS mode
  delay(100);
  GPRS.print("AT+CNMI=2,2,0,0,0\r");    // Set module to send SMS data to serial out upon receipt 
  delay(100);
  digitalWrite(2,HIGH);
  }

void loop() {
  
  digitalWrite(A1,LOW);
  delay(200);
  digitalWrite(A1,HIGH);
  delay(1000);
  digitalWrite(A1,LOW);
  duration = pulseIn(A0,HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance  <= 3){
  digitalWrite(relay,LOW);
  }
  
  lcd.setCursor(1,0);
  lcd.print("WATER LEVEL INDICATOR & CONTROLLER");
  lcd.scrollDisplayLeft();
  delay(50);
  
  if (distance >= 15 && pumpStarted == false){
    sendSMS();
    pumpStarted = true;
    digitalWrite(relay,HIGH);
  }

  if (distance <= 3 && pumpStarted == true) {
    digitalWrite(relay,LOW);
    sendSMS(String());
    pumpStarted = false;
  }
  if (distance >= 15){
   lcd.setCursor(1,1);
   lcd.print("         ");
   lcd.setCursor(1,1);
   lcd.print("WATER LEVEL IS LOW");
  }
  if (distance <= 13){
   digitalWrite(3,HIGH);
  }
   else{
   digitalWrite(3,LOW);
    }
  if (distance <= 10){
   digitalWrite(4,HIGH);
   lcd.setCursor(1,1);
   lcd.print("        ");
   lcd.setCursor(1,1);
   lcd.print("WATER LEVEL IS NORMAL");
  }
   else{
    digitalWrite(4,LOW);
 }
  if (distance <= 6){
   digitalWrite(5,HIGH);
  }
  else{
  digitalWrite(5,LOW);
    }
 if (distance <= 3){
  digitalWrite(6,HIGH);
  lcd.setCursor(1,1);
  lcd.print("        ");
  lcd.setCursor(1,1);
  lcd.print("WATER IS FULL");
  }
  else{
  digitalWrite(6,LOW);
    }
  if(GPRS.available()>0){
    textMessage = GPRS.readString();
    Serial.print(textMessage);    
    delay(10);
  }
  if(textMessage.indexOf("Start Pump")>=0){
    digitalWrite(relay, HIGH);
    pumpState = "on";
    Serial.println("ON");  
    textMessage = "";   
  }
  if(textMessage.indexOf("Stop Pump")>=0){
    digitalWrite(relay, LOW);
    pumpState = "off"; 
    Serial.println("OFF");
    textMessage = ""; 
  }
}
void sendSMS(){
  Serial.print("Low");
  GPRS.println("AT+CMGF=1");
  delay(500);
  GPRS.println("AT+CMGS=\"+233556594562\"");
  delay(500);

  GPRS.print("Hello, your water level is at minimum. But i have just started the pump to fill the tank. Thank you.");
  GPRS.write(0x1a);
  delay(500); 
}
void sendSMS(String message){
  Serial.print("Full");
  GPRS.println("AT+CMGF=1"); 
  delay(500);
  GPRS.println("AT+CMGS=\"+233556594562\""); 
  delay(500);
  
  GPRS.print("Hello, your water level is at maximum. But dont bother your self, I have already switched off the pump. Thank you."); // Send the SMS
  GPRS.write(0x1a);
  delay(500);
 
  
}
