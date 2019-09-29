const int trigPin = 9;
const int echoPin = A0;
long duration;
int distance;

void setup() {
  pinMode(9,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  digitalWrite(9,LOW);
  delay(200);

  digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);

  duration = pulseIn(A0,HIGH);
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance <= 60)
  {
    digitalWrite(10,HIGH);
  }
    else{
     digitalWrite(10,LOW);
   
   }

  }
