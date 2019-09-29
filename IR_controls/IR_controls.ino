#include <IRremote.h>
const int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int corner = 4                                                                                         ;
const int greenPin = 11;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(corner, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
}

void loop(){
  
    if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);

        switch(results.value){
          case 0x4EA240AE: //Keypad button "red"
          digitalWrite(corner, LOW);
         
          
          }

        switch(results.value){
          case 0xA32AB931: //Keypad button "green"
          digitalWrite(corner, HIGH);
          
          
          }

        irrecv.resume(); 
    }
}
