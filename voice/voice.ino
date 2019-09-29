String voice;

#define GREEN 12
#define BLUE 11
#define RED 10

void setup() {
Serial.begin(9600);
pinMode(GREEN,OUTPUT);
pinMode(BLUE,OUTPUT);
pinMode(RED,OUTPUT); 
}

int redVal;
int greenVal;
int blueVal;


void loop() {
 while (Serial.available())
 {
  delay(10);
  char c = Serial.read();
  if (c == '#') {break;}
  voice += c;
 }

 if (voice.length() > 0){
  Serial.println(voice);

  if (voice == "red")
  {
    digitalWrite(RED,HIGH);
  }
   if(voice == "green")
 {
    digitalWrite(GREEN,HIGH);
}
    if (voice == "red off")
    {
    digitalWrite(RED,LOW);
    }
    if (voice == "green off")
    {
      digitalWrite(GREEN,LOW);
    }
    
    if(voice == "good night")
    {
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
    }  
    }
     voice="";
     }
    
