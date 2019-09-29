#include <IRremote.h>

const int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int light = 3;
const int corner = 4;

void setup() {
Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(light, OUTPUT);
  pinMode(corner, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() {
if (irrecv.decode(&results)){
  Serial.println(results.value, HEX);

  switch(results.value){
  case 0x807FA857: //Keypad button "red"
  digitalWrite(corner, HIGH);
         }
  switch(results.value){
  case 0x807F807F: //Keypad button "green"
  digitalWrite(corner, LOW);
          
         }
  switch(results.value){
  case 0x807F817F: //Keypad button "green"
  digitalWrite(light, HIGH);
          }
          
  switch(results.value){
  case 0x807F58A7: //Keypad button "green"
  digitalWrite(light, LOW);
          }                    

 digitalWrite(12,HIGH);
delay(1000);
//digitalWrite(12,LOW);
//delay(1000);
digitalWrite(11,HIGH);
delay(1000);
//digitalWrite(11,LOW);
//delay(1000);
digitalWrite(10,HIGH);
delay(1000);
//digitalWrite(10,LOW);
//delay(1000);
digitalWrite(9,HIGH);
delay(1000);
//digitalWrite(9,LOW);
//delay(1000);
digitalWrite(8,HIGH);
delay(1000);
//digitalWrite(8,LOW);
//delay(1000);

//second
//digitalWrite(8,HIGH);
//delay(1000);
digitalWrite(8,LOW);
delay(1000);
//digitalWrite(9,HIGH);
//delay(1000);
digitalWrite(9,LOW);
delay(1000);
//digitalWrite(10,HIGH);
//delay(1000);
digitalWrite(10,LOW);
delay(1000);
digitalWrite(11,LOW);
delay(1000);
//digitalWrite(11,HIGH);
//delay(1000);
//digitalWrite(12,HIGH);
//delay(1000);
digitalWrite(12,LOW);
delay(1000);

//third
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,LOW);
delay(100);
digitalWrite(11,HIGH);
delay(100);
digitalWrite(11,LOW);
delay(100);
digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(100);
digitalWrite(9,HIGH);
delay(100);
digitalWrite(9,LOW);
delay(100);
digitalWrite(8,HIGH);
delay(100);
digitalWrite(8,LOW);
delay(100);

//fourth
digitalWrite(8,HIGH);
delay(100);
digitalWrite(8,LOW);
delay(100);
digitalWrite(9,HIGH);
delay(100);
digitalWrite(9,LOW);
delay(100);
digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(100);
digitalWrite(11,HIGH);
delay(100);
digitalWrite(11,LOW);
delay(100);
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,LOW);
delay(100);

//fifth
digitalWrite(8,HIGH);
delay(100);
digitalWrite(8,LOW);
delay(100);
digitalWrite(9,HIGH);
delay(100);
digitalWrite(9,LOW);
delay(100);
digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(200);
digitalWrite(11,HIGH);
delay(200);
digitalWrite(11,LOW);
delay(200);
digitalWrite(12,HIGH);
delay(200);
digitalWrite(12,LOW);
delay(200);

//sith
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);

//7
digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

//8
digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

//9
digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

//10
digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);


digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);

digitalWrite(8,HIGH);
delay(20);
digitalWrite(8,LOW);
delay(20);
digitalWrite(9,HIGH);
delay(20);
digitalWrite(9,LOW);
delay(20);
digitalWrite(10,HIGH);
delay(20);
digitalWrite(10,LOW);
delay(20);
digitalWrite(11,HIGH);
delay(20);
digitalWrite(11,LOW);
delay(20);
digitalWrite(12,HIGH);
delay(20);
digitalWrite(12,LOW);
delay(20);
  irrecv.resume();
} 
}

        
    
