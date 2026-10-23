# Traffic Lights

Cycles red, yellow and green LEDs on a timer, like a real traffic signal.

## Components
- Arduino Uno
- 1x Red LED
- 1x Yellow LED
- 1x Green LED
- 3x 220 Ω resistors
- Breadboard
- Jumper Wires (Male to Male)

## Wiring

| Arduino | Connects to |
|---------|-------------|
| Pin 8 | 220 Ω resistor → Red LED long leg (anode, +) |
| Pin 9 | 220 Ω resistor → Yellow LED long leg (anode, +) |
| Pin 10 | 220 Ω resistor → Green LED long leg (anode, +) |
| GND | All three LED short legs (cathode, −) |

<img src="https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/01-Basics/Traffic%20Lights/wiring.png" width="400px">

Connect the three short legs to the same GND rail on the breadboard, then run one wire from that rail to the Arduino's GND.

## How It Works
- Each LED gets its own output pin, set up in `setup()` with `pinMode(..., OUTPUT)`.
- `loop()` runs the sequence in order: green for 3.5 s, yellow for 2 s, red for 3.5 s, then repeats.
- The timings are named constants (`GREEN_TIME`, `YELLOW_TIME`, `RED_TIME`), so you can change them in one place.
- `setLights(red, yellow, green)` sets all three pins at once. This guarantees only one light is on at a time and keeps `loop()` easy to read.

**Why one resistor per LED?** Each LED needs its own resistor to limit its own current. Sharing one resistor makes the brightness change depending on how many LEDs are on.

## Demo
<img src="https://github.com/SaminJawad/Robotics-Arduino-Series/blob/main/01-Basics/Traffic%20Lights/live.gif" width="400px">

**Wokwi Link:** <a href="https://wokwi.com/projects/478675309689802753">Traffic Light</a>
