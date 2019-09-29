int button = 10;
int val = 0;
int lighton = 0;
int pressed = 0;
int led = 12;
void setup() {
Serial.begin(9600);


}

void loop() {
  val = digitalRead(button);
  if(val==HIGH && lighton==LOW){
    pressed = (1-pressed);
    delay(1000);
  }
  lighton = val;
  if (pressed==HIGH){
    Serial.println("Light ON");
    digitalWrite(led,HIGH);
  }
  
}
