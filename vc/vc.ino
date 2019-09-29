#include <IRremote.h>
const int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;
int ledpin = 12;
int pir = 7;
int val = 0;
bool light = false;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(pir,INPUT);
  pinMode(12, OUTPUT);
  
}

void loop(){
  val = digitalRead(pir);
  Serial.println(val);
  delay(1000);
  digitalWrite(ledpin,val);

  if (val == 1){
    digitalWrite(ledpin,HIGH);
  }
  else{
    digitalWrite(ledpin,LOW);
  }
  
    if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);

        switch(results.value){
          case 0x40BF48B7: //Keypad button "red"
          digitalWrite(12, LOW);
      
          }

        switch(results.value){
          case 0x40BFC837: //Keypad button "green"
          digitalWrite(12, HIGH);
          
          
          }

        irrecv.resume(); 
    }
}
