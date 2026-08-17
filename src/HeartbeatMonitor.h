#pragma once
#include <Arduino.h>

class HeartbeatMonitor {
public:
  HeartbeatMonitor(int samples = 5);
  void addBPM(float bpm);
  float getAverageBPM() const;
  void reset();

private:
  float* history;
  int capacity;
  int index;
  int count;
};
