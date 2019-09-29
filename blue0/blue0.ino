void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
}

void loop() {
 if(Serial.available()>0);
 {
  char data= Serial.read();
  switch(data)
  {
  case 'a': digitalWrite(8,HIGH);break;
  case 'd': digitalWrite(8,LOW);break;
  default : break;
 }
 Serial.println(data);
}
delay(50);
 }
