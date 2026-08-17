#include "HeartbeatMonitor.h"

HeartbeatMonitor::HeartbeatMonitor(int samples)
  : capacity(samples), index(0), count(0) {
  history = new float[capacity];
  reset();
}

void HeartbeatMonitor::addBPM(float bpm) {
  history[index] = bpm;
  index = (index + 1) % capacity;

  if (count < capacity) {
    count++;
  }
}

float HeartbeatMonitor::getAverageBPM() const {
  if (count == 0) return 0;

  float sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += history[i];
  }
  return sum / count;
}

void HeartbeatMonitor::reset() {
  index = 0;
  count = 0;
  for (int i = 0; i < capacity; ++i) {
    history[i] = 0;
  }
}
