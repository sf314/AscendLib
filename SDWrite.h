// Header file for SDWrite custom library

/* Description of functions in library
 *
 *  Funcs(): default constructor. Does nothing.
 *  Create objects like "" SDWrite sd; ""
 *  Call functions like "" sd.writeInt(3); ""
 *
 *  initSD(): initialize the SD card reader on the sdPin. Keep looping until done.
 *  setupFile(String name, String columns): setup the data file with a given name and certain columns (after Log column)
 *  startNewLog(): Carry over to a new line, print the log#
 *  writeInt(int n): Write an integer to the file, followed by a comma
 *  writeDouble(double n): Write a double to the file, followed by a comma.
 *
 *  // For safety, each function opens and closes the file within the brackets, ensuring that everything is safe.
 *
 */
#ifndef SDWrite_h
#define SDWrite_h

// Inclusions
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDWrite {
  public:
  SDWrite(); // Initializer
  void initSD();
  void setupFile(char name[20], String columns);
  void startNewLog();
  void writeInt(int n);
  void writeDouble(double n);
  void writeString(String s);
  void changeSDPin(int n);
    void close();

  private:
  static int logCounter;
  static File dataFile;
  static char fileName[20];
  static int sdPin;
    static bool useSD;

};




#endif
