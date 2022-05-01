// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "ShiftRegister.h"

class DrinkDispense {
    public:
    DrinkDispense(uint8_t, uint8_t, uint8_t, uint16_t, uint16_t); //latchPin, clockPin, dataPin
    bool dispense(uint8_t, uint16_t);

    private:

    void initialize();

    ShiftRegister shift;
    float num_of_drinks;
    uint16_t drink_dispense_time;
    uint16_t drink_refill_time;
};