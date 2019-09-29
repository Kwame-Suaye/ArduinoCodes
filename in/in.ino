void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  Serial.begin(9600);

}

void loop() {
  int sensor=analogRead(A1);
  Serial.print("Morning = ");
  Serial.println(sensor);
  //Serial.print("Evening = ");
  //Serial.println(sensor1);
  delay(1000);

}
