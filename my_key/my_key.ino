#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; 
byte colPins[COLS] = {6,7,8}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.println("Robojax 4x3 keypad");
  pinMode(9, OUTPUT);
}
  
void loop(){
  char key = keypad.getKey();
   if (key){
    Serial.println(key);
  } 
  
  if (key =='2'){
    digitalWrite(9, HIGH);
  } 
  else{
    digitalWrite(9, LOW);
  }

}
