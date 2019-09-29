int overspeedsensor;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeated
overspeedsensor=analogRead(A0);
Serial.println(overspeedsensor);
delay(1000);
}
