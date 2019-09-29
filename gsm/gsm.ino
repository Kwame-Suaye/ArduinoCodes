#include <SoftwareSerial.h>

// Configure software serial port
SoftwareSerial GPRS(7, 8);

// Variable to store text message
String textMessage;

// Create a variable to store Lamp state
String lampState = "HIGH";

// Relay connected to pin 12
const int relay = 12;

void setup() {
  
  pinMode(relay, OUTPUT);

  // By default the relay is off
  digitalWrite(relay, HIGH);
  
  // Initializing serial commmunication
  Serial.begin(9600); 
  GPRS.begin(9600);

  // Give time to your GSM shield log on to network
  delay(1000);

  // AT command to set SIM800L to SMS mode
  GPRS.print("AT+CMGF=1\r"); 
  delay(100);
  // Set module to send SMS data to serial out upon receipt 
  GPRS.print("AT+CNMI=2,2,0,0,0\r");
  delay(100);
}

void loop(){
  if(GPRS.available()>0){
    textMessage = GPRS.readString();
    Serial.print(textMessage);    
    delay(10);
  } 
  if(textMessage.indexOf("ON")>=0){
    // Turn on relay and save current state
    digitalWrite(relay, HIGH);
    lampState = "on";
    Serial.println("Relay set to ON");  
    textMessage = "";   
  }
  if(textMessage.indexOf("OFF")>=0){
    // Turn off relay and save current state
    digitalWrite(relay, LOW);
    lampState = "off"; 
    Serial.println("Relay set to OFF");
    textMessage = ""; 
  }
  if(textMessage.indexOf("STATE")>=0){
    String message = "Lamp is " + lampState;
    sendSMS(message);
    Serial.println("Lamp state resquest");
    textMessage = "";
  }
}  

// Function that sends SMS
void sendSMS(String message){
  // AT command to set SIM900 to SMS mode
  GPRS.print("AT+CMGF=1\r"); 
  delay(100);

  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  GPRS.println("AT+CMGS=\"+233553577854\""); 
  delay(100);
  // Send the SMS
  GPRS.println(message); 
  delay(100);

  // End AT command with a ^Z, ASCII code 26
  GPRS.println((char)26); 
  delay(100);
  GPRS.println();
  // Give module time to send SMS
  delay(5000);  
}
