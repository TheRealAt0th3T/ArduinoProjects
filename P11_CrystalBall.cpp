/**
 * Amara Tariq
 * GIMM 280
 * A7 - Project 11 Crystal Ball
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

//setting up for randomHat
#define randomHatStartNum 0  // starting number in hat
#define randomHatEndNum 7    // ending number in hat - end has to be larger than start  
#define numberInHat (randomHatEndNum - randomHatStartNum) + 1

void setup() {

  randomSeed(analogRead(A0)); //provides a random voltage to change seed
  lcd.begin(16, 2); // # of col and row on LCD
  pinMode(switchPin, INPUT);

  lcd.print("Ask the");
  lcd.setCursor(0, 1); //col 0, line 1
  lcd.print("Crystal Ball!");
}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = randomHat();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("the ball says:");
      lcd.setCursor(0, 1);

      switch (reply) {
        case 0:
          lcd.print("For sure bruhhh");
          break;
        case 1:
          lcd.print("Ehh probably");
          break;
        case 2:
          lcd.print("Without a doubt");
          break;
        case 3:
          lcd.print("Seems aight");
          break;
        case 4:
          lcd.print("Uhhhhhh");
          break;
        case 5:
          lcd.print("What did you say");
          break;
        case 6:
          lcd.print("You wish");
          break;
        case 7:
          lcd.print("Noooo");
          break;
      }
    }
  }
  prevSwitchState = switchState;
  delay(100);
}

int randomHat() {
  int thePick;    //this is the return variable with the random number from the pool
  int theIndex;
  static int currentNumInHat = 0;
  static int randArray[numberInHat];

  if  (currentNumInHat == 0) {                  // hat is emply - all have been choosen - fill up array again
    for (int i = 0 ; i < numberInHat; i++) {    // Put 1 TO numberInHat in array - starting at address 0.
      if (randomHatStartNum < randomHatEndNum) {
        randArray[i] = randomHatStartNum + i;
      }
    }
    currentNumInHat = abs(randomHatEndNum - randomHatStartNum) + 1;   // reset current Number in Hat
    // Serial.print(" hat is empty ");
    // if something should happen when the hat is empty do it here
  }

  theIndex = random(currentNumInHat);                  //choose a random index from number in hat
  thePick = randArray[theIndex];
  randArray[theIndex] =  randArray[currentNumInHat - 1]; // copy the last element in the array into the the empty slot
  //                                                     // as the the draw is random this works fine, and is faster
  //                                                     // the previous version. - from a reader suggestion on this page
  currentNumInHat--;    // decrement number in hat
  return thePick;
}
