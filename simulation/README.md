# Wokwi Simulation

This folder contains the reproducible virtual implementation of the Heartbeat Monitor with Alert System.

## Files

- `HeartbeatMonitor_Wokwi.ino` — simulation firmware
- `diagram.json` — Wokwi circuit definition
- `libraries.txt` — required Arduino library

## Wokwi Project

The validated Wokwi project used during development:

https://wokwi.com/projects/472602638056250369

## What is simulated?

The simulation generates controlled synthetic heartbeat events in firmware. It does not claim to reproduce the electrical waveform of a physical pulse sensor.

The purpose is to validate:

- Arduino firmware execution
- I2C LCD interfacing
- BPM state display
- threshold classification
- green LED normal indication
- red LED alert indication
- buzzer alert logic
- Serial Monitor output

## Test configurations

Edit this line in `HeartbeatMonitor_Wokwi.ino`:

```cpp
float targetBPM = 75.0;
```

Use these values:

| targetBPM | Expected status |
|---:|---|
| 40.0 | LOW |
| 75.0 | NORMAL |
| 120.0 | HIGH |

## Reproduce the simulation

1. Open Wokwi.
2. Create an Arduino UNO project.
3. Replace `sketch.ino` with `HeartbeatMonitor_Wokwi.ino`.
4. Replace the Wokwi diagram with `diagram.json`.
5. Add/use the `LiquidCrystal I2C` library listed in `libraries.txt`.
6. Start the simulation.
7. Open Serial Monitor at 115200 baud.
8. Test 75 BPM, 40 BPM and 120 BPM.
9. Capture the results in the `screenshots/` folder.

## Important validation note

The project was fully validated in Wokwi. Physical Arduino hardware was not available during development, so physical sensor validation is documented as a future extension.
