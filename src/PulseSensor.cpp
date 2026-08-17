#include "PulseSensor.h"

PulseSensor::PulseSensor(int analogPin, int thresholdValue, unsigned long minIntervalValue)
  : pin(analogPin),
    threshold(thresholdValue),
    minInterval(minIntervalValue),
    lastBeat(0),
    aboveThreshold(false) {}

int PulseSensor::readSignal() {
  return analogRead(pin);
}

bool PulseSensor::detectBeat(unsigned long now, unsigned long &intervalMs) {
  const int signal = readSignal();
  intervalMs = 0;

  if (signal > threshold && !aboveThreshold) {
    aboveThreshold = true;

    if (lastBeat > 0) {
      intervalMs = now - lastBeat;
    }

    if (lastBeat == 0 || intervalMs >= minInterval) {
      lastBeat = now;
      return true;
    }
  }

  if (signal < threshold) {
    aboveThreshold = false;
  }

  return false;
}

void PulseSensor::setThreshold(int value) {
  threshold = value;
}

int PulseSensor::getThreshold() const {
  return threshold;
}
