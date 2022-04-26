#include "motorDriver.h"

class iceDispense{
    public:

    iceDispense(int, int); //PWM pin, screw turn speed
    bool dispense();

    private:

    void Initialize();

    motorDriver motor;

    int turn_speed;
    int ice_dispense_time = 1000;
};