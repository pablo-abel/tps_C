#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "mascota.h"

int mascCmId(void* a, void* b)
{
     int retorno = 0;
     eMascota* masc1 = NULL;
     eMascota* masc2 = NULL;
     if(a != NULL && b != NULL)
     {
         masc1 = (eMascota*) a;
         masc2 = (eMascota*) b;
         if(masc1 -> id > masc2 -> id)
         {
             retorno = 1;
         }
         else  if(masc1 -> id < masc2 -> id)
         {
             retorno = -1;
         }
     }
     return retorno;
}
int mascCmEdad(void* a, void* b)
{
     int retorno = 0;
     eMascota* masc1 = NULL;
     eMascota* masc2 = NULL;
     if(a != NULL && b != NULL)
     {
         masc1 = (eMascota*) a;
         masc2 = (eMascota*) b;
         if(masc1 -> edad > masc2 -> edad)
         {
             retorno = 1;
         }
         else  if(masc1 -> edad < masc2 -> edad)
         {
             retorno = -1;
         }
     }
     return retorno;
}

int mascCmNombre(void* a, void* b)
{
     int retorno = 0;
     eMascota* masc1 = NULL;
     eMascota* masc2 = NULL;
     if(a != NULL && b != NULL)
     {
         masc1 = (eMascota*) a;
         masc2 = (eMascota*) b;
         retorno = strcmp(masc1 -> nombre, masc2 -> nombre);
     }
     return retorno;
}

int mascCmSexo(void* a, void* b)
{
     int retorno = 0;
     eMascota* masc1 = NULL;
     eMascota* masc2 = NULL;
     if(a != NULL && b != NULL)
     {
         masc1 = (eMascota*) a;
         masc2 = (eMascota*) b;
         if(masc1 -> sexo > masc2 -> sexo)
         {
             retorno = 1;
         }
         else  if(masc1 -> sexo < masc2 -> sexo)
         {
             retorno = -1;
         }
     }
     return retorno;
}
