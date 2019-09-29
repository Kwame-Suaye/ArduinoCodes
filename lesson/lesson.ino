void setup() {
  
pinMode(12,OUTPUT);      
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(12,HIGH);
delay(100);
digitalWrite(12,LOW);
delay(100);
digitalWrite(10,HIGH);
delay(100);
digitalWrite(10,LOW);
delay(100);
}
