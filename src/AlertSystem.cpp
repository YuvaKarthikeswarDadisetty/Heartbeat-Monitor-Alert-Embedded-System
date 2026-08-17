#include "AlertSystem.h"

AlertSystem::AlertSystem(int greenPinValue, int redPinValue, int buzzerPinValue,
                         int lowThresholdValue, int highThresholdValue)
  : greenPin(greenPinValue),
    redPin(redPinValue),
    buzzerPin(buzzerPinValue),
    lowThreshold(lowThresholdValue),
    highThreshold(highThresholdValue) {

  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
  noTone(buzzerPin);
}

AlertStatus AlertSystem::evaluate(float bpm) {
  if (bpm <= 0) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    noTone(buzzerPin);
    return STATUS_NO_SIGNAL;
  }

  if (bpm < lowThreshold) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
    tone(buzzerPin, 2000);
    return STATUS_LOW;
  }

  if (bpm <= highThreshold) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    noTone(buzzerPin);
    return STATUS_NORMAL;
  }

  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  tone(buzzerPin, 2000);
  return STATUS_HIGH;
}

const char* AlertSystem::statusText(AlertStatus status) const {
  switch (status) {
    case STATUS_LOW: return "LOW";
    case STATUS_NORMAL: return "NORMAL";
    case STATUS_HIGH: return "HIGH";
    default: return "NO SIGNAL";
  }
}
