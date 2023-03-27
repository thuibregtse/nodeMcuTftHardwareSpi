#ifndef Valve_h
#define Valve_h
#include <Arduino.h>
#include <Adafruit_ImageReader.h>
#include <Adafruit_ST7735.h> 

#define UNKNOWN = 0;
#define OPENING = 1;
#define OPEN = 2;
#define CLOSING = 3;
#define CLOSED = 4;
const int DISPLAY_W  = 128;
const int DISPLAY_H  = 128;
const int CHAR_W = 6;
const int CHAR_H = 14;

// Upper 10 px are for display label
const int LABEL_H = 10;
#include <string>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#include <SPI.h>
#include <bitmaps.h>


//const unsigned char * const bmp_table[] PROGMEM = {valve, happy, sad};


class Valve {
    
public:
    Valve(const char* displayLabel);
    void drawBitmap(const unsigned char * const bitmap_table[], unsigned int index);    // Draw monochrome bitmap
    void drawRgbBitmap(char* imageName);                                           // Draw color bitmap
    int getStatus();
    char* message;
    //void testGraphics(uint16_t color);
    void setStatusString (char* statusString);

private:  
    int _state; // State indicates open, opening, closed, closing
    int _desiredState;

};

#endif