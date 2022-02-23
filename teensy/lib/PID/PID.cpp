#include "Arduino.h"
#include "PID.h"

PID::PID(
    double* const In,       // Pointer to input value (sensor data)
    double* const Out,      // Pointer to output value (actuation command)
    double* const Set,      // Pointer to state PID controller is trying to reach (desired angle, position, etc.)
    const double Kp,        // Proportional
    const double Ki,        // Integral
    const double Kd,        // Derivative
    unsigned const int lowerLimit,   // Lowest allowable analog limit (usually 0)
    unsigned const int upperLimit,   // Highest allowable analog limit (usually 255)
    unsigned const int sampleTime,   // Sample time of controller (usually 100 ms)
    const bool POn) {        // Proportional on measurement or error (usually true)

    Output = Out;
    Input = In;
    Setpoint = Set;

    PID::SetOutputLimits(lowerLimit, upperLimit);
    PID::SetSampleTime(sampleTime);
    PID::SetTuning(Kp, Ki, Kd, POn);

    previousTime = millis() - sampleTime;
}

bool PID::Compute() {
    unsigned long currentTime = millis();
    unsigned long timeChange = (currentTime - previousTime);
    if (timeChange >= sampleTime) {
        double currentInput = *Input;
        double error = *Setpoint - currentInput;
        double deltaInput = (currentInput - lastInput);
        outputSum += (Ki * error);

        if (!pOnE) outputSum -= Kp * deltaInput;

        if (outputSum > outMax) outputSum = outMax;
        if (outputSum < outMin) outputSum = outMin;

        double currentOutput;
        if (pOnE) currentOutput = Kp * error;
        else currentOutput = 0;
        *Output = currentOutput;

        lastInput = currentInput;
        previousTime = currentTime;
        return true;
    }
    else return false;
}

void PID::SetOutputLimits(unsigned const int Min, unsigned const int Max) {
    if(Min >= Max) return;
    outMin = Min;
    outMax = Max;
}

void PID::SetTuning(double kp, double ki, double kd, bool POn) {
    //if (kp < 0 | ki < 0 | kd < 0) return;

    pOn = POn;
    pOnE = POn == P_ON_E;

    double sampleTimeInSec = ((double)sampleTime)/1000;
    Kp = kp;
    Ki = ki * sampleTimeInSec;
    Kd = kd / sampleTimeInSec;
}

void PID::SetSampleTime(const unsigned int inputTime) {
    sampleTime = inputTime;
}

void PID::Initialize() {
    outputSum = *Output;
    lastInput = *Input;
    if(outputSum > outMax) outputSum = outMax;
    else if(outputSum < outMin) outputSum = outMin;
}