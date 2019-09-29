//AKA TECHNOLOGIES
const int MQ3=A0;
const int LED=2;
int value;
void setup() {
  Serial.begin(9600);
  pinMode(MQ3,INPUT);
  pinMode(LED,OUTPUT);

}

void loop() {
  value= analogRead(MQ3);
  Serial.println(value);
  delay(1000);

  if(value>=400){
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(LED,LOW);
  }

}
