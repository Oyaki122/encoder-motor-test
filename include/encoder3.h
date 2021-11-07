#pragma once

#include <mbed.h>

#include "HAL.h"
#include "encoderBase.h"

class Encoder3 : public EncoderBase {
 public:
  Encoder3(uint16_t resolution) : EncoderBase(resolution) {}
  ~Encoder3() {}

 protected:
  void TimInit() override;
  int16_t getTimCount() override;
  void resetTimCount() override;
  void TimDeinit() override;
};