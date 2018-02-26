
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int numb;
int displayMode=0;
bool gasMode = false;
bool displayChangedState=false;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
      numb = Serial.read();
      Serial.println(numb);
  }
  if(numb=='1'){
    startupDisplay();
  }
  if(numb=='2'){
    displayMode++;
    displayChangedState=true;
  }
  if(numb=='3'){
    gasUpdate();
  }
  if(displayMode==1 && numb=='4'){
    lcd.clear();
    swipe("Calib started");
    delay(2000);
    swipe("Clench fist");
    delay(5000);
    swipe("Stretch out hand");
    delay(5000);
    swipe("Calib finished");
    delay(2000);
    swipe("Calibration");
    gasMode=true;
    lcd.setCursor(0, 1);
    lcd.print("Gas mode:");
    lcd.setCursor(9, 1);
    lcd.print("OFF");
  }

  if(displayChangedState){
    switch (displayMode) {
      case 1 :
        swipe("Calibration");
      break;
      case 2 :
        swipe("30KM/H");
      break;
      case 3 :
        swipe("17:36");
      break;
      case 4 :
        swipe("Battery Time");
        displayMode=0;
      break;
    }
  }
  numb='0';
  displayChangedState=false;
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



void swipe(String menu){
    int start = ((16-menu.length())/2);
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(start, 0);
    delay(250);
    lcd.print(menu);
}

void gasUpdate(){
  if(gasMode == true){
      lcd.setCursor(9, 1);
      lcd.print("OFF ");
      gasMode = false;
    }
    else{
      lcd.setCursor(9, 1);
      lcd.print("ON ");
      gasMode = true;
    }
}

