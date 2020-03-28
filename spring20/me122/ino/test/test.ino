
// -------- test.ino ---------
// used to practice using Vim to write an Arduino program
// Usage: not yet known

int test_pin = 1;

void setup() {
	pinMode(test_pin, 0);
}

void loop(){
	// Do stuff here
	digitalWrite(test_pin, 1);
	delay(1000);
	digitalWrite(test_pin, 0);
	delay(1000);
}
