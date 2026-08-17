# Circuit Wiring

## Arduino UNO Pin Map

| Component | Pin | Arduino UNO |
|---|---|---|
| Pulse Sensor | VCC | 5V |
| Pulse Sensor | GND | GND |
| Pulse Sensor | Signal | A0 |
| I2C LCD | VCC | 5V |
| I2C LCD | GND | GND |
| I2C LCD | SDA | A4 |
| I2C LCD | SCL | A5 |
| Green LED | Anode via 220Ω | D7 |
| Green LED | Cathode | GND |
| Red LED | Anode via 220Ω | D8 |
| Red LED | Cathode | GND |
| Buzzer | + | D9 |
| Buzzer | - | GND |

## Wokwi Validation

The Wokwi simulation validates the LCD, LEDs, buzzer and firmware decision logic.

The pulse sensor itself is not electrically simulated in the current Wokwi firmware. Instead, the simulation generates controlled synthetic BPM events.

## Physical Hardware Status

The above pin mapping is the intended physical Arduino UNO implementation.

Physical hardware was not available during development, so these connections should be treated as the hardware-ready design, not as physically validated wiring.

## Safety / Engineering Notes

- Use a 220Ω resistor in series with each LED.
- Use a suitable transistor/driver stage for larger external buzzers or loads.
- Keep all grounds common.
- Confirm the LCD I2C address; the project uses `0x27`.
