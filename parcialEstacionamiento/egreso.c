#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "egreso.h"

#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1

int menu(ePropietario listaPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[], int TAMPROPIETARIO, int TAMAUTOMOVIL, int TAMEGRESOS)
{
    int opcion;
    int respuesta='s';
    int indice;
    int flagPropietario=0;
    int flagAutomovil=0;
    int flagEgreso=0;
    inicializarPropietarios(listaPropietario,TAMPROPIETARIO);
    flagPropietario=inicializarHarcodeo(listaPropietario,TAMPROPIETARIO);
    inicializarEstadosAutomovil(listadoAutomovil,TAMAUTOMOVIL);
    flagAutomovil=cargarHarcodeAutomovil(listadoAutomovil,TAMAUTOMOVIL);
    inicializarEgresos(listadoEgresos,TAMEGRESOS);
    flagEgreso=egresosHarcode(listadoEgresos);
    do
    {
        printf("1- MENU PROPIETARIOS\n"
               "2- MENU AUTOMOVILES\n"
               "3- RECAUDACIONES\n"
               "4- DATOS FILTRADOS\n"
               "5- SALIR\n"
              );
        opcion=getInt("Eliga una opcion: \n",opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            system("cls");
            printf("1- ALTA PROPIETARIOS\n"
                   "2- MOSTRAR PROPIETARIOS\n"
                   "3- MODIFICAR PROPIETARIOS\n"
                   "4- BORRAR PROPIETARIO\n"
                   "5- ORDENAR PROPIETARIOS\n"
                   "6- SALIR DEL SUBMENU\n"
                  );
            opcion=getInt("Ingrese una opcion: \n",opcion);
            fflush(stdin);

            switch(opcion)
            {
            case 1:
                indice=buscarLibrePropietario(listaPropietario,TAMPROPIETARIO);
                flagPropietario=altaPropietario(listaPropietario,TAMPROPIETARIO,indice);
                break;

            case 2:
                mostrarTodosPropietarios(listaPropietario,TAMPROPIETARIO,flagPropietario);
                break;
            case 3:
                modificarPropietario(listaPropietario,TAMPROPIETARIO,flagPropietario);
                break;

            case 4:
                    flagEgreso=darDeBajaPropietario(listaPropietario,listadoAutomovil,listadoEgresos,TAMAUTOMOVIL,TAMPROPIETARIO,TAMEGRESOS,"Esta seguro que quiere dar de baja al propietario? (S/N) ",flagPropietario);
                break;
            case 5:
                ordenarPropietarios(listaPropietario,TAMPROPIETARIO);
                break;
            }
            break;

        case 2:
            system("cls");
            printf("1- ALTA AUTOMOVIL\n"
                   "2- MOSTRAR AUTOMOVIL\n"
                   "3- EGRESO AUTOMOVIL\n"
                   "4- SALIR\n"
                   );
            opcion=getInt("Eliga la opcion: \n", opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                indice=buscarLibreAutomovil(listaPropietario,TAMAUTOMOVIL);
                flagAutomovil=altaAutomovil(listadoAutomovil,listaPropietario,TAMAUTOMOVIL,TAMPROPIETARIO,indice,flagPropietario);
                break;
            case 2:
                mostrarListaAutomovil(listadoAutomovil,TAMAUTOMOVIL,flagAutomovil);
                break;
            case 3:
                flagEgreso=darDeBajaAutomovil(listadoAutomovil,listaPropietario,listadoEgresos,TAMAUTOMOVIL,TAMPROPIETARIO,"Estas seguro que queres realizar el egreso de este automovil? (S/N) ",TAMEGRESOS,flagAutomovil);
                break;
            case 4:
                break;
            }
            break;

        case 3:

            break;

        case 4:

            break;

            system("pause");
            system("cls");
        }
    }
    while(respuesta=='s');
}

void inicializarEgresos(eEgreso listadoEgreso[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        listadoEgreso[i].estado=0;
    }
}
int egresosHarcode(eEgreso listadoEgreso[])
{
    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};
    int idPropietario[]={1,4,3,2,1,2,2,4,3,1};
    int i;
    for(i=0;i<10;i++)
    {
        listadoEgreso[i].marca=marca[i];
        listadoEgreso[i].recaudacion=importe[i];
        listadoEgreso[i].estado=1;
    }
    return 1;
}

