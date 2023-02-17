
#include <Arduino.h>


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>
#include <bitmaps.h>
#include <Valve.h>

#include <iostream>
#include <fstream>
#include <string>




// Settings that work with NodeMCU hardware SPI
#define TFT_CS     D0 // D1 //10
#define TFT_RST    D1 // 9  // you can also connect this to the Arduino reset
#define TFT_DC     D3  // 8
#define TFT_SCLK D5   // set these to be whatever pins you like!
#define TFT_MOSI D7   // set these to be whatever pins you like!

#include <Arduino.h>




// Settings that work with NodeMCU hardware SPI
#define TFT_CS     D0 // D1 //10
#define TFT_RST    D1 // 9  // you can also connect this to the Arduino reset
#define TFT_DC     D3  // 8
#define TFT_SCLK D5   // set these to be whatever pins you like!
#define TFT_MOSI D7   // set these to be whatever pins you like!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);


float p = 3.1415926;

void testMyGraphics(uint16_t color) {
  tft.fillScreen(ST7735_BLACK);
  tft.fillCircle(64, 64, 60, ST7735_RED);
  tft.drawRect(0,0, 40,40, ST7735_YELLOW);
  tft.drawBitmap (40,40,spider, 48,48, ST7735_CYAN);

}


void testlines(uint16_t color) {
  tft.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(0, 0, x, tft.height()-1, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(0, 0, tft.width()-1, y, color);
  }

  tft.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(tft.width()-1, 0, x, tft.height()-1, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(tft.width()-1, 0, 0, y, color);
  }

  tft.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(0, tft.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(0, tft.height()-1, tft.width()-1, y, color);
  }

  tft.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawLine(tft.width()-1, tft.height()-1, x, 0, color);
  }
  for (int16_t y=0; y < tft.height(); y+=6) {
    tft.drawLine(tft.width()-1, tft.height()-1, 0, y, color);
  }
}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

void testfastlines(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST7735_BLACK);
  for (int16_t y=0; y < tft.height(); y+=5) {
    tft.drawFastHLine(0, y, tft.width(), color1);
  }
  for (int16_t x=0; x < tft.width(); x+=5) {
    tft.drawFastVLine(x, 0, tft.height(), color2);
  }
}

void testdrawrects(uint16_t color) {
  tft.fillScreen(ST7735_BLACK);
  for (int16_t x=0; x < tft.width(); x+=6) {
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color);
  }
}

void testfillrects(uint16_t color1, uint16_t color2) {
  tft.fillScreen(ST7735_BLACK);
  /*
  for (int16_t x=tft.width()-1; x > 6; x-=6) {
    tft.fillRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color1);
    tft.drawRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, color2);
    delay(50);
*/
  for (int16_t x=127; x > 6; x-=6) {
    tft.fillRect(64 -x/2, 64 -x/2 , x, x, color1);
       delay(100);
    tft.drawRect(64 -x/2, 64/2 -x/2 , x, x, color2);
    delay(100);

  }
}

void testfillcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=radius; x < tft.width(); x+=radius*2) {
    for (int16_t y=radius; y < tft.height(); y+=radius*2) {
      tft.fillCircle(x, y, radius, color);
      Serial.print (x);
      Serial.println (y);
    }
  }
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void drawGauge() {
  tft.setTextSize(2);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor (64, 64);
  tft.print ("Hi from Tom");
  delay (1000);
}

void drawValve() {
  tft.fillRect(2, 16, 118,64, ST7735_BLUE);
  tft.setTextSize(2);
  tft.setTextColor(ST7735_YELLOW);
  tft.setCursor (36,100);
  //tft.print ("Closed");

  tft.fillRect (58,16,4,62, ST7735_WHITE);

tft.setRotation(1);
tft.fillRect (58,16,4,62, ST7735_RED);


;

  delay (10000);
}



void testtriangles() {
  tft.fillScreen(ST7735_BLACK);
  int color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height()-1;
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}

void testroundrects() {
  tft.fillScreen(ST7735_BLACK);
  int color = 100;
  int i;
  int t;
  for(t = 0 ; t <= 4; t+=1) {
    int x = 0;
    int y = 0;
    int w = tft.width()-2;
    int h = tft.height()-2;
    for(i = 0 ; i <= 16; i+=1) {
      tft.drawRoundRect(x, y, w, h, 5, color);
      x+=2;
      y+=3;
      w-=4;
      h-=6;
      color+=1100;
    }
    color+=100;
  }
}

