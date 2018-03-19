int counterS=0;
int counterNotS=0;
int typeOfTap=0;
int tapModeClockcycles=10;
int oneTapClockcycles=1;
int pauseClockcycles=3;
int de=250;
int tapCounter=0;
int tapPauseCounter;
bool tapMode = false;
bool tapPause = false;
/*typeOfTap
  0: no tap
  1: hold tap 
  2: single tap 
  3: double tap
*/
void setup() {
  Serial.begin(9600);
}

void loop() {
  int presVal = (analogRead(A1));
  //Serial.println(presVal);
  
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
        Serial.print("Type of tap:");
        Serial.println(typeOfTap);
        tapPause=true;
        typeOfTap=0;
        tapCounter=0;
        counterNotS=0;
        counterS=0;
      }
    }
  }
  delay(de);
}


