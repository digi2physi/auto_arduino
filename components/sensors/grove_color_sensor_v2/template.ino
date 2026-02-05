/*
 * Component: Grove I2C Color Sensor v2.0
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - None (I2C connection, auto-detected)
 *
 * OUTPUTS (what you get):
 *   - red: int (0-255) - Red color intensity
 *   - green: int (0-255) - Green color intensity
 *   - blue: int (0-255) - Blue color intensity
 *   - clear: int (0-65535) - Clear light intensity
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: Time between readings in ms
 *   - SHOW_BAR_GRAPH: Toggle visual bar graph
 *
 * WIRING:
 *   Sensor VCC -> Arduino 3.3V or 5V
 *   Sensor GND -> Arduino GND
 *   Sensor SDA -> Arduino A4 (Uno) / pin 20 (Mega)
 *   Sensor SCL -> Arduino A5 (Uno) / pin 21 (Mega)
 *
 *   Grove Shield: Connect to any I2C port
 *
 * LIBRARY:
 *   Install "Adafruit TCS34725" via Library Manager
 */

#include <Wire.h>
#include <Adafruit_TCS34725.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define READ_INTERVAL 500     // Time between readings (ms)
#define SHOW_BAR_GRAPH true   // Set to false to disable visual bar graph

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

Adafruit_TCS34725 sensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

int red = 0;
int green = 0;
int blue = 0;
uint16_t clear = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Grove Color Sensor v2.0 - Initializing...");

  if (!sensor.begin()) {
    Serial.println("ERROR: Color sensor not found. Check wiring!");
    while (1);
  }

  Serial.println("Grove Color Sensor v2.0 - Ready");
  Serial.println("-------------------------------");
}

void loop() {
  uint16_t r, g, b, c;

  // Read raw values
  sensor.getRawData(&r, &g, &b, &c);

  // Avoid division by zero
  if (c == 0) c = 1;

  // Normalize to 0-255 range
  red = (r * 255) / c;
  green = (g * 255) / c;
  blue = (b * 255) / c;
  clear = c;

  // Clamp values
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  // Output readings
  Serial.print("[Color] R=");
  Serial.print(red);
  if (SHOW_BAR_GRAPH) printBar(red, 'R');

  Serial.print(" G=");
  Serial.print(green);
  if (SHOW_BAR_GRAPH) printBar(green, 'G');

  Serial.print(" B=");
  Serial.print(blue);
  if (SHOW_BAR_GRAPH) printBar(blue, 'B');

  Serial.print(" (clear=");
  Serial.print(clear);
  Serial.print(")");

  Serial.println();
  delay(READ_INTERVAL);
}

// Print color bar
void printBar(int val, char color) {
  Serial.print(" [");
  int bars = map(val, 0, 255, 0, 10);
  for (int i = 0; i < 10; i++) {
    Serial.print(i < bars ? "█" : "░");
  }
  Serial.print("]");
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns red value (0-255)
int readRed() {
  uint16_t r, g, b, c;
  sensor.getRawData(&r, &g, &b, &c);
  if (c == 0) c = 1;
  return constrain((r * 255) / c, 0, 255);
}

// Returns green value (0-255)
int readGreen() {
  uint16_t r, g, b, c;
  sensor.getRawData(&r, &g, &b, &c);
  if (c == 0) c = 1;
  return constrain((g * 255) / c, 0, 255);
}

// Returns blue value (0-255)
int readBlue() {
  uint16_t r, g, b, c;
  sensor.getRawData(&r, &g, &b, &c);
  if (c == 0) c = 1;
  return constrain((b * 255) / c, 0, 255);
}

// Returns dominant color as string
String getDominantColor() {
  int r = readRed();
  int g = readGreen();
  int b = readBlue();

  if (r > g && r > b) return "RED";
  if (g > r && g > b) return "GREEN";
  if (b > r && b > g) return "BLUE";
  return "MIXED";
}

// Returns true if detected color matches (with tolerance)
bool isColor(int targetR, int targetG, int targetB, int tolerance) {
  int r = readRed();
  int g = readGreen();
  int b = readBlue();

  return (abs(r - targetR) <= tolerance &&
          abs(g - targetG) <= tolerance &&
          abs(b - targetB) <= tolerance);
}
