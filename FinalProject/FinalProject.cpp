
#include <FastLED.h> //to help control individual LEDs
#include <QuickStats.h> //to help manage stats for echo and trig


QuickStats stats; //initialize an instance of this class

/**
 * PIN DEFINITIONS
 */
#define LED_PIN 7
#define NUM_LEDS 15 //------might change
const int trigPin = 9;
const int echoPin = 10;


/**
 * VARIABLES
 */
CRGB leds[NUM_LEDS];
float duration;
float durationarray[15];
int distance; //going to be in CM
int stopdistance = 115; //distance from sensor for correct parking
int startdistance = 400; //distance from sensor to start calibrating
int increment=((startdistance-stopdistance)/15);


void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //MIGHT NEED TO CHANGE ------
Serial.begin(9600); 
}


void loop() {
  for (int i=0;i<=14;i++){
    digitalWrite(trigPin, LOW); //clear trigger pin
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    durationarray[i] = pulseIn(echoPin, HIGH); //so now we capture distance
    distance = durationarray[i]*0.034/2; //math found online
    Serial.print(distance);
    Serial.print(" ");
  }

  duration = (stats.median(durationarray,15)); //taking the average of all the tries
  distance = duration * 0.034/2;

  Serial.println("Distance: " + distance);
  //Serial.println(distance);
    
  if (distance < stopdistance){
    for (int i = 0; i <= 14; i++) {
      leds[i] = CRGB ( 255, 0, 0);
      FastLED.show();
      }
  }else if(distance<stopdistance+increment){
    for (int i = 1; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 0; i++) {
      leds[i] = CRGB ( 255, 255, 0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*2){
    for (int i = 2; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 1; i++) {
      leds[i] = CRGB ( 255, 255, 0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*3){
    for (int i = 3; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 2; i++) {
      leds[i] = CRGB ( 255, 255, 0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*4){
    for (int i = 4; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 3; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*5){
    for (int i = 5; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 4; i++) {
    leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*6){
    for (int i = 6; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 5; i++) {
    leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*7){
    for (int i = 7; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 6; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*8){
    for (int i = 8; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 7; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*9){
    for (int i = 9; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 8; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*10){
    for (int i = 10; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 9; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*11){
    for (int i = 11; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 10; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*12){
    for (int i = 12; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
  for (int i = 0; i <= 11; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*13){
    for (int i = 13; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
  for (int i = 0; i <= 12; i++) {
    leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance<stopdistance+increment*14){
    for (int i = 14; i <= 14; i++) {
      leds[i] = CRGB ( 0, 0, 0);
    }
    for (int i = 0; i <= 13; i++) {
      leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }else if (distance>=stopdistance+increment*14){
    for (int i = 0; i <= 14; i++) {
    leds[i] = CRGB ( 0, 255,0);
    }
    FastLED.show();
    delay(50);
  }
}
