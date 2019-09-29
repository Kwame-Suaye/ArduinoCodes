int readsensor;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readsensor=analogRead(A0);
Serial.println(readsensor);
delay(100);

if(readsensor>1){
  digitalWrite(12,HIGH);
  delay(1000);
}else{digitalWrite(12,LOW);
delay(1000);
}}
