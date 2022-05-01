// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "hallEffect.h"
#include "motorDriver.h"

class RotateTable{
    public:

    RotateTable(uint8_t, uint8_t, uint8_t, uint8_t); //PWM pin, hall effect pin, power pin, table turn speed
    bool rotate();
    bool rotate(uint8_t); //rotate past multiple turns

    private:

    void initialize();

    HallEffect sensor;
    MotorDriver motor;

    uint8_t power_pin;
    uint8_t turn_speed;
};