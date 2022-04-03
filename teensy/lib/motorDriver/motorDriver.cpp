#include "Arduino.h"
#include "motorDriver.h"

motorDriver::motorDriver(){}

motorDriver::motorDriver(int PWMpin){
    pwm_pin = PWMpin;
    static_a_b_pins = true;
    Initialize();
}

motorDriver::motorDriver(int PWMpin, int Apin, int Bpin){
    pwm_pin = PWMpin;
    a_pin = Apin;
    b_pin = Bpin;
    static_a_b_pins = false;
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
}

void motorDriver::Move(bool direction){ //forward = true
    if (direction){
        digitalWrite(a_pin, HIGH);
        digitalWrite(a_pin, LOW);
    }
    else{
        digitalWrite(a_pin, LOW);
        digitalWrite(a_pin, HIGH);
    }
    analogWrite(pwm_pin, speed);
}

void motorDriver::Move(int setspeed, bool direction){
    if (direction){
        digitalWrite(a_pin, HIGH);
        digitalWrite(a_pin, LOW);
    }
    else{
        digitalWrite(a_pin, LOW);
        digitalWrite(a_pin, HIGH);
    }
    analogWrite(pwm_pin, setspeed);
}

void motorDriver::Stop(){
    Move(0);
}

void motorDriver::Initialize(){
    pinMode(pwm_pin, OUTPUT);
    if(!static_a_b_pins){
        pinMode(a_pin, OUTPUT);
        pinMode(b_pin, OUTPUT);
    }
    Stop();
}

