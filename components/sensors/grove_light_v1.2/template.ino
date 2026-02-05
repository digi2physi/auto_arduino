/*
 * Component: Grove Light Sensor v1.2
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - LIGHT_PIN: Analog pin connected to the sensor (default: A0)
 *
 * OUTPUTS (what you get):
 *   - rawValue: int (0-1023) - Raw analog reading
 *   - percentage: int (0-100) - Light level as percentage
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: Time between readings in ms (default: 500)
 *
 * WIRING (Grove):
 *   Connect to any Analog port (A0, A1, A2, etc.)
 *
 * WIRING (Manual):
 *   Sensor VCC -> Arduino 5V
 *   Sensor GND -> Arduino GND
 *   Sensor SIG -> Arduino Analog Pin
 */

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define LIGHT_PIN A0          // Analog pin connected to sensor
#define READ_INTERVAL 500     // Time between readings (ms)
#define SHOW_BAR_GRAPH true   // Set to false to disable visual bar graph

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

int rawValue = 0;
int percentage = 0;

void setup() {
  Serial.begin(9600);

  // Analog pins don't need pinMode for input

  Serial.println("Grove Light Sensor v1.2 - Ready");
  Serial.println("--------------------------------");
}

void loop() {
  // Read raw analog value (0-1023)
  rawValue = analogRead(LIGHT_PIN);

  // Convert to percentage (0-100)
  percentage = map(rawValue, 0, 1023, 0, 100);

  // Output readings
  Serial.print("[Light] raw=");
  Serial.print(rawValue);
  Serial.print(", percent=");
  Serial.print(percentage);
  Serial.print("%");

  // Visual bar graph
  if (SHOW_BAR_GRAPH) {
    Serial.print("  |");
    int bars = percentage / 5;  // 20 chars max width
    for (int i = 0; i < 20; i++) {
      Serial.print(i < bars ? "█" : "░");
    }
    Serial.print("|");
  }

  Serial.println();
  delay(READ_INTERVAL);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns raw analog value (0-1023)
int readLightRaw() {
  return analogRead(LIGHT_PIN);
}

// Returns light level as percentage (0-100)
int readLightPercent() {
  return map(analogRead(LIGHT_PIN), 0, 1023, 0, 100);
}

// Returns true if light level is above threshold (0-100)
bool isLightAbove(int threshold) {
  return readLightPercent() > threshold;
}
