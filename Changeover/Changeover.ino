int ECG = A0;
int Generator = A1;
int 
void setup() {
 pinMode(ECG,INPUT);
 pinMode(Generator,INPUT);
 pinMode(12,OUTPUT);
 pinMode(10,OUTPUT);
 Serial.begin(9600); 
 delay(1000);
}

void loop() {
 ECG=analogRead(A0);
 Generator=analogRead(A1);

 Serial.print("ECG = ");
 Serial.print(ECG);
 Serial.print("\t Generator = ");
 Serial.println(Generator); 
 delay(1000);


 if(ECG>1){
  digitalWrite(12,HIGH);
 }

 if(ECG==0){
  digitalWrite(12,LOW);
 }
 else{
  digitalWrite(10,HIGH);
 }
 }
}
