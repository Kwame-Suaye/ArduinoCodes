int sensor

void setup() {
   pinMode(12,OUTPUT);
   pinMode(A0,INPUT);
   Serial.print(9600);
}

void loop() {
 moisture = analogRead(A0);
  

}
