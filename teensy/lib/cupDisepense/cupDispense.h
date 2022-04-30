#include "Servo.h"

class CupDispense {
    public:
    CupDispense(int pin1, int pin2);
    bool dispense();

    private:
    Servo servo1;
    Servo servo2;
};