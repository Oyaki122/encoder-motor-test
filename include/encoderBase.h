#pragma once

#include <mbed.h>

#include "HAL.h"

class EncoderBase {
 public:
  EncoderBase(uint16_t _resolution);
  virtual ~EncoderBase();

  void start();
  void reset();
  void stop();

  void update();
  float getSumangle();  // degree
  float getRPS();       // rotation/sec
  int64_t getRawSumPulse();

 protected:
  Timer timer;
  uint64_t timerResult = 0;  // us
  int resolution;
  int64_t sumPulse = 0;
  int64_t prevSumPulse = 0;

  // HALのタイマー関係関数を登録する仮想関数
  virtual void TimInit() = 0;  //タイマー初期化、エンコーダ読み取り開始
  virtual int16_t getTimCount() = 0;  //タイマーカウント値取得
  virtual void resetTimCount() = 0;   //タイマーリセット
  virtual void TimDeinit() = 0;       //タイマー、エンコーダー終了
};