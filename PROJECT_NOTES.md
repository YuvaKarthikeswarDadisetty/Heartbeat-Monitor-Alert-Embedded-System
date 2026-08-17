# Project Notes

## Recommended Path

Start with `arduino_code/HeartbeatMonitor.ino` because it is the easiest version to upload and debug.

After validating the hardware, use the modular files in `src/` as a portfolio-oriented refactoring example.

## Hardware vs Simulation

### Hardware
Uses a real analog Pulse Sensor connected to A0.

### Simulation
Uses synthetic heartbeat events so the alert and display subsystem can be demonstrated without a physical pulse sensor.

## Thresholds

LOW < 50 BPM
NORMAL 50–100 BPM
HIGH > 100 BPM

These values are only demonstration settings.

## Important

This repository intentionally does not claim medical accuracy or clinical use.
