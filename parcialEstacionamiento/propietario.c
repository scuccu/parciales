#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "propietario.h"
#define VACIO 0
#define OCUPADO 1
#define ELIMINADO -1
float getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char mensaje[],int A)
{

    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    A=validarStringEntero(auxstring);
    return A;
}



int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;
    }

}

void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {
        if (!getStringNumerosFlotantes(requestMessage, auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxFloat = atof(auxStr);
        if(auxFloat < lowLimit || auxFloat > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxFloat;
    }
}

char validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    while(validar==0)
    {
        printf("\nLa palabra ingresada no es valida. Ingresela nuevamente ");
        gets(datoAValidar);
        fflush(stdin);
        validar=strlen(datoAValidar);
    }
    int i;
    for(i=0; i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}
char validarStringCaracter(char datoAValidar)
{
    if(isalpha(datoAValidar)==0||datoAValidar==' ')
    {
        do
        {
            printf("\nIngresa un caracter valido ");
            scanf("%c",&datoAValidar);
            fflush(stdin);
        }
        while(isalpha(datoAValidar)==0||datoAValidar==' ');
    }
    return datoAValidar;
}

float validarStringFloat(char datoAValidar[])
{
    float numero;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0; i<validar;)
    {
        if(isdigit(datoAValidar[i])==0)
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0);
        }
        else
        {
            i=i+1;
        }
    }
    numero=atof(datoAValidar);
    return numero;
}
int validarStringEntero(char datoAValidar[])
{
    int A;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ');
        }
        else
        {
            i=i+1;
        }
    }
    A=atoi(datoAValidar);
    return A;
}
void validarTarjetaDeCredito(char tarjeta[])
{
    int largo;
    largo=strlen(tarjeta);
    int i;
    for(i=0; i<7; i++)
    {
        while(largo!=7)
        {
            getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
            largo=strlen(tarjeta);
        }
        if(i<3)
        {
            if(tarjeta[i]<'0'||tarjeta[i]>'9'||tarjeta[i]==' '||tarjeta[i]=='\0')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
        else if(i==3)
        {
            if(tarjeta[3]!='-')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
        else if(i>3)
        {
            if(tarjeta[i]<'0'||tarjeta[i]>'9'||tarjeta[i]==' '||tarjeta[i]=='\0')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
    }
}


void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0; i<largo; i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}
char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
}
char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
       // seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}

void inicializarPropietarios(ePropietario lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        lista[i].estado=0;
    }
}

int inicializarHarcodeo(ePropietario lista[], int len)
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int i;
    for(i=0; i<4; i++)
    {
        strcpy(lista[i].nombre,nombre[i]);
        lista[i].idPropietario=id[i];
        strcpy(lista[i].tarjeta,tarjeta[i]);
        strcpy(lista[i].direccion,direccion[i]);
        lista[i].estado=1;
    }
    return 1;
}

int idAutoIncremental(ePropietario lista[], int len)
{
    int contador=0;
    int i;
    for(i=0; i<len; i++)
    {
        if(lista[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}

void mostrarUnPropietario(ePropietario lista[], int i)
{
    printf("%d --- %s --- %s --- %s\n\n",lista[i].idPropietario,lista[i].nombre, lista[i].direccion,lista[i].tarjeta);
}

void mostrarTodosPropietarios(ePropietario lista[], int len, int flag)
{
    if(flag==1)
    {
        printf("Id\tNombre\t\t\tDireccion\tTarjeta de credito\n");
        int i;

        for(i=0; i<len; i++)
        {
            if(lista[i].estado==1)
            {
                printf("%d\t%s\t\t\t%s\t\t%s\n",lista[i].idPropietario,lista[i].nombre,lista[i].direccion,lista[i].tarjeta);
            }
        }
    }
}

int buscarLibrePropietario(ePropietario lista[],int len)
{
    int indice;
    int i;
    for(i=0; i<len; i++)
    {
        if(lista[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int altaPropietario(ePropietario lista[], int len, int indice)
{
    if(indice!=1)
    {
        getString("Ingrese el nombre: \n",lista[indice].nombre);
        validarStringCadena(lista[indice].nombre);
        stringToUpper(lista[indice].nombre);
        lista[indice].idPropietario=idAutoIncremental(lista,len);
        getString("Ingrese su direccion: \n",lista[indice].direccion);
        stringToUpper(lista[indice].direccion);
        getString("Ingrese su tarjeta de credito(Debe seguir el formato 123-456 incluyendo el guion): \n",lista[indice].tarjeta);
        validarTarjetaDeCredito(lista[indice].tarjeta);
        //lista[indice].edad=getInt("Ingrese su edad: \n",lista[indice].edad);
        lista[indice].estado=1;
        return 1;
    }
    else
    {
        printf("No hay lugares libres \n");
    }
}
void modificarPropietario(ePropietario lista[],int len,int flag)
{
    if(flag==1)
    {
        fflush(stdin);
        int id;
        int indice;
        char caracter;
        char auxiliar[20];
        mostrarTodosPropietarios(lista,len,flag);
        id=getInt("Ingrese el id del usuario que quiere modificar: \n",id);
        indice=buscarPorIdPropietario(lista,len,id);
        modificarStringPropietario(lista,indice,auxiliar);
        caracter=deseaContinuar("desea continuar con la operacion? s/n\n");
        if(caracter=='s')
        {
            strcpy(lista[indice].tarjeta,auxiliar);
            printf("Tarjeta modificada\n");
        }
        else
        {
            printf("Modificacion no realizada\n");
        }
    }
    else
    {
        printf("No es posible moficicar los propietarios porque no hay ninguno ingresado \n");
    }
}
char modificarStringPropietario(ePropietario lista[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa la nueva tarjeta de credito (Debe seguir el formato 123-456 incluyendo guion): ",caracter);
        validarTarjetaDeCredito(caracter);
    }
    else
    {
        printf("\nId no encontrado");
    }
}
int buscarPorIdPropietario(ePropietario lista[],int len,int id)
{
    int indice;
    int i;
    for(i=0; i<len; i++)
    {
        if(lista[i].estado==1)
        {
            if(lista[i].idPropietario==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

void ordenarPropietarios(ePropietario lista[], int len)
{
    ePropietario auxiliar;
    int i;
    int j;
    int opcionOrden;
    system("cls");
    printf("Como desea ordenar los propietarios?\n");
    printf("1- ASCENDENTE\n"
           "2- DESCENDENTE\n"
           );
   opcionOrden=getInt("Eliga una opcion: \n",opcionOrden);
    fflush(stdin);

    switch(opcionOrden)
    {
    case 1:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }
        }
        mostrarTodosPropietarios(lista,len,1);
        break;

    case 2:
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {
                if(strcmp(lista[i].nombre,lista[j].nombre)<0)
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }
        }
        mostrarTodosPropietarios(lista,len,1);
        break;
    }

}


