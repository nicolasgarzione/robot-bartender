// Author : Nicolas Garzione
// Robot Bartender
// 4/30/2022

#include "Arduino.h"
#include "DrinkDispense.h"
#include "ShiftRegister.h"

DrinkDispense::DrinkDispense(
    uint8_t latch_pin_arg,
    uint8_t clock_pin_arg,
    uint8_t data_pin_arg,
    uint16_t drink_dispense_time_arg,
    uint16_t drink_refill_time_arg) {

    ShiftRegister register_init(latch_pin_arg, clock_pin_arg, data_pin_arg);

    shift = register_init;

    drink_dispense_time = drink_dispense_time_arg;
    drink_refill_time = drink_refill_time_arg;
}

bool DrinkDispense::dispense(
    uint8_t pin_out,
    uint16_t input) { 
    Serial.print(pin_out);
    Serial.print(input);
    delay(10);

    num_of_drinks = input*0.01;
    if (num_of_drinks == 0) {} // Ignores this command if an input of 0 is given
    else if (num_of_drinks < 1) { // Special case if less than 1 shot is called for
        shift.update(pin_out);
        delay(drink_dispense_time*num_of_drinks);
        shift.reset();
    }
    else { // Repeats for number of shots requested
        for (int i = round(num_of_drinks); i > 0; i--) {
            shift.update(pin_out);
            delay(drink_dispense_time); // Time it takes for shot to empty
            shift.reset();
            delay(drink_refill_time); // Time it takes for shot to refill
        }
        shift.reset();
    }

    return true;
}

void DrinkDispense::initialize() {
    shift.reset();
}