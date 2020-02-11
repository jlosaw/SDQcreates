// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>


// -----------------------------------------
// Particle Subscribe
// -----------------------------------------
// In this example, we will listen into the published events 
 


// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D5
#define PIXEL_COUNT 5
#define PIXEL_TYPE WS2812       //2812 is fine for ours, but if you use a different brand you need to look this up in the library file
#define BRIGHTNESS 30           // 0 - 255 (note, these are super bright, so lower is fine for the bench)

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

uint32_t Wheel(byte WheelPos);

void setup() {

    Particle.subscribe("JLO_Temp", tempHandler);
    // This is the event that we are subscribing too. It must correspond to the event name from temp sensor
    strip.setBrightness(BRIGHTNESS);
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}


void loop() {
//nothing necessary here
  }


// Now for the tempHandler function, which is called when the cloud tells us that our buddy's event is published.
void tempHandler(const char *event, const char *data)
{
  /* 
  We are going to look for the JLO_Temp variable and light up the neo-wheel corresponding to the temp
  */
  
  if (strcmp(data,"60")==0) {
    strip.setPixelColor(0, 0,0,255);
    strip.setPixelColor(1, 0,85,255);
    strip.setPixelColor(2, 0,0,0);
    strip.setPixelColor(3, 0,0,0);
    strip.setPixelColor(4, 0,0,0);
    
    strip.show();
  }
  

  else if (strcmp(data,"70")==0) {
    strip.setPixelColor(0, 0,0,255);
    strip.setPixelColor(1, 0,85,255);
    strip.setPixelColor(2, 0,127,180);
    strip.setPixelColor(3, 0,170,90);
    strip.setPixelColor(4, 0,0,0);
      
    strip.show();
  }
  
  
  else if (strcmp(data,"80")==0) {
    strip.setPixelColor(0, 0,0,255);
    strip.setPixelColor(1, 0,85,255);
    strip.setPixelColor(2, 0,127,180);
    strip.setPixelColor(3, 0,170,90);
    strip.setPixelColor(4, 0,255,0);
    
   /* strip.setPixelColor(5, 43,255,0);
    strip.setPixelColor(6, 85,213,0);
    strip.setPixelColor(7, 128,170,0);
    strip.setPixelColor(8, 255,128,0);
    strip.setPixelColor(9, 255,85,0);
    strip.setPixelColor(10, 0,0,0);
    strip.setPixelColor(11,0,0,0);
    */
    
    strip.show();
  }
  
  else {
    colorWipe(strip.Color(255, 0, 0), 50); // Red
 
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
