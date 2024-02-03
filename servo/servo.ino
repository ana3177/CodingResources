#include <Servo.h>
#define pin 1
Servo servo;
void setup() {
  // put your setup code here, to run once:
servo.attach(pin);
servo.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
servo.write(0);
servo.write(90);
}
