#include <Arduino.h>
//#include "PID.h"

const int latchPin = 9;
const int clockPin = 12;
const int dataPin = 11;

//PID MotorPID(&input, &output, &setpoint, kp, ki, kd, lowerlimit, upperlimit, samplerate, pon);

void setup() {
    //while (!Serial) {
   //     // Waits for serial connection, also allows for reset to return to this checkpoint
   // }
   // Serial.println('This should show up in serial monitor');
   // pinMode(LED_PIN, OUTPUT);
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
   Serial.begin(9600);
   Serial.println("Enter a number from 0-23");
}

void loop() {
    //char msg[] = "Hello from Teensy!";
    //Serial.write(msg, sizeof(msg));
    //digitalWrite(LED_PIN, HIGH);
    //delay(1000);
    //digitalWrite(LED_PIN, LOW);
    //delay(1000);
}