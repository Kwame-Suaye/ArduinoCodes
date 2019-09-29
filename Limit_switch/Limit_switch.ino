 int Limit01 = 2;
 int Limit02 = 3;
 int sensor = A0;
void setup() {
 pinMode(Limit01,INPUT);
 pinMode(Limit02,INPUT);
 pinMode(A0,INPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.begin(9600);

}

void loop() {
 sensor=analogRead(A0); 
 Serial.print("Sensor = ");
  Serial.println(sensor);
  delay(1000);

if(sensor==0){
  if(!digitalRead(Limit01)) {}
  digitalWrite(10,HIGH);

  else{
  digitalWrite(10,LOW);  
  }
}
if(sensor>=1){
  if(!digitalRead(Limit02)) {}
  digitalWrite(11,HIGH);
  
}
 
}
