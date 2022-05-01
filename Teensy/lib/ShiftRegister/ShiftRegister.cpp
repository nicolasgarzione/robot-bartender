// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022
//
// A class to interface the Teensy with
// the shift registers.

#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister() {
    latch_pin = 9;
    clock_pin = 12;
    data_pin = 11;

    pinout = 0;

    initialize();
}

ShiftRegister::ShiftRegister(
    uint8_t latchPin,
    uint8_t clockPin,
    uint8_t dataPin) {

    latch_pin = latchPin;
    clock_pin = clockPin;
    data_pin = dataPin;

    pinout = 0;

    initialize();
}

void ShiftRegister::shift_out(byte dataOut) {
    // Operation to update shift registers 
    // to set given pin to high
    i=0;

    pinMode(clock_pin, OUTPUT);
    pinMode(data_pin, OUTPUT);

    digitalWrite(data_pin, 0);
    digitalWrite(clock_pin, 0);

    for (i=7; i>=0; i--)  {
        digitalWrite(clock_pin, 0);
        if (dataOut & (1<<i) ) {
            pinState= 1;
        }
        else {
            pinState= 0;
        }

        digitalWrite(data_pin, pinState);

        digitalWrite(clock_pin, 1);

        digitalWrite(data_pin, 0);
    }

    digitalWrite(clock_pin, 0);
}

void ShiftRegister::update(int set){
    // Given a number, update the shift
    // registers to set that pin to high.
    // Can utilize daisy-chained shift
    // registers.
    if (set > 7) {
        pinout = decimal_to_hex(set-7);
        digitalWrite(latch_pin, LOW);
        shift_out(0);
        shift_out(pinout);
        digitalWrite(latch_pin, HIGH);
        delay(300);
    }
    else {
        pinout = decimal_to_hex(set+1);
        digitalWrite(latch_pin, LOW);
        shift_out(pinout);
        shift_out(0);
        digitalWrite(latch_pin, HIGH);
        delay(300);
    }
}

void ShiftRegister::initialize(){
    pinMode(latch_pin, OUTPUT);
    update(0);
}

void ShiftRegister::reset(){
    update(0);
}

byte ShiftRegister::decimal_to_hex(int set){
    return hexarray[set];
}
