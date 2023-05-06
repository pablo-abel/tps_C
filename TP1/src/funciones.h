/*
 * funciones.h
 *
 *  Created on: 21 sep. 2022
 *      Author: PC
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/// @brief imprime el menu principal
///
/// @return retorna la opcion int a elegir
int menu();

/// @brief imprime un sub menu de los costo de mantenimiento
/// y con el monto actualizado en cada opcion
///
/// @param acumUno valor de la primera opcion
/// @param acumDos valor de la segunda opcion
/// @param acumTres valor de la tercera opcion
/// @return  retorna la opcion int a elegir
int subMenuCostos(float acumUno, float acumDos, float acumTres);

/// @brief imprime un mensaje de Error
///
void mensajeError();

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

/// @brief imprime un sub menu de posiciones dentro de una cancha
/// con la cantidad de ingresos en el momento de cada posicion
///
/// @param iUno valor de la primera opcion
/// @param iDos valor de la segunda opcion
/// @param iTres valor de la tercera opcion
/// @param iCuatro valor de la cuarta opcion
/// @return retorna la opcion int a elegir
int subMenuPosicion(int iUno, int iDos, int iTres, int iCuatro);

/// @brief imprime un sub menu de las confederaciones
///
/// @return retorna la opcion int a elegir
int subMenuConfederacion();

/// @brief confirma la salida del menu
/// @param pControl puntero a ser evaluado
/// @return retorna 1 int si esta todo ok 0 si no
int confirmarSalida(char *pControl);

/// @brief valida el limite de ingreso y asigna valor por referencia
///
/// @param pCantidad puntero de la variable a setear
/// @param i valor a limitar
/// @param limite valor del limite
/// @return retorna 1 si no se llego al limite y 0 si alcanzo el limite
int validarLimite(int* pCantidad,int i, int limite);

/// @brief imprime un salto del linea 40 veces, simula un limpia pantalla
///
void limpiarPantalla();

/// @brief valida el ingreso a una opcion de calculos
///
/// @param pFlag puntero a ser evaluado para el ingreso
/// @param pFlagDos puntero a ser evaluado para el ingreso
/// @param pFlagTres puntero a ser modificado
/// @return retorna 1 int si esta todo ok 0 si no
int validarFlagCalculos(int *pFlag, int *pFlagDos, int *pFlagTres);

/// @brief valida el ingreso a una opcion de resultados
///
/// @param pFlag puntero a ser evaluado para el ingreso
/// @return retorna 1 int si esta todo ok 0 si no
int validarFlagResultado(int *pFlag);

/// @brief calcula el promedio de dos enteros
///
/// @param acumulador primer valor
/// @param i segundo valor
/// @return float promedio de dos enteros ingresados
float calcularPromedio(int acumulador, int i);

#endif /* FUNCIONES_H_ */
