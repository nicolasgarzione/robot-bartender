// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022
//
// A class to command the ice dispenser.

#include "Arduino.h"
#include "IceDispense.h"
#include "MotorDriver.h"

IceDispense::IceDispense(uint8_t pwm_pin_arg, uint8_t turn_speed_arg, uint16_t ice_dispense_time_arg){
    MotorDriver motor_init(pwm_pin_arg);
    
    motor = motor_init;
    turn_speed = turn_speed_arg;
    ice_dispense_time = ice_dispense_time_arg;

    initialize();
}

bool IceDispense::dispense(){
    motor.move();
    delay(ice_dispense_time); // Amount of time the ice dispenses for
    motor.stop();

    return true;
}

void IceDispense::initialize(){
    motor.set_speed(turn_speed);
    motor.stop();
}