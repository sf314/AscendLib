// Code file for SDWrite custom library
// Contains full definitions for all funcs and variables
/*
 * Check if Serial use is ok.
 * Check variable declaration for dataFile.
 */

// Inclusions
#include <Arduino.h>
#include <SDWrite.h>
#include "SPI.h"
#include <SD.h>

// Variables
int SDWrite::logCounter = 1;
File SDWrite::dataFile;
char SDWrite::fileName[20];
bool SDWrite::useSD = true;
int SDWrite::sdPin = 8;

// Initializer
SDWrite::SDWrite() {

}


// initialize the sd
void SDWrite::initSD() {
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
void SDWrite::setupFile(char name[20], String columns) {

    if (useSD) {
        strcpy(fileName, name);
        //fileName = name; // What?
        //dataFile = SD.open(name, FILE_WRITE);
        dataFile = SD.open(name);                           // *** HERE
        dataFile.print("\n\n");
        dataFile.print("Log, " + columns);
        dataFile.close();
        logCounter = 1;
    } else {
        // not using SD. SD nonexistent
    }
}

// Newline
void SDWrite::startNewLog() {

    if (useSD) {
        Serial.println("Starting new line...");
        //dataFile = SD.open(name, FILE_WRITE);
        dataFile = SD.open(fileName);                           // *** HERE
        dataFile.println();
        dataFile.print(String(logCounter) + ", ");
        logCounter++;
    } else {
        // not using SD.
    }
}

// write int
void SDWrite::writeInt(int n) {
    if (useSD) {
        dataFile.print(String(n) + ", ");
    }
}

// Write double
void SDWrite::writeDouble(double n) {
    if (useSD) {
        dataFile.print(String(n) + ", ");
    } else {
        // not using SD
    }
}

// Write string
void SDWrite::writeString(String s) {
    if (useSD) {
        dataFile.print(s + ", ");
    } else {
        // not using SD
    }
}


void SDWrite::close() {
    if (useSD) {
        //SD.close(); // or dataFile.close()?
        dataFile.close();
    }
}



// chagne sd pin
void SDWrite::changeSDPin(int n) {
    sdPin = n;
}
