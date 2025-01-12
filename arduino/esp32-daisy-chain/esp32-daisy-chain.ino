/***************************************************
  This is an example for our Adafruit 12-channel PWM/LED driver

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/

  These drivers uses SPI to communicate, 2 pins are required to
  interface: Data and Clock. The boards are chainable

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <SPI.h>
#include "Adafruit_TLC59711.h"
#include "DaisyChain.h"
#include "common.h"

#define DEBUG_ENABLE_MAIN 1
#if ((DEBUG_ENABLE_MAIN == 1) && (ENABLE_DEBUG_OUTPUT == 1))
#define DEBUG_INFO(f, ...) Serial.printf("[INF][Main]: " f "\n", ##__VA_ARGS__)
#else
#define DEBUG_INFO(...)
#endif

void setup() {
#if (ENABLE_DEBUG_OUTPUT == 1)
  Serial.begin(115200);
#endif
  DEBUG_INFO("%s", DIVIDER);
  DEBUG_INFO("Setup ESP32-daisy-chain [...]");

  DaisyChain::getInstance().initialize();

  DEBUG_INFO("Setup ESP32-daisy-chain [OK]");
  DEBUG_INFO("%s", DIVIDER);
}

void loop() {
  DaisyChain::getInstance().runTestShow();
}

/*
// Fill the dots one after the other with a color
void colorWipe(uint16_t r, uint16_t g, uint16_t b, uint8_t wait) {
  for (uint16_t i = 0; i < 8 * NUM_TLC59711; i++) {
    chain0_.setLED(i, r, g, b);
    chain0_.write();
    delay(wait);
  }
}

// Rainbow all LEDs at the same time, same color
void rainbow(uint8_t wait) {
  uint32_t i, j;

  for (j = 0; j < 65535; j += 10) {
    for (i = 0; i < 4 * NUM_TLC59711; i++) {
      Wheel(i, (i + j) & 65535);
    }
    chain0_.write();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint32_t i, j;

  for (j = 0; j < 65535; j += 10) { // 1 cycle of all colors on wheel
    for (i = 0; i < 4 * NUM_TLC59711; i++) {
      Wheel(i, ((i * 65535 / (4 * NUM_TLC59711)) + j) & 65535);
    }
    chain0_.write();
    delay(wait);
  }
}

// Input a value 0 to 4095 to get a color value.
// The colours are a transition r - g - b - back to r.
void Wheel(uint8_t ledn, uint16_t WheelPos) {
  if (WheelPos < 21845) {
    chain0_.setLED(ledn, 3 * WheelPos, 65535 - 3 * WheelPos, 0);
  } else if (WheelPos < 43690) {
    WheelPos -= 21845;
    chain0_.setLED(ledn, 65535 - 3 * WheelPos, 0, 3 * WheelPos);
  } else {
    WheelPos -= 43690;
    chain0_.setLED(ledn, 0, 3 * WheelPos, 65535 - 3 * WheelPos);
  }
}

// All RGB Channels on full colour
// Cycles trough all brightness settings from 0 up to 127
void increaseBrightness() {
  for (uint16_t i = 0; i < 8 * CHAIN_SIZE; i++) {
    chain0_.setLED(i, 65535, 65535, 65535);
  }
  for (int i = 0; i < 128; i++) {
    chain0_.simpleSetBrightness(i);
    chain0_.write();
    delay(100);
  }
}
*/
