# Button Toggle LED

Press a push button once to turn an LED on, press it again to turn it off.

## Components
- Arduino Uno
- 1x LED (any color)
- 1x 220 Ω resistor
- 1x Push button
- Jumper Wires (Male to Male)

## Wiring

| Arduino | Connects to |
|---------|-------------|
| Pin 2 | Push button, one leg |
| GND | Push button, opposite leg |
| Pin 8 | 220 Ω resistor → LED long leg (anode, +) |
| GND | LED short leg (cathode, −) |

<img src = "https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/01-Basics/Button%20Toggle%20LED/wiring.png" width = "400px">

## How It Works
- `INPUT_PULLUP` turns on the Arduino's built-in resistor which holds pin 2 at HIGH. Pressing the button connects the pin to GND, so it reads LOW. No external resistor is needed.
- The sketch compares the current button state with the previous one. The LED toggles only on the HIGH → LOW change, so holding the button down doesn't flicker it.
- `ledState = !ledState` flips the stored state and `digitalWrite` applies it to the LED.
- `delay(50)` ignores contact bounce, the rapid false presses a mechanical button produces for a few milliseconds.

**Why store `ledState`?** The LED must remember its state after you release the button. Without the variable, the LED would only be on while the button is held.

## Demo
<img src = "https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/01-Basics/Button%20Toggle%20LED/live.gif" width = "400px">
<b>Wokwi Link :</b> <a href = "https://wokwi.com/projects/478773356496494593">Button Toggle LED</a>
