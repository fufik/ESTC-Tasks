#include "main.h"

#define SWITCH_DELAY 8000000
#define DASH	     5000000
#define DOT	     2500000
int main(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable peripheral clock for LEDs port */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  uint16_t Pin_set = GPIO_Pin_9 | GPIO_Pin_10;
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
    int i;

    /* Switch the LED on */
    //dot
    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    /* Switch the LED off */
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    
    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);

    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);



    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DASH; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    
    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DASH; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);

    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DASH; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);



    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    
    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);

    GPIO_ResetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < DOT; i++);


    /* Switch the LED off */
    GPIO_SetBits(GPIOA, Pin_set);
    for (i = 0; i < SWITCH_DELAY; i++);
  }
}
