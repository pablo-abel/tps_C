/*
 * funciones.c
 *
 *  Created on: 21 sep. 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
	fflush(stdin);
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}

static int isValidFloatPositivo(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
            (( pBuffer[0] == '+' && pBuffer[1] != '.') ||
            (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int menu()
{
    int opcion;

        printf("   ***  Menu  ***  \n\n");
        printf("1. Ingreso de los costos de Mantenimiento. \n");
        printf("2. Carga de jugadores: \n");
        printf("3. Realizar todos los calculos. \n");
        printf("4. Informar todos los resultados.. \n");
        printf("5. Salir\n");
        printf("Ingrese la opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}
int subMenuCostos(float acumUno, float acumDos, float acumTres)
{
    int opcion;

        printf("\n***  Costos de Mantenimiento  ***\n\n");
        printf("1.Costo de hospedaje -> $%.2f \n", acumUno);
        printf("2.Costo de comida -> $%.2f \n", acumDos);
        printf("3.Costo de transporte -> $%.2f \n", acumTres);
        printf("4.Regresar al menu pricipal \n");
        printf("Ingrese la opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}
void mensajeError()
{
    printf("\nError. Elija una opcion valida!\n");
}
int subMenuPosicion(int iUno, int iDos, int iTres, int iCuatro)
{
    int opcion;

        printf("\n***  Carga de jugadores  ***\n\n");
        printf("Posicion:\n");
        printf("1.Arquero -> %d\n", iUno);
        printf("2.Defensor -> %d\n", iDos);
        printf("3.Mediocampista -> %d\n",iTres);
        printf("4.Delantero -> %d\n", iCuatro);
        printf("Ingrese la opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}

int subMenuConfederacion()
{
    int opcion;

        printf("\n***  Carga de jugadores  ***\n\n");
        printf("Confederacion:\n");
        printf("1.AFC Asia\n");
        printf("2.CAF Africa\n");
        printf("3.CONCACAF Norteamerica\n");
        printf("4.CONMEBOL Sudamerica\n");
        printf("5. UEFA Europa\n");
        printf("6. OFC Oceania\n");
        printf("Ingrese la opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

    return opcion;
}
int confirmarSalida(char *pControl)
{
    int todoOk = 0;
    char confirma;
    if(pControl != NULL)
    {
        printf("confirmar salida s/n:");
        fflush(stdin);
        confirma = tolower(getchar());
        if(confirma == 's')
        {
            *pControl = 's';
        }

        todoOk = 1;
    }

    return todoOk;
}

int utn_getFloatPositivo(float *pFloat, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloatPositivo(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int validarLimite(int* pCantidad,int i, int limite)
{
    int todoOk = 0;

    if(pCantidad != NULL && (i < limite))
    {
        i ++;
        *pCantidad = i;
        todoOk = 1;
    }

    return todoOk;
}

void limpiarPantalla()
{
    for(int i = 0; i < 40; i ++)
    {
        printf("\n");
    }
}
int validarFlagCalculos(int *pFlag, int *pFlagDos, int *pFlagTres)
{
    int todoOk = 0;

    if(pFlag != NULL && pFlagDos != NULL)
    {
        if(*pFlag && *pFlagDos)
        {
             printf("\nCalculos realizados correctamente\n");
            *pFlagTres = 1;
        }
        else if(*pFlagDos)
        {
            printf("No se puede realizar los calculos sin un minimo de 14 convocados!\n");

        }
        else
        {
            printf("\nNo se puede realizar los calculos si no se ingresaron datos en la opcion 1 y 2!\n\n");
        }

        todoOk = 1;
    }

    return todoOk;
}
int validarFlagResultado(int *pFlag)
{
    int todoOk = 0;

    if(pFlag != NULL)
    {
        if(*pFlag)
        {
            printf("Resultados: \n");
            todoOk = 1;

        }
        else
        {
            printf("\nNo hay resultado sin calculos!\n\n");
        }
    }

    return todoOk;
}
float calcularPromedio(int acumulador, int i)
{
  float promedio;

  promedio = (float)acumulador / i;

  return promedio;
}
