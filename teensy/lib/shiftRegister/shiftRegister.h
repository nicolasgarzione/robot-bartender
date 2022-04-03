#include <inttypes.h>

class shiftRegister {
    public:
    shiftRegister();
    shiftRegister(unsigned const int, unsigned const int, unsigned const int); //latchPin, clockPin, dataPin
    void Update(int);
    void Reset();

    private:

    void Initialize();

    unsigned int latch_pin;
    unsigned int clock_pin;
    unsigned int data_pin;

    uint8_t pinout;
};