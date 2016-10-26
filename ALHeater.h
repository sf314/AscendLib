// Code to easily implement the heating element

#include "Arduino.h"

class ALHeater {
public:
    void setPin(int i);
    void setHeat(int heatLevel); // between 0 and 255
        // 0        0%   duty cycle
        // 85       33%  duty cycle
        // 170      66%  duty cycle
        // 255      100% duty cycle
private:
    static int heatPin; // defaults to A3
};


/*
Notes on wiring:
Connect MOSFET Gate pin to digital pin 3
Connect MOSFET Drain pin to ground of heating pad(s)
Connect MOSFET Source to Arduino ground
Connect 10k resistor from digital pin 3 (between board and MOSFET Gate) to Arduino ground (between board and MOSFET Source)
Connect heating pad V to Arduino 5V
// See image placed in AscendLib folder

*/
