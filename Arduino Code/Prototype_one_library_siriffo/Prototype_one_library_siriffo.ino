/*
  LiquidCrystal Library - display() and noDisplay()

  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver. There are many of them out there, and you
  can usually tell them by the 16-pin interface.

  This sketch prints "Hello World!" to the LCD and uses the
  display() and noDisplay() functions to turn on and off
  the display.

  The circuit:
   LCD RS pin to digital pin 12
   LCD Enable pin to digital pin 11
   LCD D4 pin to digital pin 5
   LCD D5 pin to digital pin 4
   LCD D6 pin to digital pin 3
   LCD D7 pin to digital pin 2
   LCD R/W pin to ground
   10K resistor:
   ends to +5V and ground
   wiper to LCD VO pin (pin 3)

  Library originally added 18 Apr 2008
  by David A. Mellis
  library modified 5 Jul 2009
  by Limor Fried (http://www.ladyada.net)
  example added 9 Jul 2009
  by Tom Igoe
  modified 22 Nov 2010
  by Tom Igoe
  modified 7 Nov 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay

*/

// include the library code:
#include <LiquidCrystal.h>


#ifndef FlexSensor.h
#include "flexSensor.h"
#endif



#ifndef Hallsensor.h
#include "Hallsensor.h"
#endif

#ifndef Vibrator.h
#include "Vibrator.h" 
#endif

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int text;
int maxVal, minVal;


FlexSensor flex(A0);
Hallsensor hall1(A2);
Hallsensor hall2(A3);
Vibrator vib(3);


void setup() {
  // set up the LCD's number of columns and rows:
  //lcd.begin(16, 2);
  Serial.begin(9600);
  vib.setSpeed(0);
  flex.calib();
  vib.setMaxMinVal(flex.getMax(), flex.getMin());


  
}

 
void loop() {

//Serial.println(vib.setScaledSpeed(flex.getVal()));

/*Serial.println("max = " ); 
Serial.println(flex.getMax());
Serial.println("min = " );
Serial.println(flex.getMin());
Serial.println("varde = ");
Serial.println(flex.getVal());
Serial.println("namnare = " );
Serial.println(flex.getMax()-flex.getMin());
Serial.println("taljare = ");
Serial.println(100*(flex.getVal()-flex.getMin()));
*/
//Serial.println("scaled = ");
//Serial.println(100*((flex.getVal()-flex.getMin()))/(flex.getMax()-flex.getMin()));
vib.setSpeed(100-(100*((flex.getVal()-flex.getMin()))/(flex.getMax()-flex.getMin())));





delay(500);


  
  /*
  if (Serial.available()>0) {
    text = Serial.read();
    lcd.clear();
    switch (text) {
      case '1':
      lcd.setCursor(15, 0);
      lcd.print("Left");
      for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(250);
      }
      break;
      case '2':
      lcd.setCursor(0, 0);
      lcd.print("Right");
      for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayRight();
        // wait a bit:
        delay(250);
      }
      break;
      default:
      lcd.print(text);
    }


  }
  */
  
}
