#ifndef HALLEFFECT_H
#define HALLEFFECT_H

class hallEffect {
    public:
    
    hallEffect();
    hallEffect(int);
    bool Read();

    private:

    void Initialize();

    int signal_pin;
    bool hallSensorValue;
};

#endif