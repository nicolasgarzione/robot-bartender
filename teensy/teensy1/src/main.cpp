#include <Arduino.h>
//#include "PID.h"

constexpr int LED_PIN = 13;

//PID MotorPID(&input, &output, &setpoint, kp, ki, kd, lowerlimit, upperlimit, samplerate, pon);

void setup() {
    while (!Serial) {
        // Waits for serial connection, also allows for reset to return to this checkpoint
    }
    Serial.println('This should show up in serial monitor');
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    char msg[] = "Hello from Teensy!";
    Serial.write(msg, sizeof(msg));
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}