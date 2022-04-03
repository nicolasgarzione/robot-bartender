#include "Servo.h"

class cupDispense {
    public:
    cupDispense(int pin1, int pin2);
    bool dispense();

    private:
    Servo servo1;
    Servo servo2;
};