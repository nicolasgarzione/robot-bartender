#include "Arduino.h"
#include "MotorDriver.h"

MotorDriver::MotorDriver(){}

MotorDriver::MotorDriver(int PWMpin){
    pwm_pin = PWMpin;
    static_direction = true;
    Initialize();
}

MotorDriver::MotorDriver(int PWMpin, int PWMreversepin){
    pwm_pin = PWMpin;
    pwm_reverse_pin = PWMreversepin;
    static_direction = false;
    Initialize();
}

void MotorDriver::setSpeed(int setspeed){
    speed = setspeed;
}

void MotorDriver::Move(){ //use default speed
    analogWrite(pwm_pin, speed);
}

void MotorDriver::Move(int setspeed){
    analogWrite(pwm_pin, setspeed);
    return;
}

void MotorDriver::Move(bool direction){ //forward = true
    if (direction){
        analogWrite(pwm_pin, speed);
    }
    else{
        analogWrite(pwm_reverse_pin, speed);
    }
}

void MotorDriver::Move(int setspeed, bool direction){
    if (direction){
        analogWrite(pwm_pin, setspeed);
    }
    else{
        analogWrite(pwm_reverse_pin, setspeed);
    }
}

void MotorDriver::Stop(){
    analogWrite(pwm_pin, 0);
    if(!static_direction){
        analogWrite(pwm_reverse_pin, 0);
    }
}

void MotorDriver::Initialize(){
    pinMode(pwm_pin, OUTPUT);
    if(!static_direction){
        pinMode(pwm_reverse_pin, OUTPUT);
    }
    Stop();
}

