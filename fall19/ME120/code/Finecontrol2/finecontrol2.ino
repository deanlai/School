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
const int potPin0 = A0;
const int potPin1 = A1;
const int potPin2 = A2;

// Calibration
const float motorAscale = 1.0;
const float motorBscale = 1.0;
float calibrate;

void setup() {
  // Setup pins as outputs
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // take reading from potentiometer
  int potReading0 = analogRead(potPin0);
  int potReading1 = analogRead(potPin1);
  int potReading2 = analogRead(potPin2);

  // set base specified
  int baseSpeed = 200;
  calibrate = map(potReading0, 0, 1023, 800, 1200)/1000.0;
  // int turnRate = map(potReading0, 0, 1023, 0, 100);
  int turnRate = 30;
  int straightDuration = map(potReading1, 0, 1023, 1000, 10000);
  int turnDuration = map(potReading2, 0, 1023, 0, 5000);


  Serial.print(calibrate);
  Serial.print("  ");
  Serial.print(straightDuration);
  Serial.print("  ");
  Serial.println(turnDuration);

  // Drive robot in an out and back
  drive(0, baseSpeed, 1, 0, straightDuration);
  drive(0, baseSpeed, 1, turnRate, turnDuration);
  drive(0, baseSpeed, 1, 0, straightDuration);


  stop();
  delay(5000);
}

void drive(int direction, int speed, int turnDirection, float turnRate, int duration) {
  // Drives robot with these instructions:
  //  direction: 1 -> forward, 0 -> backward
  //  speed: 0 to 255
  //  turnDirection: 1 -> right, 0 -> left
  //  turnRate: 0 to 50 (rates above 50 see dimishing returns)
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

  // Calibrate Wheel Speeds
  int speedA = speed*calibrate;
  int speedB = speed;


  // Set PWM values to run robot
  // turnRate reduces the speed of one motor to turnRate percent of
  // the other motor to turn to robot.
  // EX: turn rate 100 stops one motor
  //     turn rate of 0 drives both motors at the same speed
  //     turn rate of 50 turns one motor at 50% the speed of the other
  if (turnDirection == 1) {
    analogWrite(PWMA, speedA);
    analogWrite(PWMB, speedB-speedB*turnRate/100);
  }
  else {
    analogWrite(PWMA, speedA-speedA*turnRate/100);
    analogWrite(PWMB, speedB);
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
