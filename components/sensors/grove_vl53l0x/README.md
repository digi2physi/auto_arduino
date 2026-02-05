# Grove VL53L0X Time of Flight Distance Sensor

Laser-based distance sensor using Time of Flight (ToF) technology. Accurate measurements up to 2 meters.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. [Install library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/): Search "Adafruit_VL53L0X" in Library Manager
3. Upload `template.ino`
4. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)

## Wiring

This sensor uses [I2C communication](https://learn.sparkfun.com/tutorials/i2c/all) - a protocol that allows multiple devices to share two wires.

| Sensor Pin | Arduino Uno | Arduino Mega |
|------------|-------------|--------------|
| VCC | 5V (or 3.3V) | 5V (or 3.3V) |
| GND | GND | GND |
| SDA | A4 | 20 |
| SCL | A5 | 21 |

> **Using Grove Shield?** Plug into any I2C port

> **What is I2C?** [Learn about I2C protocol](https://learn.sparkfun.com/tutorials/i2c/all) - it lets you connect multiple sensors using just 2 wires (SDA for data, SCL for clock).

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `distance` | int | 30-2000mm | Distance in millimeters |
| `distanceCm` | float | 3-200cm | Distance in centimeters |
| `isValid` | bool | - | True if reading is valid |

## Helper Functions

```cpp
int readDistanceMm();                      // Get distance in mm (-1 if invalid)
float readDistanceCm();                    // Get distance in cm (-1 if invalid)
bool isObjectWithin(int min, int max);     // Check if object in range (mm)
bool isObjectCloserThan(int threshold);    // Check if object closer than threshold
```

## Example Usage

```cpp
// Proximity alert
if (isObjectCloserThan(100)) {  // 100mm = 10cm
  Serial.println("Object detected nearby!");
}

// Range check
if (isObjectWithin(50, 200)) {
  Serial.println("Object in target zone");
}

// Get raw distance
int d = readDistanceMm();
if (d > 0) {
  Serial.print("Distance: ");
  Serial.println(d);
}
```

## Serial Output

With `SHOW_BAR_GRAPH true` (default):
```
[VL53L0X] dist=125mm (12.5cm)  |█████░░░░░░░░░░░░░░░| 500mm
[VL53L0X] dist=342mm (34.2cm)  |█████████████░░░░░░░| 500mm
[VL53L0X] dist=67mm (6.7cm)    |██░░░░░░░░░░░░░░░░░░| 500mm
```

With `SHOW_BAR_GRAPH false`:
```
[VL53L0X] dist=125mm (12.5cm)
[VL53L0X] dist=342mm (34.2cm)
```

## Configuration Tips

- Adjust `MAX_DISPLAY_RANGE` to match your use case (default 500mm)
- Decrease `READ_INTERVAL` for faster updates (minimum ~20ms)
- Sensor works best with diffuse surfaces; shiny or transparent surfaces may give errors

## Troubleshooting

- **"VL53L0X not found"**: Check I2C wiring (SDA→A4, SCL→A5 on Uno)
- **"Out of range"**: Object too far (>2m) or surface not reflecting laser
- **Inconsistent readings**: Ensure stable mounting, avoid vibration

## Learn More

- [How Time of Flight sensors work](https://learn.adafruit.com/adafruit-vl53l0x-micro-lidar-distance-sensor-breakout/overview)
- [I2C communication explained](https://learn.sparkfun.com/tutorials/i2c/all)
- [Arduino I2C pins reference](https://www.arduino.cc/reference/en/language/functions/communication/wire/)
- [Sensor datasheet](https://wiki.seeedstudio.com/Grove-Time_of_Flight_Distance_Sensor-VL53L0X/)
