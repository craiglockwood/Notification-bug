// This #include statement was automatically added by the Particle IDE.
#include "neopixel/neopixel.h"



// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 7
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2812

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
//               note: if not specified, D2 is selected for you.
// Parameter 3 = pixel type [ WS2812, WS2812B, WS2811, TM1803 ]
//               note: if not specified, WS2812B is selected for you.
//               note: RGB order is automatically applied to WS2811,
//                     WS2812/WS2812B/TM1803 is GRB order.
//
// 800 KHz bitstream 800 KHz bitstream (most NeoPixel products ...
//                         ... WS2812 (6-pin part)/WS2812B (4-pin part) )
//
// 400 KHz bitstream (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//                   (Radio Shack Tri-Color LED Strip - TM1803 driver
//                    NOTE: RS Tri-Color LED's are grouped in sets of 3)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


void setup() {
 
  Spark.function("order",order); // a POST request for "order" will reference order, defined below 
  Spark.function("cart",cart); // a POST request for "cart" will reference cart, defined below
  Spark.function("spike",spike); // a POST request for "spike" will reference spike, defined below
    
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
    
}




// call the below function when the POST request matches it - ORDER (Green)
int order(String command) {

colorWipe(strip.Color(0,255,0), 65);
delay(3000);
colorWipe(strip.Color(0, 0, 0), 50); // no colour
}


// call the below function when the POST request matches it - CART (Red)
int cart(String command) {

colorWipe(strip.Color(255,0,0), 65);
delay(3000);
colorWipe(strip.Color(0, 0, 0), 50); // no colour
}

// call the below function when the POST request matches it - SPIKE (blue)
int spike(String command) {
    
colorWipe(strip.Color(0,0,255), 65);
delay(3000);
colorWipe(strip.Color(0, 0, 0), 50); // no colour
}


void loop() {


colorWipe(strip.Color(0, 0, 0), 50); // no colour



}


// Fill the dots one after the other with a color, wait (ms) after each one
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


void colorAll(uint32_t c, uint8_t wait) {
  uint16_t i;
  
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
  delay(wait);
}