// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "MotorDriver.h"

class IceDispense{
    public:

    IceDispense(uint8_t, uint8_t); //PWM pin, screw turn speed
    bool dispense();

    private:

    void initialize();

    MotorDriver motor;

    uint8_t turn_speed;
    uint16_t ice_dispense_time = 1000;
};