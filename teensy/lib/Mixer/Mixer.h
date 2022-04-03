#include "motorDriver.h"

class Mixer{
    public:

    Mixer(int, int, int, int, int, int); //Motor 1 PWM, Motor 1 speed, Motor 2 PWM, Motor 2 A, Motor 2 B, Motor 2 speed
    Mixer(int, int, int, int, int, int, int); //Above plus default mix time
    bool Mix();
    bool Mix(int); //time in ms

    private:

    void Initialize();

    motorDriver motor1;
    motorDriver motor2;

    int motor1_speed;
    int motor2_speed;

    int default_mix_time;
};