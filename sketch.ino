int switchState=1;
const int sPin=A0;
const int ledPin=10;
const int switchPin=2;
int sensorData=0;
void setup()
{
 Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 pinMode(switchPin,INPUT);
}
void loop(){
  int switchRead;
  switchRead=digitalRead(switchPin);
  if(switchRead==1){
    switchState++;
    delay(500);
  }
  sensorData=analogRead(sPin);
  Serial.println(sensorData);
  delay(100);
  
  Serial.println(switchState);
  if (switchState%2==0){
    if(sensorData>400){
       for(int i=1;i<6;i++){
         analogWrite(ledPin,102);
         delayMicroseconds(500);
       }
  }
  switchRead=digitalRead(switchPin);
  if(switchRead==1){
    switchState++;
    delay(500);
  }
  if (switchState%2==0){
    if(sensorData>400){
      for(int i=1;i<6;i++){
         analogWrite(ledPin,255);
         delayMicroseconds(100);
      }
    }
  }
  else{ 
    digitalWrite(ledPin,LOW);
  }
}
}
