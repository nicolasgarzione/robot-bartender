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
    int time) { //time in ms

    shiftout.Update(pinout);
    delay(time);
    shiftout.Reset();

    return true;
}