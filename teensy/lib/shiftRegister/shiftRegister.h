#include <inttypes.h>

#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

class shiftRegister {
    public:
    shiftRegister();
    shiftRegister(unsigned const int, unsigned const int, unsigned const int); //latchPin, clockPin, dataPin
    void shiftOut(byte);
    void Update(int);
    void Reset();
    byte decimaltohex(int);

    private:

    void Initialize();

    unsigned int latch_pin;
    unsigned int clock_pin;
    unsigned int data_pin;

    int i;
    int pinState;

    int firsthalf;
    int secondhalf;

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