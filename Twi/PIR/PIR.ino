//AKA TECHNOLOGIES
int pirSensor = 8;
int relaypin = 11;
int Value;

void setup() {
pinMode(INPUT,A0);
pinMode(OUTPUT,2);
Serial.begin(9600);
}

void loop() {
Value = analogRead(pirSensor);
Serial.println(pirSensor);
delay(1000);
 if(Value > 1) {
  digitalWrite(relaypin,HIGH);
 }

}
