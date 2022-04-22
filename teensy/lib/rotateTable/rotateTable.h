#include "hallEffect.h"
#include "motorDriver.h"

class rotateTable{
    public:

    rotateTable(int, int, int); //PWM pin, hall effect pin, table turn speed
    bool rotate();
    bool rotate(int); //rotate past multiple turns

    private:

    void Initialize();

    hallEffect sensor;
    motorDriver motor;

    int turn_speed;
};