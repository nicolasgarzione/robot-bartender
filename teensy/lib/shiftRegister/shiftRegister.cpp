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

void shiftRegister::shiftOut(byte dataOut) {
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

void shiftRegister::Update(int set){
    if (set > 7) {
        pinout = decimaltohex(set-7);
        digitalWrite(latch_pin, LOW);
        shiftOut(0);
        shiftOut(pinout);
        digitalWrite(latch_pin, HIGH);
        delay(300);
    }
    else {
        pinout = decimaltohex(set+1);
        digitalWrite(latch_pin, LOW);
        shiftOut(pinout);
        shiftOut(0);
        digitalWrite(latch_pin, HIGH);
        delay(300);
    }
}

void shiftRegister::Initialize(){
    pinMode(latch_pin, OUTPUT);
    Update(0);
}

void shiftRegister::Reset(){
    Update(0);
}

byte shiftRegister::decimaltohex(int set){
    return hexarray[set];
}
