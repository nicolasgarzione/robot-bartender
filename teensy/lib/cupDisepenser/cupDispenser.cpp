#include "Arduino.h"
#include "cupDispenser.h"
#include "Servo.h"

cupDispenser::cupDispenser(int pin1, int pin2) {
    Servo createservo1;
    Servo createservo2;
    servo1.attach(pin1);
    servo2.attach(pin2);

    servo1 = createservo1;
    servo2 = createservo2;
}

void cupDispenser::dispense() {
    delay(1000);
    servo1.write(140); servo2.write(25);
    delay(1000);
    servo1.write(70); servo2.write(95);
}
