/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
int motorPin = 3;
int flexSensorPin = A0;
int hall1SensorPin = A3;
int hall2SensorPin = A2;
int speed = 200;
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, speed);
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  int flexValue = analogRead(flexSensorPin);
  int hall1Value = analogRead(hall1SensorPin);
  int hall2Value = analogRead(hall2SensorPin);
  Serial.print("flexSensor val: ");
  Serial.println(flexValue);
  Serial.print("hall1Sensor val: ");
  Serial.println(hall1Value);
  Serial.print("hall2Sensor val: ");
  Serial.println(hall2Value);
  delay(1000);
} 
