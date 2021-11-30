//Amara Tariq
//GIMM 280
//Project 6 - Light Theremin

int sensorVal;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;

void setup(){
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(9600);

  Serial.print("Calibrating Now...\n");
  while(millis() < 5000){
    sensorVal = analogRead(A0);
    if(sensorVal > sensorHigh){
       sensorHigh = sensorVal;
    }else if(sensorVal < sensorLow){
       sensorLow = sensorVal;
    }
  }
  digitalWrite(ledPin, LOW);
  Serial.print("sensorLow: ");
  Serial.println(sensorLow);
  Serial.print("sensorHigh: ");
  Serial.println(sensorHigh);
}

void loop(){
  sensorVal = analogRead(A0);
  /*
  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20); //tone(pin, frequency, [duration])
  delay(10);
  */

  int pitch = map(sensorVal, sensorLow, sensorHigh, 50, 4000);
  int distanceSensor = sensorVal;
  tone(8,pitch);
  delay(distanceSensor);
  noTone(8);
  delay(50);
}