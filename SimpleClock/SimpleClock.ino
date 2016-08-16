
#include <Adafruit_CircuitPlayground.h>

uint8_t pixel0Num = 0;
uint8_t pixel1Num = 0;
uint8_t pixel2Num = 0;
uint8_t redVal = 180;
uint8_t blueVal = 180;
uint8_t greenVal = 180;
bool start = false;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (CircuitPlayground.rightButton()) {
    start = true;
  }

  if (start) {
    CircuitPlayground.clearPixels();
    CircuitPlayground.setPixelColor(pixel2Num, 0, 0, greenVal);
    CircuitPlayground.setPixelColor(pixel1Num, 0, blueVal, 0);
    CircuitPlayground.setPixelColor(pixel0Num, redVal, 0, 0);
    
    pixel0Num++;
    if (pixel0Num == 10) {
      pixel0Num = 0;
      pixel1Num++;
      if (pixel1Num == 10) {
        pixel1Num = 0;
        pixel2Num++;
        if (pixel2Num == 10) {
          pixel2Num = 0;
        }
      }
    }
    delay(100);
    
  }
  if (CircuitPlayground.leftButton()) {
    start = false;
  }
  
}
