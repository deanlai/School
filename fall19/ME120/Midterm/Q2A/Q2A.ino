// declare Variables
const int potPin = A0;
int potReading;
float potVoltage;

void setup() {
  // Serial comms
  Serial.begin(9600);
}

void loop() {
  potReading = analogRead(potPin); // take in reading
  potVoltage = potReading * (5 / 1023.0); // convert to floating point voltage

  Serial.print(potReading);
  Serial.print("  ");
  Serial.println(potVoltage);
}
