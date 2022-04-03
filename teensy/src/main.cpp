#include <Arduino.h>
//#include "PID.h"
#include "cupDispense.h"
#include "drinkDispense.h"
#include "rotateTable.h"
#include "Mixer.h"

const int RX_PIN = 0;
const int TX_PIN = 1;
const int DC1A_PIN = 2;
const int DC1B_PIN = 3;
const int DC1PWM_PIN = 4;
const int DC2PWM_PIN = 5;
const int DC3PWM_PIN = 6;
const int DC4PWM_PIN = 7;
const int LATCH_PIN = 9;
const int DATA_PIN = 11;
const int CLOCK_PIN = 12;
const int SERVO1PWM_PIN = 19;
const int SERVO2PWM_PIN = 18;
const int HALLEFFECT_PIN = 16;

const int TABLE_ROTATION_SPEED = 100; //change this
const int DEFAULT_MIX_TIME = 100; //change this
const int MIXER_LINEAR_SPEED = 100; //change this
const int MIXER_ROTATION_SPEED = 100; //change this



//PID MotorPID(&input, &output, &setpoint, kp, ki, kd, lowerlimit, upperlimit, samplerate, pon);

void setup() { //NEEDS TO BE INCLUDED TO COMPILE
    drinkDispense drink(LATCH_PIN, CLOCK_PIN, DATA_PIN);
    cupDispense cup(SERVO1PWM_PIN, SERVO2PWM_PIN);
    rotateTable table(DC3PWM_PIN, HALLEFFECT_PIN, TABLE_ROTATION_SPEED);
    Mixer mixer(DC2PWM_PIN, MIXER_ROTATION_SPEED, DC1PWM_PIN, DC1A_PIN, DC1B_PIN, MIXER_LINEAR_SPEED);

    Serial.begin(9600);
    while (!Serial) {
        // Waits for serial connection, also allows for reset to return to this checkpoint
    }
    Serial.println('This should show up in serial monitor');
}

void loop() { //NEEDS TO BE INCLUDED TO COMPILE
    
}

