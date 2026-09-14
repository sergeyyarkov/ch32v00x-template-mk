#include "../platform/ch32v00x/debug.h"
#include "ch32v00x_gpio.h"

int main(void) {
  SystemInit();

  GPIO_InitTypeDef GPIO_InitStructure = {0};

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOD, &GPIO_InitStructure);

  Delay_Init();

  while (1) {
    GPIO_ResetBits(GPIOD, GPIO_Pin_4);
    Delay_Ms(500);
    GPIO_SetBits(GPIOD, GPIO_Pin_4);
    Delay_Ms(500);
  }
}
