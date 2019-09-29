String readvoice;

void setup() {
Serial.begin(9600);
pinMode(12,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() {
while (Serial.available())
{
  delay(10);
  char c =Serial.read();
  readvoice += c;
}
if (readvoice.length() > 0){
  Serial.println(readvoice);

  if (readvoice == "*red")
  {
    digitalWrite(12,HIGH);
    digitalWrite(10,LOW);
    delay(100);
  }
  else if (readvoice == "*red off")
  {
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    delay(100);
  }

  if (readvoice == "*green")
  {
    digitalWrite(12,LOW);
    digitalWrite(10,HIGH);
    delay(100);
  }

  else if (readvoice == "*green off")
  {
    digitalWrite(12,LOW);
    digitalWrite(10,LOW);
    delay(100);
  }
  readvoice="";
}

}
