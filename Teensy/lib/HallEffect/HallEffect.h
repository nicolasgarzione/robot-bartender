// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#ifndef HALLEFFECT_H
#define HALLEFFECT_H

class HallEffect {
    public:
    
    HallEffect();
    HallEffect(uint8_t);
    bool read();

    private:

    void initialize();

    uint8_t signal_pin;
    bool sensor_value;
};

#endif