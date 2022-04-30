#include "Arduino.h"
#include "RotateTable.h"
#include "HallEffect.h"
#include "MotorDriver.h"

RotateTable::RotateTable(int pwm, int digital_in, int power_out, int turnspeed){
    HallEffect sensor_init(digital_in);
    MotorDriver motor_init(pwm);

    powerout = power_out;
    sensor = sensor_init;
    motor = motor_init;
    turn_speed = turnspeed;

    Initialize();
}

bool RotateTable::rotate(){
    digitalWrite(powerout, HIGH);
    motor.Move();
    while(!sensor.Read()){delay(5);}
    while(sensor.Read()){delay(5);}
    motor.Stop();
    digitalWrite(powerout, LOW);

    return true;
}

bool RotateTable::rotate(int n){
    if(n == 0){
        rotate();

        return true;
    }
    else{
        digitalWrite(powerout, HIGH);
        motor.Move();
        int i = 0;
        while(i < n){
            while(!sensor.Read()){delay(5);}
            while(sensor.Read()){delay(5);}
        }
        motor.Stop();
        digitalWrite(powerout, LOW);

        return true;
    }
}

void RotateTable::Initialize(){
    motor.setSpeed(turn_speed);
    motor.Stop();
    pinMode(powerout, OUTPUT);
    digitalWrite(powerout, LOW);
}
