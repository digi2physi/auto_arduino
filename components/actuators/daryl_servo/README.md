# Daryl Servo

Standard hobby servo motor for precise angular positioning. Rotates to any angle between 0-180 degrees.

## Quick Start

1. Wire the servo to your Arduino (see [Wiring](#wiring) below)
2. Upload `template.ino`
3. Watch the servo sweep back and forth

## Wiring

| Servo Wire | Arduino |
|------------|---------|
| VCC (red) | 5V |
| GND (brown/black) | GND |
| Signal (orange/yellow) | D9 ([PWM pin](https://docs.arduino.cc/learn/microcontrollers/analog-output/)) |

> **PWM Pins on Arduino Uno:** 3, 5, 6, 9, 10, 11 (marked with ~)

> **Multiple servos or high-torque?** Use external 5-6V power supply. Connect external GND to Arduino GND.

## Configuration

```cpp
#define SERVO_PIN 9       // Must be a PWM pin
#define MIN_ANGLE 0       // Minimum angle limit
#define MAX_ANGLE 180     // Maximum angle limit
#define DEFAULT_SPEED 15  // Lower = faster movement
```

## Helper Functions

```cpp
setAngle(angle);                     // Move instantly to angle
smoothMove(angle);                   // Move smoothly to angle
smoothMove(angle, speed);            // Move smoothly with custom speed
getAngle();                          // Get current angle
sweep(fromAngle, toAngle, speed);    // Sweep between two angles
center();                            // Move to 90 degrees
moveBy(degrees);                     // Move relative (+/-)
mapToAngle(value, inMin, inMax);     // Convert sensor value to angle
```

## Example Usage

```cpp
// Move to specific angle
setAngle(45);

// Smooth movement
smoothMove(180);

// Control with potentiometer
int potValue = analogRead(A0);
int angle = mapToAngle(potValue, 0, 1023);
setAngle(angle);

// React to sensor
if (motionDetected) {
  smoothMove(90);   // Look center
} else {
  sweep(0, 180, 10); // Scan around
}
```

## Serial Output

```
[Servo] Sweeping to 0 degrees...
[Servo] Sweeping to 180 degrees...
[Servo] Moving to center (90 degrees)...
```

## Troubleshooting

- **Servo jitters/twitches**: Use external power supply, add capacitor across power lines
- **Servo doesn't move**: Check signal wire is on PWM pin (marked ~)
- **Servo moves wrong direction**: Swap MIN_ANGLE and MAX_ANGLE
- **Limited range**: Some servos have less than 180° range; adjust limits

## Learn More

- [How servo motors work](https://lastminuteengineers.com/servo-motor-arduino-tutorial/)
- [PWM explained](https://docs.arduino.cc/learn/microcontrollers/analog-output/)
- [Arduino Servo library](https://www.arduino.cc/reference/en/libraries/servo/)
- [Servo motor basics](https://learn.sparkfun.com/tutorials/hobby-servo-tutorial/all)
