/*
 * jugador.h
 *
 *  Created on: 16 nov 2022
 *      Author: PC
 */

#include "confederacion.h"
#ifndef JUGADOR_H_
#define JUGADOR_H_

typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
}eJugador;



#endif /* JUGADOR_H_ */

void limpiarPantalla();

/** \brief funcion que confirma la salida
 *
 * \param pControl char* puntero a char que pedimos por parametros
 * \return int 1 si esta todo ok
 *
 */
int confirmarSalida(char *pControl);

/** \brief menu de posiciones
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuPosiciones();

/** \brief incializo isEmpty en 1
 *
 * \param jugadores[] eJugador estructura a recorrer
 * \param tam int tamaño de las filas
 * \return int 1 si esta todo ok
 *
 */
int inicializarJugadores(eJugador jugadores[], int tam);

/** \brief harcodea una lista de 10 jugadores
 *
 * \param jugadores[] eJugador estructura de jugadores
 * \param tam int tamaño de las filas
 * \param cant int cantidad de jugadores que quiero harcodear
 * \param pId int* puntero ID
 * \return int 1 si esta todo ok
 *
 */
int harcodearJugadores(eJugador jugadores[], int tam, int cant, int* pId);

/** \brief busca si hay un espacio libre
 *
 * \param jugadores[] eJugador estructura que recorre
 * \param tam int tamaño de las filas
 * \param pIndice int* puntero indice a ser evaluado para la busqueda
 * \return int indice -1 si no encontro lugar
 *
 */
int buscarLibre(eJugador jugadores[], int tam, int* pIndice);


/**
* \brief Toma una cadena y evalua si es un entero sin signo
* \param pEntero Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getEnteroSoloNumeros(short *pEntero, int limite, char *mensaje, char *mensajeError, int reintentos);

/**
* \brief Toma una cadena y evalua si es un float positivo
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getFloatPositivo(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos);

/** \brief genera el alta de un jugador
 *
 * \param jugadores[] eJugador estructura que le genero el alta
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura que pido por parametro
 * \param tamc int tamaño de las filas de eConfederacion
 * \param pId int* puntero del ID de jugador
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion o problemas en el ingreso de datos
 *
 */
int altaJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc, int* pId);

/** \brief muestro un jugador con sus datos
 *
 * \param unJugador eJugador estructura a recorrer
 * \param confederaciones[] eConfederacion estructura que le pido la descripcion
 * \param tam int tamaño de las filas de eConfederacion
 * \return void
 *
 */
void mostrarJugador(eJugador unJugador, eConfederacion confederaciones[], int tam);

/** \brief muestro la lista de jugadores
 *
 * \param jugadores[] eJugador  estructura a recorrer
 * \param tam int tamaño de las filas de eJugador
 * \param confederaciones[] eConfederacion estructura que le pido la descripcion
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamc);

/** \brief busca el ID de los jugadores
 *
 * \param jugadores[] eJugador estructura a recorrer
 * \param tam int tamaño de las filas
 * \param pIndice int* puntero indice
 * \param id int ID a buscar
 * \return int indice -1 si el ID no esta registrado
 *
 */
int buscarJugador(eJugador jugadores[], int tam, int* pIndice, int id);

/** \brief genera la baja de un jugador
 *
 * \param jugadores[] eJugador estructura que le genero la baja
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura que pido por parametro
 * \param tamc int  tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int bajaJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief menu de opciones modificar
 *
 * \return int retorna la opcion ingresada
 *
 */
int menuModificacion();

/** \brief modifica datos de la estructura eJugador
 *
 * \param jugadores[] eJugador estructura a modificar
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura que pido por parametro
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion o problemas en la modificacion de datos
 *
 */
int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief ordena la lista de jugadores
 *
 * \param jugadores[] eJugador estructura a ordenar
 * \param tam int tamaño de las filas de eJugador
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int ordenarJugador(eJugador jugadores[], int tam);

/** \brief muestro una lista de jugadores segun la confederacion que se elija
 *
 * \param idConfederacion int ID que pido por parametro
 * \param jugadores[] eJugador estructura a recorrer
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura que pido por parametro
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarJugadoresIdConfederacion(int idConfederacion, eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief muestro una lista de jugadores segun el ID seleccionado
 *
 * \param jugadores[] eJugador estructura de los jugadores
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura de las confederaciones
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarConfederacionesJugadores(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief muestro la confederacion con mas años de contratos
 *
 * \param jugadores[] eJugador estructura de los jugadores
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura de las confederaciones
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarConfederacionMaxContrato(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief muestro porcentaje de jugadores por cada confederación
 *
 *
 * \param jugadores[] eJugador estructura de los jugadores
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura de las confederaciones
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarPorcentaje(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief mustro un listado de jugadores con su region
 *
 * \param idRegion int
 * \param jugadores[] eJugador estructura de los jugadores
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura de las confederaciones
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarJugadoresIdRegion(int idRegion, eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief mustro la region con mas jugadores y el listado de los mismos
 *
 * \param jugadores[] eJugador estructura de los jugadores
 * \param tam int tamaño de las filas de eJugador
 * \param confederacion[] eConfederacion estructura de las confederaciones
 * \param tamc int tamaño de las filas de eConfederacion
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarRegionMaxJugadores(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);

/** \brief
 *
 * \param jugadores[] eJugador
 * \param tam int
 * \param confederacion[] eConfederacion
 * \param tamc int
 * \return int
 *
 */
int mostrarPromedioSalario(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc);



