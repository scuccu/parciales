#include "propietario.h"
typedef struct
{

    char patente[10];
    int marca;
    char nombreMarca[10];
    int idIngreso;
    int idPropietario;
    int estado;

}eAutomovil;

/** \brief Funcion que inicializa en 0 los estados de la estructura
 *
 * \param listado[] eAutomovil Estructura a la que le inicializa el estado en 0
 * \param tamanio int Tamaño de la Estructura
 * \return void
 *
 */
void inicializarEstadosAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil);
/** \brief Funcion que asigna automaticamente un Id a las nuevas altas
 *
 * \param listado[] eAutomovil Estructura a la que se le asigna el ID
 * \param tamanio int Tamaño de la estructura
 * \return int Retorna el siguiente ID
 *
 */
int idAutoIncrementalAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil);
/** \brief Funcion que busca un lugar libre en el estacionamiento
 *
 * \param listadoAutomovil[] eAutomovil Estructura en donde se buscara el lugar libre
 * \param tamanioAutomovil int Tamaño de la estructura donde se buscara el lugar libre
 * \return int Devuelve el indice del lugar libre o -1 si no hay lugar libre
 *
 */
int buscarLibreAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil);
/** \brief Funcion que muestra un elemento de la estructura automovil
 *
 * \param listadoAutomovil[] eAutomovil Estructura que se va a mostrar
 * \param tamanioAutomovil int Tamaño de la estructura
 * \param i int Posicion donde esta el elemento a mostrar
 * \return void
 *
 */
void mostrarUnoAutomovil(eAutomovil listadoAutomovil[],int tamanio,int i);
/** \brief Funcion que invoca a mostrarUno y muestra todos los elementos de la estructura Automovil
 *
 * \param listado[] eAutomovil Estructura que se va a listar
 * \param tamanio int Tamaño de la estructura
 * \param flag int Bandera que comprueba si previamente se ingreso algun automovil
 * \return void
 *
 */
void mostrarListaAutomovil(eAutomovil listadoAutomovil[],int tamanio,int flag);

/** \brief Funcion que toma un Id ingresado por el usuario y lo compara con todos los ID pertenecientes a la estructura
 *
 * \param listado[] eAutomovil Estructura con la que se comparara el ID ingresado
 * \param tamanio int Tamaño de la Estructura
 * \param id int Id que ingresa el usuario
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 *
 */
int buscarPorIdAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil,int id);
/** \brief Funcion que valida el formato de patente ingresado por el usuario
 *
 * \param patente[] char Patente ingresada a validar
 * \return char Retorna la patente validada
 *
 */
char validarPatenteIngresada(char patente[]);
/** \brief pone en mayuscular el string ingresado
 *
 * \param string ingresado
 * \return la cadena modificada
 *
 */

char stringMayusculas(char cadena[]);
/** \brief Funcion que precarga con datos la estructura
 *
 * \param listado[] eAutomovil Estructura a la que se va a cargar con datos
 * \param tamanio int Tamaño de la estructura que se va a cargar
 * \return int Retorna 1 si se cargaron los datos de manera efectiva
 *
 */
int cargarHarcodeAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil);
/** \brief Funcion que tomando la marca ingresada por el usuario (entero) la reemplaza por su nombre
 *
 * \param listadoAutomovil[] eAutomovil Estructura que almacena las marcas
 * \param marca int Marca a verificar
 * \param marcaString[] char Nombre de la marca que se va a guardar
 * \return char Retorna el nombre de la marca
 *
 */
char cambiarMarcas(eAutomovil listadoAutomovil[],int marca,char marcaString[]);

/** \brief Funcion que da de alta nuevos automoviles
 *
 * \param listadoAutomovil[] eAutomovil estructura donde se daran de alta los vehiculos
 * \param listadoPropietario[] ePropietario estructura que contiene los propietarios a los que se les asignara el vehiculo
 * \param tamanioAutomovil int Tamaño de la estructura Automovil
 * \param tamanioPropietario int Tamaño de la estructura propietario
 * \param indice int Indice en el que se dara de alta al vehiculo
 * \param flagPropietario int Bandera que indica si anteriormente se dio de alta algun propietario
 * \return int Retorna 1 si se dio de alta el automovil
 *
 */
int altaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int tamanioAutomovil,int tamanioPropietario,int indice,int flagPropietario);
/** \brief Funcion que lista las marcas de automoviles posibles
 *
 * \return void
 *
 */
void mostrarMarcasAutomovil();
/** \brief Funcion que valida si la marca ingresada por el usuario existe
 *
 * \param marcaAVerificar int Marca ingresada por el usuario
 * \return int Marca validada
 *
 */
int verificarMarca(int marcaAVerificar);
/** \brief Funcion que teniendo el Indice donde se guarda el automovil, busca si hay un propietario que sea dueño de ese coche
 *
 * \param listadoAutomovil[] eAutomovil Estructura que se va a usar para la busqueda del ID
 * \param listadoPropietario[] ePropietario Estructura que se va a recorrer para comparar los ID
 * \param indiceAutomovil int Indice en donde se guarda el automovil
 * \param tamanioPropietario int Tamaño de la estructura propietario
 * \return int Retorna el indice en donde esta el propietario o -1 si no encontro coincidencia entre el ID perteneciente a la estructura automovil y el ID perteneciente a la estructura Propietario
 *
 */
int buscarPorIdPropietarioAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int indiceAutomovil,int tamanioPropietario);