void tftPrintTest() {
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 30);
  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.println("Hello World!");
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(3);
  tft.println("Hello World!");
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(4);
  tft.print(1234.567);
  delay(1500);
  tft.setCursor(0, 0);
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(0);
  tft.println("Hello World!");
  tft.setTextSize(1);
  tft.setTextColor(ST7735_GREEN);
  tft.print(p, 6);
  tft.println(" Want pi?");
  tft.println(" ");
  tft.print(8675309, HEX); // print 8,675,309 out in HEX!
  tft.println(" Print HEX!");
  tft.println(" ");
  tft.setTextColor(ST7735_WHITE);
  tft.println("Sketch has been");
  tft.println("running for: ");
  tft.setTextColor(ST7735_MAGENTA);
  tft.print(millis() / 1000);
  tft.setTextColor(ST7735_WHITE);
  tft.print(" seconds.");
}

void mediabuttons() {
  // play
  tft.fillScreen(ST7735_BLACK);
  tft.fillRoundRect(25, 10, 78, 60, 8, ST7735_WHITE);
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_RED);
  delay(500);
  // pause
  tft.fillRoundRect(25, 90, 78, 60, 8, ST7735_WHITE);
  tft.fillRoundRect(39, 98, 20, 45, 5, ST7735_GREEN);
  tft.fillRoundRect(69, 98, 20, 45, 5, ST7735_GREEN);
  delay(500);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_BLUE);
  delay(50);
  // pause color
  tft.fillRoundRect(39, 98, 20, 45, 5, ST7735_RED);
  tft.fillRoundRect(69, 98, 20, 45, 5, ST7735_RED);
  // play color
  tft.fillTriangle(42, 20, 42, 60, 90, 40, ST7735_GREEN);
}

char label[20];

void setup(void) {
  Serial.begin(115200);
  Serial.println("Hello! ST7735 TFT Test");

  strcpy (label, "CrawlSpace");
  Serial.println("Creating valve");
  Valve valve1(label);
  Serial.println("Valve has been created");
  valve1.setStatusString("Pizzled");
  delay(10000);

  Serial.println("Opening valve");

  char* foo = valve1.open(); 
  Serial.print ("Results of valve.open: ");
  Serial.print (foo);

Serial.println ("Testing object graphics...");
valve1.testGraphics(ST7735_WHITE);

delay (20000);

  // Use this initializer if you're using a 1.8" TFT
  //tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  // Use this initializer (uncomment) if you're using a 1.44" TFT
  tft.initR(INITR_144GREENTAB);   // initialize a ST7735S chip, black tab

  // Use this initializer (uncomment) if you're using a 0.96" 180x60 TFT
  //tft.initR(INITR_MINI160x80);   // initialize a ST7735S chip, mini display

  Serial.println("Initialized");

  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  testMyGraphics(ST7735_BLUE);
  delay (5000);

  // large block of text
  tft.fillScreen(ST7735_BLACK);
 // testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST7735_WHITE);
  //testdrawtext("BELLOW MINIONS!", ST7735_CYAN);
  //delay(1000);

  // tft print function!
  //tftPrintTest();
  //delay(4000);

  // a single pixel
  //tft.drawPixel(tft.width()/2, tft.height()/2, ST7735_GREEN);
  //delay(500);

  // line draw test
  //testlines(ST7735_RED);
  drawValve();
  delay(500);

  // optimized lines
 // testfastlines(ST7735_RED, ST7735_BLUE);
 // delay(500);

 // testdrawrects(ST7735_GREEN);
 // delay(500);

 // testfillrects(ST7735_BLUE, ST7735_MAGENTA);
 // delay(500);

 // tft.fillScreen(ST7735_BLACK);
 // testfillcircles(10, ST7735_BLUE);
 // testdrawcircles(10, ST7735_WHITE);
 // delay(500);

 // testroundrects();
 // delay(500);

 // testtriangles();
 // delay(500);

//  mediabuttons();
//  delay(500);

  Serial.println("done");
  delay(1000);
}

void loop() {
  //tft.invertDisplay(true);
  delay(500);
  //tft.invertDisplay(false);
  delay(500);
}