int idEgresoAutoIncremental(eEgreso listadoEgresos[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoEgresos[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}

int buscarLibreEgresos(eEgreso listadoEgresos[],int tamanio)
{
    int indice;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoEgresos[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarRecaudaciones(eEgreso listadoEgresos[],int tamanio,int flag)
{
    if(flag==1)
    {
        float egresos=0;
        int i;
        for(i=0; i<tamanio; i++)
        {
            if(listadoEgresos[i].estado==1)
            {
                egresos+=listadoEgresos[i].recaudacion;
            }
        }
        printf("La recaudacion total del estacionamiento es de: $%.2f",egresos);
    }
    else
    {
        printf("\nNo es posible mostrar recaudaciones porque no se realizo ningun egreso");
    }

}
void mostrarRecaudacionesPorMarca(eEgreso listadoEgresos[],int tamanio,int flag)
{
    if(flag==1)
    {
        float alpha=0;
        float ferrari=0;
        float audi=0;
        float otro=0;
        int i;
        for(i=0; i<tamanio; i++)
        {
            if(listadoEgresos[i].estado==1)
            {
                if(listadoEgresos[i].marca==1)
                {
                    alpha+=listadoEgresos[i].recaudacion;
                }
                else if(listadoEgresos[i].marca==2)
                {
                    ferrari+=listadoEgresos[i].recaudacion;
                }
                else if(listadoEgresos[i].marca==3)
                {
                    audi+=listadoEgresos[i].recaudacion;
                }
                else
                {
                    otro+=listadoEgresos[i].recaudacion;
                }

            }
        }
        printf("\nRecaudacion de los coches pertenecientes a la marca Alfa Romeo: $%.2f",alpha);
        printf("\nRecaudacion de los coches pertenecientes a la marca Ferrari: $%.2f",ferrari);
        printf("\nRecaudacion de los coches pertenecientes a la marca Audi: $%.2f",audi);
        printf("\nRecaudacion de los coches pertenecientes a otras marcas: $%.2f",otro);
    }
    else
    {
        printf("\nNo es posible mostrar recaudaciones porque no se realizo ningun egreso");
    }

}
int darDeBajaPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int tamanioPropietario,int tamanioEgreso,char mensaje[],int flag)
{
    if(flag==1)
    {
        int Id;
        int indice;
        int retorno;
        fflush(stdin);
        mostrarTodosPropietarios(listadoPropietario,tamanioPropietario,flag);
        Id=getInt("\nIngresa el Id a dar de baja ",Id);
        indice=buscarPorIdPropietario(listadoPropietario,tamanioPropietario,Id);
        retorno=borrarEntidadPropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,indice,tamanioEgreso,mensaje);
        return retorno;
    }
    else
    {
        printf("\nNo es posible dar de baja propietarios porque no hay ninguno ingresado");
    }

}
int borrarEntidadPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,char mensaje[])
{
    int contadorEncontrados=0;
    int valor=0;
    int contadorEgresados=0;
    char pregunta;
    int valorTotal=0;
    int retorno=0;
    int i;
    int horas;
    if(indice!=-1)
    {
        for(i=0; i<tamanioAutomovil; i++)
            if(listadoPropietario[indice].idPropietario==listadoAutomovil[i].idPropietario&&listadoAutomovil[i].estado==1)
            {
                contadorEncontrados=contadorEncontrados+1;
                valor=tasarCochePropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,indice,tamanioEgreso);
                valorTotal=valorTotal+valor;
            }
    }
    printf("\nDebe abonar $%d correspondientes a los %d coches que tiene estacionados",valorTotal,contadorEncontrados);
    pregunta=deseaContinuar("\nDesea dar de baja al propietario? (S/N)");
    if(pregunta=='s')
    {
        listadoPropietario[indice].estado=2;
        printf("\nPropietario dado de baja");
        for(i=0; i<tamanioAutomovil; i++)
        {
            if(listadoPropietario[indice].idPropietario==listadoAutomovil[i].idPropietario&&listadoAutomovil[i].estado==1)
            {
                egresarCochePropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,i,tamanioEgreso,valor,horas);
            }
        }
    }
    else
    {
        printf("\nPropietario no borrado\n");
    }
}

int tasarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso)
{
    int horas;
    int valor;
    horas=devolverHorasEstadia();
    valor=tasarEstadia(listadoAutomovil[indice].marca,horas);
    return valor;
}

void egresarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,int valor,int horas)
{
    int indiceEgreso;
    listadoAutomovil[indice].estado=0;
    indiceEgreso=buscarLibreEgresos(listadoEgresos,tamanioEgreso);
    listadoEgresos[indiceEgreso].estado=1;
    listadoEgresos[indiceEgreso].idEgreso=idEgresoAutoIncremental(listadoEgresos,tamanioEgreso);
    listadoEgresos[indiceEgreso].idIngreso=listadoAutomovil[indice].idIngreso;
    listadoEgresos[indiceEgreso].marca=listadoAutomovil[indice].marca;
    listadoEgresos[indiceEgreso].recaudacion=valor;
    listadoEgresos[indiceEgreso].horas=horas;
}

int tasarEstadia(int marca,int horas)
{
    int valorTotal;
    if(marca==1)
    {
        valorTotal=horas*150;
    }
    else if(marca==2)
    {
        valorTotal=horas*175;
    }
    else if(marca==3)
    {
        valorTotal=horas*200;
    }
    else
    {
        valorTotal=horas*250;
    }
    return valorTotal;
}
int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
int darDeBajaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int tamanio,int tamanioPropietario,char mensaje[],int tamanioEgreso,int flag)
{
    if(flag==1)
    {
        int Id=0;
        int indice;
        int indicePropietario;
        int retorno;
        fflush(stdin);
        mostrarListaAutomovil(listadoAutomovil,tamanio,flag);
        Id=getInt("\nIngresa el Id de ingreso a dar de baja ",Id);
        indice=buscarPorIdAutomovil(listadoAutomovil,tamanio,Id);
        indicePropietario=buscarPorIdPropietarioAutomovil(listadoAutomovil,listadoPropietario,indice,tamanioPropietario);
        retorno=borrarEntidadAutomovil(listadoAutomovil,listadoPropietario,listadoEgresos,indice,indicePropietario,mensaje,tamanioEgreso);
        return retorno;
    }
    else
    {
        printf("\nPara dar de baja un automovil debe haber alguno ingresado\n");
    }

}

int borrarEntidadAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int indice,int indicePropietario,char mensaje[],int tamanioEgreso)
{
    char pregunta;
    int horas;
    int valor;
    int indiceEgreso;
    if(indice!=-1)
    {
        horas=devolverHorasEstadia();
        valor=tasarEstadia(listadoAutomovil[indice].marca,horas);
        cambiarMarcas(listadoAutomovil,listadoAutomovil[indice].marca,listadoAutomovil[indice].nombreMarca);
        printf("\nNombre del propietario: %s\nPatente del Auto: %s\nMarca del auto: %s\nHoras de estadia: %d\nValor de la estadia: $%d\n",listadoPropietario[indicePropietario].nombre,listadoAutomovil[indice].patente,listadoAutomovil[indice].nombreMarca,horas,valor);
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            listadoAutomovil[indice].estado=0;
            indiceEgreso=buscarLibreEgresos(listadoEgresos,tamanioEgreso);
            listadoEgresos[indiceEgreso].estado=1;
            listadoEgresos[indiceEgreso].idEgreso=idEgresoAutoIncremental(listadoEgresos,tamanioEgreso);
            listadoEgresos[indiceEgreso].idIngreso=listadoAutomovil[indice].idIngreso;
            listadoEgresos[indiceEgreso].marca=listadoAutomovil[indice].marca;
            listadoEgresos[indiceEgreso].recaudacion=valor;
            listadoEgresos[indiceEgreso].horas=horas;
            return 1;
        }
        return 0;
    }
    else
    {
        printf("\nId no encontrado");
    }
}
