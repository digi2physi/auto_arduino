# Design Philosophy

## Core Principles

### 1. "It Just Works"
Every template should work out-of-the-box when wired correctly. No debugging required for basic use. Users should feel immediate success.

### 2. Clear Boundaries
Users should know exactly:
- What they CAN change (USER CONFIGURATION section)
- What they SHOULDN'T change unless experienced (TEMPLATE CODE section)
- What each input/output does (Contract header)

### 3. Transparency, Not Black Box
While beginners can use templates without understanding them, the code should be:
- Readable and well-commented
- Educational for those who want to learn
- Not overly abstracted

### 4. Short, Focused Checks
Instead of one massive template trying to do everything:
- Each component gets its own focused template
- Combining components = combining templates
- Easy to verify each part works independently

## Code Style Guidelines

### Comments
```cpp
// Good: Explains WHY
// Wait 2 seconds because DHT11 needs recovery time between reads
delay(2000);

// Bad: Explains WHAT (obvious from code)
// Wait 2000 milliseconds
delay(2000);
```

### Variable Names
```cpp
// Good: Self-explanatory
int temperaturePin = 2;
float currentHumidity = readHumidity();

// Bad: Cryptic
int tp = 2;
float h = rH();
```

### Structure
```cpp
// Good: Clear sections
// === SETUP ===
void setup() {
  // Initialize serial
  Serial.begin(9600);

  // Initialize sensor
  dht.begin();
}

// Bad: No structure
void setup() {
  Serial.begin(9600);
  dht.begin();
}
```

## Difficulty Levels

Each component is tagged with a difficulty level:

| Level | Description | User Expectation |
|-------|-------------|------------------|
| **beginner** | Just plug and play | Change 1-2 values, works immediately |
| **intermediate** | Some customization needed | May need to understand basic concepts |
| **advanced** | Requires understanding | User should read and understand the code |

## The "Contract" Metaphor

Think of each component template as a contract:

**You (the user) agree to:**
- Connect the component correctly (WIRING)
- Provide required inputs (INPUTS)
- Configure parameters as needed (PARAMETERS)

**The template agrees to:**
- Provide reliable outputs (OUTPUTS)
- Handle edge cases gracefully
- Fail clearly with helpful error messages

## Future Vision: Autoblocks

Eventually, these templates could be visualized as blocks:

```
┌─────────────────────┐      ┌─────────────────────┐
│   DHT11 Sensor      │      │    LCD Display      │
│                     │      │                     │
│ [Pin: 2]            │      │ [I2C: 0x27]         │
│                     │      │                     │
│ ──► temperature ────┼──────┼──► line1            │
│ ──► humidity    ────┼──────┼──► line2            │
│ ──► isValid         │      │                     │
└─────────────────────┘      └─────────────────────┘
```

The structured `component.json` files enable this kind of visual representation.
