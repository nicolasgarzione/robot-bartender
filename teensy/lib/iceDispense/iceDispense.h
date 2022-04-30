#include "MotorDriver.h"

class IceDispense{
    public:

    IceDispense(int, int); //PWM pin, screw turn speed
    bool dispense();

    private:

    void Initialize();

    MotorDriver motor;

    int turn_speed;
    int ice_dispense_time = 1000;
};