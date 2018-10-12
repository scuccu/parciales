#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "automovil.h"
#define ALPHA_ROMEO "ALFA ROMERO"
#define FERRARI "FERRARI"
#define AUDI "AUDI\t"
#define OTRO  "OTRO\t"


void inicializarEstadosAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        listadoAutomovil[i].estado=0;
    }
}
int idAutoIncrementalAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int contador=0;
    int i;
    for(i=0;i<tamanioAutomovil;i++)
    {
        if(listadoAutomovil[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}

int buscarLibreAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int indice;
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        if(listadoAutomovil[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarUnoAutomovil(eAutomovil listadoAutomovil[],int tamanio,int i)
{
    printf("%d\t\t%d\t\t  %s\t     %s\n",listadoAutomovil[i].idIngreso,listadoAutomovil[i].idPropietario,listadoAutomovil[i].patente,listadoAutomovil[i].nombreMarca);
}

void mostrarListaAutomovil(eAutomovil listadoAutomovil[],int tamanio,int flag)
{
    if(flag==1)
    {
        int i;
        printf("Id ingreso\tId propietario\tPatente\t\tMarca \n");
        for(i=0; i<tamanio; i++)
        {
            if(listadoAutomovil[i].estado==1)
            {
               cambiarMarcas(listadoAutomovil,listadoAutomovil[i].marca,listadoAutomovil[i].nombreMarca);
                printf("%d\t\t%d\t\t%s\t\t%s\n",listadoAutomovil[i].idIngreso,listadoAutomovil[i].idPropietario,listadoAutomovil[i].patente,listadoAutomovil[i].nombreMarca);
            }

        }
    }
    else
    {
        printf("\nPara mostrar los automoviles es necesario que haya ingresado alguno\n");
    }

}

int buscarPorIdAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        if(listadoAutomovil[i].estado==1)
        {
            if(listadoAutomovil[i].idIngreso==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

char stringMayusculas(char cadena[])
{
    int largo;
    largo=strlen(cadena);
    int i;
    for(i=0;i<largo;i++)
    {
        cadena[i]=toupper(cadena[i]);
    }
    return cadena;
}

char validarPatenteIngresada(char patente[])
{
    stringMayusculas(patente);
    int largo;
    largo=strlen(patente);
    int i;
    for(i=0; i<7; i++)
    {
        while(largo!=7)
        {
            getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
            largo=strlen(patente);
            stringMayusculas(patente);
        }
        if(i<3)
        {
            if(patente[i]<'A'||patente[i]>'Z'||patente[i]==' '||patente[i]=='\0'&&patente[i]<'a'&&patente[i]>'z')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
        else if(i==3)
        {
            if(patente[i]!='-')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
        else if(i>=4&&i<7)
        {
            if(patente[i]<'0'||patente[i]>'9')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
    }
    return patente;
}

int cargarHarcodeAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int i;
    for(i=0; i<10; i++)
    {
        strcpy(listadoAutomovil[i].patente,patente[i]);
        listadoAutomovil[i].idIngreso=id[i];
        listadoAutomovil[i].marca=marca[i];
        listadoAutomovil[i].idPropietario=propietario[i];
        listadoAutomovil[i].estado=1;
    }
    return 1;
}
char cambiarMarcas(eAutomovil listadoAutomovil[],int marca,char marcaString[])
{
    switch(marca)
    {
    case 1:
        strcpy(marcaString,ALPHA_ROMEO);
        break;
    case 2:
        strcpy(marcaString,FERRARI);
        break;
    case 3:
        strcpy(marcaString,AUDI);
        break;
    case 4:
       strcpy(marcaString,OTRO);
       break;
    }
    return marcaString;
}

int altaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int tamanioAutomovil,int tamanioPropietario,int indice,int flagPropietario)
{
    if(flagPropietario==1)
    {
        int ID;
        if(indice!=-1)
        {
            mostrarTodosPropietarios(listadoPropietario,tamanioPropietario,flagPropietario);
            listadoAutomovil[indice].idPropietario=getInt("\nIngresa el ID del propietario al que se le va a asignar el coche ",listadoAutomovil[indice].idPropietario);
            ID=buscarPorIdPropietario(listadoPropietario,tamanioPropietario,listadoAutomovil[indice].idPropietario);
            if(ID!=-1)
            {
                getString("Ingresa la patente de tu coche (ABC-123) ",listadoAutomovil[indice].patente);
                validarPatenteIngresada(listadoAutomovil[indice].patente);
                mostrarMarcasAutomovil(listadoAutomovil);
                listadoAutomovil[indice].marca=getInt("\nIngresa la marca de tu automovil ",listadoAutomovil[indice].marca);
                verificarMarca(listadoAutomovil[indice].marca);
                cambiarMarcas(listadoAutomovil,listadoAutomovil[indice].marca,listadoAutomovil[indice].nombreMarca);
                listadoAutomovil[indice].idIngreso=idAutoIncrementalAutomovil(listadoAutomovil,tamanioAutomovil);
                listadoAutomovil[indice].estado=1;
                return 1;
            }
            else
            {
                printf("\nID de propietario no encontrado");
            }

        }
        else
        {
            printf("\nNo hay lugares libres");
        }
    }
    else
    {
        printf("\nNo se puede dar de alta un automovil porque no hay ningun propietario ingresado\n");
    }
}

void mostrarMarcasAutomovil()
{
    printf("\n1- ALFA ROMEO");
    printf("\n2- FERRARI");
    printf("\n3- AUDI");
    printf("\n4- OTRO");
}


int verificarMarca(int marcaAVerificar)
{
    while(marcaAVerificar!=1&&marcaAVerificar!=2&&marcaAVerificar!=3&&marcaAVerificar!=4)
    {
        marcaAVerificar=getInt("Marca no existente. Ingrese una valida ",marcaAVerificar);
    }
    return marcaAVerificar;
}
int buscarPorIdPropietarioAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int indiceAutomovil,int tamanioPropietario)
{
    int indicePropietario;
    int i;
    for(i=0;i<tamanioPropietario;i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            if(listadoAutomovil[indiceAutomovil].idPropietario==listadoPropietario[i].idPropietario)
            {
                indicePropietario=i;
                break;
            }
        }
    }
    return indicePropietario;
}
