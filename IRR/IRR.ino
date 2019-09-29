int sensor = 0;
int MOTOR = 4;

void setup() {
    Serial.begin(9600);
     pinMode(MOTOR,OUTPUT);
     pinMode(sensor,INPUT);
}
 

 
void loop() {
    int moisture = analogRead(sensor);
 
    Serial.println(moisture);
 
    if(moisture > 70) {
        digitalWrite(MOTOR, LOW);
    } else   {
        digitalWrite(MOTOR, HIGH);
    }
    delay(100);
}

