#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

class motorDriver{
    public:

    #define FORWARD true
    #define REVERSE false

    motorDriver();
    motorDriver(int); //PWM pin
    motorDriver(int, int, int); //PWM, A, B
    void setSpeed(int);
    void Move(); //use default speed, set direction
    void Move(int); //variable speed, set diretion
    void Move(bool); //set speed, variable diretion
    void Move(int, bool); //variable speed, variable direction
    void Stop();

    private:

    void Initialize();

    int pwm_pin;
    int a_pin;
    int b_pin;
    int speed;
    bool static_a_b_pins;
};

#endif