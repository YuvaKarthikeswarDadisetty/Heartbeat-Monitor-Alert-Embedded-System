# Interview Preparation

## 1. Explain your project.

This is an educational heartbeat monitoring prototype using Arduino UNO, a pulse sensor, I2C LCD, LEDs and buzzer. The controller samples the pulse signal, detects valid beats, measures the interval between beats, calculates approximate BPM, averages recent values, and compares BPM against configurable demonstration thresholds. The result is shown on the LCD and alerts are generated using LEDs and a buzzer.

## 2. How is BPM calculated?

BPM = 60000 / beat interval in milliseconds.

## 3. Why use millis()?

It provides non-blocking timing for beat intervals and other periodic operations.

## 4. Why use an ADC?

The analog sensor signal must be converted into digital values for firmware processing.

## 5. How do you prevent double counting?

A minimum accepted beat interval rejects peaks that occur too close together.

## 6. Why average readings?

A moving average reduces short-term variation in calculated BPM.

## 7. Why use I2C?

I2C reduces the number of microcontroller pins needed for the LCD.

## 8. What happens at an alert threshold?

The red LED and buzzer are activated and the LCD displays LOW or HIGH.

## 9. What are the limitations?

Noise, motion artifacts, sensor placement, simplified peak detection and lack of clinical validation.

## 10. Is this a medical device?

No. It is an educational embedded-systems prototype and must not be used for medical decisions.
