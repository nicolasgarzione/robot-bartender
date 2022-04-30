#include "Arduino.h"
#include "HallEffect.h"

HallEffect::HallEffect() {
    signal_pin = 16;
    Initialize();
}

HallEffect::HallEffect(int signalpin) {
    signal_pin = signalpin;
    Initialize();
}

bool HallEffect::Read(){
    hallSensorValue = digitalRead(signal_pin);
    return hallSensorValue;
}

void HallEffect::Initialize(){
    pinMode(signal_pin, INPUT);
}