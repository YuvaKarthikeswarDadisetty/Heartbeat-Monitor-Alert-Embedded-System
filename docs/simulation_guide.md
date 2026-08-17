# Wokwi Simulation Guide

1. Create an Arduino UNO project in Wokwi.
2. Add a 16x2 I2C LCD, green LED, red LED and buzzer.
3. Wire LCD SDA to A4 and SCL to A5.
4. Wire green LED to D7 through 220Ω.
5. Wire red LED to D8 through 220Ω.
6. Wire buzzer to D9 and GND.
7. Use `simulation/HeartbeatMonitor_Wokwi.ino`.
8. Set `targetBPM = 75.0` for NORMAL.
9. Set `targetBPM = 40.0` for LOW.
10. Set `targetBPM = 120.0` for HIGH.
11. Run the simulation.
12. Open Serial Monitor at 115200 baud.
13. Capture screenshots for the GitHub `screenshots/` folder.

The simulation generates synthetic heartbeat events in firmware because the physical pulse sensor is not required for demonstrating the BPM/alert subsystem.
