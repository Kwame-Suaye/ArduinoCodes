void setup() {
  // put your setup code here, to run once
pinMode(4,OUTPUT);
pinMode(13,OUTPUT);      
pinMode(10,OUTPUT);
pinMode(7,OUTPUT);
pinMode(5,OUTPUT);
delay(5000);
digitalWrite(4,HIGH);
delay(2000);

}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH);
delay(150);
digitalWrite(13,LOW);
delay(50);
digitalWrite(10,HIGH);
delay(150);
digitalWrite(10,LOW);
delay(50);
digitalWrite(7,HIGH);
delay(150);
digitalWrite(7,LOW);
delay(50);
digitalWrite(5,HIGH);
delay(150);
digitalWrite(5,LOW);
delay(50);
digitalWrite(13,HIGH);
digitalWrite(10,HIGH);
digitalWrite(7,HIGH);
digitalWrite(5,HIGH);
delay(2000);
}
