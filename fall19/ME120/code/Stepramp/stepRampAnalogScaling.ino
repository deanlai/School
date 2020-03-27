//---------------------------------------------------------------------
// ME213 Section 001
// Homework 4, Problem 3
// Sean Lai
//
// stepRampAnalogScaloing.ino
//
// Converts an analog input using a step ramp function
//---------------------------------------------------------------------

// Declare constants
const int xmin = 0, x1 = 400, x2 = 800, xmax = 1023;
const float y1 = 10.0, y2 = 20.0;

// Delcare pins
int potPin = A0;

void setup() {
  // Setup serial communications
  Serial.begin(9600);
}

void loop() {
  // Declare variables and slope of ramp
  int potReading;
  float y, slope = (y2-y1)/(x2-x1);

  // Read input from potentiometer
  potReading = analogRead(potPin);

  // Logic for step ramp function
  if (potReading >= xmin && potReading < x1) {
    y = y1;
  }
  else if (potReading >= x1 && potReading < x2){
    y = y1 + slope*(potReading-x1);
  }
  else if (potReading >= x2 && <= xmax) {
    y = y2;
  }
  else { Serial.println("Error: potReading outside of expected range") }

  // Print to serial monitor
  Serial.print(potReading);
  Serial.print("   ");
  Serial.println(y);
}
