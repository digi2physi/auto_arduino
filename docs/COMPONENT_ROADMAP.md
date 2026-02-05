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

---

## Priority Order

1. **Light Sensor v1.2** - Simplest, analog read
2. **Temp & Humi Sensor** - Common beginner sensor
3. **VL53L0X** - Distance measurement, I2C
4. **BMA400** - Accelerometer, more outputs to handle

---

## Adding New Components

To add a new component:
1. Create folder: `components/sensors/grove_[component_name]/`
2. Create `component.json` with metadata
3. Create `template.ino` following the standard format
4. Create `README.md` with quick reference
5. Test with actual hardware
6. Update this roadmap
