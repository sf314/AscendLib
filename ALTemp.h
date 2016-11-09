// Def for Temperature sensor

#include "Arduino.h"

class ALTemp {
public:
    void setPin(int i);
    void setVoltage(double v); // 5.0 or 3.3
    double read();
private:
    static int tempPin; // default analog 0
    static int voltage; // default 5V
};
