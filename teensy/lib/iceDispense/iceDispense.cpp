#include "Arduino.h"
#include "iceDispense.h"
#include "motorDriver.h"

iceDispense::iceDispense(int pwm, int turnspeed){
    motorDriver motor_init(pwm);
    
    motor = motor_init;
    turn_speed = turnspeed;

    Initialize();
}

bool iceDispense::dispense(){
    motor.Move();
    delay(ice_dispense_time);
    motor.Stop();

    return true;
}

void iceDispense::Initialize(){
    motor.setSpeed(turn_speed);
    motor.Stop();
}