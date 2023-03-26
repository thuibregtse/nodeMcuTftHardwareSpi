#include <Arduino.h>
#include "Valve.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <Adafruit_ImageReader.h>
#include <bitmaps.h>

using namespace std;

#define TFT_CS D0  // TFT select pin
#define TFT_RST D1 // 9  // you can also connect this to the Arduino reset
#define SD_CS D2   // 4 // SD card select pin
#define TFT_DC D3  // 8
#define TFT_SCLK D5
#define TFT_MOSI D7

ImageReturnCode stat; // Status from image-reading functions
SdFat                SD;         // SD card filesystem
Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys

Adafruit_ST7735      tft    = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
Adafruit_Image       img;        // An image loaded into RAM
int32_t              width  = 0, // BMP image dimensions
                     height = 0;
float p = 3.1415926;

//const uint16_t * PROGMEM valveOpenRGB;
char message[80];
//Adafruit_ImageReader reader;


Valve::Valve(const char *label)
{

  // strcpy(_label,fileName);
  // Serial.print ("Constructor received a string of ");
  // printf("Display label is : %s", displayLabel);
  message = (char *)malloc(strlen(label) * sizeof(char) + 1);

  // Copy the input string to the class's field.
  strcpy(message, label);
  cout << "Copied to ";
  cout << message;

  tft.initR(INITR_144GREENTAB); // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_WHITE);
  tft.setTextSize(2); // 12x16 for this display
  tft.setTextColor(ST7735_BLACK);
  tft.setCursor((DISPLAY_W / 2) - (strlen(message) * CHAR_W), 0); // 128/2 - strlen/2 * 12
  // tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(label);

  if(!SD.begin(SD_CS, SD_SCK_MHZ(10))) { // Breakouts require 10 MHz limit due to longer wires
    Serial.println(F("SD begin() failed"));
    for(;;); // Fatal error, do not continue
  }
  Serial.println(F("OK!"));
  delay(5000);
}

// From this example: https://stackoverflow.com/questions/28219715/how-do-you-assign-a-string-field-from-a-constructor-in-a-c-class-for-arduino


//ImageReturnCode stat; // Status from image-reading functions

void Valve::setStatusString(char* message)  {

  // Clear the previous text rectangle
      tft.fillRect(0,DISPLAY_H - CHAR_H,DISPLAY_W, CHAR_H, ST7735_GREEN);
      tft.setCursor((DISPLAY_W / 2) - (strlen(message) * CHAR_W), DISPLAY_H - CHAR_H); //128/2 - strlen/2 * 12
      tft.setTextColor(ST7735_BLACK);
      tft.print (message);

  //    Serial.print(F("Loading lily.bmp to screen..."));
  //    stat = reader.drawBMP("/lily.bmp", tft, 0, 0);
      Serial.print(F("Loading lily.bmp to screen..."));
      //stat = reader.drawBMP("/lily.bmp", tft, 0, 0);
 

      reader.printStatus(stat);   // How'd we do?
}


int Valve::getStatus() {
    return (0);
}

void Valve::drawBitmap(const unsigned char *const bitmap_table[])
{
    tft.fillRect(0, CHAR_H + 2, DISPLAY_W, DISPLAY_H - CHAR_H - CHAR_H - 2, ST7735_WHITE);
    tft.drawBitmap(14, CHAR_H + 2, bitmap_table[0], 100, 100, ST7735_BLACK);

 // tft2.fillCircle(64, 64, 60, ST7735_GREEN);

 
  tft.drawRect(0,0, 40,40, ST7735_YELLOW);
  //tft.drawBitmap (40,CHAR_H + 2,spider, 48,48, ST7735_BLACK);
}

//void Valve::drawRgbBitmap(const uint16_t * const rgb_table[])
void Valve::drawRgbBitmap()
 {
  tft.fillRect(0, CHAR_H + 2, DISPLAY_W, DISPLAY_H - CHAR_H - CHAR_H -2, ST7735_WHITE);
  //stat = reader.drawBMP("/lily.bmp", tft, 0, 0);

 // tft.drawBMP(14, CHAR_H + 2, valveOpenRGB, 100,100);
  tft.fillCircle(64, 64, 60, ST7735_GREEN);
 // tft2.drawRect(0,0, 40,40, ST7735_YELLOW);
  //tft2.drawBitmap (40,CHAR_H + 2,spider, 48,48, ST7735_BLACK);
}



/*
void Valve::testGraphics(uint16_t color) {
  tft2.fillScreen(ST7735_BLACK);
  tft2.fillCircle(64, 64, 60, ST7735_GREEN);
  tft2.drawRect(0,0, 40,40, ST7735_YELLOW);
  tft2.drawBitmap (40,40,spider, 48,48, ST7735_CYAN);

}
*/

