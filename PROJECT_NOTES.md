# Project Notes

## Final Implementation Position

This repository should be presented as:

**A Wokwi-validated Embedded Systems prototype with a hardware-ready Arduino UNO design.**

Do not claim physical hardware testing.

## What Was Actually Validated

The Wokwi implementation validated:

- Arduino UNO firmware execution
- LCD display
- Normal state at 75 BPM
- Low alert at 40 BPM
- High alert at 120 BPM
- Green LED logic
- Red LED logic
- Buzzer logic
- Serial Monitor output

## What Was Not Validated

- Physical pulse sensor electrical behavior
- Real-world motion artifacts
- Physical sensor calibration
- Physical hardware wiring
- Clinical accuracy

## Interview Positioning

A good explanation is:

"I developed the Arduino-based embedded architecture and validated the complete BPM display and alert workflow using Wokwi because physical hardware was not available. I tested controlled 40, 75 and 120 BPM scenarios and documented the physical Arduino pin mapping as the next hardware-validation step."

## Reproducibility

The `simulation/` directory contains:

- `HeartbeatMonitor_Wokwi.ino`
- `diagram.json`
- `libraries.txt`
- `README.md`

This allows another developer to reproduce the simulation rather than relying only on screenshots.

## Source Code Paths

- `arduino_code/HeartbeatMonitor.ino` is the easiest standalone hardware firmware.
- `simulation/HeartbeatMonitor_Wokwi.ino` is the validated synthetic-BPM simulation firmware.
- `src/` contains a complete modular hardware reference implementation for portfolio study/refactoring.
