
#include <Arduino.h>
#define SD_CS   D2 // SD card select pin

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
//#include <Adafruit_ImageReader.h>
//#include <Adafruit_EPD.h>
#include <SPI.h>
#include <bitmaps.h>
#include <Valve.h>

#include <iostream>
#include <fstream>
#include <string>




// SdFat                SD;         // SD card filesystem
 // Adafruit_ImageReader reader(SD); // Image-reader object, pass in SD filesys

//  Adafruit_SPIFlash    flash(&flashTransport);
///  FatVolume        filesys;
///  Adafruit_ImageReader reader(filesys); // Image-reader, pass in flash filesys



const unsigned char happy[] PROGMEM =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

const unsigned char sad[] PROGMEM = {
  B00000000, B11000000,
  B00000000, B11000000,
  B00000000, B11000000,
  B00000000, B11100000,
  B00000000, B11100000,
  B00000000, B11111000,
  B00000000, B11111111,
  B00000000, B10011111,
  B00000000, B11111100,
  B00000000, B01110000,
  B00000000, B10100000,
  B00000000, B11100000,
  B00000000, B11110000,
  B00000000, B11110000,
  B00000000, B01110000,
  B00000000, B00110000
};


const unsigned char * const bmp_table[] PROGMEM = {valve, happy, sad};


// Settings that work with NodeMCU hardware SPI
#define TFT_CS     D0 // D1 //10
#define TFT_RST    D1 // 9  // you can also connect this to the Arduino reset
#define TFT_DC     D3  // 8
#define TFT_SCLK D5   // set these to be whatever pins you like!
#define TFT_MOSI D7   // set these to be whatever pins you like!



char label[20];


void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello! TFT OO Test");
  delay(500);
  strcpy (label, "CrawlSpace");
  Serial.println("Creating valve");
  Valve valve1(label);
  Serial.println("Valve has been created");
  valve1.setStatusString("Pizzled");

  valve1.setStatusString("Open");
  delay(500);
  valve1.drawRgbBitmap();
  //valve1.drawBitmap(bmp_table);

  uint16_t time = millis();
  
  time = millis() - time;

  Serial.println(time, DEC);
  // large block of text
  //testdrawtext("BELLOW MINIONS!", ST7735_CYAN);
  Serial.println("done");
  delay(1000);
}

void loop() {
  //tft.invertDisplay(true);
  delay(500);
  //tft.invertDisplay(false);
  delay(500);
}
