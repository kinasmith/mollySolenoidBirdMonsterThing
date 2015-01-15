int sensorPin = A0; //where your sensor plugs in
int sensorValue = 0; //holder for sensor readings
int solenoidPin = 8; //the pin where your solenoid output is
int triggerLevel = 50; //adjust sensitivity here (0-1023)
int numberOfRetracts = 1;

void setup() {
  //Serial.begin(9600); //Opens serial port for communcation with host computer
  pinMode(solenoidPin, OUTPUT);  //sets the mode of the solenoid pin
  //  Serial.println("setup");
}

void loop() {
  sensorValue = analogRead(sensorPin);  //read sensor value
  // Serial.println(sensorValue);  
  //   delay(10); //delay for serial prints

  if(sensorValue > triggerLevel) { //triggers 
    for(int i = 0; i < numberOfRetracts; i++) { //number of times the solenoid triggers
      doSolenoidThing();       //move solenoid
      // Serial.println("soldenoid thing");
    }
  }

}

void doSolenoidThing() {
  digitalWrite(solenoidPin, HIGH); //retract solenoid
  delay(500); //hold the solenoid retracted
  digitalWrite(solenoidPin, LOW); //release solenoid
  delay(500); //wait
}



