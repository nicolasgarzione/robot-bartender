#include "Arduino.h"
#include "CupDispense.h"
#include "Servo.h"

CupDispense::CupDispense(int pin1, int pin2) {
    Servo createservo1;
    Servo createservo2;
    createservo1.attach(pin1);
    createservo2.attach(pin2);

    servo1 = createservo1;
    servo2 = createservo2;
}

bool CupDispense::dispense() {
    delay(200);
    servo1.write(70); servo2.write(95);
    delay(1000);
    servo1.write(140); servo2.write(25);
    delay(1000);

    return true;
}
