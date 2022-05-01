// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "Arduino.h"
#include "RotateTable.h"
#include "HallEffect.h"
#include "MotorDriver.h"

RotateTable::RotateTable(uint8_t pwm_arg, uint8_t digital_pin_arg, uint8_t power_pin_arg, uint8_t turn_speed_arg){
    HallEffect sensor_init(digital_pin_arg);
    MotorDriver motor_init(pwm_arg);

    power_pin = power_pin_arg;
    sensor = sensor_init;
    motor = motor_init;
    turn_speed = turn_speed_arg;

    initialize();
}

bool RotateTable::rotate(){
    digitalWrite(power_pin, HIGH);
    motor.move();
    while(!sensor.read()){delay(5);}
    while(sensor.read()){delay(5);}
    motor.stop();
    digitalWrite(power_pin, LOW);

    return true;
}

bool RotateTable::rotate(uint8_t n){
    if(n == 0){
        rotate();

        return true;
    }
    else{
        digitalWrite(power_pin, HIGH);
        motor.move();
        int i = 0;
        while(i < n){
            while(!sensor.read()){delay(5);}
            while(sensor.read()){delay(5);}
        }
        motor.stop();
        digitalWrite(power_pin, LOW);

        return true;
    }
}

void RotateTable::initialize(){
    motor.set_speed(turn_speed);
    motor.stop();
    pinMode(power_pin, OUTPUT);
    digitalWrite(power_pin, LOW);
}
