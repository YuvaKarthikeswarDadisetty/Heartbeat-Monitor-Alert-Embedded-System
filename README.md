# ❤️ Heartbeat Monitor with Alert System

An Embedded Systems-based heartbeat monitoring prototype that calculates and displays BPM states and generates threshold-based alerts using Arduino UNO, an I2C LCD, LEDs and a buzzer.

> ⚠️ **Educational Disclaimer:** This project is an educational embedded-systems prototype. It is **not a medical diagnostic device**. Hobby-grade sensors can produce approximate readings and must not be used for medical decisions. The thresholds used in this project are demonstration values only.

---

## 📌 Project Overview

The project demonstrates an embedded monitoring pipeline:

```text
Pulse Sensor / Simulated Heartbeat
            ↓
       Microcontroller
            ↓
     Beat / BPM Processing
            ↓
      Threshold Logic
            ↓
     ┌──────┼──────┐
    LOW   NORMAL  HIGH
     ↓      ↓      ↓
   RED    GREEN   RED
    +       │      +
 BUZZER     │    BUZZER
            ↓
        LCD Display
```

The physical design is hardware-ready for an Arduino UNO with an analog pulse sensor. Because physical hardware was not available during development, the complete control, display and alert workflow was validated using Wokwi.

---

## ✅ Implementation Status

### Virtual Simulation — Completed

The system was implemented and validated in Wokwi.

Validated scenarios:

- 40 BPM → LOW
- 75 BPM → NORMAL
- 120 BPM → HIGH
- LCD status output
- Green LED normal indication
- Red LED alert indication
- Buzzer alert logic
- Serial Monitor output

### Physical Hardware — Future Extension

The circuit and firmware are designed for Arduino UNO hardware with an analog pulse sensor.

Physical hardware validation was **not performed** because the required hardware was not available during development.

The project therefore makes no claim of physical sensor validation.

---

## 🔬 Wokwi Simulation

Validated Wokwi project:

https://wokwi.com/projects/472602638056250369

The simulation uses controlled synthetic heartbeat events. This validates the BPM/threshold/alert subsystem but does not reproduce every electrical characteristic of a physical pulse sensor.

See `simulation/README.md`.

---

## ✨ Features

- Arduino UNO embedded firmware
- Pulse-sensor-ready architecture
- BPM calculation concept
- Threshold-based classification
- LOW / NORMAL / HIGH states
- 16×2 I2C LCD
- Green LED normal indication
- Red LED alert indication
- Buzzer alert
- Serial Monitor debugging
- Wokwi simulation
- Reproducible `diagram.json`
- Test report
- Validation matrix
- GitHub proof-of-work documentation

---

## 🛠️ Hardware Design

### Recommended physical components

- Arduino UNO
- Analog Pulse Sensor
- 16×2 I2C LCD
- Green LED
- Red LED
- 220Ω resistors
- Buzzer
- Breadboard
- Jumper wires

### Pin mapping

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

---

## 🧠 Embedded Concepts

- Microcontroller programming
- GPIO
- ADC
- Sensor interfacing
- Sampling
- Peak-detection fundamentals
- Beat interval timing
- BPM calculation
- Moving-average smoothing
- Threshold comparison
- I2C communication
- LCD interfacing
- Serial communication
- Alert generation
- Virtual embedded simulation

---

## 📐 BPM Calculation

The basic educational calculation is:

```text
BPM = 60000 / beat interval in milliseconds
```

Examples:

```text
1000 ms → 60 BPM
750 ms  → 80 BPM
600 ms  → 100 BPM
```

A physical implementation should use a validated sensor signal and appropriate filtering/peak detection. The Wokwi simulation uses synthetic heartbeat timing.

---

## 🚦 Demonstration Alert Logic

| BPM | Status | Green LED | Red LED | Buzzer |
|---:|---|---|---|---|
| < 50 | LOW | OFF | ON | ON |
| 50–100 | NORMAL | ON | OFF | OFF |
| > 100 | HIGH | OFF | ON | ON |

These values are **software demonstration thresholds only** and are not clinical recommendations.

---

## 🧪 Validation Matrix

