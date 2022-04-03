#include "Arduino.h"
#include "shiftRegister.h"

shiftRegister::shiftRegister() {
    latch_pin = 9;
    clock_pin = 12;
    data_pin = 11;

    pinout = 0;

    Initialize();
}

shiftRegister::shiftRegister(
    unsigned const int latchPin,
    unsigned const int clockPin,
    unsigned const int dataPin) {

    latch_pin = latchPin;
    clock_pin = clockPin;
    data_pin = dataPin;

    pinout = 0;

    Initialize();
}

void shiftRegister::Update(int set){
    bitSet(pinout, set);
    digitalWrite(latch_pin, LOW);
    shiftOut(data_pin, clock_pin, LSBFIRST, pinout);
    digitalWrite(latch_pin, HIGH);
}

void shiftRegister::Initialize(){
    pinMode(latch_pin, OUTPUT);
    pinMode(clock_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);
    Update(0);
}

void shiftRegister::Reset(){
    Update(0);
}