// -----------------------------------------------------------------------
// ME120, Section 001
// Homework 4, Problem 2
// Sean Lai
//
// Nightlight
//
// Uses a potentiometer to set the light level reading from a photoresistor
// at which a nightlight turns on or off.
// -----------------------------------------------------------------------

// Setup sensor and output pins
const int potPin = A0;
const int photoPin = A1;
const int LEDPin = 9;

// declare variables for reading and calibration
int photoVal, potVal;

void setup() {
  // Setup LED output pin
  pinMode(LEDPin, OUTPUT);

  // Setup Serial communications for debugging
  Serial.begin(9600);
}

void loop() {
  // Take readings from photoresistor and potentiometer
  photoVal = analogRead(photoPin);
  potVal = analogRead(potPin);

  // Test if light reading is less than
  if(photoVal < potVal) {
    digitalWrite(LEDPin, HIGH); // Turn LED on
  }
  // Otherwise turn it off
  else {
    digitalWrite(LEDPin, LOW);

  }
  // debugging
  Serial.print("pot: ");
  Serial.print(potVal);
  Serial.print("  ");
  Serial.print("photo: ");
  Serial.println(photoVal);
}
