#include <OneWire.h>
#include <DallasTemperature.h>

int temp_sensor = 5;
float temperature = 0;
OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);

void setup(){
  pinMode(5,INPUT_PULLUP);
  Serial.begin(9600);
  
  sensors.begin();
}
void loop(){
  //Serial.print("Requesting Temperature from sensors");
  sensors.requestTemperatures();
  //Serial.println("Done");
  temperature = sensors.getTempCByIndex(0);

  Serial.print("Temperature is ");
  Serial.println(temperature);
  delay(1000);
  
  }
