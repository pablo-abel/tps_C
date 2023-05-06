#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
 * \brief Verifica si una cadena de caracteres puede o no ser convertia a numero entero
 * \param cadena Es la cadena a ser analizada
 * \return Verdadero si la cadena contiene un valor numerico entero, Falso si no
 *
 */
int esNumero(char* cadena)
{
	int retorno = 1;
	int i;
	for(i=0;cadena[i]!='\0';i++)
	{
		if(i==0 && cadena[i] == '-')
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			retorno = 0;
			break;
		}
		//continue
	}
	// break
	return retorno;
}

/**
 * \brief Solicita un numero al usuario, lo valida, verifica y devuelve el resultado
 * \param pResultado Puntero al resultado alli se dejara el numero ingresado por el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param minimo Valor minimo aceptado
 * \param maximo Valor maximo aceptado
 * \param reintentos Cantidad de reintentos en el caso de error
 * \return En caso de exito (0), en caso de error (-1)
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int bufferInt;
    char bufferChar[4096];
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
	do
	{
	    printf("%s",mensaje);
	    scanf("%s",bufferChar);
	    if(esNumero(bufferChar))
	    {
		    bufferInt = atoi(bufferChar);

		    if(bufferInt >= minimo && bufferInt <= maximo)
		    {
			    *pResultado = bufferInt;
			    retorno = 0;
			    break;
		    }
	    }
	    printf("%s",mensajeError);
	    reintentos--;
	}while(reintentos >= 0);
    }
    return retorno;
}



/**
 * \brief Solicita un caracter al usuario, lo valida, verifica y devuelve el resultado
 * \param pResultado Puntero al resultado alli se dejara el caracter ingresado por el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param minimo Valor minimo aceptado
 * \param maximo Valor maximo aceptado
 * \param reintentos Cantidad de reintentos en el caso de error
 * \return En caso de exito (0), en caso de error (-1)
 *
 */
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char buffer;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
	do
	{
	    printf("%s",mensaje);
	    fflush(stdin);
	    scanf("%c",&buffer);
	    if(buffer >= minimo && buffer <= maximo)
	    {
		    *pResultado = buffer;
		    retorno = 0;
		    break;
	    }
	    printf("%s",mensajeError);
	    reintentos--;
	}while(reintentos>=0);

    }
    return retorno;
}


