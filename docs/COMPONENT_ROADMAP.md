# Component Roadmap

## Status Legend
- ⬜ Not started
- 🟨 In progress
- ✅ Complete and tested

---

## Grove Sensors

| Component | Status | Difficulty | Notes |
|-----------|--------|------------|-------|
| VL53L0X (Time of Flight) | 🟨 | beginner | Distance sensor, I2C, up to 2m range |
| BMA400 (Accelerometer) | 🟨 | intermediate | 3-axis accelerometer, I2C, low power |
| Temp & Humi Sensor | 🟨 | beginner | Temperature and humidity, DHT11 based |
| Light Sensor v1.2 | 🟨 | beginner | Analog light intensity sensor |
| I2C Color Sensor v2.0 | 🟨 | beginner | RGB color detection, I2C |

---

## Other Sensors

| Component | Status | Difficulty | Notes |
|-----------|--------|------------|-------|
| SEN-21999 | 🟨 | beginner | SparkFun sensor |

---

## Actuators

| Component | Status | Difficulty | Notes |
|-----------|--------|------------|-------|
| WS2811 LED (F5-C-WS2811) | 🟨 | beginner | Addressable RGB LED |
| Daryl Servo | 🟨 | beginner | Servo motor |

---

## Priority Order

1. ~~Light Sensor v1.2~~ ✓
2. ~~Temp & Humi Sensor~~ ✓
3. ~~VL53L0X~~ ✓
4. ~~BMA400~~ ✓
5. Grove I2C Color Sensor v2.0
6. WS2811 LED
7. SEN-21999
8. Daryl Servo

---

## Adding New Components

To add a new component:
1. Create folder: `components/[category]/[component_name]/`
2. Create `component.json` with metadata
3. Create `template.ino` following the standard format
4. Create `README.md` with quick reference
5. Test with actual hardware
6. Update this roadmap
