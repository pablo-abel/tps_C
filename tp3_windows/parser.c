#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* archivo que recibo
 * \param pArrayListJugador LinkedList* lista de los jugadore
 * \return int retorna 0 si esta todo ok y -1 si hubo un error
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
  int retorno = -1;
  int cant;
  char buffer[6][370];
  Jugador* auxJugador = NULL;

  if(pFile != NULL)
  {
    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3], buffer[4], buffer[5]);
    do
    {
      cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3], buffer[4], buffer[5]);
      if(cant != 6)
      {
	  break;
      }
      auxJugador = jug_newParametros(buffer[0], buffer[1],buffer[2], buffer[3], buffer[4], buffer[5]);
      if(auxJugador != NULL)
      {
	ll_add(pArrayListJugador, auxJugador);
	auxJugador = NULL;
      }

    }while(!feof(pFile));
    retorno = 0;
  }
  return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char* archivo que recibo
 * \param pArrayListJugador LinkedList* lista de los jugadore
 * \return int retorna 0 si esta todo ok y -1 si hubo un error
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
  int retorno = -1;
  int cant;
  Jugador* auxJugador = NULL;

  if(pFile != NULL)
  {
     do
     {
       auxJugador = jug_new();
       if(auxJugador != NULL)
       {
	   cant = fread(auxJugador, sizeof(Jugador), 1, pFile);
	   if(cant != 1)
	   {
	       break;
	   }
	   ll_add(pArrayListJugador, auxJugador);
	   auxJugador = NULL;
       }

     }while(!feof(pFile));
     retorno = 0;
  }
  return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* archivo que recibo
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si esta todo ok y -1 si hubo un error
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
  int retorno = -1;
  int cant;
  char buffer[4][370];
  Seleccion* auxSeleccion = NULL;

  if(pFile != NULL)
  {
    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3]);
    do
    {
      cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3]);
      if(cant != 4)
      {
	  break;
      }
      auxSeleccion = selec_newParametros(buffer[0], buffer[1],buffer[2], buffer[3]);
      if(auxSeleccion != NULL)
      {
	  ll_add(pArrayListSeleccion, auxSeleccion);
	  auxSeleccion = NULL;
      }

    }while(!feof(pFile));
    retorno = 0;
  }
  return retorno;
}

