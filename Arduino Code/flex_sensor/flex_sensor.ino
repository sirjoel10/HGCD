
//input
int flexSensorPin = A0; //analog pin 0
// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;
int sensorStart = 0;
// maximum sensor value
int deg = 0;
  
void setup(){
  Serial.begin(9600);
  //callib();
}

void loop(){
  int sensorValue = analogRead(flexSensorPin); 
  //deg = map(sensorValue, sensorMin, sensorMax, 0, 100);
  //Serial.print("deg: ");
  //Serial.println(deg);
  Serial.print("Sensor val: ");
  Serial.println(sensorValue);
  delay(250);
}


void callib(){
 // calibrate during the first five seconds 
 Serial.println("Callibration Start");
 bool nextop = false;
 unsigned long startTime1 = millis();
 Serial.println("Stretch out");
 while (millis()-startTime1< 10000){
  sensorStart=analogRead(flexSensorPin);
 }
 Serial.println("Move fingers");
 
 unsigned long startTime2 = millis();
 while (millis()-startTime2< 10000){
   sensorValue = sensorStart - analogRead(flexSensorPin);
   // record the maximum sensor value
   if (sensorValue > sensorMax) {
     sensorMax = sensorValue;
   }

   // record the minimum sensor value
   if (sensorValue < sensorMin) {
     sensorMin = sensorValue;
   }
 }
 Serial.println("Callibration Finished");
}


