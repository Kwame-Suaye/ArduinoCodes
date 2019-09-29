String voice;

void allon(){
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
}
void alloff(){
  digitalWrite(10,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    if (c =='#') {break;}
    voice += c;
  }
    if (voice.length() > 0){  
      Serial.println(voice);

      if(voice == "*all active") {allon();}
 else if(voice == "*all deactive"){alloff();}


 else if(voice == "*11"){digitalWrite(10,HIGH);}  
 else if(voice == "*12"){digitalWrite(12,HIGH);}
 else if(voice == "*three on"){digitalWrite(13,HIGH);} 

 else if(voice == "*one off"){digitalWrite(10,LOW);}
  else if(voice == "*two off"){digitalWrite(12,LOW);}
  else if(voice == "*three off"){digitalWrite(13,LOW);}

 voice ="";     
  }
}