| Feature | Wokwi | Physical Hardware |
|---|---|---|
| Arduino firmware | ✅ Validated | ⏳ Future |
| I2C LCD | ✅ Validated | ⏳ Future |
| Green LED | ✅ Validated | ⏳ Future |
| Red LED | ✅ Validated | ⏳ Future |
| Buzzer | ✅ Validated | ⏳ Future |
| 75 BPM NORMAL | ✅ Validated | ⏳ Future |
| 40 BPM LOW | ✅ Validated | ⏳ Future |
| 120 BPM HIGH | ✅ Validated | ⏳ Future |
| Pulse sensor electrical behavior | Simulation not used | ⏳ Future |
| Real-world motion/noise behavior | ❌ Not validated | ⏳ Future |

---

## 📂 Project Structure

```text
Heartbeat-Monitor-Alert-Embedded-System/
│
├── src/
├── arduino_code/
├── simulation/
│   ├── HeartbeatMonitor_Wokwi.ino
│   ├── diagram.json
│   ├── libraries.txt
│   └── README.md
├── circuit_diagram/
├── data/
├── outputs/
├── screenshots/
├── reports/
├── docs/
├── README.md
├── PROJECT_NOTES.md
├── LICENSE
└── .gitignore
```

---

## ▶️ Wokwi Execution

1. Open the Wokwi project.
2. Use the Arduino UNO.
3. Use `simulation/HeartbeatMonitor_Wokwi.ino`.
4. Use `simulation/diagram.json`.
5. Use the `LiquidCrystal I2C` library.
6. Run at 115200 baud.
7. Test 75 BPM.
8. Test 40 BPM.
9. Test 120 BPM.
10. Capture screenshots.

---

## 🧪 Test Results

| Test ID | Scenario | Input | Expected | Result |
|---|---|---:|---|---|
| T01 | Normal | 75 BPM | NORMAL | ✅ PASS |
| T02 | Low alert | 40 BPM | LOW + alert | ✅ PASS |
| T03 | High alert | 120 BPM | HIGH + alert | ✅ PASS |
| T04 | LCD | All states | Correct display | ✅ PASS |
| T05 | Green LED | 75 BPM | ON | ✅ PASS |
| T06 | Red LED | 40/120 BPM | ON | ✅ PASS |
| T07 | Buzzer | 40/120 BPM | ON | ✅ PASS |
| T08 | Serial Monitor | All states | Correct logs | ✅ PASS |

All results above are **Wokwi simulation results**.

---

## 📸 Project Evidence

The repository includes:

- Wokwi NORMAL state
- Wokwi LOW alert state
- Wokwi HIGH alert state
- Source-code structure
- Circuit/wiring documentation
- Test report
- Validation matrix

See the `screenshots/` directory.

---

## ⚠️ Limitations

- Physical hardware was not available during development.
- The pulse waveform is not electrically simulated in the current Wokwi firmware.
- The simulation uses controlled synthetic BPM events.
- Real sensor noise has not been experimentally characterized.
- Motion artifacts have not been experimentally characterized.
- Thresholds are demonstration values only.
- No medical validation has been performed.
- The system is not intended for diagnosis or treatment.

---

## 🚀 Future Improvements

### Hardware Validation
- Arduino UNO + physical pulse sensor
- Sensor calibration
- Real-world noise testing

### Better Signal Processing
- Adaptive threshold
- Digital filtering
- Peak-to-peak validation
- Signal-quality detection
- Refractory period tuning

### Advanced Hardware
- ESP32
- MAX30102
- OLED display

### Connectivity
- Bluetooth
- Wi-Fi
- MQTT
- Cloud dashboard
- Mobile application

### Data
- CSV logging
- SD card
- Timestamped measurements
- Long-term trend visualization

---

## 🎓 Learning Outcomes

This project demonstrates:

- Embedded C / Arduino programming
- GPIO
- ADC concepts
- Sensor integration
- Timing with `millis()`
- BPM calculation
- I2C communication
- LCD interfacing
- Threshold logic
- LED/buzzer control
- Serial debugging
- Wokwi simulation
- Testing
- Git/GitHub documentation

---

## 👨‍💻 Author

**Yuva Karthikeswar**

Embedded Systems | IoT | AI/ML | Electronics & Communication Engineering

---

## 📄 License

MIT License

---

## ⚠️ Medical Disclaimer

This project is strictly an educational embedded-systems prototype. It is not a medical device and must not be used for diagnosis, treatment, or medical decision-making.
