#ifndef SPARKMOTOR_H
#define SPARKMOTOR_H

#include <Arduino.h>

class SparkMotor {
public:
    SparkMotor(
        int rpwm_l = 9, int lpwm_l = 3, int en_l = 2,
        int rpwm_r = 10, int lpwm_r = 11, int en_r = 8
    );
    
    void begin();  // Initialize pins
    
    // Operator overloading for motor(speedLeft, speedRight)
    void operator()(int leftSpeed, int rightSpeed);

private:
    int _rpwm_l, _lpwm_l, _en_l;
    int _rpwm_r, _lpwm_r, _en_r;
};

#endif