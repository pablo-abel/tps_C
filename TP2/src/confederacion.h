/*
 * confederacion.h
 *
 *  Created on: 16 nov 2022
 *      Author: PC
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
}eConfederacion;


#endif /* CONFEDERACION_H_ */

/** \brief cargo por ID el nombre de la estructura
 *
 * \param confederaciones[] eConfederacion estructura a recorrer
 * \param tamc int tamaño de las filas
 * \param idConfederacion int Id que pedimos por parametro para comparar
 * \param nombre[] char cadena que le asigno al nombre de la estructura eConfederacion
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreConfederacion(eConfederacion confederaciones[], int tamc, int idConfederacion, char nombre[]);

/** \brief cargo por ID la region de la estructura
 *
 * \param confederaciones[] eConfederacion estructura a recorrer
 * \param tamc int tamaño de las filas
 * \param idConfederacion int Id que pedimos por parametro para comparar
 * \param nombre[] char cadena que le asigno a la region de la estructura eConfederacion
 * \return int retorno 1 si esta todo Ok -1 si hubo un error 0 si hubo problema en la validacion
 *
 */
int cargarNombreRegion(eConfederacion confederaciones[], int tamc, int idConfederacion, char nombre[]);

/** \brief muestro la lista de Confederacion
 *
 * \param confederaciones[] eConfederacion estructura a mostrar
 * \param tamc int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int mostrarConfederacion(eConfederacion confederaciones[],int tamc);

/** \brief valida que el ID exista en la estructura
 *
 * \param id int ID a validar
 * \param confederaciones[] eConfederacion estructura a recorrer
 * \param tamc int tamaño de las filas
 * \return int 1 si esta todo ok 0 si hubo problema en la validacion
 *
 */
int validarConfederacion(int id, eConfederacion confederaciones[],int tamc);
