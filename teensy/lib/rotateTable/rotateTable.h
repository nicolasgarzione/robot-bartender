#include "hallEffect.h"
#include "motorDriver.h"

class RotateTable{
    public:

    RotateTable(int, int, int, int); //PWM pin, hall effect pin, power pin, table turn speed
    bool rotate();
    bool rotate(int); //rotate past multiple turns

    private:

    void Initialize();

    HallEffect sensor;
    MotorDriver motor;

    int powerout;
    int turn_speed;
};