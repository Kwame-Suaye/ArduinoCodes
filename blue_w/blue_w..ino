int state = 0;

void setup() {
pinMode(12,OUTPUT);
digitalWrite(12,LOW);
Serial.begin(9600);

}

void loop() {
if(Serial.available() > 0){
 state = Serial.read();
}

if (state== '0') {
  digitalWrite(12,LOW);
  Serial.println("LED: OFF");
  state = 0;
}
else if (state == '1'){
  digitalWrite(12,HIGH);
  Serial.println("LED: ON");
  state = 0;
}
}
