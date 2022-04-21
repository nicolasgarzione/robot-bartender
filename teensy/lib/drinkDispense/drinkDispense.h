#include "shiftRegister.h"

class drinkDispense {
    public:
    drinkDispense(unsigned const int, unsigned const int, unsigned const int); //latchPin, clockPin, dataPin
    bool dispense(int, int);

    private:
    shiftRegister shiftout;
    double numofdrinks;
    int drinkdispensetime = 100;
};