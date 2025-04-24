#include <Arduino.h>
#include <SparkMotor.h>

SparkMotor motors;
// Format: SparkMotor(left_RPWM, left_LPWM, left_EN, right_RPWM, right_LPWM, right_EN)
// SparkMotor motors(5, 6, 7, 4, 3, 2);  // Example custom setup

void setup() {
    motors.begin();
}

void loop() {
    motors(80, 80);  // Drive forward
    delay(1000);
    motors(-80, -80);  // Reverse
    delay(1000);
    motors(0, 0);  // Stop
    delay(1000);
}
