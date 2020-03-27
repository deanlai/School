/*
Homework 3, Problem 5, version 2
Variable Blink Rate LED

Blinks an LED with delays dependent on a Potentiometer reading.
*/


// declare variables
int LEDPin = 13;
int readPin = A0;
int reading; // Stores potentiometer reading to set delay


void setup() {
  // Setup LED output
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  reading = analogRead(readPin);

  // Blink LED on and off based on value for reading variable
  digitalWrite(LEDPin, HIGH);
  delay(reading);
  digitalWrite(LEDPin, LOW);
  delay(reading);
}
