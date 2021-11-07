#include "encoder3.h"

void Encoder3::TimInit() {
  MX_TIM3_Init();
  HAL_TIM_Encoder_MspInit(&htim3);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
}

int16_t Encoder3::getTimCount() { return (int16_t)TIM3->CNT; }
void Encoder3::resetTimCount() { TIM3->CNT = 0; }

void Encoder3::TimDeinit() { HAL_TIM_Encoder_DeInit(&htim3); }