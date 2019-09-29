int readsensor;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readsensor=analogRead(A1);
Serial.println(readsensor);
delay(1000);

if(readsensor>800){
  digitalWrite(11,HIGH);
  delay(1000);
}else{digitalWrite(11,LOW);
delay(1000);
}}
