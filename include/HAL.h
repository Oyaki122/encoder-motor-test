#include <mbed.h>

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void MX_TIM1_Init(void);
void MX_TIM3_Init(void);
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef* htim_encoder);