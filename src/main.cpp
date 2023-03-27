
#include <Arduino.h>
/*
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#include <SPI.h>
#include <bitmaps.h>
   */

#include <Valve.h>
#include <iostream>
#include <fstream>
#include <string>

char label[20];
const unsigned char * const bmp_table[] PROGMEM = {valveicon, happy, sad};

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello! TFT OO Test");
  delay(500);

  strcpy (label, "CrawlSpace");
  Serial.println("Creating valve");
  Valve valve1(label);
  Serial.println("Valve has been created");
  
  
  valve1.setStatusString("Pizzled");
  delay(2000);
  valve1.setStatusString("Open");
  delay(500);

  valve1.drawBitmap(bmp_table, 0);

  delay (5000);

  valve1.drawRgbBitmap("/lily.bmp");


  uint16_t time = millis();
  time = millis() - time;
  Serial.println(time, DEC);

}

void loop() {
  delay(500);
}
