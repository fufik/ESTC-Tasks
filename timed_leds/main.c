#include "main.h"

#define SWITCH_DELAY 1000000
#define PERIOD	     1000
#define PRESCALER    42000
int main(void)
{
  TIM_TimeBaseInitTypeDef tim_struct;
  GPIO_InitTypeDef GPIO_InitStructure;
  /* Enable peripheral clock for LEDs port */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  /* Enable peripheral clock for timer port */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
  tim_struct.TIM_Period = PERIOD - 1;
  tim_struct.TIM_Prescaler = PRESCALER - 1;
  tim_struct.TIM_ClockDivision = 0;
  tim_struct.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &tim_struct);
  TIM_Cmd(TIM2, ENABLE);

  uint16_t Pin_set = GPIO_Pin_8|GPIO_Pin_9;
  /*Init LEDs on obves*/
  GPIO_InitStructure.GPIO_Pin   = Pin_set;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


  /* Turn all the leds off */
  GPIO_SetBits(GPIOA, Pin_set);

  while (1)
  {
    /* Switch the LED on */
     if (TIM_GetCounter(TIM2) == 0)
	GPIO_ResetBits(GPIOA, Pin_set);
    
     if (TIM_GetCounter(TIM2) == 300)
	GPIO_SetBits(GPIOA, Pin_set);
	
     Pin_set = GPIO_Pin_9|GPIO_Pin_10;
     if (TIM_GetCounter(TIM2) == 350)
	GPIO_ResetBits(GPIOA, Pin_set);
    
     if (TIM_GetCounter(TIM2) == 650)
	GPIO_SetBits(GPIOA, Pin_set);
	
     Pin_set = GPIO_Pin_10|GPIO_Pin_8;

     if (TIM_GetCounter(TIM2) == 700)
	GPIO_ResetBits(GPIOA, Pin_set);
    
     if (TIM_GetCounter(TIM2) == 1000)
	GPIO_SetBits(GPIOA, Pin_set);
	
     Pin_set = GPIO_Pin_8|GPIO_Pin_9;

  }
}
