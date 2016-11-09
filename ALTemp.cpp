// Implementing Temp sensor
#include "Arduino.h"
#include "ALTemp.h"

int ALTemp::tempPin  = 0;
int ALTemp::voltage = 5000;

void ALTemp::setPin(int i) {
    tempPin = i;
}

void ALTemp::setVoltage(double v) {
    // switch (v) {
    //     case 5.0:
    //         voltage = 5000;
    //         break;
    //     case 3.3:
    //         voltage = 3300;
    //         break;
    //     default:
    //         Serial.println("ALTemp: Undefined voltage. Pass 5 or 3.3");
    //         voltage = 5000;
    //         break;
    // }
    if (v == 5.0) {
        voltage = 5000;
    } else if (v == 3.3) {
        voltage = 3300;
    } else {
        voltage = 5000;
    }
}

double ALTemp::read() {
    double pinMillivolts = analogRead(tempPin) * ((double)voltage / 1024);
    double celsius = (pinMillivolts - 500) / 10; // in celsius

    // perform other calculations, or switch on a thing to use Fahrenheit
    //double fahrenheit =  celsius * 1.8 + 32;
    return celsius;
}
