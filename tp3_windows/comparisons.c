/*
 * comparisons.c
 *
 *  Created on: 20 nov 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

int Jug_cmEdad(void* a, void* b)
{
     int retorno = 0;
     Jugador* jug1 = NULL;
     Jugador* jug2 = NULL;
     if(a != NULL && b != NULL)
     {
         jug1 = (Jugador*) a;
         jug2 = (Jugador*) b;
         if(jug1->edad > jug2->edad)
         {
             retorno = 1;
         }
         else  if(jug1->edad < jug2->edad)
         {
             retorno = -1;
         }
     }
     return retorno;
}
int Jug_cmNacionalida(void* a, void* b)
{
     int retorno = 0;
     Jugador* jug1 = NULL;
     Jugador* jug2 = NULL;
     if(a != NULL && b != NULL)
     {
         jug1 = (Jugador*) a;
         jug2 = (Jugador*) b;
         retorno = strcmp(jug1->nacionalidad, jug2->nacionalidad);
     }
     return retorno;
}

int Jug_cmNombre(void* a, void* b)
{
     int retorno = 0;
     Jugador* jug1 = NULL;
     Jugador* jug2 = NULL;
     if(a != NULL && b != NULL)
     {
         jug1 = (Jugador*) a;
         jug2 = (Jugador*) b;
         retorno = strcmp(jug1->nombreCompleto, jug2->nombreCompleto);
     }
     return retorno;
}

int selec_cmConfederacion(void* a, void* b)
{
     int retorno = 0;
     Seleccion* selec1 = NULL;
     Seleccion* selec2 = NULL;
     if(a != NULL && b != NULL)
     {
         selec1 = (Seleccion*) a;
         selec2 = (Seleccion*) b;
         retorno = strcmp(selec1->confederacion, selec2->confederacion);
     }
     return retorno;
}

