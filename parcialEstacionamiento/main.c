#include <stdio.h>
#include <stdlib.h>
#include "egreso.h"
#define TAMPROPIETARIO 100
#define TAMAUTOMOVIL 20
#define TAMEGRESOS 100
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
int main()
{
    ePropietario listaPropietario[TAMPROPIETARIO];
    eAutomovil listadoAutomovil[TAMAUTOMOVIL];
    eEgreso listadoEgresos[TAMEGRESOS];
    menu(listaPropietario,listadoAutomovil,listadoEgresos, TAMPROPIETARIO, TAMAUTOMOVIL, TAMEGRESOS);
    return 0;
}
