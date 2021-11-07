#include "encoderBase.h"

EncoderBase::EncoderBase(uint16_t _resolution) : resolution(_resolution) {}
EncoderBase::~EncoderBase() { stop(); }

void EncoderBase::start() {
  TimInit();
  timer.start();
  resetTimCount();
}

void EncoderBase::reset() {
  sumPulse = 0;
  prevSumPulse = 0;
  timerResult = 0;
  resetTimCount();
  timer.reset();
}

void EncoderBase::stop() {
  reset();
  timer.stop();
  TimDeinit();
}

void EncoderBase::update() {
  prevSumPulse = sumPulse;
  sumPulse += getTimCount();
  resetTimCount();
  timerResult = timer.read_high_resolution_us();
  timer.reset();
}

float EncoderBase::getSumangle() {
  return sumPulse * 360.0f / (resolution * 4);
}

float EncoderBase::getRPS() {
  return (sumPulse - prevSumPulse) / (resolution * 4 * timerResult * 1E-6);
}

int64_t EncoderBase::getRawSumPulse() { return sumPulse; }
