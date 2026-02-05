# Grove BMA400 3-Axis Accelerometer

Low-power 3-axis accelerometer for motion detection, orientation sensing, and tilt measurement.

## Quick Start

1. Connect sensor to **I2C port** (any I2C port on Grove shield)
2. Install library: Sketch → Include Library → Manage Libraries → Search "Grove 3-Axis Digital Accelerometer BMA400"
3. Upload `template.ino`
4. Open Serial Monitor (9600 baud)

## Wiring

**Grove Shield:** Plug into any I2C port

**Manual wiring:**
| Sensor | Arduino Uno | Arduino Mega |
|--------|-------------|--------------|
| VCC | 3.3V or 5V | 3.3V or 5V |
| GND | GND | GND |
| SDA | A4 | 20 |
| SCL | A5 | 21 |

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `accelX` | float | -2 to +2g | X axis acceleration |
| `accelY` | float | -2 to +2g | Y axis acceleration |
| `accelZ` | float | -2 to +2g | Z axis acceleration |
| `pitch` | float | -90° to +90° | Tilt forward/backward |
| `roll` | float | -180° to +180° | Tilt left/right |

## Axis Orientation

```
        Z (up)
        │
        │
        └───── Y (right)
       /
      /
     X (forward)
```

When flat on table: X≈0, Y≈0, Z≈+1g

## Helper Functions

```cpp
float readAccelX();              // Get X acceleration in g
float readAccelY();              // Get Y acceleration in g
float readAccelZ();              // Get Z acceleration in g
float readPitch();               // Get pitch angle in degrees
float readRoll();                // Get roll angle in degrees
bool isMoving(float threshold);  // Detect movement
bool isFlat(float tolerance);    // Check if device is flat
```

## Example Usage

```cpp
// Motion detection
if (isMoving(0.2)) {
  Serial.println("Device moved!");
}

// Orientation check
if (isFlat(0.1)) {
  Serial.println("Device is flat");
}

// Tilt-based control
float tilt = readPitch();
if (tilt > 30) {
  Serial.println("Tilted forward");
} else if (tilt < -30) {
  Serial.println("Tilted backward");
}
```

## Serial Output

With `SHOW_BAR_GRAPH true` (default):
```
[BMA400] X=+0.05g [░░░░░█░░░░░] Y=-0.12g [░░░░█|░░░░░] Z=+0.98g [░░░░░|░░░░█]
         pitch=+2.9° roll=-6.8°
```

The bar graph shows:
- `|` = center (0g)
- `█` = current value
- Range: -2g to +2g

With `SHOW_BAR_GRAPH false`:
```
[BMA400] X=+0.05g Y=-0.12g Z=+0.98g
         pitch=+2.9° roll=-6.8°
```

## Notes

- At rest on flat surface, Z should read approximately +1g (gravity)
- Pitch and roll are calculated from acceleration, not true gyroscope data
- For precise orientation tracking, consider sensor fusion with a gyroscope
