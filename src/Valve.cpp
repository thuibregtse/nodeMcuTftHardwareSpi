#include <Arduino.h>
#include "Valve.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <bitmaps.h>

using namespace std;


#define TFT_CS     D0 // D1 //10
#define TFT_RST    D1 // 9  // you can also connect this to the Arduino reset
#define TFT_DC     D3  // 8
#define TFT_SCLK D5   // set these to be whatever pins you like!
#define TFT_MOSI D7   // set these to be whatever pins you like!
Adafruit_ST7735 tft2 = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);


Valve::Valve(const char* label) {
  
//strcpy(_label,fileName);
//Serial.print ("Constructor received a string of ");
//printf("Display label is : %s", displayLabel);
message = (char*) malloc( strlen(label) * sizeof(char) + 1 );

  //Copy the input string to the class's field.
  strcpy( message, label);
  cout << "Copied to ";
  cout << message;

   tft2.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab
   tft2.setTextSize(2); //12x16 for this display
      
   // use the length of the string and the display width to calculate cursor start

   tft2.setCursor((64 - (strlen(message) * 6)), 0); //128/2 - strlen/2 * 12
   //  tft2.setCursor(64 , 0);
  //tft.setTextColor(color);
  tft2.setTextWrap(true);
  tft2.print(label);
  delay(5000);
}

// From this example: https://stackoverflow.com/questions/28219715/how-do-you-assign-a-string-field-from-a-constructor-in-a-c-class-for-arduino




void Valve::setStatusString(char* statusString)  {

      tft2.setCursor((64 - (strlen(statusString) * 6)), 110); //128/2 - strlen/2 * 12
      tft2.print (statusString);
}

char* Valve::setStatusGraphic(int statusGraphicIndex) {  // Maybe add fg/bg colors

       ;
       //Serial.println (statusString);
       return ("Closed");
}

int Valve::getStatus() {
    return (0);
}

void Valve::testGraphics(uint16_t color) {
  tft2.fillScreen(ST7735_BLACK);
  tft2.fillCircle(64, 64, 60, ST7735_GREEN);
  tft2.drawRect(0,0, 40,40, ST7735_YELLOW);
  tft2.drawBitmap (40,40,spider, 48,48, ST7735_CYAN);

}