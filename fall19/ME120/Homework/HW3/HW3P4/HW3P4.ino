/*
Homework 3, Problem 4
Lux Calculation

Calculates Lux incident at a photo resistor given values for
resistance r (ohms), and two constants c1 and c2.
*/

// declare variables
float lux, r, c1, c2;

void setup() {
  // Setup Serial communications
  Serial.begin(9600);

  // assign given values
  r = 950; // in Ohms
  c1 = 1680;
  c2 = 1.08;

  // calculate lux using L = (R/c1)^(1/c2)
  lux = pow((r/c1), (1/c2));

  // print solution for debugging
  Serial.print("lux = ");
  Serial.println(lux);
}

void loop() {
  // not used
}
