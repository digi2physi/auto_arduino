# User Guide - How to Use DaVinci Templates

## Quick Start

### Step 1: Find Your Component
Browse the `components/` folder and find the component you need:
```
components/
├── sensors/
│   ├── temperature/
│   │   ├── dht11/
│   │   ├── dht22/
│   │   └── ds18b20/
│   ├── motion/
│   │   ├── pir/
│   │   └── ultrasonic/
│   └── light/
│       └── ldr/
├── actuators/
│   ├── motors/
│   └── leds/
└── displays/
    ├── lcd_i2c/
    └── oled/
```

### Step 2: Read the Contract
Open the component folder and check:
1. **README.md** - Quick overview and wiring guide
2. **component.json** - Structured metadata
3. **template.ino** - The actual Arduino code

### Step 3: Copy and Customize
1. Copy the `template.ino` to your project
2. Look for the `USER CONFIGURATION` section at the top
3. Change only what you need (pin numbers, parameters)
4. Upload to your Arduino

## Template File Structure

Each template follows this structure:

```cpp
// ═══════════════════════════════════════════════════════════════
// COMPONENT INFO (don't modify)
// ═══════════════════════════════════════════════════════════════
/*
 * [Contract header - explains inputs/outputs/parameters]
 */

// ═══════════════════════════════════════════════════════════════
// USER CONFIGURATION (modify this section)
// ═══════════════════════════════════════════════════════════════
#define DATA_PIN 2        // <-- Change this to your pin
#define READ_INTERVAL 2000 // <-- Change if needed

// ═══════════════════════════════════════════════════════════════
// TEMPLATE CODE (modify only if you know what you're doing)
// ═══════════════════════════════════════════════════════════════
// ... rest of the code
```

## Understanding the Output

### Serial Monitor
All templates output data to Serial Monitor in a consistent format:
```
[ComponentName] value1=123, value2=456, status=OK
```

### For Advanced Users
Templates expose functions you can use in your own code:
```cpp
float temp = readTemperature();
bool isMotion = checkMotion();
```

## Combining Multiple Components

See the `examples/` folder for projects that combine multiple components:
- `examples/weather_station/` - Temperature + Humidity + Display
- `examples/motion_light/` - PIR sensor + LED
- `examples/data_logger/` - Multiple sensors + SD card

## Troubleshooting

### "No reading" or "NaN"
- Check your wiring matches the WIRING section
- Verify the correct pin number in USER CONFIGURATION
- Make sure the component is powered (5V/3.3V as required)

### "Library not found"
- Install required libraries via Arduino IDE: Sketch → Include Library → Manage Libraries
- Required libraries are listed in `component.json` under "dependencies"

### Still not working?
- Check the component's README.md for known issues
- Try the "test" sketch in the component folder (if available)
