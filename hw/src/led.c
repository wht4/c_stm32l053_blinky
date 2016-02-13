/******************************************************************************/
/** @file       led.c
 *******************************************************************************
 *
 *  @brief      Module for handling the attached user led
 *
 *  @author     wht4
 *
 *  @remark     Last modifications
 *                 \li V1.0, February 2016, wht4, initial release
 *
 ******************************************************************************/
/*
 *  functions  global:
 *              led_init
 *              led_green_toogle
 *  functions  local:
 *              .
 *
 ******************************************************************************/

/****** Header-Files **********************************************************/
#include "led.h"

/****** Macros ****************************************************************/

/****** Data types ************************************************************/
GPIO_TypeDef * tUserLedPort[LED_QUANTITY] = {
		GPIOB,
		GPIOA
};

uint32_t u32UserLedPin[LED_QUANTITY] = {
		4,
		5
};

/****** Function prototypes ****************************************************/

/****** Data ******************************************************************/

/****** Implementation ********************************************************/

/*******************************************************************************
 *  function :    led_init
 ******************************************************************************/
void
led_init(void) {

    /* Enable the peripheral clock of GPIOA and GPIOB */
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN;

	/* Select output mode (01) on GPIOA pin 5 */
	GPIOA->MODER = (GPIOA->MODER & ~(GPIO_MODER_MODE5)) | (GPIO_MODER_MODE5_0);

	/* Select output mode (01) on GPIOB pin 4 */
	GPIOB->MODER = (GPIOB->MODER & ~(GPIO_MODER_MODE4)) | (GPIO_MODER_MODE4_0);
}


/*******************************************************************************
 *  function :    led_toogle
 ******************************************************************************/
void
led_toogle(Led_t tLed) {

	if (tLed < LED_QUANTITY) {
		tUserLedPort[tLed]->ODR ^= (1 << u32UserLedPin[tLed]);
	}
}
