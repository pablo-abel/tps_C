/*
 * confederacion.c
 *
 *  Created on: 16 nov 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confederacion.h"
#include "jugador.h"

int cargarNombreConfederacion(eConfederacion confederaciones[], int tamc, int idConfederacion, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(confederaciones != NULL && tamc > 0)
    {
        todoOk = 1;
        for(int i = 0; i < tamc; i ++)
        {
            if(confederaciones[i].id == idConfederacion)
            {
                strcpy(nombre, confederaciones[i].nombre);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int cargarNombreRegion(eConfederacion confederaciones[], int tamc, int idConfederacion, char nombre[])
{
    int todoOk = 0;
    int flag = 1;
    if(confederaciones != NULL && tamc > 0)
    {
        todoOk = 1;
        for(int i = 0; i < tamc; i ++)
        {
            if(confederaciones[i].id == idConfederacion)
            {
                strcpy(nombre, confederaciones[i].region);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int mostrarConfederacion(eConfederacion confederaciones[],int tamc)
{
    int todoOk = 0;
    if(confederaciones != NULL && tamc > 0)
    {
        printf("===================================================================\n");
        printf("|                 *** lista Confederaciones ***                   |\n");
        printf("===================================================================\n");
        printf("|   id   |    Nombre    |     Region              | Anio Creacion |\n");
        printf("===================================================================\n");
        for(int i = 0; i < tamc; i ++)
        {
             printf("|  %3d   |    %-8s  |  %-22s |     %4d      |\n", confederaciones[i].id,
                                                                       confederaciones[i].nombre,
                                                                       confederaciones[i].region,
                                                                       confederaciones[i].anioCreacion);
        }
        printf("===================================================================\n");
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int validarConfederacion(int id, eConfederacion confederaciones[],int tamc)
{
    int todoOk = 0;
    if(confederaciones != NULL && tamc > 0)
    {
        for(int i = 0; i < tamc; i ++)
        {
            if(confederaciones[i].id == id)
            {
                todoOk = 1;
            }
        }
    }
    return todoOk;
}
