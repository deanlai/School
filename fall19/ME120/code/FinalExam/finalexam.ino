// breadboard stuff

// delcare pins
const int LED1 = 6, LED2 = 9, LED3 = 10, LED4 = 11;
const int potPinVoltage = A0, potPinDimmer = A1;


void setup(){
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop(){
  int voltageReading;
  float voltage;
  int dimmerReading;
  voltageReading = analogRead(potPinVoltage);
  voltage = voltageReading*5.0/1023;
  dimmerReading = analogRead(potPinDimmer);
  dimmerReading = map(dimmerReading, 0, 1023, 0, 255);

  Serial.println(voltage);

  if(voltage < 1.1) {
    turnOnLEDs(1, 0, 0, 0, dimmerReading);
  } else if (1.1 <= voltage && voltage < 2.2) {
    turnOnLEDs(1, 1, 0, 0, dimmerReading);
  } else if (2.2 <= voltage && voltage < 3.3) {
    turnOnLEDs(1, 1, 1, 0, dimmerReading);
  } else {
    turnOnLEDs(1, 1, 1, 1, dimmerReading);
  }
}

void turnOnLEDs(int led1, int led2, int led3, int led4, int dim) {
  if (led1) {
    analogWrite(LED1, dim);
  }
  if (led2) {
    analogWrite(LED2, dim);
  } else {
    analogWrite(LED2, 0);
  }
  if (led3) {
    analogWrite(LED3, dim);
  } else {
    analogWrite(LED3, 0);
  }
  if (led4) {
    analogWrite(LED4, dim);
  } else {
    analogWrite(LED4, 0);
  }
}
