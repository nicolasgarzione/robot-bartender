#include "shiftRegister.h"

class DrinkDispense {
    public:
    DrinkDispense(unsigned const int, unsigned const int, unsigned const int); //latchPin, clockPin, dataPin
    bool dispense(int, int);

    private:
    ShiftRegister shiftout;
    double numofdrinks;
    int drinkdispensetime = 4000;
    int drinkrefilltime = 4000;
};