String voice;


void setup() {
Serial.begin(9600);
pinMode(12,OUTPUT); 
}


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

  if (voice == "so")
  {
    digitalWrite(12,HIGH);
  }
   if(voice == "dhoom")
 {
    digitalWrite(12,LOW);
}
  if (voice == "doom")
  {
    digitalWrite(12,LOW);
  }
  if (voice == "do")
  {
    digitalWrite(12,LOW);
  }
  
 }
     voice="";
     }
