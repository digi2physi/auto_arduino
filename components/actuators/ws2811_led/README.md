# WS2811 Addressable RGB LED (F5-C-WS2811)

Addressable RGB LED that can display any color. Multiple LEDs can be chained together and controlled individually.

## Quick Start

1. Wire the LED to your Arduino (see [Wiring](#wiring) below)
2. [Install library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/): Search "Adafruit NeoPixel" in Library Manager
3. Upload `template.ino`
4. Watch the LED cycle through colors

## Wiring

| LED Pin | Arduino |
|---------|---------|
| VCC (5V) | 5V |
| GND | GND |
| DIN (Data In) | D6 ([digital pin](https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/#digital-pins)) |

> **Tip:** Add a 300-500Ω resistor between Arduino pin and LED data line for protection.

> **Multiple LEDs?** Connect DOUT of first LED to DIN of next. For many LEDs (10+), use an external 5V power supply.

## Configuration

```cpp
#define LED_PIN 6      // Change to your data pin
#define NUM_LEDS 1     // Change to number of LEDs in chain
#define BRIGHTNESS 50  // 0-255 (start low!)
```

## Helper Functions

```cpp
setAllColor(r, g, b);              // Set all LEDs to same color
setLedColor(index, r, g, b);       // Set specific LED (0-indexed)
setBrightness(level);              // Set brightness (0-255)
allOff();                          // Turn all LEDs off
rainbowCycle(wait);                // Rainbow animation
blinkColor(r, g, b, times, delay); // Blink effect
fadeColor(r, g, b, steps, delay);  // Fade in/out effect
```

## Example Usage

```cpp
// Set to red
setAllColor(255, 0, 0);

// Set to custom color (orange)
setAllColor(255, 165, 0);

// Set specific LED in chain
setLedColor(0, 0, 255, 0);  // First LED green
setLedColor(1, 0, 0, 255);  // Second LED blue

// Blink red 3 times
blinkColor(255, 0, 0, 3, 200);

// Rainbow effect
rainbowCycle(10);
```

## Common Colors

| Color | R | G | B |
|-------|---|---|---|
| Red | 255 | 0 | 0 |
| Green | 0 | 255 | 0 |
| Blue | 0 | 0 | 255 |
| White | 255 | 255 | 255 |
| Yellow | 255 | 255 | 0 |
| Cyan | 0 | 255 | 255 |
| Magenta | 255 | 0 | 255 |
| Orange | 255 | 165 | 0 |
| Purple | 128 | 0 | 128 |
| Off | 0 | 0 | 0 |

## Serial Output

```
[LED] Red
[LED] Green
[LED] Blue
[LED] White
[LED] Off
```

## Troubleshooting

- **LED not lighting**: Check data pin connection and direction (DIN vs DOUT)
- **Wrong colors**: Try changing `NEO_GRB` to `NEO_RGB` in code
- **Flickering**: Add capacitor (100-1000µF) across power lines
- **First LED works, others don't**: Check connections between LEDs

## Learn More

- [How addressable LEDs work](https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels)
- [NeoPixel best practices](https://learn.adafruit.com/adafruit-neopixel-uberguide/best-practices)
- [RGB color picker](https://www.w3schools.com/colors/colors_picker.asp)
- [WS2811 vs WS2812 explained](https://www.seeedstudio.com/blog/2019/02/14/ws2812b-vs-ws2811-addressable-rgb-led-strips-how-are-they-different/)
