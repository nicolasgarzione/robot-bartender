// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include <iostream>
#include <sstream>
#include <string>

#include <Arduino.h>
#include "CupDispense.h"
#include "DrinkDispense.h"
#include "IceDispense.h"
#include "RotateTable.h"
#include "Mixer.h"

const uint8_t RX_PIN = 0;
const uint8_t TX_PIN = 1;
const uint8_t DC1PWM_REVERSE_PIN = 3;
const uint8_t DC1PWM_PIN = 4;
const uint8_t DC2PWM_PIN = 5;
const uint8_t DC3PWM_PIN = 6;
const uint8_t DC4PWM_PIN = 7;
const uint8_t LATCH_PIN = 9;
const uint8_t DATA_PIN = 11;
const uint8_t CLOCK_PIN = 12;
const uint8_t SERVO1PWM_PIN = 19;
const uint8_t SERVO2PWM_PIN = 18;
const uint8_t HALLEFFECT_PIN = 16;
const uint8_t HALLEFFECT_POWER_PIN = 17;
const uint8_t LED_PIN = 13;

const uint8_t TABLE_ROTATION_SPEED = 256; //change this
const uint8_t ICE_DISPENSE_SPEED = 100;
const uint16_t DEFAULT_MIX_TIME = 3000; //change this
const uint8_t MIXER_LINEAR_SPEED = 100; //change this
const uint8_t MIXER_ROTATION_SPEED = 256; //change this

std::string cmd;
std::string split1;
std::string split2;
std::string split3;

std::stringstream ss1;
std::stringstream ss2;

char subsystem;
uint8_t identifier;
uint8_t value;

bool continue_indicator;
bool should_continue;

bool executeCMD(char, int, int);

DrinkDispense drink(LATCH_PIN, CLOCK_PIN, DATA_PIN);
CupDispense cup(SERVO1PWM_PIN, SERVO2PWM_PIN);
IceDispense ice(DC4PWM_PIN, ICE_DISPENSE_SPEED);
RotateTable table(DC3PWM_PIN, HALLEFFECT_PIN, HALLEFFECT_POWER_PIN, TABLE_ROTATION_SPEED);
Mixer mixer(DC2PWM_PIN, MIXER_ROTATION_SPEED, DC1PWM_PIN, DC1PWM_REVERSE_PIN, MIXER_LINEAR_SPEED);

void setup() { //NEEDS TO BE INCLUDED TO COMPILE
    Serial.begin(9600);
    while (!Serial) {} // Waits for serial connection
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

        continue_indicator = executeCMD(subsystem, value, identifier);
        if (continue_indicator == true) {
            Serial.println('1');
        }
        else {
            Serial.println('0');
        }
        digitalWrite(LED_PIN, LOW);
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
            break;
        case 'B':
            should_continue = drink.dispense(identifier, value);
            break;
        case 'C':
            should_continue = cup.dispense();
            break;
        case 'D':
            should_continue = mixer.mix();
            break;
        case 'E': 
            should_continue = ice.dispense();
            break;
        case 'X':  
            should_continue = false;
            break;
        case 'Z':  
            should_continue = true;
            break;
        default:
            should_continue = false;
            break;
    }
    return should_continue;
}

