/**
 * @file FinalProject.cpp
 * @author Amara Tariq
 * @brief GIMM 280 - Parking Garage Assistant
 * @version 0.1
 * @date 2021-12-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * LIBRARYs
 * referenced in the amazon listing for LED
 */
#include <FastLED.h>
#include <QuickStats.h>

QuickStats stats; //initialize an instance of this class

/**
 * PIN DEFINITIONS
 */
#define LED_PIN 9
#define NUM_LEDS 60
const int trigPin = 11;
const int echoPin = 12;

/**
 * VARIABLES
 */
CRGB leds[NUM_LEDS];
float duration;
float durationarray[15];
int distance;            //going to be in CM
int stopdistance = 115;  //distance from sensor for correct parking = about 1.5ft
int startdistance = 400; //distance from sensor to start calibrating = a little longer than avg length of car (13 ft)
int increment = 10;      //15 different loops for increments

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); //class initialization to control LEDs
    Serial.begin(9600);
}

void loop()
{
    
    digitalWrite(trigPin, LOW); //clear trigger pin
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    /**
     * PULSEIN(pin, value)
     * Reads the echoPin, returns the sound wave travel time in microseconds
     * useful to make more accurate with moving vehicle, for now simplified 
     * later can put in for-loop and allow it to calculate median 
     */
    duration = pulseIn(echoPin, HIGH); 
    distance = duration * 0.034 / 2; //math found online
    
    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 10) //Right where the car should be told to stop
    {
        for (int i = 0; i <= NUM_LEDS; i++) //all LEDs 
        {
            leds[i] = CRGB(255, 0, 0); //RED
            FastLED.show();
        }
    }
    else if (distance < 20)
    {
        for (int i = 1; i <= NUM_LEDS; i++) //reset all LED
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 0; i++) //turn two from the middle on
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104); //LAVENDER
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 25)
    {
        for (int i = 2; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 2; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 30)
    { //----testing
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 3; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 35)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 4; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 40)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 5; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 45)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 6; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 50)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 7; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 55)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 8; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 60)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 9; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 65)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 10; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 70)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 11; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 75)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 12; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else

        if (distance < 80)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 13; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance < 85)
    {
        for (int i = 0; i <= NUM_LEDS; i++)
        {
            leds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= 14; i++)
        {
            leds[(NUM_LEDS / 2) + i - 1] = CRGB(159, 43, 104);
            leds[(NUM_LEDS / 2) - i] = CRGB(159, 43, 104);
        }
        FastLED.show();
        delay(50);
    }
    else if (distance >= 90) //when no car sensed yet
    {
        for (int i = 0; i <= NUM_LEDS; i++) //GREEN
        {
            leds[i] = CRGB(0, 255, 0);
        }
        FastLED.show();
        delay(50);
    }
}