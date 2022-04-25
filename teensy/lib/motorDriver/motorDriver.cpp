#include "Arduino.h"
#include "motorDriver.h"

motorDriver::motorDriver(){}

motorDriver::motorDriver(int PWMpin){
    pwm_pin = PWMpin;
    static_direction = true;
    Initialize();
}

motorDriver::motorDriver(int PWMpin, int PWMreversepin){
    pwm_pin = PWMpin;
    pwm_reverse_pin = PWMreversepin;
    static_direction = false;
    Initialize();
}

void motorDriver::setSpeed(int setspeed){
    speed = setspeed;
}

void motorDriver::Move(){ //use default speed
    analogWrite(pwm_pin, speed);
}

void motorDriver::Move(int setspeed){
    analogWrite(pwm_pin, setspeed);
    return;
}

void motorDriver::Move(bool direction){ //forward = true
    if (direction){
        analogWrite(pwm_pin, speed);
    }
    else{
        analogWrite(pwm_reverse_pin, speed);
    }
}

void motorDriver::Move(int setspeed, bool direction){
    if (direction){
        analogWrite(pwm_pin, setspeed);
    }
    else{
        analogWrite(pwm_reverse_pin, setspeed);
    }
}

void motorDriver::Stop(){
    analogWrite(pwm_pin, 0);
    if(!static_direction){
        analogWrite(pwm_reverse_pin, 0);
    }
}

void motorDriver::Initialize(){
    pinMode(pwm_pin, OUTPUT);
    if(!static_direction){
        pinMode(pwm_reverse_pin, OUTPUT);
    }
    Stop();
}

