// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "Servo.h"

class CupDispense {
    public:
    CupDispense(uint8_t, uint8_t);
    bool dispense();

    private:
    Servo servo_1;
    Servo servo_2;
};