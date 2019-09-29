#include <OneWire.h>
#include <DallasTemperature.h>
int greenLedPin = 2;
int yellowLedPin = 3;
int redLedPin = 4;

int temp_sensor = 5;

float temperature = 0;
int lowerLimit = 15;
int higherLimit = 35;
OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);
void setup(void){
  Serial.begin(9600);
  
  //Setup the LEDS to act as outputs
  pinMode(redLedPin,OUTPUT);
  pinMode(greenLedPin,OUTPUT);
  pinMode(yellowLedPin,OUTPUT);
  
  sensors.begin();
}

digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  
  Serial.print("Temperature is ");
  Serial.print(temperature);
