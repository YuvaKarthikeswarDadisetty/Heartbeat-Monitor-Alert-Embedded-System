#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// WOKWI SIMULATION VERSION
// Synthetic heartbeat events are generated in firmware.
// Educational demonstration only.

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int GREEN_LED_PIN = 7;
const int RED_LED_PIN = 8;
const int BUZZER_PIN = 9;

const int LOW_BPM_THRESHOLD = 50;
const int HIGH_BPM_THRESHOLD = 100;

// Change this value to test LOW, NORMAL and HIGH.
// 40 -> LOW, 75 -> NORMAL, 120 -> HIGH.
float targetBPM = 75.0;

unsigned long beatInterval;
unsigned long lastBeat = 0;
float currentBPM = 0;

void setup() {
  Serial.begin(115200);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Heartbeat Sim");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(1500);

  beatInterval = 60000.0 / targetBPM;
  lastBeat = millis();
  lcd.clear();
}

void loop() {
  unsigned long now = millis();

  if (now - lastBeat >= beatInterval) {
    lastBeat = now;
    currentBPM = targetBPM;

    Serial.print("Simulated Beat | BPM: ");
    Serial.println(currentBPM);

    updateStatus();
  }

  static unsigned long lastDisplay = 0;
  if (now - lastDisplay >= 500) {
    lastDisplay = now;
    updateDisplay();
  }
}

void updateStatus() {
  if (currentBPM < LOW_BPM_THRESHOLD) {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    Serial.println("STATUS: LOW");
  } else if (currentBPM <= HIGH_BPM_THRESHOLD) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    digitalWrite(RED_LED_PIN, LOW);
    noTone(BUZZER_PIN);
    Serial.println("STATUS: NORMAL");
  } else {
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    Serial.println("STATUS: HIGH");
  }
}

void updateDisplay() {
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  lcd.print((int)currentBPM);
  lcd.print("          ");

  lcd.setCursor(0, 1);

  if (currentBPM < LOW_BPM_THRESHOLD) {
    lcd.print("LOW           ");
  } else if (currentBPM <= HIGH_BPM_THRESHOLD) {
    lcd.print("NORMAL        ");
  } else {
    lcd.print("HIGH          ");
  }
}
