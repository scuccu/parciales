typedef struct
{
    int idPropietario;
    char nombre[50];
    char direccion[50];
    char tarjeta[50];
    int estado;


}ePropietario;
/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
 float getFloat(char* mensaje);


int getInt(char mensaje[],int A);
////////FUNCIONES DE VALIDACION///////

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[]);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]);
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[]);
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void);
/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargará el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[]);
/**
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 *
 */

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int validarStringEntero(char datoAValidar[]);
char deseaContinuar(char mensaje[]);
char getChar(char mensaje[],char caracter);
////////FUNCIONES ABM////////



/** \brief Funcion que inicializa en 0 los estados de la estructura
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que le inicializa el estado en 0
 * \param tamanio int Tamaño de la estructura
 * \return void
 *
 */
void inicializarPropietarios(ePropietario listaPropietario[], int len);
/** \brief Funcion que inicializa en 0 los estados de la estructura
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que le inicializa el estado en 0
 * \param tamanio int Tamaño de la estructura
 * \return void
 *
 */
int inicializarHarcodeo(ePropietario listaPropietario[], int len);

/** \brief Funcion que asigna automaticamente un Id a las nuevas altas
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que se le asigna el ID
 * \param tamanio int Tamaño de la estructura
 * \return int Retorna el siguiente ID
 *
 */
int idAutoIncremental(ePropietario listaPropietario[], int len);
/** \brief Funcion que muestra un elemento dentro de una estructura de arrays
 *
 * \param listadoPropietario[] ePropietario Estructura a mostrar
 * \param tamanio int Tamaño de la estructura
 * \param i int Subindice de la estructura que se va a mostrar
 * \return void
 *
 */
void mostrarUnPropietario(ePropietario listaPropietario[], int i);
/** \brief Funcion que invoca a mostrarUno y muestra todos los elementos de la estructura
 *
 * \param listadoPropietario[] ePropietario estructura que se muestra
 * \param tamanio int Tamaño de la estructura
 * \param flag int Bandera que indica si se ingreso un propietario previamente
 * \return void
 *
 */
void modificarPropietario(ePropietario lista[],int len,int flag);
/** \brief Funcion que permite modificar un string dentro de una estructura
 *
 * \param listado[] ePropietario estructura en la que se va a modificar el string
 * \param indice int Indice de la estructura en el que se va a modificar el string
 * \param caracter[] char Array de caracteres en donde se va a guardar el nuevo string ingresado
 * \return char Retorna el string modificado
 *
 */
char modificarStringPropietario(ePropietario lista[],int indice,char caracter[]);
/** \brief Funcion que toma un Id ingresado por el usuario y lo compara con todos los ID pertenecientes a la estructura
 *
 * \param listado[] ePropietario estructura con la que se comparara el ID ingresado
 * \param tamanio int Tamaño de la estructura
 * \param id int Id que ingresa el usuario
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 *
 */
int buscarPorIdPropietario(ePropietario lista[],int len,int id);

void ordenarPropietarios(ePropietario lista[], int len);
