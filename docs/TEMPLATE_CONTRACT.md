# Template Contract Format

## Overview
Each component template follows a standard "contract" format that clearly defines:
1. What the component expects (inputs)
2. What the component provides (outputs)
3. What the user can customize (parameters)

## Contract Structure

### Header Section
Every template file starts with a structured header comment:

```cpp
/*
 * Component: [Component Name]
 * Type: [sensor/actuator/display]
 *
 * INPUTS (what you provide):
 *   - PIN_xxx: [description]
 *   - [other required inputs]
 *
 * OUTPUTS (what you get):
 *   - [output_name]: [type] - [description]
 *   - [output_name]: [type] - [description]
 *
 * PARAMETERS (what you can customize):
 *   - [param_name]: [default] - [description]
 *
 * WIRING:
 *   [Simple wiring diagram or instructions]
 */
```

## Example: Temperature Sensor (DHT11)

```cpp
/*
 * Component: DHT11 Temperature & Humidity Sensor
 * Type: sensor
 *
 * INPUTS (what you provide):
 *   - DATA_PIN: Digital pin connected to DHT11 data pin
 *
 * OUTPUTS (what you get):
 *   - temperature: float - Temperature in Celsius
 *   - humidity: float - Relative humidity percentage
 *   - heatIndex: float - "Feels like" temperature
 *   - isValid: bool - Whether the reading is valid
 *
 * PARAMETERS (what you can customize):
 *   - READ_INTERVAL: 2000ms - Minimum time between readings
 *   - USE_FAHRENHEIT: false - Set true for Fahrenheit output
 *
 * WIRING:
 *   DHT11 VCC  -> Arduino 5V
 *   DHT11 GND  -> Arduino GND
 *   DHT11 DATA -> Arduino Digital Pin (your choice)
 */
```

## Contract Metadata File (component.json)

Each component folder also contains a `component.json` for programmatic access:

```json
{
  "name": "DHT11 Temperature & Humidity Sensor",
  "type": "sensor",
  "category": "temperature",
  "difficulty": "beginner",
  "inputs": [
    {
      "name": "DATA_PIN",
      "type": "digital_pin",
      "required": true,
      "description": "Digital pin connected to DHT11 data pin"
    }
  ],
  "outputs": [
    {
      "name": "temperature",
      "type": "float",
      "unit": "celsius",
      "description": "Temperature reading"
    },
    {
      "name": "humidity",
      "type": "float",
      "unit": "percent",
      "description": "Relative humidity"
    }
  ],
  "parameters": [
    {
      "name": "READ_INTERVAL",
      "type": "int",
      "default": 2000,
      "unit": "ms",
      "description": "Minimum time between readings"
    }
  ],
  "dependencies": ["DHT.h"],
  "testedWith": ["Arduino Uno", "Arduino Nano", "ESP32"]
}
```

## Design Principles

1. **Explicit over Implicit**: Every input/output/parameter is documented
2. **Tested Templates**: Every template is verified with actual hardware before publishing
3. **Minimal Dependencies**: Use standard libraries when possible
4. **Readable Code**: Prioritize clarity over cleverness
