// Authors : Nicolas Garzione, Tejas Bhagoliwal
// Robot Bartender
// 4/30/2022

#include "Arduino.h"
#include "Mixer.h"
#include "MotorDriver.h"

Mixer::Mixer(uint8_t pwm_pin_1_arg, uint8_t speed_1_arg, uint8_t pwm_pin_2_arg, uint8_t pwm_reverse_pin_2_arg, uint8_t speed_2_arg){
    MotorDriver motor1_init(pwm_pin_1_arg);
    MotorDriver motor2_init(pwm_pin_2_arg, pwm_reverse_pin_2_arg);

    motor_1 = motor1_init;
    motor_2 = motor2_init;

    uint8_t motor_1_speed = speed_1_arg;
    uint8_t motor_2_speed = speed_2_arg;

    motor_1.set_speed(motor_1_speed);
    motor_2.set_speed(motor_2_speed);

    default_mix_time = 3000; //arbitrary value;

    initialize();
}

Mixer::Mixer(uint8_t pwm_pin_1_arg, uint8_t speed_1_arg, uint8_t pwm_pin_2_arg, uint8_t pwm_reverse_pin_2_arg, uint8_t speed_2_arg, uint16_t mix_time_arg){
    MotorDriver motor1_init(pwm_pin_1_arg);
    MotorDriver motor2_init(pwm_pin_2_arg, pwm_reverse_pin_2_arg);

    motor_1 = motor1_init;
    motor_2 = motor2_init;

    motor_1.set_speed(motor_1_speed);
    motor_2.set_speed(motor_2_speed);

    default_mix_time = mix_time_arg;

    initialize();
}

bool Mixer::mix(){
    delay(200);
    motor_2.move(FORWARD);
    delay(450); //CHANGE THIS BEFORE TEST
    motor_2.stop();
    delay(400);
    motor_1.move();
    delay(default_mix_time);
    motor_1.stop();
    delay(400);
    motor_2.move(REVERSE);
    delay(570); //CHANGE THIS BEFORE TEST
    motor_2.stop();

    return true;
}

bool Mixer::mix(uint16_t mix_time){
    if (mix_time == 0) {
        mix();
    }
    else {
        delay(200);
        motor_2.move(FORWARD);
        delay(450); //CHANGE THIS BEFORE TEST
        motor_2.stop();
        delay(400);
        motor_1.move();
        delay(mix_time);
        motor_1.stop();
        delay(400);
        motor_2.move(REVERSE);
        delay(570); //CHANGE THIS BEFORE TEST
        motor_2.stop();
    } 

    return true;
}

void Mixer::initialize(){
    motor_1.stop();
    motor_2.stop();
}