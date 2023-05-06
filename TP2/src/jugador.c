/*
 * jugador.c
 *
 *  Created on: 16 nov 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "confederacion.h"


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

static int isValidEnteroSoloNumeros(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if (pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
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
            todoOk = 1;
        }
    }
    return todoOk;
}

int menuPosiciones()
{
    int opcion;

    printf(" *Posicion:  \n");
    printf("1 - Arquero  \n");
    printf("2 - Defensor \n");
    printf("3 - Mediocampo \n");
    printf("4 - Delantero \n");
    printf("Ingrese opcion:   \n");
    scanf("%d", &opcion);
    printf("\n\n\n\n\n\n");
    return opcion;
}
void limpiarPantalla()
{
    for(int i = 0; i < 5; i ++)
    {
        printf("\n");
    }
}

int inicializarJugadores(eJugador jugadores[], int tam)
{
    int todoOk = 0;

    if(jugadores != NULL && tam > 0)
    {
        for(int i = 0; i > tam; i ++)
        {
            jugadores[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int harcodearJugadores(eJugador jugadores[], int tam, int cant, int* pId)
{
    int todoOk = 0;
    eJugador jugadoresTest[15]={{1,"Emiliano Martinez","Arquero",1,100,100000,4,0},
                                {2,"Juan Musso","Arquero",12,100,80000,2,0},
                                {3,"Leo Messi","Delantero",10,100,80000,4,0},
                                {4,"Almirez Ali","Delantero",9,100,55000,1,0},
                                {5,"Harry Maguire","Delantero",2,101,70000,4,0},
                                {6,"Eric Dier","Defensor",3,101,60000,2,0},
                                {7,"Harry Kane","Delantero",10,101,3000,2,0},
                                {8,"Alfred Gomis","Arquero",1,101,9000,1,0},
                                {9,"Abdelkarim Hassan","Mediocampista",8,101,48000,1,0},
                                {10,"Guillermo Ochoa","Arquero",1,104,90000,4,0},
                                {11,"Tecatito","Delantero",11,104,100000,3,0},
                                {12,"Luis Romo","Mediocampista",7,104,100000,2,0},
                                {13,"Bamba Dieng ","Delantero",9,103,100000,2,0},
                                {14,"Demba Seck","Delantero",11,103,6000,2,0},
                                {15,"Tarek Salman","Defensor",6,102,78000,5,0}};


    if(jugadores != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
         for(int i = 0; i < cant; i ++)
         {
             jugadores[i] = jugadoresTest[i];
             (*pId) ++;
         }
         todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eJugador jugadores[], int tam, int* pIndice)
{
    int indice = -1;
    if(jugadores != NULL && tam > 0 && pIndice != NULL)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(jugadores[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return indice;
}

int buscarJugador(eJugador jugadores[], int tam, int* pIndice, int id)
{
    int indice = -1;
    if(jugadores != NULL && tam > 0 && pIndice != NULL)
    {
        for(int i = 0; i < tam; i ++)
        {
            if(!jugadores[i].isEmpty && jugadores[i].id == id)
            {
                indice = i;
                break;
            }
        }
        *pIndice = indice;
    }
    return indice;
}

void mostrarJugador(eJugador unJugador, eConfederacion confederaciones[], int tam)
{
    char nombre[50];

    if(cargarNombreConfederacion(confederaciones, tam, unJugador.idConfederacion, nombre) == 1)
    {

         printf("|  %3d   |  %-22s |  %-14s |      %2hd       | %10.2f |   %-8s    |         %hd         |\n", unJugador.id,
                                                                                                                unJugador.nombre,
                                                                                                                unJugador.posicion,
                                                                                                                unJugador.numeroCamiseta,
                                                                                                                unJugador.salario,
                                                                                                                nombre,
                                                                                                                unJugador.aniosContrato);
    }

}

int mostrarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamc)
{
    int todoOk = 0;
    int flag = 1;
    if(jugadores != NULL && tam > 0 && confederaciones != NULL && tamc > 0)
    {

        printf("=======================================================================================================================\n");
        printf("|                                              *** lista Jugadores ***                                                |\n");
        printf("=======================================================================================================================\n");
        printf("|   id   |      Nombre             | Posicion        | n de camiseta |   sueldo   | confederacion | anios de contrato |\n");
        printf("=======================================================================================================================\n");
        for(int i = 0; i < tam; i ++)
        {
            if(jugadores[i].isEmpty == 0)
            {
                mostrarJugador(jugadores[i], confederaciones, tamc);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("|                                           No hay jugadores para mostrar !                                        |\n");
        }
        printf("=======================================================================================================================\n");
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int utn_getEnteroSoloNumeros(short *pEntero, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEnteroSoloNumeros(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
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

int altaJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc, int* pId)
{
    int todoOk = 0;
    int i = 0;
    int opcion;
    int indice;
    eJugador auxJugador;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0 && pId != NULL)
    {
	limpiarPantalla();
        printf("\n      Alta Alumno     \n");
        printf("     =============     \n\n");
        indice = buscarLibre(jugadores, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar!");
        }
        else
        {
            todoOk = 1;
            printf("Ingrese nombre del jugador: ");
            fflush(stdin);
            gets(auxJugador.nombre);
            while(strlen(auxJugador.nombre) >= 50 || atoi(auxJugador.nombre))
            {
                fflush(stdin);
                printf("Error. Ingrese un nombre valido: ");
                gets(auxJugador.nombre);
            }
            strlwr(auxJugador.nombre);
            auxJugador.nombre[0] = toupper(auxJugador.nombre[0]);
	    while(auxJugador.nombre[i] != '\0')
	    {
		if(auxJugador.nombre[i] == ' ')
		{
		    auxJugador.nombre[i + 1] = toupper(auxJugador.nombre[i + 1]);
		}
		i++;
	    }
	    limpiarPantalla();
            printf("Elija la posicion del jugador: \n");
            do
	    {
        	switch(menuPosiciones())
		{
		  case 1:
		      strcpy(auxJugador.posicion, "Arquero");
		  break;
		  case 2:
		      strcpy(auxJugador.posicion, "Defensor");
		  break;
		  case 3:
		      strcpy(auxJugador.posicion, "Mediocampo");
		  break;
		  case 4:
		      strcpy(auxJugador.posicion, "Delantero");
		  break;
		  default:
		      printf("La opcion no existe! Ingrese la opcion correcta\n\n");
		      opcion = 5;
		  break;
		}
            }while(opcion == 5);

            if(utn_getEnteroSoloNumeros(&auxJugador.numeroCamiseta, 3, "Ingrese el numero de camiseta: ", "Error. Igrese el numero de camiseta maximo 99: ", 2) == -1)
            {
        	printf("\nLLego al limite de reintentos!");
        	todoOk = 0;
            }

            if(utn_getFloatPositivo(&auxJugador.salario, 7, "Ingrese el sueldo: ", "Error. Igrese un sueldo valido: ", 2) == -1)
	    {
        	printf("\nLLego al limite de reintentos!");
        	todoOk = 0;
	    }

            limpiarPantalla();
            mostrarConfederacion(confederacion, tamc);
            printf("Ingrese ID de confederacion: ");
            scanf("%d", &auxJugador.idConfederacion);
            while(!validarConfederacion(auxJugador.idConfederacion, confederacion, tamc))
            {
        	limpiarPantalla();
                mostrarConfederacion(confederacion, tamc);
                printf("Error. Ingrese ID de confederacion: ");
                scanf("%d", &auxJugador.idConfederacion);
            }

            if(utn_getEnteroSoloNumeros(&auxJugador.aniosContrato, 3, "Ingrese anios de contratos: ", "Error. Igrese los anios de contratos valido: ", 2) == -1)
	    {
        	printf("LLego al limite de reintentos!");
        	todoOk = 0;
	    }
            limpiarPantalla();
            if(todoOk)
	    {
                auxJugador.id = *pId;
                (*pId) ++;
        	auxJugador.isEmpty = 0;
		jugadores[indice] = auxJugador;
	    }


        }
    }
    return todoOk;
}

int bajaJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    int indice;
    char confirmar;
    int id;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("\n      Baja Alumno     \n");
        printf("     =============     \n\n");
        mostrarJugadores(jugadores, tam, confederacion, tamc);
        printf("Ingrese el ID del jugador: ");
        scanf("%d", &id);
        indice = buscarJugador(jugadores, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarJugador(jugadores[indice], confederacion, tamc);
            printf("Confirma baja? s/n:  ");
            fflush(stdin);
            confirmar = tolower(getchar());
            if(confirmar == 's')
            {
                jugadores[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja Cancelada! \n");
            }
        }
    }
    return todoOk;
}

int menuModificacion()
{
    int opcion;
    limpiarPantalla();
    printf("Seleccione lo que quiere modificar:    \n \n");
    printf("1- Nombre \n");
    printf("2- Posicion \n");
    printf("3- numero de camiseta \n");
    printf("4- sueldo \n");
    printf("5- confederacion \n");
    printf("6- Anios de contratos \n");
    printf("Ingrese opcion:  \n");
    scanf("%d", &opcion);

    return opcion;
}

int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    int i = 0;
    int opcion;
    int indice;
    char confirmar;
    int id;
    char auxNombre[50];
    char auxPosicion[50];
    short auxNumeroCamiseta;
    float auxSalario;
    int auxConfederacion;
    short auxAniosContrato;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("\n      Modificar Alumno     \n");
        printf("     ==================     \n\n");
        mostrarJugadores(jugadores, tam, confederacion, tamc);
        printf("Ingrese el ID del jugador: ");
        scanf("%d", &id);
        indice = buscarJugador(jugadores, tam, &indice, id);
        if(indice == -1)
        {
            printf("ID no registrado en el sistema!");
        }
        else
        {
            mostrarJugador(jugadores[indice], confederacion, tamc);
            printf("Confirma modificacion? s/n:  ");
            fflush(stdin);
            confirmar = tolower(getchar());
            if(confirmar == 's')
            {
        	todoOk = 1;
                switch ( menuModificacion())
                {
		  case 1:
		      printf("ingrese un nuevo nombre:");
		      fflush(stdin);
		      gets(auxNombre);
		      while(strlen(auxNombre) >= 50 || atoi(auxNombre))
		      {
			 fflush(stdin);
			 printf("Error. Ingrese un nombre valido: ");
			 gets(auxNombre);
		      }
		      strlwr(auxNombre);
		      auxNombre[0] = toupper(auxNombre[0]);
		      while(auxNombre[i] != '\0')
		      {
			  if(auxNombre[i] == ' ')
			  {
			      auxNombre[i + 1] = toupper(auxNombre[i + 1]);
			  }
			  i++;
		      }
		      strcpy(jugadores[indice].nombre, auxNombre);
		  break;
		  case 2:
		      printf("\n\nElija una nueva posicion: \n");
		      do
		      {
			  switch(menuPosiciones())
			  {
			    case 1:
				strcpy(auxPosicion, "Arquero");
			    break;
			    case 2:
				strcpy(auxPosicion, "Defensor");
			    break;
			    case 3:
				strcpy(auxPosicion, "Mediocampo");
			    break;
			    case 4:
				strcpy(auxPosicion, "Delantero");
			    break;
			    default:
				printf("La opcion no existe! Ingrese la opcion correcta\n\n");
				opcion = 5;
			    break;
			  }
		      }while(opcion == 5);
		      strcpy(jugadores[indice].posicion, auxPosicion);

		  break;
		  case 3:
		     if(utn_getEnteroSoloNumeros(&auxNumeroCamiseta, 3, "ingrese un nuevo numero de camiseta:", "Error. Igrese el numero de camiseta maximo 99: ", 2) == 0)
		     {
			 jugadores[indice].numeroCamiseta = auxNumeroCamiseta;
		     }
		     else
		     {
			   printf("\nLLego al limite de reintentos!");
			   todoOk = 0;
		     }

		  break;
		  case 4:
		      if(utn_getFloatPositivo(&auxSalario, 7, "Ingrese el nuevo sueldo: ", "Error. Igrese un sueldo valido: ", 2) == 0)
		      {
			  jugadores[indice].salario = auxSalario;

		      }
		      else
		      {
			  printf("\nLLego al limite de reintentos!");
			  todoOk = 0;
		      }

		  break;
		  case 5:
		      printf("\n\n");
		      mostrarConfederacion(confederacion, tamc);
		      printf("Ingrese el ID de la nueva confederacion: ");
		      scanf("%d", &auxConfederacion);
		      while(!validarConfederacion(auxConfederacion, confederacion, tamc))
		      {
			  limpiarPantalla();
			  mostrarConfederacion(confederacion, tamc);
			  printf("Error. Ingrese ID de confederacion: ");
			  scanf("%d", &auxConfederacion);
		      }
		      jugadores[indice].idConfederacion = auxConfederacion;
		  break;
		  case 6:
		      if(utn_getEnteroSoloNumeros(&auxAniosContrato, 3, "ingrese una nueva cantidad de anios de contrato:", "Error. Igrese el numero de camiseta maximo 99: ", 2) == 0)
		      {
		         jugadores[indice].aniosContrato = auxAniosContrato;
		      }
		      else
		      {
			  printf("\nLLego al limite de reintentos!");
		          todoOk = 0;
		      }
		  break;
		  default:
		      printf("Opcion invalida!\n");
		  break;
                }
            }
            else
            {
                printf("Modificacion Cancelada! \n");
            }
        }
    }
    return todoOk;
}

int ordenarJugador(eJugador jugadores[], int tam)
{
    int todoOk = 0;
    eJugador auxNombre;

    if(jugadores != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i ++)
        {
            for(int j = i + 1; j < tam; j ++)
            {

                if((jugadores[i].idConfederacion >  jugadores[j].idConfederacion) ||
                  ((jugadores[i].idConfederacion ==  jugadores[j].idConfederacion) &&
                  strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0))
                {
                    auxNombre = jugadores[i];
                    jugadores[i] = jugadores[j];
                    jugadores[j] = auxNombre;
                }

            }
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarJugadoresIdConfederacion(int idConfederacion, eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    char descConfederacion[20];
    char nombre[50];
    int flag = 1;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("===========================================\n");
        printf("| lista de jugadores por Confederaciones  |\n");
        printf("===========================================\n");
        printf("|   Jugadores            | Confederacion  |\n");
        printf("===========================================\n");
        for (int i = 0; i < tam; i++)
        {
            if (!jugadores[i].isEmpty && jugadores[i].idConfederacion == idConfederacion)
            {
                if(cargarNombreConfederacion(confederacion, tamc, jugadores[i].idConfederacion, nombre) == 1)
                {
                     printf("| %-22s |   %-10s   |\n", jugadores[i].nombre, nombre);
                }
                flag = 0;
            }
        }
        if (flag)
        {
            cargarNombreConfederacion(confederacion, tamc, idConfederacion, descConfederacion);
            printf("\n       No hay jugadores en %s!           \n\n", descConfederacion);
        }
        printf("===========================================\n");
        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}
int mostrarConfederacionesJugadores(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    int idConfederacion;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        mostrarConfederacion(confederacion, tamc);
        printf("Ingrese ID de la confederacion: ");
        scanf("%d", &idConfederacion);
        while(!validarConfederacion(idConfederacion, confederacion, tamc))
        {
            limpiarPantalla();
            mostrarConfederacion(confederacion, tamc);
            printf("Error. Ingrese ID de la confederacion valido: ");
            scanf("%d", &idConfederacion);
        }

        mostrarJugadoresIdConfederacion(idConfederacion, jugadores, tam, confederacion, tamc);
        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarConfederacionMaxContrato(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    int acum[] = {0,0,0,0,0,0};
    int maximo;


    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("\n=============================================\n");
        printf("*Confederacion con mas anios de contratos es:\n");
         printf("=============================================\n\n\n");
        for (int i = 0; i < tamc; i++)
        {
             for (int j = 0; j < tam; j++)
             {
                 if (jugadores[j].isEmpty == 0 && jugadores[j].idConfederacion == confederacion[i].id)
                 {
                     acum[i] += jugadores[j].aniosContrato;
                 }
             }
             for (int i = 0; i < tamc; i++)
             {
                 if(i == 0 || acum[i] > maximo)
                 {
                     maximo = acum[i];
                 }
             }
        }
        for (int i = 0; i < tamc; i++)
        {
            if(acum[i] == maximo)
            {
               printf("\nConfederacion:   %s \n\n", confederacion[i].nombre);
            }
        }

        printf("===========================================\n");

        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPorcentaje(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    float porcentaje[] = {0,0,0,0,0,0};
    int contador[] = {0,0,0,0,0,0};
    int contadorJugador = 0;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("\n===========================================\n");
        printf("*Porcentaje de jugadores por confederacion\n");
        printf("===========================================\n\n");
        for (int i = 0; i < tamc; i++)
        {
             for (int j = 0; j < tam; j++)
             {
                 if (jugadores[j].isEmpty == 0 && jugadores[j].idConfederacion == confederacion[i].id)
                 {
                    contador[i] ++;
                    contadorJugador ++;
                 }
             }
         }
         for (int i = 0; i < tamc; i++)
         {
             if(contador[i] > 0)
             {
                 porcentaje[i] =  ((float) contador[i] / contadorJugador) * 100;
                 printf("%s: %.2f\n\n", confederacion[i].nombre, porcentaje[i]);
             }
             else
             {
                  printf("%s: No tiene jugadores!\n\n", confederacion[i].nombre);
             }
         }
        printf("===========================================\n\n");

        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarJugadoresIdRegion(int idRegion, eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    char nombre[50];

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("==============================================\n");
        printf("|lista de jugadores maximo cantidad en region|\n");
        printf("==============================================\n");
        printf("|     Jugadores          |     Region        |\n");
        printf("==============================================\n");
        for (int i = 0; i < tam; i++)
        {
            if (!jugadores[i].isEmpty && jugadores[i].idConfederacion == idRegion)
            {
                if(cargarNombreRegion(confederacion, tamc, jugadores[i].idConfederacion, nombre) == 1)
                {
                     printf("|  %-22s |    %-10s    |\n", jugadores[i].nombre, nombre);
                }
            }
        }
        printf("==============================================\n");
        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int mostrarRegionMaxJugadores(eJugador jugadores[], int tam, eConfederacion confederacion[], int tamc)
{
    int todoOk = 0;
    int contador[] = {0,0,0,0,0,0};
    int maximo;

    if(jugadores != NULL && tam > 0 && confederacion != NULL && tamc > 0)
    {
	limpiarPantalla();
        printf("\n=======================================\n");
        printf("*Region con el maximo de jugadores es:\n");
        printf("=======================================\n");
        for (int i = 0; i < tamc; i++)
        {
             for (int j = 0; j < tam; j++)
             {
                 if (jugadores[j].isEmpty == 0 && jugadores[j].idConfederacion == confederacion[i].id)
                 {
                     contador[i] ++;
                 }
             }
             for (int i = 0; i < tamc; i++)
             {
                 if(i == 0 || contador[i] > maximo)
                 {
                     maximo = contador[i];
                 }
             }
        }
        for (int i = 0; i < tamc; i++)
        {
            if(contador[i] == maximo)
            {
               printf("\nRegion:   %s \n\n", confederacion[i].region);
               printf("=======================================\n\n\n");

               mostrarJugadoresIdRegion(confederacion[i].id, jugadores, tam, confederacion, tamc);

            }
        }
        printf("\n\n\n\n\n\n");
        todoOk = 1;
    }
    return todoOk;
}

