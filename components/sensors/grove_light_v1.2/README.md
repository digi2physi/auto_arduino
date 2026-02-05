# Grove Light Sensor v1.2

Analog light intensity sensor using a photoresistor. Outputs higher values in brighter light.

## Quick Start

1. Connect sensor to **Analog port A0** (or change `LIGHT_PIN`)
2. Upload `template.ino`
3. Open Serial Monitor (9600 baud)

## Wiring

**Grove Shield:** Plug into any Analog port (A0, A1, A2...)

**Manual wiring:**
| Sensor | Arduino |
|--------|---------|
| VCC | 5V |
| GND | GND |
| SIG | A0 |

## Outputs

| Output | Type | Range | Description |
|--------|------|-------|-------------|
| `rawValue` | int | 0-1023 | Raw analog reading |
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
[Light] raw=123, percent=12%
```
