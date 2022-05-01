// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "motorDriver.h"

class Mixer{
    public:

    Mixer(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t); //Motor 1 PWM, Motor 1 speed, Motor 2 PWM, Motor 2 Reverse PWM, Motor 2 speed
    Mixer(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint16_t); //Above plus default mix time
    bool mix();
    bool mix(uint16_t); //time in ms

    private:

    void initialize();

    MotorDriver motor_1;
    MotorDriver motor_2;

    uint8_t motor_1_speed;
    uint8_t motor_2_speed;

    uint8_t default_mix_time;
};