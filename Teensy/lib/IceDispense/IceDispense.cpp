// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "Arduino.h"
#include "IceDispense.h"
#include "MotorDriver.h"

IceDispense::IceDispense(uint8_t pwm_pin_arg, uint8_t turn_speed_arg){
    MotorDriver motor_init(pwm_pin_arg);
    
    motor = motor_init;
    turn_speed = turn_speed_arg;

    initialize();
}

bool IceDispense::dispense(){
    motor.move();
    delay(ice_dispense_time);
    motor.stop();

    return true;
}

void IceDispense::initialize(){
    motor.set_speed(turn_speed);
    motor.stop();
}