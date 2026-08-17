#pragma once
#include <Arduino.h>

enum AlertStatus {
  STATUS_NO_SIGNAL,
  STATUS_LOW,
  STATUS_NORMAL,
  STATUS_HIGH
};

class AlertSystem {
public:
  AlertSystem(int greenPin, int redPin, int buzzerPin,
              int lowThreshold, int highThreshold);
  AlertStatus evaluate(float bpm);
  const char* statusText(AlertStatus status) const;

private:
  int greenPin;
  int redPin;
  int buzzerPin;
  int lowThreshold;
  int highThreshold;
};
