//---------------------------------------------------------------------
// ME120, Section 001
// Sean Lai
//
// Motor Controller
// Note when hooking up motors:
// A01(+) A02(-), B01(-), B02(+) due to the physical orientation of the motors,
// because the B motor is mounted upside down.
//
// Drives robot on specified courses given direction, distance,
// turn radius, and turn direction.
//
// Uses motor calibration
//---------------------------------------------------------------------

// For this robot, right motor -> motor A
//                  left motor -> motor B

// Declare pins for motors
const int AI1 = 13, AI2 = 12, PWMA = 11;
const int BI1 = 8, BI2 = 9, PWMB = 10;
const int potPin = A0;
const float wheelDiameter = 2.5938;
const float wheelBase = 5.1875;

// CALIBRATIONS
const float slopeA = 8.312; const float interceptA = 7.08;
const float slopeB = 8.506; const float interceptB = 7.447;
const float scalingFactor = 1.8;


void setup() {
  // Setup pins as outputs
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Setup Serial Communications
  Serial.begin(9600);
}

void loop() {
  // take reading from potentiometer
  int potReading = analogRead(potPin);

  turn(1, 1, 7, 7, PI/2);
  turn(1, 0, 7, 7, PI/2);

}

void turn(int heading, int direction, int speed, int radius, float angle) {
  // heading: 0 -> backward, 1 - forward
  // direction: 0 -> left, 1 -> right
  // speed: 0-10 inches per second
  // radius: from b/2 to large in inches
  // angle: radians
  int pwmA, pwmB;
  float deltaT = 1000*radius*angle/speed;
  float deltaV = wheelBase*speed/radius;
  float omegaR = omegaRL(direction, 1, deltaV, speed, wheelDiameter);
  float omegaL = omegaRL(direction, 0, deltaV, speed, wheelDiameter);
  pwmA = getPWMFromOmega(omegaR, 'A');
  pwmB = getPWMFromOmega(omegaL, 'B');

  if (heading == 0) {
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
  analogWrite(PWMA, pwmA);
  analogWrite(PWMB, pwmB);

  delay((float)deltaT);
}

void stop() {
  digitalWrite(AI1, 0);
  digitalWrite(AI2, 0);
  digitalWrite(BI1, 0);
  digitalWrite(BI2, 0);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
}

float getPWMFromOmega(float omega, char motor){
  if (motor == 'A') {
    // returns calibrated PWM value for motor A
    return (slopeA*omega + interceptA)*scalingFactor;
  }
  else {
    // returns calibrated PWM value for motor B
    return (slopeB*omega + interceptB)*scalingFactor;
  }
}

float omegaRL(int direction, int side, float deltaV, float avgV, float diameter) {
  // takes in direction of turn and motor side, 0 -> left, 1 -> right,
  // and deltaV, avgV, and wheel diameter for the turn
  // and returns rotational velocity of given motor
  if (direction == side) {
    // if motor side is the same as turn direction
    return (2 / diameter)*(avgV - (deltaV/2));
  }
  else {
    // if motor side is the opposite of turn direction
    return (2 / diameter)*(avgV + (deltaV/2));
  }
}
