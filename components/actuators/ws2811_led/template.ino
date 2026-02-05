/*
 * Component: WS2811 Addressable RGB LED (F5-C-WS2811)
 * Type: actuator
 *
 * INPUTS (what you provide):
 *   - LED_PIN: Digital pin connected to LED data line
 *   - NUM_LEDS: Number of LEDs in the chain
 *
 * CONTROLS (what you can do):
 *   - Set color of individual LEDs (RGB)
 *   - Set brightness
 *   - Run color animations
 *
 * PARAMETERS (what you can customize):
 *   - BRIGHTNESS: Global brightness (0-255)
 *
 * WIRING:
 *   LED VCC (5V) -> Arduino 5V (or external 5V for many LEDs)
 *   LED GND     -> Arduino GND
 *   LED DIN     -> Arduino Digital Pin (D6)
 *
 *   TIP: Add a 300-500 ohm resistor between Arduino pin and LED data line
 *
 * LIBRARY:
 *   Install "Adafruit NeoPixel" via Library Manager
 */

#include <Adafruit_NeoPixel.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define LED_PIN 6           // Digital pin connected to LED
#define NUM_LEDS 1          // Number of LEDs in chain
#define BRIGHTNESS 50       // Brightness (0-255), start low to protect eyes

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();  // Initialize all LEDs to off

  Serial.println("WS2811 LED - Ready");
  Serial.println("------------------");
  Serial.println("Commands: r=red, g=green, b=blue, w=white, o=off, c=cycle");
}

void loop() {
  // Demo: cycle through colors
  Serial.println("[LED] Red");
  setAllColor(255, 0, 0);
  delay(1000);

  Serial.println("[LED] Green");
  setAllColor(0, 255, 0);
  delay(1000);

  Serial.println("[LED] Blue");
  setAllColor(0, 0, 255);
  delay(1000);

  Serial.println("[LED] White");
  setAllColor(255, 255, 255);
  delay(1000);

  Serial.println("[LED] Off");
  setAllColor(0, 0, 0);
  delay(1000);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Set all LEDs to the same color
void setAllColor(int r, int g, int b) {
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}

// Set a specific LED to a color (0-indexed)
void setLedColor(int ledIndex, int r, int g, int b) {
  if (ledIndex >= 0 && ledIndex < NUM_LEDS) {
    strip.setPixelColor(ledIndex, strip.Color(r, g, b));
    strip.show();
  }
}

// Set brightness (0-255)
void setBrightness(int brightness) {
  strip.setBrightness(constrain(brightness, 0, 255));
  strip.show();
}

// Turn all LEDs off
void allOff() {
  setAllColor(0, 0, 0);
}

// Rainbow cycle animation
void rainbowCycle(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    for (int i = 0; i < NUM_LEDS; i++) {
      int pixelHue = firstPixelHue + (i * 65536L / NUM_LEDS);
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

// Blink all LEDs
void blinkColor(int r, int g, int b, int times, int delayMs) {
  for (int i = 0; i < times; i++) {
    setAllColor(r, g, b);
    delay(delayMs);
    allOff();
    delay(delayMs);
  }
}

// Fade in/out effect
void fadeColor(int r, int g, int b, int steps, int delayMs) {
  // Fade in
  for (int i = 0; i <= steps; i++) {
    int brightness = map(i, 0, steps, 0, 255);
    strip.setBrightness(brightness);
    setAllColor(r, g, b);
    delay(delayMs);
  }
  // Fade out
  for (int i = steps; i >= 0; i--) {
    int brightness = map(i, 0, steps, 0, 255);
    strip.setBrightness(brightness);
    setAllColor(r, g, b);
    delay(delayMs);
  }
  strip.setBrightness(BRIGHTNESS);  // Reset to default
}
