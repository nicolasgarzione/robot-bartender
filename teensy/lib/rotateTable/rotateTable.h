#include "hallEffect.h"
#include "motorDriver.h"

class rotateTable{
    public:

    rotateTable(int, int, int, int); //PWM pin, hall effect pin, power pin, table turn speed
    bool rotate();
    bool rotate(int); //rotate past multiple turns

    private:

    void Initialize();

    hallEffect sensor;
    motorDriver motor;

    int powerout;
    int turn_speed;
};