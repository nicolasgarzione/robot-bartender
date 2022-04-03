#include "Arduino.h"
#include "hallEffect.h"

hallEffect::hallEffect(int signalpin) {
    signal_pin = 16;
    Initialize();
}

hallEffect::hallEffect(int signalpin) {
    signal_pin = signalpin;
    Initialize();
}

bool hallEffect::Read(){
    hallSensorValue = digitalRead(signal_pin);
    return hallSensorValue;
}

void hallEffect::Initialize(){
    pinMode(signal_pin, INPUT);
}