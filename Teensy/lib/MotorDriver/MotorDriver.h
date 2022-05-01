// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

class MotorDriver{
    public:

    #define FORWARD true
    #define REVERSE false

    MotorDriver();
    MotorDriver(uint8_t); //PWM pin
    MotorDriver(uint8_t, uint8_t); //PWM, PWM_reverse
    void set_speed(uint8_t);
    void move(); //use default speed, set direction
    void move(uint8_t); //variable speed, set diretion
    void move(bool); //set speed, variable diretion
    void move(uint8_t, bool); //variable speed, variable direction
    void stop();

    private:

    void initialize();

    uint8_t pwm_pin;
    uint8_t pwm_reverse_pin;
    uint8_t speed;
    bool static_direction;
};

#endif