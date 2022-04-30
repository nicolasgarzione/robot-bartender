#ifndef HALLEFFECT_H
#define HALLEFFECT_H

class HallEffect {
    public:
    
    HallEffect();
    HallEffect(int);
    bool Read();

    private:

    void Initialize();

    int signal_pin;
    bool hallSensorValue;
};

#endif