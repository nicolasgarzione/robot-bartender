// Authors : Nicolas Garzione, Tejas Bhagoliwal
// Robot Bartender
// 4/30/2022
//
// A class to command the cup dispenser.

#include "Arduino.h"
#include "CupDispense.h"
#include "Servo.h"

CupDispense::CupDispense(uint8_t pin_1, uint8_t pin_2) {
    Servo create_servo_1;
    Servo create_servo_2;
    create_servo_1.attach(pin_1);
    create_servo_2.attach(pin_2);

    servo_1 = create_servo_1;
    servo_2 = create_servo_2;
}

bool CupDispense::dispense() {
    delay(200);
    servo_1.write(70); servo_2.write(95); // Arms move out, loading cup
    delay(1000);
    servo_1.write(140); servo_2.write(25); // Arms move back, dropping cup
    delay(1000);

    return true;
}
