#include <Servo.h>

Servo myServo;  // Create servo object

void setup() {
  myServo.attach(9);  // Attach servo to pin 9
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15);  // Wait for servo to reach position
  }

  // Sweep back from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}
