/*
Homework 3, Problem 5, version 2
Variable Blink Rate LED

Blinks an LED with delays dependent on a Potentiometer reading,
with a minimum delay of 0.1s and a maximum of 3.0s
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
  reading = analogRead(readPin); // Reads value of potentiometer pin

  // maps numbers 0 to 1023 to numbers 100 to 3000
  reading = map(reading, 0, 1023, 100, 3000);

  // Blink LED on and off based on value for reading variable
  digitalWrite(LEDPin, HIGH);
  delay(reading);
  digitalWrite(LEDPin, LOW);
  delay(reading);
}
