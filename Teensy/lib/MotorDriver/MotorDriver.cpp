// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022
//
// A class to interface with the
// motor drivers used.s

#include "Arduino.h"
#include "MotorDriver.h"

MotorDriver::MotorDriver(){}

MotorDriver::MotorDriver(uint8_t pwm_pin_arg){
    pwm_pin = pwm_pin_arg;
    static_direction = true;
    initialize();
}

MotorDriver::MotorDriver(uint8_t pwm_pin_arg, uint8_t pwm_reverse_pin_arg){
    pwm_pin = pwm_pin_arg;
    pwm_reverse_pin = pwm_reverse_pin_arg;
    static_direction = false;
    initialize();
}

void MotorDriver::set_speed(uint8_t speed_arg){
    speed = speed_arg;
}

void MotorDriver::move(){ 
    // Moves motor forward using default speed.
    analogWrite(pwm_pin, speed);
}

void MotorDriver::move(uint8_t speed_arg){
    // Moves motor forward using given speed.
    analogWrite(pwm_pin, speed_arg);
    return;
}

void MotorDriver::move(bool direction_arg){ 
    // Moves motor in given direction using default speed.
    if (direction_arg){
        analogWrite(pwm_pin, speed);
    }
    else{
        analogWrite(pwm_reverse_pin, speed);
    }
}

void MotorDriver::move(uint8_t speed_arg, bool direction_arg){
    // Moves motor in given direction using given speed.
    if (direction_arg){
        analogWrite(pwm_pin, speed_arg);
    }
    else{
        analogWrite(pwm_reverse_pin, speed_arg);
    }
}

void MotorDriver::stop(){
    analogWrite(pwm_pin, 0);
    if(!static_direction){
        analogWrite(pwm_reverse_pin, 0);
    }
}

void MotorDriver::initialize(){
    pinMode(pwm_pin, OUTPUT);
    if(!static_direction){
        pinMode(pwm_reverse_pin, OUTPUT);
    }
    stop();
}

