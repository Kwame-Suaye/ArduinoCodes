  #include <SoftwareSerial.h>// Configure software serial port
  //#include <Wire.h> 
  #include <LiquidCrystal_I2C.h>
  SoftwareSerial GPRS(7, 8);// Variable to store text message
  //#include <OneWire.h>
  #//include <DallasTemperature.h>

  /*int temp_sensor = 5;
  float temperature = 0;
  OneWire oneWirePin(temp_sensor);
  DallasTemperature sensors(&oneWirePin);*/
  String textMessage;    // Create a variable to store pump state
  String pumpState = "HIGH";
  const int trigPin = A1;
  const int echoPin = A0;
  long duration;
  int distance;
  bool pumpStarted = false;
  
  const int en =2, rw = 1, rs = 0, d4 = 4, d5 = 5,  d6 = 6,  d7 = 7, bl = 3;
  const int i2c_addr = 0x27;
  LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);
void setup() {
  lcd.begin(16,2);
  pinMode(A1,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(5,INPUT_PULLUP);

  //sensors.begin();

  lcd.setCursor(3,0);
  lcd.print("WELCOME...");
  lcd.setCursor(0,1);
  delay(2000);
  lcd.clear();

  //sensors.requestTemperatures();
  //temperature = sensors.getTempCByIndex(0);
  
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
  //Serial.print("\t Temperature: ");
  //Serial.println(temperature);
  delay(1000);
  
  lcd.setCursor(1,0);
  lcd.print("OIL LEVEL INDICATOR");
  lcd.setCursor(0,1);
  lcd.print("TEMPERATURE: ");
  //lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");
  lcd.scrollDisplayLeft();
  delay(50);
  
  if (distance >= 40 && pumpStarted == false){
    sendSMS();
    pumpStarted = true;
  }

  if (distance <= 15 && pumpStarted == true) {
    sendSMS(String());
    pumpStarted = false;
    }
 
  if(GPRS.available()>0){
    textMessage = GPRS.readString();
    Serial.print(textMessage);    
    delay(10);
  }
  /*if(textMessage.indexOf("ON")>=0){
    pumpState = "on";
    Serial.println("Relay set to ON");  
    textMessage = "";   
  }
  if(textMessage.indexOf("OFF")>=0){
    pumpState = "off"; 
    Serial.println("Relay set to OFF");
    textMessage = ""; 
  }*/
}
void sendSMS(){
  Serial.print("minimum level");
  delay(100);
  GPRS.println("AT+CMGS=\"+233553577854\"");
  delay(100);

  GPRS.print("Oil is at it's minimum level");
  GPRS.println((char)26); 
  delay(100);
  GPRS.println();
  delay(2000); 
}
void sendSMS(String message){
  delay(100);
  GPRS.println("AT+CMGS=\"+233553577854\""); 
  delay(100);
  
  GPRS.print("Oil is at it's maximum level"); // Send the SMS
  delay(100);
 
  GPRS.println((char)26); 
  delay(100);
  GPRS.println();
  delay(2000);  
} 
