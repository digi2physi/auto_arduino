# Grove Temperature & Humidity Sensor

Digital temperature and humidity sensor based on DHT11. Simple and reliable for basic environmental monitoring.

## Quick Start

1. Wire the sensor to your Arduino (see [Wiring](#wiring) below)
2. [Install library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/): Search "DHT sensor library" by Adafruit in Library Manager
3. Upload `template.ino`
4. Open [Serial Monitor](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) (9600 baud)

## Wiring

| Sensor Pin | Arduino |
|------------|---------|
| VCC | 5V |
| GND | GND |
| SIG | D2 ([digital pin](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/#digital-pins)) |

> **Using Grove Shield?** Plug into any Digital port (D2, D3, D4...)

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

## Troubleshooting

- **"Failed to read sensor"**: Check wiring, ensure 5V power
- **First reading invalid**: Normal - DHT11 needs warmup time
- **Readings fluctuate**: DHT11 has limited accuracy (±2°C, ±5%); for precision use DHT22

## Learn More

- [How DHT11 works](https://lastminuteengineers.com/dht11-dht22-arduino-tutorial/)
- [Temperature vs Humidity explained](https://www.weather.gov/arx/why_dewpoint_vs_humidity)
- [Installing Arduino libraries](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/)
- [Sensor datasheet](https://wiki.seeedstudio.com/Grove-TemperatureAndHumidity_Sensor/)
