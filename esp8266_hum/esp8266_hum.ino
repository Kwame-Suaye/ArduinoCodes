#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

DHT dht;
void setup() {
  pinMode(D0, INPUT);
  Serial.begin(9600);

}

void loop() {
  int chk = DHT.read11(D0);
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
