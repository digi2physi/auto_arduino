# Grove I2C Color Sensor v2.0

RGB color sensor based on TCS34725. Detects color values and light intensity.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. [Install library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/): Search "Adafruit TCS34725" in Library Manager
3. Upload `template.ino`
4. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)

## Wiring

This sensor uses [I2C communication](https://learn.sparkfun.com/tutorials/i2c/all).

| Sensor Pin | Arduino Uno | Arduino Mega |
|------------|-------------|--------------|
| VCC | 3.3V or 5V | 3.3V or 5V |
| GND | GND | GND |
| SDA | A4 | 20 |
| SCL | A5 | 21 |

> **Using Grove Shield?** Plug into any I2C port

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `red` | int | 0-255 | Red color intensity |
| `green` | int | 0-255 | Green color intensity |
| `blue` | int | 0-255 | Blue color intensity |
| `clear` | int | 0-65535 | Clear (total) light intensity |

## Helper Functions

```cpp
int readRed();                    // Get red value (0-255)
int readGreen();                  // Get green value (0-255)
int readBlue();                   // Get blue value (0-255)
String getDominantColor();        // Get "RED", "GREEN", "BLUE", or "MIXED"
bool isColor(r, g, b, tolerance); // Check if color matches target
```

## Example Usage

```cpp
// Detect dominant color
String color = getDominantColor();
Serial.println("Detected: " + color);

// Check for specific color (red)
if (isColor(200, 50, 50, 30)) {
  Serial.println("Red object detected!");
}

// Read individual values
int r = readRed();
int g = readGreen();
int b = readBlue();
```

## Serial Output

With `SHOW_BAR_GRAPH true` (default):
```
[Color] R=180 [███████░░░] G=45 [████░░░░░░] B=32 [███░░░░░░░] (clear=1250)
[Color] R=52 [█████░░░░░] G=210 [████████░░] B=48 [████░░░░░░] (clear=2100)
```

With `SHOW_BAR_GRAPH false`:
```
[Color] R=180 G=45 B=32 (clear=1250)
```

## Troubleshooting

- **"Color sensor not found"**: Check I2C wiring (SDA→A4, SCL→A5 on Uno)
- **Values always low**: Ensure object is close to sensor (1-2cm works best)
- **Inconsistent readings**: Use consistent lighting, avoid shadows

## Learn More

- [How RGB color sensing works](https://learn.adafruit.com/adafruit-color-sensors/overview)
- [RGB color model explained](https://www.w3schools.com/colors/colors_rgb.asp)
- [I2C communication explained](https://learn.sparkfun.com/tutorials/i2c/all)
- [Sensor datasheet](https://wiki.seeedstudio.com/Grove-I2C_Color_Sensor_V2/)
