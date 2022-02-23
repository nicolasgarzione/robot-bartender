#include "Servo.h"

class cupDispenser {
    public:
    cupDispenser(int pin1, int pin2);
    void dispense();

    private:
    Servo servo1;
    Servo servo2;
};