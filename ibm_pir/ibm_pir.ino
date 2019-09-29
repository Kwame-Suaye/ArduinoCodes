int relay = 13;
int pir = 12;
int val = 0;
void setup() {
  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pir);
  Serial.println(val);
  delay(1000);
  digitalWrite(relay, val);

  if (val == 1){
    digitalWrite(relay, HIGH);
  }
  else{
    digitalWrite(relay, LOW);
  }

}
