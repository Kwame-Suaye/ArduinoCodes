#include <dht.h>
 
#define datapin 8

dht DHT;

void setup() {
  pinMode(8,INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int readData = DHT.read11(datapin);
  float t = DHT.temperature;
  float h = DHT.humidity;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("\t Humidity = ");
  Serial.print(h);
  Serial.println(" %");
  delay(2000);    
}
