#include <AccelStepper.h>

AccelStepper stepper(1, 3, 5);

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(100);
  stepper.setCurrentPosition(0);
}

void loop() {
  if (Serial.available()) {
    int val = Serial.readString().toInt();
    Serial.print("Got - ");
    Serial.println(val);

    stepper.moveTo(val);
    stepper.runToPosition();
  }
}
