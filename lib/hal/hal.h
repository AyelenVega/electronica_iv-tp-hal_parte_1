#ifndef HAL_H
#define HAL_H

#include <stdbool.h>
#include <stdint.h>

typedef enum HPin{
    Pin_LED,
    Pin_NUM_HANDLES
}HPin;

/* Aquí tus prototipos de funciones */

void Pin_ponModoSalida(HPin pin);

void Pin_ponEstadoBajo(HPin pin);

void Pin_ponEstadoAlto(HPin pin);

bool Pin_consultaEstado(HPin pin);

void Pin_invierteEstado(HPin pin);

void Systick_inicializa(void);

uint32_t Systick_obtMilisegundos(void);

void Systick_esperaMilisegundos(uint32_t tiempo);

void SysTick_Handler(void);



#endif