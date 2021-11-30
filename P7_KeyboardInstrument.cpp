/**
 * Amara Tariq
 * GIMM 280
 * A6 - Project 7 Keyboard Instrument
 */

#include "pitches.h"

//array of notes 
int notes[] = {NOTE_A5, NOTE_CS6, NOTE_E5, NOTE_AS4}; //i am not musically talented so doesn't sound too great

void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  if(keyVal >= 1011 && keyVal <= 1023){
    tone(8, notes[0]);
  }else if(keyVal >= 990 && keyVal <= 1010){
    tone(8, notes[1]);
  }else if(keyVal >= 475 && keyVal <= 550){
    tone(8, notes[2]);
  }else if(keyVal >= 1 && keyVal <= 100){
    tone(8, notes[3]);
  }else{
    noTone(8);
  }
}
