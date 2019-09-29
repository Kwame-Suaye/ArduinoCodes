int readsensor1;
int readsensor2;
void setup() {
// put your setup code here, to run once:
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
Serial.begin(9600);
delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  readsensor1=analogRead(A0);
  readsensor2=analogRead(A1);
 Serial.print("readsensor1 = ");
  Serial.print(readsensor1);
  Serial.print("\t readsensor2 = ");
  Serial.println(readsensor2);
  delay(1000);

  if(readsensor1==0){
    digitalWrite(11,HIGH);
  }
  else{digitalWrite(11,LOW);
  }

  if(readsensor2>1){
    digitalWrite(12,HIGH);
    
  }
  else{digitalWrite(12,LOW);

  }
  }
  
