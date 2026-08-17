# System Architecture

```text
Pulse Sensor
     |
     v
Analog Signal / ADC
     |
     v
Heartbeat Detection
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
  +--+--------+
  |  |        |
 LOW NORMAL HIGH
  |    |       |
 Red Green    Red
 +Buzzer       +Buzzer
     |
     v
 LCD / Serial Monitor
```

## Layers

1. Sensing: pulse sensor and ADC.
2. Processing: peak detection, timing and BPM calculation.
3. Decision: threshold comparison.
4. Output: LCD, LEDs, buzzer and serial logging.
