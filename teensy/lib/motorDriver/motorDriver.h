#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

class motorDriver{
    public:

    #define FORWARD true
    #define REVERSE false

    motorDriver();
    motorDriver(int); //PWM pin
    motorDriver(int, int); //PWM, PWM_reverse
    void setSpeed(int);
    void Move(); //use default speed, set direction
    void Move(int); //variable speed, set diretion
    void Move(bool); //set speed, variable diretion
    void Move(int, bool); //variable speed, variable direction
    void Stop();

    private:

    void Initialize();

    int pwm_pin;
    int pwm_reverse_pin;
    int speed;
    bool static_direction;
};

#endif