#include "Arduino.h"
#include "rotateTable.h"
#include "hallEffect.h"
#include "motorDriver.h"

rotateTable::rotateTable(int pwm, int digital_in, int turnspeed){
    hallEffect sensor_init(digital_in);
    motorDriver motor_init(pwm);

    sensor = sensor_init;
    motor = motor_init;
    turn_speed = turnspeed;

    Initialize();
}

bool rotateTable::Rotate(){
    motor.Move();
    while(!sensor.Read()){}
    while(sensor.Read()){}
    motor.Stop();

    return true;
}

bool rotateTable::Rotate(int n){
    if(n == 0){
        Rotate();
    }
    else{
        motor.Move();
        int i = 0;
        while(i < n + 1){
            while(!sensor.Read()){}
            while(sensor.Read()){}
        }
        motor.Stop();

        return true;
    }
}

void rotateTable::Initialize(){
    motor.setSpeed(turn_speed);
    motor.Stop();
}
