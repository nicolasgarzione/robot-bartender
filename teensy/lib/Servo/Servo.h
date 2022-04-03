#ifndef PWMServo_h
#define PWMServo_h

#include <inttypes.h>

class Servo
{
  public:
    Servo();
    uint8_t attach(int pinArg) { return attach(pinArg, 544, 2400); }
                             // pulse length for 0 degrees in microseconds, 544uS default
                             // pulse length for 180 degrees in microseconds, 2400uS default
    uint8_t attach(int pinArg, int min, int max);
                             // attach to a pin, sets pinMode, returns 0 on failure, won't
                             // position the servo until a subsequent write() happens
                             // Only works for 9 and 10.
    void detach();
    void write(int angleArg); // specify the angle in degrees, 0 to 180
    uint8_t read() { return angle; }
    uint8_t attached();
    
  private:
    uint8_t pin;
    uint8_t angle;       // in degrees
    uint8_t min16;       // minimum pulse, 16uS units  (default is 34)
    uint8_t max16;       // maximum pulse, 16uS units, 0-4ms range (default is 150)
    static uint32_t attachedpins[]; // 1 bit per digital pin
};

#endif