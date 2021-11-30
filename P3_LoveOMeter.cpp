const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup(){
 
  Serial.begin(9600); //opens connections between arduino and comp
              //9600 is speed that arduino comms
  for(int pinNumber = 2; pinNumber < 5; pinNumber++){
      pinMode(pinNumber,OUTPUT);
      digitalWrite(pinNumber, LOW);
  }
}


void loop(){
  
  int sensorVal = analogRead(sensorPin); //getting input from temp sensor
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal/1024.0)*5.0; //converting ADC to volt
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: "); 
  float temp = (voltage - 0.5)*100; //converting volt to temp
  Serial.println(temp);
  
  Serial.print(", degrees F: "); 
  float F = (1.8)*temp +32; //converting C to F
  Serial.println(F);
  
  if(temp < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temp >= baselineTemp+2 && temp < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temp >= baselineTemp+4 && temp < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temp >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
