// Implementing the heater Code

#include "ALHeater.h"

int ALHeater::heatPin = 3; // Arduino digital pin

void ALHeater::setPin(int i) {
    heatPin = i;
}

void ALHeater::setHeat(int heatLevel) {
    analogWrite(heatPin, heatLevel);
    // Takes values from 0 to 255
    // Needs about 20s to get sufficiently hot.
    // Create a graph of temp over time, make func for temp given heatLevel
}
