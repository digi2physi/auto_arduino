# Grove Light Sensor v1.2

Analog light intensity sensor using a photoresistor (LDR). Outputs higher values in brighter light.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. Upload `template.ino`
3. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)

## Wiring

| Sensor Pin | Arduino |
|------------|---------|
| VCC | 5V |
| GND | GND |
| SIG | A0 ([analog pin](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/#analog-pins)) |

> **Using Grove Shield?** Plug into any Analog port (A0, A1, A2...)

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `rawValue` | int | 0-1023 | Raw [analog reading](https://www.arduino.cc/reference/en/language/functions/analog-io/analogread/) |
| `percentage` | int | 0-100 | Light level (0=dark, 100=bright) |

## Helper Functions

```cpp
int readLightRaw();           // Get raw value (0-1023)
int readLightPercent();       // Get percentage (0-100)
bool isLightAbove(int threshold);  // Check if above threshold
```

## Example Usage

```cpp
// Turn on LED when it's dark
if (readLightPercent() < 30) {
  digitalWrite(LED_PIN, HIGH);
}
```

## Serial Output

With `SHOW_BAR_GRAPH true` (default):
```
[Light] raw=512, percent=50%  |██████████░░░░░░░░░░|
[Light] raw=890, percent=87%  |█████████████████░░░|
[Light] raw=123, percent=12%  |██░░░░░░░░░░░░░░░░░░|
```

With `SHOW_BAR_GRAPH false`:
```
[Light] raw=512, percent=50%
[Light] raw=890, percent=87%
```

## Learn More

- [How LDR (photoresistor) works](https://www.electronics-tutorials.ws/io/io_4.html)
- [Analog Input on Arduino](https://docs.arduino.cc/built-in-examples/basics/AnalogReadSerial/)
- [Sensor datasheet](https://wiki.seeedstudio.com/Grove-Light_Sensor/)
