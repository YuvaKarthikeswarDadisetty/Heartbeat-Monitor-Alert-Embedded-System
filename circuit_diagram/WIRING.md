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

## Notes

- Confirm LCD I2C address; common addresses are `0x27` and `0x3F`.
- Use a 220Ω resistor in series with each LED.
- For larger buzzers/loads, use a suitable transistor/driver stage rather than driving the load directly from a GPIO.
