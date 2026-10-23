# Blink LED

Blinks an LED on and off once per second. The "Hello World" of Arduino.

## Components
- Arduino Uno
- 1x LED (any color)
- 1x 220 Ω resistor
- Jumper Wires (Male to Male)

## Wiring

| Arduino | Connects to |
|---------|-------------|
| Pin 13 | 220 Ω resistor → LED long leg (anode, +) |
| GND | LED short leg (cathode, −) |

<img src = "https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/Basics/Blink%20LED/wiring.png" width = "400px">


## How It Works
- `pinMode(LED_PIN, OUTPUT)` in `setup()` tells the board that pin 13 sends current out rather than reading input.
- `digitalWrite(HIGH)` puts 5 V on the pin and the LED lights. `LOW` puts 0 V and it turns off.
- `delay(1000)` pauses the program for 1000 ms, so each state lasts one second.
- `loop()` repeats forever, which creates the blinking.

**Why the resistor?** An LED has almost no resistance of its own, so without one it draws too much current and burns out (along with possibly the pin). With a typical red LED (~2 V drop), 220 Ω gives about 14 mA: bright and safe.

## Demo
<img src = "https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/Basics/Blink%20LED/live.gif">
<b>Wokwi Link :</b> <a href = "https://wokwi.com/projects/478675309689802753">Blink LED</a>
