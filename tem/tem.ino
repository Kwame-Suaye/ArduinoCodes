#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS A2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float Celcius=0;
float Fahrenheit=0;
void setup()
{
pinMode(A2,INPUT_PULLUP);  
Serial.begin(9600);
sensors.begin();
}
void loop()
{
sensors.requestTemperatures();
Celcius=sensors.getTempCByIndex(0);
Fahrenheit=sensors.toFahrenheit(Celcius);
Serial.print(" C ");
Serial.print(Celcius);
Serial.print(" F ");
Serial.println(Fahrenheit);
delay(1000);
}
