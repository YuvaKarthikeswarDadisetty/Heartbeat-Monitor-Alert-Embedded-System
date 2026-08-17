# System Architecture

## Conceptual Physical Architecture

```text
Analog Pulse Sensor
        |
        v
Arduino ADC / Sampling
        |
        v
Beat Detection
        |
        v
Beat Interval
        |
        v
BPM Calculation
        |
        v
Moving Average
        |
        v
Threshold Comparison
        |
   +----+-----+
   |    |     |
  LOW NORMAL HIGH
   |    |     |
 Red  Green  Red
 +Buz   |    +Buz
   \    |    /
       LCD
```

## Current Wokwi Architecture

```text
Synthetic BPM Event
        |
        v
Arduino UNO
        |
        v
BPM State
        |
   +----+-----+
   |    |     |
 LOW NORMAL HIGH
   |    |     |
 Red  Green  Red
 +Buz   |    +Buz
   \    |    /
       LCD
        |
    Serial Monitor
```

## Engineering Boundary

The physical architecture is pulse-sensor-ready.

The Wokwi implementation intentionally uses synthetic BPM events to validate the downstream processing and alert subsystem because a physical pulse sensor was not available.
