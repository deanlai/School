//  File:  wheel_calibration.ino
//
//  Spin a robot wheel for a fixed time interval at a fixed PWM signal.
//  The user counts the rotations to obtain data for a calibration of
//  omega = f(PWM)

// -- Global pin variables connect digital I/O channels to the
//    inputs on the TB6612
const int AIN1 = 13;    //  Pin IN1 for motor A
const int AIN2 = 12;    //  Pin IN2 for motor A
const int PWMA = 11;    //  Pin for PWM input to motor A
const int PWMB = 10;    //  Pin for PWM input to motor B
const int BIN2 =  9;    //  Pin IN2 for motor B
const int BIN1 =  8;    //  Pin IN1 for motor B

// --------------------------------------------------------------
void setup() {
  pinMode(AIN1, OUTPUT);    //  Set all motor contro pins as outputs
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);       //  Start up the Serial Monitor
  delay(5000);              //  Pause before starting any tests
}

// --------------------------------------------------------------
void loop() {

  int pwm, min_PWM=55, delta_PWM=25, measureTime=10000, waitTime=8000;

  Serial.println("\n\nBegin Test for");
  Serial.print(measureTime);
  Serial.println("  seconds");

  for ( pwm=min_PWM; pwm<=155; pwm+=delta_PWM ) {

    Serial.print("Rotate at speed ");   Serial.println(pwm);
    forward(pwm);
    delay(measureTime);

    // -- Pause to record data
    stopMotors();
    delay(waitTime);
  }

  Serial.println("\nTest complete");
  delay(2*waitTime);    //   Wait before starting next test
}

// --------------------------------------------------------------
void forward(int motorSpeed) {

    // -- Drive both motors forward:  IN1 -> HIGH,  IN2 -> LOW
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, motorSpeed);

    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, motorSpeed);
}

// --------------------------------------------------------------
void reverse(int motorSpeed) {

    // -- Drive both motors forward: IN1 -> LOW,  IN2 -> HIGH
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    analogWrite(PWMA, motorSpeed);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMB, motorSpeed);
}

// --------------------------------------------------------------
void stopMotors() {

    // -- Stop both motors:  IN1 -> LOW,  IN2 -> LOW
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    analogWrite(PWMA, 0);

    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMB, 0);
}
