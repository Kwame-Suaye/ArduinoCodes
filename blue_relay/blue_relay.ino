int inByte = 0;

void setup() {
 pinMode(12,OUTPUT);
Serial.println(9600);
}

void loop()
{ 
 inByte = Serial.read();
 
 if (inByte == 'A')
 {
  digitalWrite(12,HIGH);
  Serial.print('A');
  inByte = 0;
 }
}
