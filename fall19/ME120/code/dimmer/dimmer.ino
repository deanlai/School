/*
Dimmer

Dims an LED using PWM based off a reading from a potentiometer
*/

// declare pins
int potPin = A0;
int LEDPin = 3;

// declare variable for reading from potentiometer
int potReading;

void setup() {
  // setup LED Pin
  pinMode(LEDPin, OUTPUT);
  // Setup Serial comm for debugging
  Serial.begin(9600);
}

void loop() {
  potReading = analogRead(potPin); // read in potentiometer
  potReading /= 4; // convert to 8 bit integer
  Serial.println(potReading);
  analogWrite(LEDPin, potReading);
}
