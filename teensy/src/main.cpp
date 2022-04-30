#include <iostream>
#include <sstream>
#include <string>

#include <Arduino.h>
//#include "PID.h"
#include "CupDispense.h"
#include "DrinkDispense.h"
#include "IceDispense.h"
#include "RotateTable.h"
#include "Mixer.h"

const int RX_PIN = 0;
const int TX_PIN = 1;
const int DC1PWM_REVERSE_PIN = 3;
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
const int HALLEFFECT_POWER_PIN = 17;
const int LED_PIN = 13;

const int TABLE_ROTATION_SPEED = 256; //change this
const int ICE_DISPENSE_SPEED = 100;
const int DEFAULT_MIX_TIME = 3000; //change this
const int MIXER_LINEAR_SPEED = 100; //change this
const int MIXER_ROTATION_SPEED = 256; //change this

std::string cmd;
std::string split1;
std::string split2;
std::string split3;

std::stringstream ss1;
std::stringstream ss2;

char subsystem;
int identifier;
int value;

bool continue_indicator;
bool should_continue;

bool executeCMD(char, int, int);

DrinkDispense drink(LATCH_PIN, CLOCK_PIN, DATA_PIN);
CupDispense cup(SERVO1PWM_PIN, SERVO2PWM_PIN);
IceDispense ice(DC4PWM_PIN, ICE_DISPENSE_SPEED);
RotateTable table(DC3PWM_PIN, HALLEFFECT_PIN, HALLEFFECT_POWER_PIN, TABLE_ROTATION_SPEED);
Mixer mixer(DC2PWM_PIN, MIXER_ROTATION_SPEED, DC1PWM_PIN, DC1PWM_REVERSE_PIN, MIXER_LINEAR_SPEED);
//PID MotorPID(&input, &output, &setpoint, kp, ki, kd, lowerlimit, upperlimit, samplerate, pon);

void setup() { //NEEDS TO BE INCLUDED TO COMPILE
    Serial.begin(9600);
    while (!Serial) {
        // Waits for serial connection
    }
    //Serial.println("This should show up in serial monitor");
    pinMode(LED_PIN, OUTPUT);
}

void loop() { //NEEDS TO BE INCLUDED TO COMPILE
    if (Serial.available() == 7) {
        digitalWrite(LED_PIN, HIGH);
        cmd = "";
        split1.clear();
        split2.clear();
        split3.clear();
        ss1.str(std::string());
        ss1.clear();
        ss2.str(std::string());
        ss2.clear();

        subsystem = 'Z';
        identifier = 0;
        value = 0;

        cmd = Serial.readStringUntil('\n').c_str();

        split1 = cmd[0];

        split2.push_back(cmd[1]);
        split2.push_back(cmd[2]);
        split2.push_back(cmd[3]);

        split3.push_back(cmd[4]);
        split3.push_back(cmd[5]);

        subsystem = split1[0];

        ss1 << split2;
        ss1 >> value;

        ss2 << split3;
        ss2 >> identifier;

        //Serial.println(subsystem);
        //Serial.println(value);
        //Serial.println(identifier);

        continue_indicator = executeCMD(subsystem, value, identifier);
        if (continue_indicator == true) {
            Serial.println('1');
        }
        else {
            Serial.println('0');
        }
        digitalWrite(LED_PIN, LOW);
        //Serial.println(continue_indicator);
    }
    else if (Serial.available() > 6) {
        Serial.println('0');
        Serial.flush();
    }
}

bool executeCMD(char subsystem, int value, int identifier) {
    switch(subsystem) {
        case 'A':
            should_continue = table.rotate(value);
            //should_continue = true;
            break;
        case 'B':
            should_continue = drink.dispense(identifier, value);
            //should_continue = true;
            break;
        case 'C':
            should_continue = cup.dispense();
            //should_continue = true;
            break;
        case 'D':
            should_continue = mixer.mix();
            //should_continue = true;
            break;
        case 'E': //ice
            should_continue = ice.dispense();
            //should_continue = true;
            break;
        case 'X': //error 
            should_continue = false;
            break;
        case 'Z': //to ping 
            should_continue = true;
            break;
        default:
            should_continue = false;
            break;
    }
    return should_continue;
}

