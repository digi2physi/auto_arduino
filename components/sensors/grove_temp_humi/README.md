# Grove Temperature & Humidity Sensor

Digital temperature and humidity sensor based on DHT11. Simple and reliable for basic environmental monitoring.

## Quick Start

1. Connect sensor to **Digital port D2** (or change `DHT_PIN`)
2. Install library: Sketch → Include Library → Manage Libraries → Search "DHT sensor library" by Adafruit
3. Upload `template.ino`
4. Open Serial Monitor (9600 baud)

## Wiring

**Grove Shield:** Plug into any Digital port (D2, D3, D4...)

**Manual wiring:**
| Sensor | Arduino |
|--------|---------|
| VCC | 5V |
| GND | GND |
| SIG | D2 |

## Outputs

| Output | Type | Range | Accuracy | Description |
|--------|------|-------|----------|-------------|
| `temperature` | float | 0-50°C | ±2°C | Temperature in Celsius |
| `humidity` | float | 20-90% | ±5% | Relative humidity |
| `isValid` | bool | - | - | Reading validity check |

## Helper Functions

```cpp
float readTemperature();    // Get temperature in Celsius
float readTemperatureF();   // Get temperature in Fahrenheit
float readHumidity();       // Get humidity percentage
bool isReadingValid();      // Check if sensor works
```

## Example Usage

```cpp
// Simple threshold alert
if (readTemperature() > 30) {
  Serial.println("It's hot!");
}

// Check humidity
if (readHumidity() < 40) {
  Serial.println("Air is dry");
}
```

## Serial Output

With `SHOW_BAR_GRAPH true` (default):
```
[TempHumi] temp=24.0C |█████████░░░░░░░░░░░|  humi=65.0% |█████████████░░░░░░░|
[TempHumi] temp=24.5C |█████████░░░░░░░░░░░|  humi=64.0% |████████████░░░░░░░░|
```

With `SHOW_BAR_GRAPH false`:
```
[TempHumi] temp=24.0C  humi=65.0%
[TempHumi] temp=24.5C  humi=64.0%
```

## Notes

- DHT11 requires minimum 2 seconds between readings
- First reading after power-on may be invalid
- Accuracy is limited (±2°C, ±5% humidity) - for precision use DHT22/AM2302
