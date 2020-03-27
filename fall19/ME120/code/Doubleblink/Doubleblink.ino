/*
DoubleBlink

Blinks two LEDs in a specific sequence.
1) Red LED on for 1.2s
2) All LEDs off for 0.4s
3) Yellow LED on for 0.3s
4) All LEDs off for 0.15s   --> From here the sequence reverses
5) Yellow LED on for 0.3s
6) All LEDs off for 0.4s
7) Red LED on for 1.2s
*/
int LED_red = 12; // Sets red LED to pin 12
int LED_yellow = 13; // Sets yellow LED to pin 13

// Assign variables for various time delays

int t1 = 1200;
int t2 = 400;
int t3 = 300;
int t4 = 150;

void setup() {
  // initialize LED pins
  pinMode(LED_red, OUTPUT);
  pinMode(LED_yellow, OUTPUT);

}

void loop() {
  // Blink sequence
  digitalWrite(LED_red, HIGH);
  delay(t1);
  digitalWrite(LED_red,LOW);
  delay(t2);
  digitalWrite(LED_yellow, HIGH);
  delay(t3);
  digitalWrite(LED_yellow, LOW);
  delay(t4);
  digitalWrite(LED_yellow, HIGH);
  delay(t3);
  digitalWrite(LED_yellow, LOW);
  delay(t2);
  digitalWrite(LED_red, HIGH);
  delay(t1);
  digitalWrite(LED_red, LOW);
  delay(t1);
}
