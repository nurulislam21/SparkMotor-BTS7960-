#include "SparkMotor.h"
#include <Arduino.h>

SparkMotor::SparkMotor(
    int rpwm_l, int lpwm_l, int en_l,
    int rpwm_r, int lpwm_r, int en_r
) : 
    _rpwm_l(rpwm_l), _lpwm_l(lpwm_l), _en_l(en_l),
    _rpwm_r(rpwm_r), _lpwm_r(lpwm_r), _en_r(en_r) {}

void SparkMotor::begin() {
    pinMode(_rpwm_l, OUTPUT);
    pinMode(_lpwm_l, OUTPUT);
    pinMode(_en_l, OUTPUT);
    pinMode(_rpwm_r, OUTPUT);
    pinMode(_lpwm_r, OUTPUT);
    pinMode(_en_r, OUTPUT);
    digitalWrite(_en_l, LOW);
    digitalWrite(_en_r, LOW);
}

// Overloaded () operator for direct motor control
void SparkMotor::operator()(int leftSpeed, int rightSpeed) {
    leftSpeed = constrain(leftSpeed, -100, 100);
    rightSpeed = constrain(rightSpeed, -100, 100);

    // Left motor logic (same as original)
    if (leftSpeed != 0) {
        digitalWrite(_en_l, HIGH);
        analogWrite(leftSpeed > 0 ? _rpwm_l : _lpwm_l, map(abs(leftSpeed), 0, 100, 0, 255));
        analogWrite(leftSpeed > 0 ? _lpwm_l : _rpwm_l, 0);
    } else {
        digitalWrite(_en_l, LOW);
        analogWrite(_rpwm_l, 0);
        analogWrite(_lpwm_l, 0);
    }

    // Right motor logic (same as original)
    if (rightSpeed != 0) {
        digitalWrite(_en_r, HIGH);
        analogWrite(rightSpeed > 0 ? _rpwm_r : _lpwm_r, map(abs(rightSpeed), 0, 100, 0, 255));
        analogWrite(rightSpeed > 0 ? _lpwm_r : _rpwm_r, 0);
    } else {
        digitalWrite(_en_r, LOW);
        analogWrite(_rpwm_r, 0);
        analogWrite(_lpwm_r, 0);
    }
}