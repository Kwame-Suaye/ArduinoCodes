 #include <SoftwareSerial.h>// Configure software serial port
  #include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  SoftwareSerial GPRS(7, 8);// Variable to store text message

  String textMessage;    // Create a variable to store pump state
  String pumpState = "HIGH";
  const int relay = 12;

  boolean state, lastState;
  const int trigPin = A1;
  const int echoPin = A0;
  long duration;
  int distance;
  const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
  const int i2c_addr = 0x3F;
  LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
void setup() {
  lcd.begin(16,2);
  pinMode(A1,OUTPUT);
  pinMode(A0,INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  

  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  lcd.setCursor(0,1);
  delay(2000);
  lcd.print("SUAYE TECHNOLOGIES");
  delay(2000);
  lcd.scrollDisplayLeft();
  delay(5000); 
  lcd.clear();
  
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);
  Serial.begin(9600); 
  GPRS.begin(9600);
  delay(1000);

 
  GPRS.print("AT+CMGF=1\r"); // AT command to set SIM800L to SMS mode
  delay(100);
  GPRS.print("AT+CNMI=2,2,0,0,0\r");    // Set module to send SMS data to serial out upon receipt 
  delay(100);
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
   if(distance <= 30){
    digitalWrite(relay,HIGH);
  }
  else{
    digitalWrite(relay,LOW);
  }
  
  lcd.setCursor(1,0);
  lcd.print("AUTOMATIC WATER LEVEL & CONTROLLER");
  lcd.scrollDisplayLeft();
  delay(50);
  
  if (distance <= 30 ){
  sendSMS();
  }
  delay(500);

  if(GPRS.available()>0){
    textMessage = GPRS.readString();
    Serial.print(textMessage);    
    delay(10);
  }
  if(textMessage.indexOf("ON")>=0){
    digitalWrite(relay, HIGH);
    pumpState = "on";
    Serial.println("Relay set to ON");  
    textMessage = "";   
  }
  if(textMessage.indexOf("OFF")>=0){
    digitalWrite(relay, LOW);
    pumpState = "off"; 
    Serial.println("Relay set to OFF");
    textMessage = ""; 
  }
}
void sendSMS(String message){
  GPRS.print("AT+CMGF=1\r");     // AT command to set SIM900 to SMS mode 
  delay(100);
  GPRS.println("AT+CMGS=\"+233553577854\""); 
  delay(100);
  
  GPRS.println(message); // Send the SMS
  delay(100);
 
  GPRS.println((char)26); 
  delay(100);
  GPRS.println();
  delay(5000);  
}
void sendSMS(){
  Serial.print("Water level is low ");
  GPRS.println("AT+CMGF=1");

  delay(100);
  GPRS.println("AT+CMGS=\"+233545568861\"");
  delay(100);

  GPRS.print("Water level is low ");
  GPRS.println((char)26); 
  delay(100);
  GPRS.println();
  delay(5000); 
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
