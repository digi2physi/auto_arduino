/*
 * Component: Grove VL53L0X Time of Flight Distance Sensor
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - None (I2C connection, auto-detected)
 *
 * OUTPUTS (what you get):
 *   - distance: int (30-2000mm) - Distance in millimeters
 *   - distanceCm: float (3-200cm) - Distance in centimeters
 *   - isValid: bool - Whether reading is in valid range
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: Time between readings in ms
 *   - SHOW_BAR_GRAPH: Toggle visual bar graph
 *   - MAX_DISPLAY_RANGE: Bar graph max range in mm
 *
 * WIRING:
 *   Sensor VCC -> Arduino 5V (or 3.3V)
 *   Sensor GND -> Arduino GND
 *   Sensor SDA -> Arduino A4 (Uno) / pin 20 (Mega)
 *   Sensor SCL -> Arduino A5 (Uno) / pin 21 (Mega)
 *
 *   Grove Shield: Connect to any I2C port
 *
 * LIBRARY:
 *   Install "Adafruit_VL53L0X" via Library Manager
 */

#include <Wire.h>
#include <Adafruit_VL53L0X.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define READ_INTERVAL 100       // Time between readings (ms)
#define SHOW_BAR_GRAPH true     // Set to false to disable visual bar graph
#define MAX_DISPLAY_RANGE 500   // Bar graph max range (mm)

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

Adafruit_VL53L0X sensor = Adafruit_VL53L0X();

int distance = 0;
float distanceCm = 0;
bool isValid = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Grove VL53L0X ToF Sensor - Initializing...");

  if (!sensor.begin()) {
    Serial.println("ERROR: VL53L0X not found. Check wiring!");
    while (1);
  }

  Serial.println("Grove VL53L0X ToF Sensor - Ready");
  Serial.println("--------------------------------");
}

void loop() {
  VL53L0X_RangingMeasurementData_t measurement;

  sensor.rangingTest(&measurement, false);

  // Check if reading is valid
  isValid = (measurement.RangeStatus != 4);

  if (!isValid) {
    Serial.println("[VL53L0X] ERROR: Out of range");
    delay(READ_INTERVAL);
    return;
  }

  // Get distance values
  distance = measurement.RangeMilliMeter;
  distanceCm = distance / 10.0;

  // Output reading
  Serial.print("[VL53L0X] dist=");
  Serial.print(distance);
  Serial.print("mm (");
  Serial.print(distanceCm, 1);
  Serial.print("cm)");

  if (SHOW_BAR_GRAPH) {
    Serial.print("  |");
    int displayDist = constrain(distance, 0, MAX_DISPLAY_RANGE);
    int bars = map(displayDist, 0, MAX_DISPLAY_RANGE, 0, 20);
    for (int i = 0; i < 20; i++) {
      Serial.print(i < bars ? "█" : "░");
    }
    Serial.print("| ");
    Serial.print(MAX_DISPLAY_RANGE);
    Serial.print("mm");
  }

  Serial.println();
  delay(READ_INTERVAL);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns distance in millimeters, or -1 if invalid
int readDistanceMm() {
  VL53L0X_RangingMeasurementData_t m;
  sensor.rangingTest(&m, false);
  if (m.RangeStatus == 4) return -1;
  return m.RangeMilliMeter;
}

// Returns distance in centimeters, or -1 if invalid
float readDistanceCm() {
  int mm = readDistanceMm();
  if (mm < 0) return -1;
  return mm / 10.0;
}

// Returns true if object is within given range (mm)
bool isObjectWithin(int rangeMin, int rangeMax) {
  int d = readDistanceMm();
  return (d >= rangeMin && d <= rangeMax);
}

// Returns true if object is closer than threshold (mm)
bool isObjectCloserThan(int threshold) {
  int d = readDistanceMm();
  return (d > 0 && d < threshold);
}
