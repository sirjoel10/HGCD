/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
 
int motorPin = 10;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt();
      analogWrite(motorPin, speed);
  }
} 
