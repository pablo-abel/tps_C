#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "mascota.h"

int mostrarMascota(eMascota* mascota)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int edad;
    char sexo[20];
    if(mascota != NULL)
    {
        if(mascotaGetId(mascota, &id) &&
           mascotaGetNombre(mascota, nombre) &&
           mascotaGetEdad(mascota, &edad) &&
           mascotaGetFullSexo(mascota, sexo))
        {
            printf(" %d   %-8s   %d     %s\n", id, nombre, edad, sexo);
            todoOk = 1;
        }

    }
    return todoOk;
}

void mostrarMascotas(LinkedList* lista)
{
    printf("-------------------------------\n");
    printf(" Id    Nombre   Edad    Sexo\n");
    printf("-------------------------------\n");
    for(int i = 0; i < ll_len(lista); i ++)
    {
        mostrarMascota((eMascota*) ll_get(lista, i));
    }
    printf("\n\n");
}

int esMacho(void* m)
{
    int ok = 0;
    eMascota* unaMascota = NULL;
    if(m != NULL)
    {
        unaMascota = (eMascota*) m;
        if(unaMascota->sexo == 'm')
        {
            ok = 1;
        }
    }
   // printf("%d\n", ok);// me fijo si esta todo ok con el rotorno de la fincion
    return ok;
}
eMascota* new_Mascota()
{
    eMascota* auxM = NULL;
    auxM = (eMascota*) malloc(sizeof(eMascota));
    return auxM;
}

eMascota* new_MascotaParam(int id, char* nombre, int edad, char sexo)
{
    eMascota* nuevaMascota;
    nuevaMascota = new_Mascota();
    if(nuevaMascota != NULL)
    {
        if(!(mascotaSetId(nuevaMascota, id) &&
             mascotaSetNombre(nuevaMascota, nombre) &&
             mascotaSetEdad(nuevaMascota, edad) &&
             mascotaSetSexo(nuevaMascota, sexo)))
        {
            free(nuevaMascota);
            nuevaMascota = NULL;
        }
    }
    return nuevaMascota;
}
int mascotaSetId(eMascota* pMasc, int id)
{
    int todoOk = 0;
    if(pMasc != NULL)
    {
        pMasc->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int mascotaGetId(eMascota* pMasc, int* pId)
{
    int todoOk = 0;
    if(pMasc != NULL && pId != NULL)
    {
        *pId = pMasc->id;
        todoOk = 1;
    }
    return todoOk;
}
int mascotaSetNombre(eMascota* pMasc, char* nombre)
{
    int todoOk = 0;
    char auxCadena[20];
    if(pMasc != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
    {
        strcpy(auxCadena, nombre);
        strlwr(auxCadena);
        auxCadena[0] = toupper(auxCadena[0]);
        strcpy(pMasc->nombre, auxCadena);
        todoOk = 1;
    }
    return todoOk;
}

int mascotaGetNombre(eMascota* pMasc, char* pNombre)
{
    int todoOk = 0;

    if(pMasc!= NULL && pNombre != NULL)
    {
        strcpy(pNombre, pMasc->nombre);
        todoOk = 1;
    }
    return todoOk;
}
int mascotaSetEdad(eMascota* pMasc, int edad)
{
    int todoOk = 0;
    if(pMasc != NULL)
    {
        pMasc->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}
int mascotaGetEdad(eMascota* pMasc, int* pEdad)
{
    int todoOk = 0;
    if(pMasc != NULL && pEdad != NULL)
    {
        *pEdad = pMasc->edad;
        todoOk = 1;
    }
    return todoOk;
}
int mascotaSetSexo(eMascota* pMasc, char sexo)
{
    int todoOk = 0;
    sexo = tolower(sexo);
    if(pMasc != NULL && (sexo == 'h' || sexo == 'm'))
    {
        pMasc->sexo = sexo;
        todoOk = 1;
    }
    return todoOk;
}

int mascotaGetFullSexo(eMascota* pMasc, char* pSexo)
{
    int todoOk = 0;
   // char sexo = tolower(sexo);
    if(pMasc != NULL && pSexo != NULL)
    {
        if(pMasc->sexo == 'h')
        {
            strcpy(pSexo, "Hembra");
        }
        else
        {
            strcpy(pSexo, "Macho");
        }
        todoOk = 1;
    }
    return todoOk;
}
