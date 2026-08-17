#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "PulseSensor.h"
#include "HeartbeatMonitor.h"
#include "AlertSystem.h"

// Modular hardware reference implementation.
// For the easiest first upload, use arduino_code/HeartbeatMonitor.ino.

const int PULSE_PIN = A0;
const int GREEN_LED_PIN = 7;
const int RED_LED_PIN = 8;
const int BUZZER_PIN = 9;

const int SIGNAL_THRESHOLD = 550;
const int LOW_BPM_THRESHOLD = 50;
const int HIGH_BPM_THRESHOLD = 100;

const unsigned long MIN_BEAT_INTERVAL = 300;
const unsigned long NO_BEAT_TIMEOUT = 3000;

LiquidCrystal_I2C lcd(0x27, 16, 2);

PulseSensor pulseSensor(PULSE_PIN, SIGNAL_THRESHOLD, MIN_BEAT_INTERVAL);
HeartbeatMonitor bpmMonitor(5);
AlertSystem alertSystem(
  GREEN_LED_PIN,
  RED_LED_PIN,
  BUZZER_PIN,
  LOW_BPM_THRESHOLD,
  HIGH_BPM_THRESHOLD
);

float currentBPM = 0.0;
unsigned long lastBeatTime = 0;
unsigned long lastDisplay = 0;

void updateLCD(float bpm, const char* status) {
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  if (bpm <= 0) {
    lcd.print("--");
  } else {
    lcd.print((int)bpm);
  }
  lcd.print("          ");

  lcd.setCursor(0, 1);
  lcd.print(status);
  lcd.print("            ");
}

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Heartbeat");
  lcd.setCursor(0, 1);
  lcd.print("Modular Ref.");
  delay(1500);
  lcd.clear();

  Serial.println("Heartbeat Monitor - Modular Reference");
}

void loop() {
  const unsigned long now = millis();
  unsigned long intervalMs = 0;

  if (pulseSensor.detectBeat(now, intervalMs)) {
    if (intervalMs >= MIN_BEAT_INTERVAL) {
      const float instantBPM = 60000.0 / intervalMs;

      if (instantBPM >= 30.0 && instantBPM <= 220.0) {
        bpmMonitor.addBPM(instantBPM);
        currentBPM = bpmMonitor.getAverageBPM();
        lastBeatTime = now;

        Serial.print("Beat | Interval: ");
        Serial.print(intervalMs);
        Serial.print(" ms | BPM: ");
        Serial.println(currentBPM);
      }
    } else if (lastBeatTime == 0) {
      lastBeatTime = now;
    }
  }

  if (lastBeatTime > 0 && now - lastBeatTime > NO_BEAT_TIMEOUT) {
    currentBPM = 0.0;
  }

  const AlertStatus status = alertSystem.evaluate(currentBPM);

  if (now - lastDisplay >= 250) {
    lastDisplay = now;

    updateLCD(currentBPM, alertSystem.statusText(status));

    Serial.print("Raw: ");
    Serial.print(pulseSensor.readSignal());
    Serial.print(" | BPM: ");
    Serial.print(currentBPM);
    Serial.print(" | Status: ");
    Serial.println(alertSystem.statusText(status));
  }

  delay(10);
}
