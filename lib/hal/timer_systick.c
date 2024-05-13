#include <stm32f1xx.h>
#include "hal.h"


// Función para inicializar el temporizador SysTick
void HAL_SysTick_Init(uint32_t ticks) {
    // Configurar el temporizador SysTick para que genere una interrupción cada 'ticks' milisegundos
    SysTick->LOAD = (ticks * (SystemCoreClock / 1000)) - 1; // Configurar el valor de recarga del contador
    SysTick->VAL = 0; // Reiniciar el contador
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; // Habilitar el temporizador
}

// Función de interrupción del temporizador SysTick
void SysTick_Handler(void) {
    // Implementa aquí la lógica de la interrupción del temporizador SysTick
    // Por ejemplo, cambiar el estado del LED, etc.
}


