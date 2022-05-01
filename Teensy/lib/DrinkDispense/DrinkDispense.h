// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "ShiftRegister.h"

class DrinkDispense {
    public:
    DrinkDispense(uint8_t, uint8_t, uint8_t); //latchPin, clockPin, dataPin
    bool dispense(uint8_t, uint16_t);

    private:
    ShiftRegister shift;
    float num_of_drinks;
    uint8_t drink_dispense_time = 4000;
    uint8_t drink_refill_time = 4000;
};