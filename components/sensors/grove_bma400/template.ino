/*
 * Component: Grove BMA400 3-Axis Accelerometer
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - None (I2C connection, auto-detected)
 *
 * OUTPUTS (what you get):
 *   - accelX: float (-2 to +2g) - X axis acceleration
 *   - accelY: float (-2 to +2g) - Y axis acceleration
 *   - accelZ: float (-2 to +2g) - Z axis acceleration
 *   - pitch: float (-90 to +90°) - Tilt forward/backward
 *   - roll: float (-180 to +180°) - Tilt left/right
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
 *   Install "Grove 3-Axis Digital Accelerometer BMA400" via Library Manager
 *   Or download from: https://github.com/Seeed-Studio/Grove_3Axis_Digital_Accelerometer_BMA400
 */

#include <Wire.h>
#include <Grove_3Axis_Digital_Accelerometer_BMA400.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define READ_INTERVAL 100       // Time between readings (ms)
#define SHOW_BAR_GRAPH true     // Set to false to disable visual bar graph

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

BMA400 sensor;

float accelX = 0;
float accelY = 0;
float accelZ = 0;
float pitch = 0;
float roll = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Grove BMA400 Accelerometer - Initializing...");

  if (sensor.isConnection()) {
    sensor.initialize();
    Serial.println("Grove BMA400 Accelerometer - Ready");
    Serial.println("-----------------------------------");
  } else {
    Serial.println("ERROR: BMA400 not found. Check wiring!");
    while (1);
  }
}

void loop() {
  // Read acceleration values
  sensor.getAcceleration(&accelX, &accelY, &accelZ);

  // Calculate pitch and roll angles
  pitch = atan2(accelX, sqrt(accelY * accelY + accelZ * accelZ)) * 180.0 / PI;
  roll = atan2(accelY, accelZ) * 180.0 / PI;

  // Output X axis
  Serial.print("[BMA400] X=");
  printFloat(accelX, 2);
  Serial.print("g");
  if (SHOW_BAR_GRAPH) printAxisBar(accelX);

  // Output Y axis
  Serial.print(" Y=");
  printFloat(accelY, 2);
  Serial.print("g");
  if (SHOW_BAR_GRAPH) printAxisBar(accelY);

  // Output Z axis
  Serial.print(" Z=");
  printFloat(accelZ, 2);
  Serial.print("g");
  if (SHOW_BAR_GRAPH) printAxisBar(accelZ);

  Serial.println();

  // Output angles on separate line
  Serial.print("         pitch=");
  printFloat(pitch, 1);
  Serial.print("° roll=");
  printFloat(roll, 1);
  Serial.println("°");

  delay(READ_INTERVAL);
}

// Print float with sign and padding
void printFloat(float val, int decimals) {
  if (val >= 0) Serial.print("+");
  Serial.print(val, decimals);
}

// Print bar graph for axis value (-2g to +2g)
void printAxisBar(float val) {
  Serial.print(" [");
  int center = 5;
  int pos = constrain(map(val * 100, -200, 200, 0, 10), 0, 10);
  for (int i = 0; i <= 10; i++) {
    if (i == center) {
      Serial.print(i == pos ? "█" : "|");
    } else if (i == pos) {
      Serial.print("█");
    } else {
      Serial.print("░");
    }
  }
  Serial.print("]");
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns acceleration on X axis in g
float readAccelX() {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return x;
}

// Returns acceleration on Y axis in g
float readAccelY() {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return y;
}

// Returns acceleration on Z axis in g
float readAccelZ() {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return z;
}

// Returns pitch angle in degrees (-90 to +90)
float readPitch() {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return atan2(x, sqrt(y * y + z * z)) * 180.0 / PI;
}

// Returns roll angle in degrees (-180 to +180)
float readRoll() {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return atan2(y, z) * 180.0 / PI;
}

// Returns true if movement detected (acceleration exceeds threshold in any axis)
bool isMoving(float threshold) {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  // Check if any axis deviates from expected gravity
  return (abs(x) > threshold || abs(y) > threshold || abs(abs(z) - 1.0) > threshold);
}

// Returns true if device is roughly flat (Z pointing up or down)
bool isFlat(float tolerance) {
  float x, y, z;
  sensor.getAcceleration(&x, &y, &z);
  return (abs(x) < tolerance && abs(y) < tolerance);
}
