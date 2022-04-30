#include "Arduino.h"
#include "IceDispense.h"
#include "MotorDriver.h"

IceDispense::IceDispense(int pwm, int turnspeed){
    MotorDriver motor_init(pwm);
    
    motor = motor_init;
    turn_speed = turnspeed;

    Initialize();
}

bool IceDispense::dispense(){
    motor.Move();
    delay(ice_dispense_time);
    motor.Stop();

    return true;
}

void IceDispense::Initialize(){
    motor.setSpeed(turn_speed);
    motor.Stop();
}