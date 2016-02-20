/******************************************************************************/
/** @file       systick.c
 *******************************************************************************
 *
 *  @brief      General systick module for stm32l0
 *              <p>
 *              Allows to generate delays in busy loop
 *
 *  @author     wht4
 *
 *  @remark     Last modifications
 *                 \li V1.0, February 2016, wht4, initial release
 *
 ******************************************************************************/
/*
 *  functions  global:
 *              systick_init
 *              systick_delayMs
 *              systick_irq
 *  functions  local:
 *              .
 *
 ******************************************************************************/

/****** Header-Files **********************************************************/
#include "stm32l0xx.h"
#include "systick.h"

/****** Macros ****************************************************************/

/****** Data types ************************************************************/

/****** Fuction prototypes ****************************************************/

/****** Data ******************************************************************/
static volatile uint32_t u32Tick = 0;

/****** Implementation ********************************************************/


/*******************************************************************************
 *  function :    systick_init
 ******************************************************************************/
void
systick_init(uint32_t u32Ticks) {

    SysTick_Config(u32Ticks);
}


/*******************************************************************************
 *  function :    systick_delayMs
 ******************************************************************************/
void
systick_delayMs(uint32_t u32DelayMs) {

    uint32_t u32StartTick = u32Tick;
    while((u32DelayMs + u32StartTick) > u32Tick) {
        // TODO Go to sleep mode within busy loop
    }
}


/*******************************************************************************
 *  function :    systick_irq
 ******************************************************************************/
void
systick_irq(void) {

    u32Tick++;
}

