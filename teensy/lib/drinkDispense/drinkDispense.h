#include "shiftRegister.h"

class drinkDispense {
    public:
    drinkDispense(unsigned const int, unsigned const int, unsigned const int); //latchPin, clockPin, dataPin
    bool dispense(int, int);

    private:
    shiftRegister shiftout;
    double numofdrinks;
    int drinkdispensetime = 4000;
    int drinkrefilltime = 4000;
};