//---------------------------------------------------------------------
// ME120, Section 001
// Sean Lai
//
// Fine Control Functions
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
  // Drive robot in an expanding spiral
  drive(1, 100, 1, 75, 400);
  drive(1, 100, 1, 70, 400);
  drive(1, 100, 1, 65, 400);
  drive(1, 100, 1, 60, 400);
  drive(1, 100, 1, 55, 400);
  drive(1, 100, 1, 50, 400);
  drive(1, 100, 1, 45, 400);
  drive(1, 100, 1, 40, 400);
  drive(1, 100, 1, 35, 400);
  drive(1, 100, 1, 30, 400);
  drive(1, 100, 1, 25, 400);
  stop();
  delay(5000);
}

void drive(int direction, int speed, int turnDirection, int turnRate, int duration) {
  // Drives robot with these instructions:
  //  direction: 1 -> forward, 0 -> backward
  //  speed: 0 to 255
  //  turnDirection: 1 -> right, 0 -> left
  //  turnRate: 0 to 50
  //  duration: length of time to perform command in milliseconds

  // Set direction of travel
  if (direction == 1) {
    digitalWrite(AI1, 1);
    digitalWrite(AI2, 0);
    digitalWrite(BI1, 1);
    digitalWrite(BI2, 0);
  }
  else {
    digitalWrite(AI1, 0);
    digitalWrite(AI2, 1);
    digitalWrite(BI1, 0);
    digitalWrite(BI2, 1);
  }

  // Set PWM values to run robot
  // turnRate reduces the speed of one motor to turnRate percent of
  // the other motor to turn to robot.
  // EX: turn rate 100 stops one motor
  //     turn rate of 0 drives both motors at the same speed
  //     turn rate of 50 turns one motor at 50% the speed of the other
  if (turnDirection == 1) {
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed*(1-turnRate/100));
  }
  else {
    analogWrite(PWMA, speed*(1-turnRate/100));
    analogWrite(PWMB, speed);
  }

  // Set duration
  delay(duration);
}

void stop() {
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}
