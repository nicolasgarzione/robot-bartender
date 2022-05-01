// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include <inttypes.h>

#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

class ShiftRegister {
    public:
    ShiftRegister();
    ShiftRegister(uint8_t, uint8_t, uint8_t); //latchPin, clockPin, dataPin
    void shift_out(byte);
    void update(int);
    void reset();
    byte decimal_to_hex(int);

    private:

    void initialize();

    uint8_t latch_pin;
    uint8_t clock_pin;
    uint8_t data_pin;

    uint8_t i;
    uint8_t pinState;

    uint8_t firsthalf;
    uint8_t secondhalf;

    byte pinout;
    byte hexarray[9] = {
        0x00,
        0x01,
        0x02,
        0x04,
        0x08,
        0x10,
        0x20,
        0x40,
        0x80
    };
};

#endif