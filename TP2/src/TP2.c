/*
 ============================================================================
 Name        : TP2.c
 Author      : Pablo Toledo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "utn.h"
#include "confederacion.h"

#define TAM_J 3000
#define TAM_C 6

int main(void)
{

    setbuf(stdout, NULL);

    int opcion;
    int respuesta;
    char confirmar;
    int nextId = 1;

    eJugador jugadores[TAM_J];

    eConfederacion confederaciones[TAM_C] = {{100, "CONMEBOL", "SUDAMERICA", 1916},
					     {101, "UEFA", "EUROPA", 1954},
					     {102, "AFC", "ASIA", 1954},
					     {103, "CAF", "AFRICA", 1957},
					     {104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
					     {105, "OFC", "OCEANIA", 1966}};


    if(!inicializarJugadores(jugadores, TAM_J))
    {
	printf("Problemas al inicializar!");
    }

    harcodearJugadores(jugadores, TAM_J, 15, &nextId);

    do
    {
	limpiarPantalla();
        respuesta = utn_getNumero(&opcion, "     ABM jugador    \n"
                                           "---------------------\n"
                                           "1 - Alta jugador\n"
                                           "2 - Baja jugador\n"
                                           "3 - Modificar jugador\n"
                                           "4 - lista jugadores predeterminada\n"
				           "5 - *INFORMES: \n"
					   "6 - Salir\n"
                                           "Ingrese opcion:\n", "No es una opcion valida\n", 1, 6, 4);
        if(!respuesta)
        {
	    switch(opcion)
	    {
	      case 1:
		  if(!altaJugador(jugadores, TAM_J, confederaciones, TAM_C, &nextId))
		  {
		      printf("Problemas al realizar el alta! \n");
		  }
		  else
		  {
		      printf("Alta exitosa! \n");
		  }
	      break;
	      case 2:
		  if(!bajaJugador(jugadores, TAM_J, confederaciones, TAM_C))
		  {
		      printf("NO se pudo realizar la baja! \n");
		  }
		  else
		  {
		      printf("Baja exitosa! \n");
		  }
	      break;
	      case 3:
		  if(!modificarJugador(jugadores, TAM_J, confederaciones, TAM_C))
		  {
		      printf("NO se pudo realizar la modificacion! \n");
		  }
		  else
		  {
		      printf("Modificacion exitosa! \n");
		  }
	      break;
	      case 4:
		  mostrarJugadores(jugadores, TAM_J, confederaciones, TAM_C);
	      break;
	      case 5:
		  do
		  {
		    limpiarPantalla();
		    respuesta = utn_getNumero(&opcion," *INFORMES   \n"
						      "1 - Listado jugadores alfabeticamente por nombres \n"
						      "2 - Listado confederacion con sus jugadores \n"
						      "3 - total y promedio de todos los salarios y\n"
						      "    jugadores que cobran mas del salario promedio  \n"
						      "4 - confederacion con mayor cantidad de años de contrato total  \n"
						      "5 - porcentaje de jugadores por cada confederacion  \n"
						      "6 - region con mas jugadores y listado de los mismos  \n"
						      "7 - Salir  \n"
						      "Ingrese opcion:\n", "No es una opcion valida\n", 1, 7, 4);
		    if(!respuesta)
		    {
			  switch(opcion)
			  {
			    case 1:
				if (!ordenarJugador(jugadores, TAM_J))
				{
				    printf("NO se pudo ordenar! \n");
				}
				else
				{
				    printf("Se ordeno la lista por nombres! \n");
				}
			    break;
			    case 2:
				mostrarConfederacionesJugadores(jugadores, TAM_J, confederaciones, TAM_C);
			    break;
			    case 3:
				printf("La opcion 3");
			    break;
			    case 4:
				mostrarConfederacionMaxContrato(jugadores, TAM_J, confederaciones, TAM_C);
			    break;
			    case 5:
				mostrarPorcentaje(jugadores, TAM_J, confederaciones, TAM_C);
			    break;
			    case 6:
				mostrarRegionMaxJugadores(jugadores, TAM_J, confederaciones, TAM_C);
			    break;
			    case 7:
				if(!confirmarSalida(&confirmar))
				{
				    opcion = 0;
				}
			    break;
			  }
		    }
		  }while(opcion != 7);
	      break;
	      case 6:
		  if(!confirmarSalida(&confirmar))
		  {
		      opcion = 0;
		  }
	      break;

	    }
        }

    }while(opcion != 6);

    return EXIT_SUCCESS;
}
