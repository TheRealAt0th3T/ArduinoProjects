//input for LEDs
const int gLEDpin = 9;
const int rLEDpin = 11;
const int bLEDpin = 10;

//Sensor Pins for each LED
const int rSP = A0;
const int gSP = A1;
const int bSP = A2;

//Values for LEDs
int rVal = 0;
int gVal = 0;
int bVal = 0;

//Sensor Values for LEDs
int rSV = 0;
int gSV = 0;
int bSV = 0;


void setup(){
  Serial.begin(9600);

  pinMode(gLEDpin, OUTPUT);
  pinMode(rLEDpin, OUTPUT);
  pinMode(bLEDpin, OUTPUT);
}


void loop(){
 
  /*
  rSV = analogRead(rSP);
  delay(5);
  gSV = analogRead(gSP);
  delay(5);
  bSV = analogRead(bSP);
  
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(rSV);
  Serial.print("\t Green: ");
  Serial.print(gSV);
  Serial.print("\t Blue: ");
  Serial.println(bSV);
  
  rVal = rSV/4;
  gVal = gSV/4;
  bVal = bSV/4;
  */
  
  //Ignoring light sensor and randomly assigning new colour combo
  int upper = 100;
  int lower = 25;
  int bRandomValue = (rand()%(upper - lower + 1)) + lower;
  
  rVal = random();
  gVal = random();
  bVal = bRandomValue;
  
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(rVal);
  Serial.print("\t Green: ");
  Serial.print(gVal);
  Serial.print("\t Blue: ");
  Serial.println(bVal);
  
  analogWrite(rLEDpin, rVal);
  analogWrite(gLEDpin, gVal);
  analogWrite(bLEDpin, bVal);
  delay(1000);
}
