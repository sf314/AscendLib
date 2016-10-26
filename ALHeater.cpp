// Implementing the heater Code

#include "ALHeater.h"

int ALHeater::heatPin = 3; // Arduino digital pin

void ALHeater::setPin(int i) {
    heatPin = i;
}

void ALHeater::setHeat(int heatLevel) {
    analogWrite(heatPin, heatLevel);
    // Takes values from 0 to 255
}
