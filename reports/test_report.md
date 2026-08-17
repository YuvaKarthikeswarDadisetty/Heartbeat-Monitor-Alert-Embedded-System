# Test Report — Wokwi Validation

## Scope

This report documents the tests actually executed in Wokwi.

Physical hardware testing was not performed.

## Test Matrix

| ID | Condition | Input | Expected Result | Status |
|---|---|---:|---|---|
| T01 | Normal | 75 BPM | NORMAL, green LED, buzzer OFF | PASS |
| T02 | Low alert | 40 BPM | LOW, red LED, buzzer ON | PASS |
| T03 | High alert | 120 BPM | HIGH, red LED, buzzer ON | PASS |
| T04 | LCD | 75 BPM | `BPM: 75 / NORMAL` | PASS |
| T05 | LCD | 40 BPM | `BPM: 40 / LOW` | PASS |
| T06 | LCD | 120 BPM | `BPM: 120 / HIGH` | PASS |
| T07 | Serial | 75 BPM | `STATUS: NORMAL` | PASS |
| T08 | Serial | 40 BPM | `STATUS: LOW` | PASS |
| T09 | Serial | 120 BPM | `STATUS: HIGH` | PASS |

## Evidence

Screenshots are stored in:

```text
screenshots/
```

## Interpretation

The tests demonstrate that the firmware correctly handles controlled BPM states and drives the corresponding display and alert outputs in the Wokwi environment.

## Not Covered

- Real pulse sensor waveform validation
- Sensor placement effects
- Motion artifacts
- Physical electrical noise
- Physical Arduino hardware behavior
- Clinical accuracy

## Disclaimer

The test thresholds are demonstration values and are not medical guidance.
