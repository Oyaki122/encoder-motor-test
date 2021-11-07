#pragma once

#include <mbed.h>

#include "HAL.h"
#include "encoderBase.h"

class Encoder1 : public EncoderBase {
 public:
  Encoder1(uint16_t resolution) : EncoderBase(resolution) {}
  ~Encoder1() {}

 protected:
  void TimInit() override;
  int16_t getTimCount() override;
  void resetTimCount() override;
  void TimDeinit() override;
};