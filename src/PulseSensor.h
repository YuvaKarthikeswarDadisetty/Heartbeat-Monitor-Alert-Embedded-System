#pragma once
#include <Arduino.h>

class PulseSensor {
public:
  PulseSensor(int analogPin, int threshold, unsigned long minInterval);

  int readSignal();
  bool detectBeat(unsigned long now, unsigned long &intervalMs);

  void setThreshold(int value);
  int getThreshold() const;

private:
  int pin;
  int threshold;
  unsigned long minInterval;
  unsigned long lastBeat;
  bool aboveThreshold;
};
