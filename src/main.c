#include "hal.h"

int main(void)
{
    Pin_ponModoSalida(Pin_LED);
    Pin_ponEstadoAlto(Pin_LED);
    Systick_inicializa();


    for(;;){
        Systick_esperaMilisegundos (500);
        Pin_invierteEstado(Pin_LED);
    }
    return 0;
}