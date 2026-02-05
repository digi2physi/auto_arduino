/*
 * Component: Daryl Servo
 * Type: actuator
 *
 * INPUTS (what you provide):
 *   - SERVO_PIN: PWM-capable pin connected to servo signal wire
 *
 * CONTROLS (what you can do):
 *   - Set angle (0-180 degrees)
 *   - Smooth movement to target angle
 *   - Sweep back and forth
 *
 * PARAMETERS (what you can customize):
 *   - MIN_ANGLE: Minimum angle limit
 *   - MAX_ANGLE: Maximum angle limit
 *   - DEFAULT_SPEED: Delay between degrees for smooth movement
 *
 * WIRING:
 *   Servo VCC (red)    -> Arduino 5V (or external power)
 *   Servo GND (brown/black) -> Arduino GND
 *   Servo Signal (orange/yellow) -> Arduino PWM Pin (D9)
 *
 *   TIP: For multiple servos, use external 5-6V power supply
 *
 * LIBRARY:
 *   Uses built-in Servo library (no installation needed)
 */

#include <Servo.h>

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION - Modify this section
// ═══════════════════════════════════════════════════════════════

#define SERVO_PIN 9         // PWM pin connected to servo (must be PWM capable)
#define MIN_ANGLE 0         // Minimum angle limit
#define MAX_ANGLE 180       // Maximum angle limit
#define DEFAULT_SPEED 15    // Delay between degrees (lower = faster)

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE - Modify only if you know what you're doing
// ═══════════════════════════════════════════════════════════════

Servo servo;
int currentAngle = 90;

void setup() {
  Serial.begin(9600);

  servo.attach(SERVO_PIN);
  servo.write(currentAngle);

  Serial.println("Daryl Servo - Ready");
  Serial.println("-------------------");
  Serial.print("Starting at ");
  Serial.print(currentAngle);
  Serial.println(" degrees");
}

void loop() {
  // Demo: sweep back and forth
  Serial.println("[Servo] Sweeping to 0 degrees...");
  smoothMove(0);
  delay(500);

  Serial.println("[Servo] Sweeping to 180 degrees...");
  smoothMove(180);
  delay(500);

  Serial.println("[Servo] Moving to center (90 degrees)...");
  smoothMove(90);
  delay(1000);
}

// ═══════════════════════════════════════════════════════════════
// HELPER FUNCTIONS - Use these in your own code
// ═══════════════════════════════════════════════════════════════

// Move instantly to angle
void setAngle(int angle) {
  angle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
  servo.write(angle);
  currentAngle = angle;
}

// Move smoothly to target angle
void smoothMove(int targetAngle) {
  smoothMove(targetAngle, DEFAULT_SPEED);
}

// Move smoothly with custom speed (lower = faster)
void smoothMove(int targetAngle, int speedDelay) {
  targetAngle = constrain(targetAngle, MIN_ANGLE, MAX_ANGLE);

  if (targetAngle > currentAngle) {
    for (int a = currentAngle; a <= targetAngle; a++) {
      servo.write(a);
      delay(speedDelay);
    }
  } else {
    for (int a = currentAngle; a >= targetAngle; a--) {
      servo.write(a);
      delay(speedDelay);
    }
  }
  currentAngle = targetAngle;
}

// Get current angle
int getAngle() {
  return currentAngle;
}

// Sweep between two angles (one cycle)
void sweep(int fromAngle, int toAngle, int speedDelay) {
  smoothMove(fromAngle, speedDelay);
  smoothMove(toAngle, speedDelay);
}

// Center the servo (90 degrees)
void center() {
  smoothMove(90);
}

// Move by relative amount
void moveBy(int degrees) {
  smoothMove(currentAngle + degrees);
}

// Map a value (like sensor input) to servo angle
int mapToAngle(int value, int inMin, int inMax) {
  return map(value, inMin, inMax, MIN_ANGLE, MAX_ANGLE);
}
