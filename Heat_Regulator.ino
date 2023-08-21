#include <DHT.h>
#define Type DHT11
#define RELAY A0
int sensePin = 2;
DHT HT(sensePin,Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;
int delayTime = 1000;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HT.begin();
pinMode(RELAY,OUTPUT);
delay(setTime);
}

void loop() {
  humidity =HT.readHumidity();
  tempC = HT.readTemperature();
  //tempF =HT.readTemperature(true);
  
 // digitalWrite(RELAY,HIGH);
 

  if(tempC<=40){
    digitalWrite(RELAY,HIGH);
    
    Serial.print(10);
    Serial.print(",");
    Serial.print(tempC);
    Serial.println(" ");
    }else{
      digitalWrite(RELAY,LOW);
      Serial.print(0);
      Serial.print(",");
      Serial.print(tempC);
      Serial.println(" ");}
  

}
