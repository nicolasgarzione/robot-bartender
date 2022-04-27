#include "Arduino.h"
#include "Mixer.h"
#include "motorDriver.h"

Mixer::Mixer(int pwm1, int speed1, int pwm2, int pwm2_reverse, int speed2){
    motorDriver motor1_init(pwm1);
    motorDriver motor2_init(pwm2, pwm2_reverse);

    motor1 = motor1_init;
    motor2 = motor2_init;

    int motor1_speed = speed1;
    int motor2_speed = speed2;

    motor1.setSpeed(motor1_speed);
    motor2.setSpeed(motor2_speed);

    default_mix_time = 3000; //arbitrary value;

    Initialize();
}

Mixer::Mixer(int pwm1, int speed1, int pwm2, int pwm2_reverse, int speed2, int mix_time){
    motorDriver motor1_init(pwm1);
    motorDriver motor2_init(pwm2, pwm2_reverse);

    motor1 = motor1_init;
    motor2 = motor2_init;

    motor1.setSpeed(motor1_speed);
    motor2.setSpeed(motor2_speed);

    default_mix_time = mix_time;

    Initialize();
}

bool Mixer::mix(){
    delay(200);
    motor2.Move(FORWARD);
    delay(450); //CHANGE THIS BEFORE TEST
    motor2.Stop();
    delay(400);
    motor1.Move();
    delay(default_mix_time);
    motor1.Stop();
    delay(400);
    motor2.Move(REVERSE);
    delay(570); //CHANGE THIS BEFORE TEST
    motor2.Stop();

    return true;
}

bool Mixer::mix(int mix_time){
    if (mix_time == 0) {
        mix();
    }
    else {
        delay(5000);
        motor2.Move(FORWARD);
        delay(1000); //CHANGE THIS BEFORE TEST
        motor2.Stop();
        motor1.Move();
        delay(mix_time);
        motor1.Stop();
        motor2.Move(REVERSE);
        delay(1000); //CHANGE THIS BEFORE TEST
        motor2.Stop();
    } 

    return true;
}

void Mixer::Initialize(){
    motor1.Stop();
    motor2.Stop();
}