//---------------------------------------------------------------------
// ME120, Section 001
// Sean Lai
//
// Motor Control with Fucntions
// Note when hooking up motors:
// A01(+) A02(-), B01(-), B02(+) due to the physical orientation of the motors,
// because the B motor is mounted upside down.
//---------------------------------------------------------------------

// Declare pins for motors
const int AI1 = 13, AI2 = 12, PWMA = 11;
const int BI1 = 8, BI2 = 9, PWMB = 10;

void setup() {
  // Setup pins as outputs
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void loop() {
  forward(50);
  delay(500);
  forward(100);
  delay(500);
  right(100);
  delay(300);
  backward(100);
  delay(1000);
  stop();
  delay(5000);
}

void forward(int speed) {
  // Drive motors forward at speed ssent to function
  digitalWrite(AI1, 1);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 1);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void backward(int speed) {
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 1);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 1);
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void right(int speed) {
  digitalWrite(AI1, 1);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 1);
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void left(int speed) {
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 1);
  digitalWrite(BI1, 1);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
}

void stop() {
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}
