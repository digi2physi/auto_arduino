/*
 * Component: Grove Temperature & Humidity Sensor (DHT11)
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - DHT_PIN: Digital pin connected to the sensor (default: 2)
 *
 * OUTPUTS (what you get):
 *   - temperature: float (0-50°C) - Temperature in Celsius
 *   - humidity: float (20-90%) - Relative humidity
 *   - isValid: bool - Whether the reading is valid
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: Time between readings (min 2000ms)
 *   - SHOW_BAR_GRAPH: Toggle visual bar graph
 *
 * WIRING:
 *   Sensor VCC -> Arduino 5V
 *   Sensor GND -> Arduino GND
 *   Sensor SIG -> Arduino Digital Pin (D2)
 *
 *   Grove Shield: Connect to any Digital port
 *
 * LIBRARY:
 *   Install "DHT sensor library" by Adafruit via Library Manager
 */

#include <DHT.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define DHT_PIN 2             // Digital pin connected to sensor
#define READ_INTERVAL 2000    // Time between readings (min 2000ms)
#define SHOW_BAR_GRAPH true   // Set to false to disable visual bar graph

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

float temperature = 0;
float humidity = 0;
bool isValid = false;

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("Grove Temp & Humidity Sensor - Ready");
  Serial.println("-------------------------------------");
}

void loop() {
  // Read sensor values
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Check if reading is valid
  isValid = !isnan(temperature) && !isnan(humidity);

  if (!isValid) {
    Serial.println("[TempHumi] ERROR: Failed to read sensor");
    delay(READ_INTERVAL);
    return;
  }

  // Output temperature
  Serial.print("[TempHumi] temp=");
  Serial.print(temperature, 1);
  Serial.print("C");

  if (SHOW_BAR_GRAPH) {
    Serial.print(" |");
    int tempBars = constrain(map(temperature, 0, 50, 0, 20), 0, 20);
    for (int i = 0; i < 20; i++) {
      Serial.print(i < tempBars ? "█" : "░");
    }
    Serial.print("|");
  }

  // Output humidity
  Serial.print("  humi=");
  Serial.print(humidity, 1);
  Serial.print("%");

  if (SHOW_BAR_GRAPH) {
    Serial.print(" |");
    int humiBars = constrain(map(humidity, 0, 100, 0, 20), 0, 20);
    for (int i = 0; i < 20; i++) {
      Serial.print(i < humiBars ? "█" : "░");
    }
    Serial.print("|");
  }

  Serial.println();
  delay(READ_INTERVAL);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns temperature in Celsius
float readTemperature() {
  return dht.readTemperature();
}

// Returns temperature in Fahrenheit
float readTemperatureF() {
  return dht.readTemperature(true);
}

// Returns relative humidity (0-100%)
float readHumidity() {
  return dht.readHumidity();
}

// Returns true if sensor reading is valid
bool isReadingValid() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  return !isnan(t) && !isnan(h);
}
