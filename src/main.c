#include "debug.h"

int main(void) {
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(GPIOA, &GPIO_InitStructure);

  Delay_Init();
  Delay_Ms(1000);
  Delay_Ms(1000);
#if (SDI_PRINT == SDI_PR_OPEN)
  SDI_Printf_Enable();
#else
  USART_Printf_Init(115200);
#endif
  printf("SystemClk:%d\r\n", SystemCoreClock);
  printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID());


  while (1) {
    Delay_Ms(1000);
    GPIOA->OUTDR ^= GPIO_Pin_1;
  }
}
