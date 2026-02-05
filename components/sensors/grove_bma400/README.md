# Grove BMA400 3-Axis Accelerometer

Low-power 3-axis accelerometer for motion detection, orientation sensing, and tilt measurement.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. [Install library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/): Search "Grove 3-Axis Digital Accelerometer BMA400" in Library Manager
3. Upload `template.ino`
4. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)

## Wiring

This sensor uses [I2C communication](https://learn.sparkfun.com/tutorials/i2c/all) - a protocol that allows multiple devices to share two wires.

| Sensor Pin | Arduino Uno | Arduino Mega |
|------------|-------------|--------------|
| VCC | 3.3V or 5V | 3.3V or 5V |
| GND | GND | GND |
| SDA | A4 | 20 |
| SCL | A5 | 21 |

> **Using Grove Shield?** Plug into any I2C port

> **What is I2C?** [Learn about I2C protocol](https://learn.sparkfun.com/tutorials/i2c/all) - it lets you connect multiple sensors using just 2 wires (SDA for data, SCL for clock).

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `accelX` | float | -2 to +2g | X axis [acceleration](https://www.arduino.cc/education/courses/accelerometer-basics/) |
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

When flat on table: X≈0, Y≈0, Z≈+1g (gravity pulling down)

> **What is "g"?** 1g = 9.8 m/s² (Earth's gravity). When stationary, the sensor reads ~1g pointing toward Earth's center. [Learn more about accelerometers](https://learn.sparkfun.com/tutorials/accelerometer-basics/all).

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

## Troubleshooting

- **"BMA400 not found"**: Check I2C wiring (SDA→A4, SCL→A5 on Uno)
- **Z not reading ~1g when flat**: Sensor may be tilted or miscalibrated
- **Noisy readings**: Add small delay between reads, or average multiple samples

## Learn More

- [How accelerometers work](https://learn.sparkfun.com/tutorials/accelerometer-basics/all)
- [I2C communication explained](https://learn.sparkfun.com/tutorials/i2c/all)
- [Pitch and Roll explained](https://www.youtube.com/watch?v=pQ24NtnaLl8)
- [Arduino I2C pins reference](https://www.arduino.cc/reference/en/language/functions/communication/wire/)
- [Sensor datasheet](https://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer_BMA400/)
