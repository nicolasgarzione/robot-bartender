#include "Arduino.h"
#include "HallEffect.h"

HallEffect::HallEffect() {
    signal_pin = 16;
    initialize();
}

HallEffect::HallEffect(uint8_t signal_pin_arg) {
    signal_pin = signal_pin_arg;
    initialize();
}

bool HallEffect::read(){
    sensor_value = digitalRead(signal_pin);
    return sensor_value;
}

void HallEffect::initialize(){
    pinMode(signal_pin, INPUT);
}