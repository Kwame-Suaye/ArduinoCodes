#include <IRremote.h>
const int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int ledpin = 12;
int pir = 7;
int val = 0;
bool light = false;

#include <LiquidCrystal.h>
int RS=A5, E=A4, D4=A3, D5=A2, D6=A1, D7=A0;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup(){
  lcd.begin(16, 2);
  delay(50);
  lcd.setCursor(0, 0);
  lcd.print("Tech Leads Ghana");
  delay(5000);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Smart Energy Saver");
  delay(50);
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(pir,INPUT);
  pinMode(12, OUTPUT);
  
}

void loop(){
  lcd.setCursor(1,1);
  lcd.print("Power Consumed: ");
  lcd.println("KW ");
  lcd.scrollDisplayLeft();
  delay(50);
  val = digitalRead(pir);
  Serial.println(val);
  delay(1000);
      
    if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
    }

     if(val == 1){
      digitalWrite(12,HIGH);
     }
     else{
      digitalWrite(12,LOW);
     }

     
     if(results.value == 0x40BF48B7 && val == 1  && light == false)
    {
      digitalWrite(12,LOW);
      }
   
    
      if(results.value == 0x40BFC837 && val == 1)
    {
      digitalWrite(12,HIGH);
      }
   
   
        
        

        irrecv.resume(); 
    }
