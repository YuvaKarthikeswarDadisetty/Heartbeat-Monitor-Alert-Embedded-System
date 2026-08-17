# Interview Preparation

## 1. Explain your project.

This is an educational heartbeat monitoring prototype designed around an Arduino UNO, pulse-sensor-ready input, I2C LCD, LEDs and buzzer. I implemented the firmware and validated the downstream BPM display and threshold-alert workflow in Wokwi because physical hardware was not available. I tested controlled 75 BPM NORMAL, 40 BPM LOW and 120 BPM HIGH scenarios. The repository also contains the physical Arduino pin mapping and hardware-ready architecture for future deployment.

## 2. Did you test the project on real hardware?

No. Physical hardware was not available during development. I used Wokwi to validate the embedded firmware, LCD, LEDs, buzzer and threshold behavior. I documented physical hardware as the next validation stage rather than claiming tests I did not perform.

## 3. How is BPM calculated?

The educational formula is:

BPM = 60000 / beat interval in milliseconds.

## 4. Why use millis()?

It provides non-blocking timing for measuring intervals and scheduling periodic operations.

## 5. Why use an ADC in the physical design?

An analog pulse sensor would produce a voltage signal that the Arduino ADC converts into a digital value for firmware processing.

## 6. How would you prevent double counting?

A physical implementation should use a refractory/minimum beat interval, threshold hysteresis and appropriate filtering/peak validation.

## 7. Why average BPM readings?

A moving average reduces short-term fluctuations caused by sensor noise and measurement variation.

## 8. Why use I2C?

I2C allows the LCD to communicate using only SDA and SCL, reducing GPIO usage.

## 9. What happens at an alert threshold?

The firmware classifies the BPM as LOW, NORMAL or HIGH. LOW/HIGH states activate the red LED and buzzer; NORMAL activates the green LED and disables the buzzer.

## 10. What are the limitations?

The current validation is simulation-only. The synthetic BPM model does not validate physical sensor noise, motion artifacts or real-world signal quality. The thresholds are demonstration values and the prototype is not a medical device.
