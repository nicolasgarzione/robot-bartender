#include "Arduino.h"
#include "Mixer.h"
#include "motorDriver.h"

Mixer::Mixer(int pwm1, int speed1, int pwm2, int pwmA, int pwmB, int speed2){
    motorDriver motor1_init(pwm1);
    motorDriver motor2_init(pwm2, pwmA, pwmB);

    int motor1_speed = speed1;
    int motor2_speed = speed2;

    default_mix_time = 100; //arbitrary value;

    Initialize();
}

Mixer::Mixer(int pwm1, int speed1, int pwm2, int pwmA, int pwmB, int speed2, int mix_time){
    motorDriver motor1_init(pwm1);
    motorDriver motor2_init(pwm2, pwmA, pwmB);

    int motor1_speed = speed1;
    int motor2_speed = speed2;

    default_mix_time = mix_time;

    Initialize();
}

bool Mixer::Mix(){
    motor2.Move(FORWARD);
    delay(100); //CHANGE THIS BEFORE TEST
    motor2.Stop();
    motor1.Move();
    delay(default_mix_time);
    motor1.Stop();
    motor2.Move(REVERSE);
    delay(100); //CHANGE THIS BEFORE TEST
    motor2.Stop();
}

bool Mixer::Mix(int mix_time){
    motor2.Move(FORWARD);
    delay(100); //CHANGE THIS BEFORE TEST
    motor2.Stop();
    motor1.Move();
    delay(mix_time);
    motor1.Stop();
    motor2.Move(REVERSE);
    delay(100); //CHANGE THIS BEFORE TEST
    motor2.Stop();
}

void Mixer::Initialize(){
    motor1.setSpeed(motor1_speed);
    motor2.setSpeed(motor2_speed);
    motor1.Stop();
    motor2.Stop();
}