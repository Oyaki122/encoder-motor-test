#include "encoder1.h"

void Encoder1::TimInit() {
  MX_TIM1_Init();
  HAL_TIM_Encoder_MspInit(&htim1);
  HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
}

int16_t Encoder1::getTimCount() { return (int16_t)TIM1->CNT; }
void Encoder1::resetTimCount() { TIM1->CNT = 0; }

void Encoder1::TimDeinit() { HAL_TIM_Encoder_DeInit(&htim1); }