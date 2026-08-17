#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// HEARTBEAT MONITOR WITH ALERT SYSTEM
// Educational Embedded Systems Prototype
// NOT a medical diagnostic device.

// ---------------- Pins ----------------
const int PULSE_PIN = A0;
const int GREEN_LED_PIN = 7;
const int RED_LED_PIN = 8;
const int BUZZER_PIN = 9;

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- Thresholds ----------------
// Educational demonstration values only.
const int LOW_BPM_THRESHOLD = 50;
const int HIGH_BPM_THRESHOLD = 100;

// ---------------- Detection ----------------
int signalThreshold = 550;
const unsigned long MIN_BEAT_INTERVAL = 300;
const unsigned long NO_BEAT_TIMEOUT = 3000;

// ---------------- Smoothing ----------------
const int BPM_SAMPLES = 5;
float bpmHistory[BPM_SAMPLES];
int bpmIndex = 0;
int bpmCount = 0;

bool pulseDetected = false;
unsigned long lastBeatTime = 0;
float currentBPM = 0.0;

void setup() {
  Serial.begin(115200);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Heartbeat");
  lcd.setCursor(0, 1);
  lcd.print("Monitor");
  delay(2000);
  lcd.clear();

  Serial.println("================================");
  Serial.println(" HEARTBEAT MONITOR");
  Serial.println(" Educational Prototype");
  Serial.println("================================");
}

void loop() {
  int signal = analogRead(PULSE_PIN);
  unsigned long now = millis();

  detectHeartbeat(signal, now);

  if (lastBeatTime > 0 && now - lastBeatTime > NO_BEAT_TIMEOUT) {
    currentBPM = 0;
    updateOutputs(0);
  } else {
    updateOutputs(currentBPM);
  }

  printSerialData(signal);
  delay(10);
}

void detectHeartbeat(int signal, unsigned long now) {
  if (signal > signalThreshold && !pulseDetected) {
    pulseDetected = true;

    if (lastBeatTime > 0) {
      unsigned long interval = now - lastBeatTime;

      if (interval >= MIN_BEAT_INTERVAL) {
        float instantBPM = 60000.0 / interval;

        if (instantBPM >= 30 && instantBPM <= 220) {
          addBPMValue(instantBPM);
          currentBPM = calculateAverageBPM();

          Serial.print("Beat detected | Interval: ");
          Serial.print(interval);
          Serial.print(" ms | Instant BPM: ");
          Serial.print(instantBPM);
          Serial.print(" | Average BPM: ");
          Serial.println(currentBPM);
        }
      }
    }

    lastBeatTime = now;
  }

  if (signal < signalThreshold) {
    pulseDetected = false;
  }
}

void addBPMValue(float bpm) {
  bpmHistory[bpmIndex] = bpm;
  bpmIndex = (bpmIndex + 1) % BPM_SAMPLES;

  if (bpmCount < BPM_SAMPLES) {
    bpmCount++;
  }
}

float calculateAverageBPM() {
  if (bpmCount == 0) return 0;

  float sum = 0;
  for (int i = 0; i < bpmCount; i++) {
    sum += bpmHistory[i];
  }
  return sum / bpmCount;
}

void updateOutputs(float bpm) {
  if (bpm <= 0) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    updateLCD(0, "NO SIGNAL");
    return;
  }

  if (bpm < LOW_BPM_THRESHOLD) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    updateLCD(bpm, "LOW");
  } else if (bpm <= HIGH_BPM_THRESHOLD) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    updateLCD(bpm, "NORMAL");
  } else {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    updateLCD(bpm, "HIGH");
  }
}

void updateLCD(float bpm, const char* status) {
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  if (bpm <= 0) lcd.print("--");
  else lcd.print((int)bpm);
  lcd.print("          ");

  lcd.setCursor(0, 1);
  lcd.print(status);
  lcd.print("            ");
}

void printSerialData(int signal) {
  static unsigned long lastPrint = 0;

  if (millis() - lastPrint >= 500) {
    lastPrint = millis();

    Serial.print("Raw Signal: ");
    Serial.print(signal);
    Serial.print(" | BPM: ");
    Serial.print(currentBPM);
    Serial.print(" | Status: ");

    if (currentBPM <= 0) Serial.println("NO SIGNAL");
    else if (currentBPM < LOW_BPM_THRESHOLD) Serial.println("LOW");
    else if (currentBPM <= HIGH_BPM_THRESHOLD) Serial.println("NORMAL");
    else Serial.println("HIGH");
  }
}
