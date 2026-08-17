#pragma once
#include <Arduino.h>

class PulseSensor {
public:
  PulseSensor(int analogPin, int threshold, unsigned long minInterval);
  int readSignal();
  bool detectBeat(unsigned long now);
  void setThreshold(int threshold);
  int getThreshold() const;

private:
  int pin;
  int threshold;
  unsigned long minInterval;
  unsigned long lastBeat;
  bool aboveThreshold;
};
