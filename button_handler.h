#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

#include "nrf.h"
#include "nrf_gpio.h"
//#include "nrf_drv_gpiote.h"
//#include <nrfx.h>

// TODO: move defines to common header file for project.

#define BUTTON 11 //P0.11 = button 1 on PCA10100

void button_handler_init(void);
void GPIOTE_IRQHandler(void);

#endif //BUTTON_HANDLER_H