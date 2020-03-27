//---------------------------------------------------------------------
// ME120, Section 001
// Sean Lai
//
// Basic Motor Control
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
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void loop() {
  // Drive motors forward for 3s
  digitalWrite(AI1, 1);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 1);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
  delay(3000);

  // Drive motors forward for 3s
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 1);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 1);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
  delay(3000);

  // Drive in opposite directions, A forward, B backward 1.5s
  digitalWrite(AI1, 1);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 1);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
  delay(1500);

  // Drive in opposite directions, B forward, A backward 1.5s
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 1);
  digitalWrite(BI1, 1);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 255);
  analogWrite(PWMB, 255);
  delay(1500);

  // Stop motors for 3s
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  delay(3000);
}
