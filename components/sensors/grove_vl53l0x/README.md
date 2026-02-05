# Grove VL53L0X Time of Flight Distance Sensor

Laser-based distance sensor using Time of Flight (ToF) technology. Accurate measurements up to 2 meters.

## Quick Start

1. Connect sensor to **I2C port** (any I2C port on Grove shield)
2. Install library: Sketch → Include Library → Manage Libraries → Search "Adafruit_VL53L0X"
3. Upload `template.ino`
4. Open Serial Monitor (9600 baud)

## Wiring

**Grove Shield:** Plug into any I2C port

**Manual wiring:**
| Sensor | Arduino Uno | Arduino Mega |
|--------|-------------|--------------|
| VCC | 5V (or 3.3V) | 5V (or 3.3V) |
| GND | GND | GND |
| SDA | A4 | 20 |
| SCL | A5 | 21 |

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

## Notes

- I2C address is fixed at 0x29
- Readings below 30mm may be unreliable
- "Out of range" error means object is too far or no reflection detected
