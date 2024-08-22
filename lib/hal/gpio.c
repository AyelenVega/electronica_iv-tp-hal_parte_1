#include <stm32f1xx.h>
#include "hal.h"

/* Aquí tu implementación de controlador para puerto GPIO */


static void habilitaRelojPuertoC(void)
{

    RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_IOPCEN;
}

typedef struct Pin{
    GPIO_TypeDef*puerto;
    int pin;
    void (*habilitaReloj)(void);
}Pin;

static const Pin descriptores[Pin_NUM_HANDLES]={
    [Pin_LED] = {.puerto=GPIOC,.pin=13,.habilitaReloj=habilitaRelojPuertoC}
};

void Pin_ponModoSalida (HPin pin)
{
    if (pin>=Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin;

    desc-> habilitaReloj();
    
    const int offset = ((desc->pin % 8) * 4);
    const uint32_t mascaraReset = 0xF    << offset;
    const uint32_t mascaraSet   = 0b0010 << offset;

    if (desc->pin < 8){
        desc->puerto->CRL = (desc->puerto->CRL & ~mascaraReset) | mascaraSet;
    }else{
        desc->puerto->CRH = (desc->puerto->CRH & ~mascaraReset) | mascaraSet;
    }

};

void Pin_ponEstadoBajo (HPin pin)
{
    if (pin>=Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin;
    desc -> puerto -> BSRR = 1 << desc -> pin;
};

void Pin_ponEstadoAlto (HPin pin)
{
    if (pin>=Pin_NUM_HANDLES) return;
    const Pin *desc = descriptores + pin;
    desc -> puerto -> BRR = 1 << desc -> pin;
};

bool Pin_consultaEstado(HPin pin) 
{
    if (pin >= Pin_NUM_HANDLES) return false;
    const Pin *desc = descriptores + pin; 
    return desc->puerto->ODR & (1 << desc->pin);
}

void Pin_invierteEstado(HPin pin)
{
    if (Pin_consultaEstado(pin)){
        Pin_ponEstadoAlto(pin);
    }else{
        Pin_ponEstadoBajo(pin);
    }
}