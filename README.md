# ❤️ Heartbeat Monitor with Alert System

An Embedded Systems-based heartbeat monitoring prototype that measures or simulates heartbeat signals, calculates approximate Beats Per Minute (BPM), displays the result on an LCD, and generates threshold-based alerts using LEDs and a buzzer.

> ⚠️ **Educational Disclaimer:** This project is an educational embedded-systems prototype. It is **not a medical diagnostic device**. Hobby-grade sensors can produce approximate readings and the output must not be used for medical decisions. The thresholds in this project are demonstration settings only.

## Project Overview

The system demonstrates:

Pulse Sensor → Analog Signal → Arduino → Beat Detection → BPM Calculation → Threshold Comparison → LCD → LED/Buzzer

## Industry Relevance

The concepts demonstrated are relevant to wearable fitness devices, smart watches, sports monitoring, rehabilitation prototypes, remote monitoring prototypes and other sensor-based embedded systems.

## Features

- Analog pulse sensor interfacing
- ADC-based signal acquisition
- Heartbeat peak detection
- BPM calculation
- Moving-average smoothing
- Configurable demonstration thresholds
- 16×2 I2C LCD
- Green/red LED indicators
- Buzzer alert
- Serial Monitor debugging
- Wokwi simulation
- Test cases and documentation
- GitHub proof-of-work plan

## Recommended Hardware

- Arduino UNO
- Pulse Sensor
- 16×2 I2C LCD
- Green LED
- Red LED
- 220Ω resistors
- Buzzer
- Breadboard
- Jumper wires
- USB cable

## Software

- Arduino IDE
- Embedded C / Arduino C++
- Wokwi
- Git
- GitHub

## BPM Calculation

`BPM = 60000 / beat interval in milliseconds`

Examples:

- 1000 ms → 60 BPM
- 750 ms → 80 BPM
- 600 ms → 100 BPM

Several readings are averaged to improve display stability.

## Demonstration Alert Logic

| BPM | Status | Green | Red | Buzzer |
|---:|---|---|---|---|
| < 50 | LOW | OFF | ON | ON |
| 50–100 | NORMAL | ON | OFF | OFF |
| > 100 | HIGH | OFF | ON | ON |

These are educational demonstration thresholds and are not clinical recommendations.

## Circuit Connections

| Component | Arduino UNO |
|---|---|
| Pulse Sensor VCC | 5V |
| Pulse Sensor GND | GND |
| Pulse Sensor Signal | A0 |
| LCD VCC | 5V |
| LCD GND | GND |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Green LED | D7 through 220Ω |
| Red LED | D8 through 220Ω |
| Buzzer + | D9 |
| Buzzer - | GND |

See `circuit_diagram/WIRING.md`.

## Folder Structure

```text
Heartbeat-Monitor-Alert-Embedded-System/
├── src/
├── arduino_code/
├── simulation/
├── circuit_diagram/
├── data/
├── outputs/
├── screenshots/
├── reports/
├── docs/
├── README.md
└── .gitignore
```

## Hardware Setup

1. Install Arduino IDE.
2. Select Arduino UNO.
3. Install `LiquidCrystal_I2C`.
4. Connect the hardware according to the wiring guide.
5. Open `arduino_code/HeartbeatMonitor.ino`.
6. Upload the firmware.
7. Open Serial Monitor at 115200 baud.
8. Observe the LCD and alert outputs.
9. Calibrate `signalThreshold` for the actual sensor.

## Virtual Simulation

Use Wokwi with `simulation/HeartbeatMonitor_Wokwi.ino`.

Change:

```cpp
float targetBPM = 75.0;
```

Use:

- `40.0` → LOW
- `75.0` → NORMAL
- `120.0` → HIGH

The simulation uses synthetic heartbeat events to demonstrate the BPM and alert subsystem without physical hardware.

See `docs/simulation_guide.md`.

## Testing

See `reports/test_report.md`.

Key tests:

- Startup
- No pulse
- Normal BPM
- Low BPM
- High BPM
- Closely spaced peaks
- LCD output
- LED status
- Buzzer status
- Serial output

## Limitations

- Hobby-grade sensors may be noisy.
- Motion can introduce false peaks.
- Sensor placement affects results.
- Peak detection is intentionally simple.
- Thresholds are not clinical guidance.
- The prototype has no medical validation.
- Wokwi uses a synthetic heartbeat model.

## Future Improvements

- ESP32
- MAX30102
- OLED
- Bluetooth
- Wi-Fi
- MQTT
- Cloud dashboard
- Data logging
- SD card
- Mobile application
- Improved digital filtering
- Adaptive peak detection
- Signal-quality estimation

## Learning Outcomes

This project demonstrates:

- Embedded C / Arduino programming
- ADC
- GPIO
- Sensor interfacing
- Signal processing fundamentals
- Peak detection
- Timing with `millis()`
- BPM calculation
- I2C
- LCD interfacing
- Alert logic
- Serial debugging
- Virtual simulation
- Git/GitHub workflow
- Embedded testing

## Author

**Yuva Karthikeswar Dadisetty**

Embedded Systems | IoT | AI/ML | Electronics & Communication Engineering

## License

This project is provided for educational and portfolio purposes.

## Medical Disclaimer

This project is not a medical device and must not be used for diagnosis, treatment, or medical decision-making.
