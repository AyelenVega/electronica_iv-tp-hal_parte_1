#include <stm32f1xx.h>
#include "hal.h"

/* Aquí tu implementación de controlador para puerto GPIO */

static void habilitaRelojPuertoC(void)
{
    RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPCEN;
}

typedef struct pin{
    GPIO_TypeDef*puerto;
    int pin;
    void (*habilitaReloj)(void);
}pin;

