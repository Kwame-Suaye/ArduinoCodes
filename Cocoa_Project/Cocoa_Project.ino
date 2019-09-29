 #include <dht.h>
 dht DHT;
 int Limit01 = 2;
 int Limit02 = 3;
 int RainSensor = A3;
 int LDR1 = A1;   //morning
 int LDR2 = A2;   //evening


void setup() {
  pinMode(A0,INPUT);     //humidity sensor
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(Limit01,INPUT);
  pinMode(Limit02,INPUT);
  pinMode(12,OUTPUT);       //open
  pinMode(13,OUTPUT);       //close
  Serial.begin(9600);

}

void loop() {
  int readData = DHT.read11(A0);
  RainSensor=analogRead(A1);
  LDR1=analogRead(A2);
  LDR2=analogRead(A3);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\t Humidity = ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("\t RainSensor = ");
  Serial.print(RainSensor);
  Serial.print("\t LDR1 = ");
  Serial.print(LDR1);
  Serial.print("\t LDR2 = ");
  Serial.println(LDR2);
  delay(2000);
  
  //rainy weather
  if(DHT.humidity>=90){
    digitalWrite(13,HIGH);
  }
  else {
    digitalWrite(13,LOW);
  }
  if(RainSensor>=100){
    digitalWrite(13,HIGH);
  }
  else {
    digitalWrite(13,LOW);
  } 
  

  //morning
      
}
