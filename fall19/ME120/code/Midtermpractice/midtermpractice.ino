// Midterm arduino practice
//
// Can I write a program from scratch?
//

// Variables and Constants
const int RedLEDPin = 13; // Set Red LED Pin to 13
const int GreenLEDPin = 11; // Set green LED Pin to 11 (for PWM)
const int potPin = A0; // Set potentiometer input to A0
const int photoPin = A1; // Set photoresistor pin to A1


void setup() {
  pinMode(RedLEDPin, OUTPUT); // Setup LED Pins to output
  pinMode(GreenLEDPin, OUTPUT);

  // Setup Serial comm
  Serial.begin(9600);
}

void loop() {
  int i;
  for (i = 0; i < 100; i++) {
    Serial.print(i);
    Serial.print("  ");
    Serial.println(sqrt(i));
    delay(100);
  }

}

void LEDBlinker(int on, int pin, int time) {
  // Blinks an LED on (1) or off (0) for argument <on>, at <pin>, for <time> ms.
  if (on) {
    digitalWrite(pin, 1);
    delay(time);
  }
  else {
    digitalWrite(pin, 0);
    delay(time);
  }
}
