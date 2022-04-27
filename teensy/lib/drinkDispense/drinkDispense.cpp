#include "Arduino.h"
#include "drinkDispense.h"
#include "shiftRegister.h"

drinkDispense::drinkDispense(
    unsigned const int latchPin,
    unsigned const int clockPin,
    unsigned const int dataPin) {

    shiftRegister register_init(latchPin, clockPin, dataPin);

    shiftout = register_init;
}

bool drinkDispense::dispense(
    int pinout,
    int input) { //time in ms
    Serial.print(pinout);
    Serial.print(input);
    delay(10);

    numofdrinks = input*0.01;
    if (numofdrinks == 0) {
        // do nothing
    }
    else if (numofdrinks < 1) {
        shiftout.Update(pinout);
        delay(drinkdispensetime*numofdrinks);
        shiftout.Reset();
    }
    else {
        for (int i = round(numofdrinks); i > 0; i--) {
            shiftout.Update(pinout);
            delay(drinkdispensetime);
            shiftout.Reset();
            delay(drinkrefilltime);
        }
        shiftout.Reset();
    }

    return true;
}