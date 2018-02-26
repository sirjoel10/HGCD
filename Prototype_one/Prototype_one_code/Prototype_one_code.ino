#include <LiquidCrystal.h>
#include "PWMServo.h"

//#ifndef FlexSensor.h
#include "flexSensor.h"
//#endif

//#ifndef Hallsensor.h
#include "Hallsensor.h"
//#endif

//#ifndef Vibrator.h
#include "Vibrator.h" 
//#endif

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int displayMode=0;
bool gasMode = false;
bool displayChangedState=false;
bool deviceOn=false;

//Initialize Sensors
FlexSensor flex(A2);
Hallsensor hall1(A0);
Hallsensor hall2(A1);
Vibrator vib(10);
PWMServo servo;


//Variables for Hallsensor tap 
int counterS=0;
int counterNotS=0;
int typeOfTap=0;
int tapOutput=0;
int tapModeClockcycles=15;
int oneTapClockcycles=1;
int pauseClockcycles=20;
int de=100;
int tapCounter=0;
int tapPauseCounter=0;
bool tapMode = false;
bool tapPause = false;

//Varibles for simple Hallsensor tap
bool outputTapped = false;
bool simpleTapped = false;
bool simpleTapMode = false;
bool simpleTapPause = false;
int simpleCounterS = 0;
int simpleTapCounter = 0;
int simpleTapPauseCounter = 0;
int simplePauseClockcycles = 10;

//Variables for pwm
int speed = 0;
int pwmOut = 0;
bool callibrated = false;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN_A);
}

 
void loop() {
  updateTap(hall2);
  if(tapOutput == 3 ){
    //Serial.println("You tapped twice on hall2");
    if(deviceOn == false){
      startupDisplay();
      deviceOn = true;
    }
    else{
      closeDisplay();
      deviceOn= false;
    }
  }
  else if(deviceOn==true){
    simpleUpdateTap(hall1);
    if(tapOutput == 2){
      //Serial.println("You Tapped Once on hall2");
      displayMode++;
      switch (displayMode) {
      case 1 :
        swipe("Calibration");
      break;
      case 2 :
        swipe("30KM/H");
      break;
      case 3 :
        swipe("Battery Time");
      break;
      case 4 :
        swipe("17:36");
        displayMode=0;
      break;
      }
    }
    else if(tapOutput == 1){
     callibFlex();
    }
    if(outputTapped == true){
      gasUpdate();
      //Serial.println("You tapped on hall1");
    }
    if(gasMode == true){
      sendPWM();
      
    }
  }
  delay(100);
}


void updateTap(Hallsensor hall){
  tapOutput=0;
  int presVal = hall.analogVal();
  if(tapPause == true){
    tapPauseCounter++;
    if(tapPauseCounter > pauseClockcycles){
      tapPause = false;
      tapPauseCounter=0;
    }
  }
  else{
    if((514 < presVal ||  presVal < 509) && tapMode==false){
      tapMode=true;
    }
    if(tapMode == true){
      tapCounter++;
      if(514 < presVal ||  presVal < 509){
        counterS++; 
      }
      else{
        counterS=0;
      }
      if(counterS > oneTapClockcycles && typeOfTap == 0){
        typeOfTap=1;
      }
      if(typeOfTap == 1){
        if(514 > presVal &&  presVal > 509){
          counterNotS++; 
        }
        else{
          counterNotS=0;
        }
        if(counterNotS > oneTapClockcycles){
        typeOfTap = 2;
        }
      }
      if(typeOfTap == 2){
        if(counterS > oneTapClockcycles){
        typeOfTap = 3;
        }
      }
      if(tapCounter > tapModeClockcycles){
        tapMode = false;
        tapOutput=typeOfTap;
        if(typeOfTap==1){
          tapPause=true;
        }
        typeOfTap=0;
        tapCounter=0;
        counterNotS=0;
        counterS=0;
      }
    }
  }
}
void simpleUpdateTap(Hallsensor hall){
  int presVal = hall.analogVal();
  outputTapped = false;
  if(simpleTapPause == true){
    simpleTapPauseCounter++;
    if(simpleTapPauseCounter > simplePauseClockcycles){
      simpleTapPause = false;
      simpleTapPauseCounter=0;
    }
  }
  else{
    if((514 < presVal ||  presVal < 509) && simpleTapMode == false){
      simpleTapMode = true;
    }
    if(simpleTapMode == true){
      simpleTapCounter++;
      if(514 < presVal ||  presVal < 509){
        simpleCounterS++; 
      }
      else{
        simpleCounterS = 0;
      }
      if(simpleCounterS > oneTapClockcycles && simpleTapped==false){
        simpleTapped = true;
      }
      if(simpleTapCounter > tapModeClockcycles){
        simpleTapMode = false;
        outputTapped=simpleTapped;
        simpleTapped=false;
        simpleTapCounter=0;
        simpleCounterS = 0;
        simpleTapPause=true;
      }
  } 
 }
}

void startupDisplay(){
  unsigned long startTime = millis();
  lcd.begin(16, 2);
  lcd.print("Are you Awake?");
  while (millis()-startTime< 2000){
  }
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("17:36");
  lcd.setCursor(0, 1);
  lcd.print("Gas mode:");
  lcd.setCursor(9, 1);
  lcd.print("OFF");
}
void closeDisplay(){
  lcd.clear();
  int displayMode=0;
  bool gasMode = false;
  bool displayChangedState=false;
  bool deviceOn=false;
  vib.setSpeed(0);
}


void swipe(String menu){
    int start = ((16-menu.length())/2);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(start, 0);
    lcd.print(menu);
}

void gasUpdate(){
  if(gasMode == true){
      lcd.setCursor(9, 1);
      lcd.print("OFF ");
      gasMode = false;
      vib.setSpeed(0);
    }
    else{
      if(callibrated == false){
        lcd.setCursor(0, 1);
        lcd.print("Callib first");
        delay(2000);
        lcd.setCursor(0, 1);
        lcd.print("Gas mode:");
        lcd.setCursor(9, 1);
        lcd.print("OFF ");
      }
      else{
      lcd.setCursor(9, 1);
      lcd.print("ON ");
      gasMode = true;
      }
    }
}   

void callibFlex(){
  callibrated = true;
  if(displayMode==1){
    vib.setSpeed(0);
    lcd.clear();
    swipe("Calib started");
    delay(2000);
    swipe("Clench fist");
    flex.clench();
    swipe("Stretch out hand");
    flex.stretch();
    swipe("Calib finished");
    delay(2000);
    swipe("Calibration");
    gasMode=false;
    lcd.setCursor(0, 1);
    lcd.print("Gas mode:");
    lcd.setCursor(9, 1);
    lcd.print("OFF");
  }
}

void sendPWM(){
  speed=(100-(100*((flex.getVal()-flex.getMin()))/(flex.getMax()-flex.getMin())));
  pwmOut=map(speed, 0, 100, 0, 179);
  if(speed > 5){
    vib.setSpeed(speed);
  }
  if(pwmOut>10){
  servo.write(pwmOut);
  }
}

