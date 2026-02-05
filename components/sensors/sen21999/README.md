# SparkFun PIR Breakout - 1µA (SEN-21999)

Ultra-low power passive infrared (PIR) motion sensor. Detects movement of warm bodies (humans, animals) by sensing infrared radiation changes.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. Upload `template.ino`
3. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)
4. Wait ~30 seconds for sensor warmup
5. Walk in front of the sensor to test

## Wiring

| Sensor Pin | Arduino |
|------------|---------|
| VCC | **3.3V** (not 5V!) |
| GND | GND |
| OUT | D2 ([digital pin](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/#digital-pins)) |

> **Important:** This sensor requires 3.3V power, not 5V!

## Outputs

| Output | Type | Description |
|--------|------|-------------|
| `motionDetected` | bool | `true` when motion detected, `false` otherwise |

## Helper Functions

```cpp
bool isMotionDetected();              // Check if motion is currently detected
bool waitForMotion(timeoutMs);        // Wait for motion with timeout
bool motionStarted();                 // True only when motion STARTS
bool motionEnded();                   // True only when motion ENDS
```

## Example Usage

```cpp
// Simple motion check
if (isMotionDetected()) {
  Serial.println("Someone is here!");
}

// React only when motion starts
if (motionStarted()) {
  digitalWrite(LED_PIN, HIGH);  // Turn on light
}

// Wait for motion (with 10 second timeout)
if (waitForMotion(10000)) {
  Serial.println("Motion detected within 10 seconds");
} else {
  Serial.println("Timeout - no motion");
}
```

## Serial Output

```
[PIR] No motion       [░░░░░░░░░░]
[PIR] MOTION DETECTED! [██████████]
>>> Motion started!
[PIR] MOTION DETECTED! [██████████]
[PIR] No motion       [░░░░░░░░░░]
>>> Motion ended.
```

## Troubleshooting

- **Always detecting motion**: Wait 30-60 seconds after power on for warmup
- **Not detecting**: Make sure VCC is connected to 3.3V (not 5V)
- **Inconsistent detection**: Avoid pointing at heat sources (windows, heaters)
- **Detection range too short/long**: Some PIR sensors have adjustable sensitivity

## Learn More

- [How PIR sensors work](https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/how-pirs-work)
- [PIR sensor tutorial](https://lastminuteengineers.com/pir-sensor-arduino-tutorial/)
- [SparkFun product page](https://www.sparkfun.com/products/21999)
- [Digital input explained](https://docs.arduino.cc/learn/microcontrollers/digital-pins/)
