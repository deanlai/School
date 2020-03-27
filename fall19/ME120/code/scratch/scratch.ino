// ME120, section 001
//scratch.ino
//
// Basic program for testing code

const int sensorPin = A0;

int sensorReading;

void setup() {
  // Serial communications
  Serial.begin(9600);
}

void loop() {
  sensorReading = analogRead(sensorPin);
  Serial.println(sensorReading);
}
