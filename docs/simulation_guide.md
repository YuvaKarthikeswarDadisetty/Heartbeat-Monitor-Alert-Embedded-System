# Wokwi Simulation Guide

## Purpose

This simulation validates the embedded firmware's display and alert subsystem without physical hardware.

## Files

```text
simulation/
├── HeartbeatMonitor_Wokwi.ino
├── diagram.json
├── libraries.txt
└── README.md
```

## Test 1 — NORMAL

Set:

```cpp
float targetBPM = 75.0;
```

Expected:

```text
BPM: 75
NORMAL
```

Green LED ON, red LED OFF, buzzer OFF.

## Test 2 — LOW

Set:

```cpp
float targetBPM = 40.0;
```

Expected:

```text
BPM: 40
LOW
```

Red LED ON and buzzer ON.

## Test 3 — HIGH

Set:

```cpp
float targetBPM = 120.0;
```

Expected:

```text
BPM: 120
HIGH
```

Red LED ON and buzzer ON.

## Important

The simulation uses synthetic heartbeat timing. It should not be described as a physical pulse-sensor electrical simulation.
