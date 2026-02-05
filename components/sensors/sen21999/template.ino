/*
 * Component: SparkFun PIR Breakout - 1µA (SEN-21999)
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - PIR_PIN: Digital pin connected to sensor output
 *
 * OUTPUTS (what you get):
 *   - motionDetected: bool - True when motion is detected
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: Time between readings in ms
 *   - SHOW_BAR_GRAPH: Toggle visual indicator
 *
 * WIRING:
 *   Sensor VCC -> Arduino 3.3V (NOT 5V!)
 *   Sensor GND -> Arduino GND
 *   Sensor OUT -> Arduino Digital Pin (D2)
 *
 * LIBRARY:
 *   None required - uses built-in digitalRead
 */

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define PIR_PIN 2             // Digital pin connected to sensor
#define READ_INTERVAL 100     // Time between readings (ms)
#define SHOW_BAR_GRAPH true   // Set to false to disable visual indicator

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

bool motionDetected = false;
bool lastMotionState = false;

void setup() {
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);

  Serial.println("SparkFun PIR (SEN-21999) - Ready");
  Serial.println("--------------------------------");
  Serial.println("Warming up sensor (wait ~30 seconds)...");
  delay(2000);  // Brief warmup
  Serial.println("Ready to detect motion!");
}

void loop() {
  // Read sensor state
  motionDetected = digitalRead(PIR_PIN) == HIGH;

  // Output status
  Serial.print("[PIR] ");

  if (motionDetected) {
    Serial.print("MOTION DETECTED!");
    if (SHOW_BAR_GRAPH) {
      Serial.print(" [██████████]");
    }
  } else {
    Serial.print("No motion      ");
    if (SHOW_BAR_GRAPH) {
      Serial.print(" [░░░░░░░░░░]");
    }
  }

  Serial.println();

  // Notify on state change
  if (motionDetected != lastMotionState) {
    if (motionDetected) {
      Serial.println(">>> Motion started!");
    } else {
      Serial.println(">>> Motion ended.");
    }
    lastMotionState = motionDetected;
  }

  delay(READ_INTERVAL);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Returns true if motion is currently detected
bool isMotionDetected() {
  return digitalRead(PIR_PIN) == HIGH;
}

// Waits for motion and returns true when detected (with timeout)
bool waitForMotion(unsigned long timeoutMs) {
  unsigned long startTime = millis();
  while (millis() - startTime < timeoutMs) {
    if (isMotionDetected()) {
      return true;
    }
    delay(50);
  }
  return false;
}

// Returns true only when motion STARTS (rising edge)
bool motionStarted() {
  static bool lastState = false;
  bool currentState = isMotionDetected();
  bool started = (currentState && !lastState);
  lastState = currentState;
  return started;
}

// Returns true only when motion ENDS (falling edge)
bool motionEnded() {
  static bool lastState = false;
  bool currentState = isMotionDetected();
  bool ended = (!currentState && lastState);
  lastState = currentState;
  return ended;
}
