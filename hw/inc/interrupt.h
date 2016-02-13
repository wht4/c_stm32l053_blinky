#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/******************************************************************************/
/** \file       interrupt.h
 *******************************************************************************
 *
 *  \brief      All application defined interrupt handlers
 *
 *  \author     wht4
 *
 ******************************************************************************/
/*
 *  function    SysTick_Handler
 *
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/****** Header-Files **********************************************************/

/****** Macros ****************************************************************/

/****** Data types ************************************************************/

/****** Function prototypes ****************************************************/
extern void
SysTick_Handler(void);

/****** Data ******************************************************************/

/****** Implementation ********************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* INTERRUPT_H_ */