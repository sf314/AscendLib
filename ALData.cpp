// Code file for ALData custom library
// Contains full definitions for all funcs and variables
/*
 * Check if Serial use is ok.
 * Check variable declaration for dataFile.
 */

// Inclusions
#include <Arduino.h>
#include <ALData.h>
#include "SPI.h"
#include <SD.h>

// Variables
int ALData::logCounter = 1;
File ALData::dataFile;
String ALData::fileName = "";
bool ALData::useSD = true;
int ALData::sdPin = 8;

// Initializer
ALData::ALData() {

}


// initialize the sd
void ALData::initSD() {
    Serial.println("Initializing SD card...");
    Serial.print("Using pin ");
    Serial.println(sdPin);


    // Try a maximum of 5 times before quitting
    int tries = 3; // set max number of tries here
    bool failed = false;

    while (!SD.begin(sdPin) && tries > 0) {
        delay(100); // change delay?
        Serial.print(tries);
        Serial.println("...");
        tries--;
        if (tries <=0) {
            failed = true;
            useSD = false;
        }
    }

    if (failed) {
        Serial.println("Card not initialized... Not using SD");
    } else {
        Serial.println("Card initialized. ");
    }
}

// setup
void ALData::setupFile(String name, String columns) {

    if (useSD) {
        fileName = name;
        dataFile = SD.open(name, FILE_WRITE);
        dataFile.print("\n\n");
        dataFile.print("Log, " + columns);
        dataFile.close();
        logCounter = 1;
    } else {
        // not using SD. SD nonexistent
    }
}

// Newline
void ALData::startNewLog() {

    if (useSD) {
        Serial.println("Starting new line...");
        dataFile = SD.open(fileName, FILE_WRITE);
        dataFile.println();
        dataFile.print(String(logCounter) + ", ");
        logCounter++;
    } else {
        // not using SD.
    }
}

// write int
void ALData::writeInt(int n) {
    if (useSD) {
        dataFile.print(String(n) + ", ");
    }
}

// Write double
void ALData::writeDouble(double n) {
    if (useSD) {
        dataFile.print(String(n) + ", ");
    } else {
        // not using SD
    }
}

// Write string
void ALData::writeString(String s) {
    if (useSD) {
        dataFile.print(s + ", ");
    } else {
        // not using SD
    }
}


void ALData::close() {
    if (useSD) {
        dataFile.close();
    }
}



// chagne sd pin
void ALData::changeSDPin(int n) {
    sdPin = n;
}
