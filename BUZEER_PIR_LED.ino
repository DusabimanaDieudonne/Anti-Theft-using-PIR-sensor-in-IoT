int ledPin = 4;                    // Pin LED is connected to
int piezoBuzzerPin = 3;           // Pin Piezo Buzzer is connected to
int pirSensorPin = 2;
int motionDetected = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirSensorPin, INPUT);     // declare the PIR sensor as input
  pinMode(piezoBuzzerPin, OUTPUT); //declare buzzer as output
  Serial.begin(9600); //Set serial out if we want debugging
  Serial.println("Starting");
  delay(1000); //Allow time for the PIR Sensor to calibrate
}

void loop(){
  
  motionDetected = digitalRead(pirSensorPin);  // Read the PIR sensor
  if(motionDetected == HIGH) //If motion detected
  {            
    digitalWrite(ledPin, HIGH);
   analogWrite(piezoBuzzerPin, 200);
    delay(100);
    analogWrite(ledPin, LOW);
    analogWrite(piezoBuzzerPin, 25);
    delay(100);
    Serial.println("Motion");
  }
  digitalWrite(ledPin, LOW);
  analogWrite(piezoBuzzerPin,255);
}
