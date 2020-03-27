// declare Variables
const int potPin = A0;
int potReading;
float potVoltage;

int redLEDPin = 12;
int yellowLEDPin = 11;

void setup() {
  // Serial comms
  Serial.begin(9600);
}

void loop() {
  potReading = analogRead(potPin); // take in reading
  potVoltage = potReading * (5 / 1023.0); // convert to floating point voltage

  if (potVoltage <= 1 ) {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, HIGH);
  }
  else if (potVoltage <= 2) {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
  }
  else if (potVoltage <= 3) {
    digitalWrite(yellowLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
  }
  else if (potVoltage <= 4) {
    digitalWrite(redLEDPin, LOW);
    digitalWrite(yellowLEDPin, LOW);
  }
  else {
    digitalWrite(yellowLEDPin, HIGH);
    digitalWrite(redLEDPin, HIGH);
  }


  Serial.print(potReading);
  Serial.print("  ");
  Serial.println(potVoltage);
}
