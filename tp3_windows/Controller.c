#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "parser.h"
#include "utn.h"
#include "comparisons.h"
#include "LinkedList.h"


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char* archivo que quiero leer
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 1 si se cargo el archivo -1 si hubo un error
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{

  int retorno = -1;
  char confirma;
  FILE* pFile;

  if(path != NULL && pArrayListJugador != NULL)
  {
      retorno = 0;
      pFile = fopen(path, "r");
      if(pFile != NULL)
      {
          if(ll_len(pArrayListJugador) > 0)
          {
              printf("Cuidado! Se pueden sobrescribir la lista de los jugadores\n");
              printf("Quiere sobrescribirla? s/n:");
              fflush(stdin);
              confirma = tolower(getchar());
          }
          if(ll_len(pArrayListJugador) == 0 || confirma == 's')
          {
              ll_clear(pArrayListJugador);
              parser_JugadorFromText(pFile, pArrayListJugador);
              retorno = 1;
          }
      }
      fclose(pFile);
  }
  return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char* archivo que quiero leer
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 1 si se cargo el archivo -1 si hubo un error
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
  int retorno = -1;
  FILE* pFile;

  if(path != NULL && pArrayListJugador != NULL)
  {
     retorno = 0;
     pFile = fopen(path, "rb");
     if(pFile != NULL)
     {
	parser_JugadorFromBinary(pFile, pArrayListJugador);
	 retorno = 1;
     }
      fclose(pFile);
  }
  return retorno;
}

/** \brief Busco el mayor ID de la lista
 *
 * \param lista LinkedList* lista de jugadores
 * \param id int* ultimo id
 * \return int retorno 1 si esta todo ok y 0 si hubo un problema
 *
 */
int buscarMayorId(LinkedList* pArrayListJugador, int* id)
{
    int retorno = 0;
    Jugador* auxJugador = NULL;
    int mayor;
    if(pArrayListJugador != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListJugador); i ++)
        {
            auxJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if(i == 0 || auxJugador->id > mayor)
            {
                mayor = auxJugador->id;
            }
        }
        *id = mayor + 1;
        printf("\n\n");
        retorno = 1;
    }
    return retorno;
}

/** \brief Busca un jugador por ID dentro de la lista
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \param id int Id a procurar
 * \return int retorno el indice si esta todo ok -1 si hobo un error
 *
 */
int controller_buscarJugador(LinkedList* pArrayListJugador, int id)
{
    int indice = -1;
    Jugador* jugador;
    if(pArrayListJugador != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListJugador); i ++)
        {
            jugador = (Jugador*) ll_get(pArrayListJugador, i);
            if(jugador!= NULL)
            {
                if(!ll_isEmpty(pArrayListJugador) && jugador->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

/** \brief
 *
 * \param pControl char*
 * \return int
 *
 */
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

/** \brief menu de las posiciones dentro del campo
 *
 * \param posicion[] char vector al que le asigno la posicion
 * \return int retorna 1 si se cargo el archivo -1 si hubo un error 0 si no se eligio una posicion
 *
 */
int menuPosiciones(char posicion[])
{
    int retorno = -1;
    int opcion;
    int respuesta;

    if(posicion != NULL)
    {
        respuesta = utn_getNumero(&opcion,"\n\n*Posiciones:\n1-Portero\n2-Defensa Central\n3-Lateral Izquierdo\n"
                                  "4-Lateral Derecho\n5-Mediocentro\n6-Mediocentro Ofencivo \n7-Pivote\n"
                                  "8-Extremo Izquierdo\n9-Extremo Derecho\n10-Delantero Centro\n7-11-Salir\n"
                                  "Ingrese opcion:\n", "No es una opcion valida\n", 1, 11 , 4);
        printf("\n\n\n\n\n\n");
        if(!respuesta)
        {
            retorno = 1;
            do
            {
              switch(opcion)
              {
                case 1:
                strcpy(posicion, "Portero");
                break;
                case 2:
                strcpy(posicion, "Defensa Central");
                break;
                case 3:
                strcpy(posicion, "Lateral Izquierdo");
                break;
                case 4:
                strcpy(posicion, "Lateral Derecho");
                break;
                case 5:
                strcpy(posicion, "Mediocentro");
                break;
                case 6:
                strcpy(posicion, "Mediocentro Ofencivo");
                break;
                case 7:
                strcpy(posicion, "Pivote");
                break;
                case 8:
                strcpy(posicion, "Extremo Izquierdo");
                break;
                case 9:
                strcpy(posicion, "Extremo Derecho");
                break;
                case 10:
                strcpy(posicion, "Delantero Centro");
                break;
                default:
                    printf("La opcion no existe!\n\n");
                    opcion = 11;
                    retorno = 0;
                break;
              }
            }while(opcion == 11);
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 0 si se genero el alta y -1 si hubo un error
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
  int retorno = -1;
  Jugador* auxJugador = NULL;
  char nombreCompleto[100];
  int nextId = 1;
  int edad;
  char posicion[30];
  char nacionalidad[30];
  int idSeleccion = 0;

  if(pArrayListJugador != NULL)
  {
     buscarMayorId(pArrayListJugador, &nextId);

     printf("Ingrese nombre del jugador: ");
     fflush(stdin);
     gets(nombreCompleto);
     while(strlen(nombreCompleto) >= 100 || atoi(nombreCompleto))
     {
	 fflush(stdin);
	 printf("Error. Ingrese un nombre valido: ");
	 gets(nombreCompleto);
     }

     if(utn_getEnteroSoloNumeros(&edad, 4, "Ingrese la edad: ", "Error. Igrese una edad valida: ", 2) == -1)
     {
	 printf("\nLLego al limite de reintentos!");
     }

     limpiarPantalla();
     printf("Elija la posicion del jugador: ");
     if(!menuPosiciones(posicion))
     {
	 printf("\nProblemas al elegir la posicion!\n");
     }

     printf("Ingrese la nacionalidad del jugador: ");
     fflush(stdin);
     gets(nacionalidad);
     while(strlen(nacionalidad) >= 30 || atoi(nacionalidad))
     {
	 fflush(stdin);
	 printf("Error. Ingrese una nacionalidad valida: ");
	 gets(nacionalidad);
     }

     auxJugador = jug_newParametrosPorTipo(nextId, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
     if(auxJugador != NULL)
     {
	 ll_add(pArrayListJugador, auxJugador);
	 auxJugador = NULL;
	 retorno = 0;
     }

  }
  return retorno;
}

/** \brief Listar de los jugadores
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
  int retorno = 0;
  if(pArrayListJugador != NULL)
  {
      limpiarPantalla();
      printf("========================================================================================================\n");
      printf("|                                       *** lista Jugadores ***                                        |\n");
      printf("========================================================================================================\n");
      printf("|   id   |      Nombre              |  edad  |    posicion          |   nacionalidad    | idSeleccion  |\n");
      printf("========================================================================================================\n");
      for(int i = 0; i < ll_len(pArrayListJugador); i ++)
      {
	      mostrarJugador((Jugador*) ll_get(pArrayListJugador,i));
      }
      if(ll_isEmpty(pArrayListJugador))
      {
	  printf("\n|                                            Lista vacia!                                              |\n\n");
      }
      printf("========================================================================================================\n");
      printf("\n\n");
      retorno = 1;
  }

  return retorno;
}

/** \brief Lista se los convocados
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{
    int retorno = 0;
    Jugador* auxJugador;
    if(pArrayListJugador != NULL)
    {
	limpiarPantalla();
        printf("========================================================================================================\n");
        printf("|                                       *** lista Convocados ***                                       |\n");
        printf("========================================================================================================\n");
        printf("|   id   |      Nombre              |  edad  |    posicion          |   nacionalidad    | idSeleccion  |\n");
        printf("========================================================================================================\n");
        for(int i = 0; i < ll_len(pArrayListJugador); i ++)
        {
            auxJugador = (Jugador*) ll_get(pArrayListJugador,i);
            if(auxJugador->idSeleccion != 0)
            {
                 mostrarJugador(auxJugador);
            }

        }
        if(ll_isEmpty(pArrayListJugador))
        {
            printf("\n|                                             Lista vacia!                                             |\n\n");
        }
        printf("========================================================================================================\n");
        printf("\n\n");
        auxJugador = NULL;
        retorno = 1;
    }

    return retorno;
}

/** \brief menu de modificacion
 *
 * \return int retorna la opcion
 *
 */
int menuModificacion()
{
    int opcion;
    limpiarPantalla();
    printf("Seleccione lo que quiere modificar:    \n \n");
    printf("1- Nombre \n");
    printf("2- edad \n");
    printf("3- posicion \n");
    printf("4- nacionalidad \n");
    printf("Ingrese opcion:  \n");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Modificar datos del jugador
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 1 si se hizo la modificacion -1 si hubo un error y 0 si no se genero la modificacion
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
  int retorno = -1;
  int indice;
  char confirmar;
  int id;
  char auxNombre[100];
  int auxEdad;
  char auxPosicion[50];
  char auxNacionalidad[50];
  Jugador* auxJugador = NULL;

  if(pArrayListJugador != NULL)
  {
      printf("\n      Modificar Jugador     \n");
      printf("     ==================     \n\n");
      controller_listarJugadores(pArrayListJugador);
      printf("Ingrese el ID del jugador: ");
      scanf("%d", &id);
      indice = controller_buscarJugador(pArrayListJugador, id);
      if(indice == -1)
      {
	  printf("ID no registrado en el sistema!");
      }
      else
      {
	  auxJugador = ll_get(pArrayListJugador, indice);
	  mostrarJugador((Jugador*) ll_get(pArrayListJugador,indice));
	  printf("Confirma modificacion? s/n:  ");
	  fflush(stdin);
	  confirmar = tolower(getchar());
	  if(confirmar == 's')
	  {
	      retorno = 1;
	      switch(menuModificacion())
	      {
		case 1:
		    printf("ingrese un nuevo nombre:");
		    fflush(stdin);
		    gets(auxNombre);
		    jug_setNombreCompleto(auxJugador, auxNombre);
		break;
		case 2:
		   if(utn_getEnteroSoloNumeros(&auxEdad, 4, "ingrese la nueva edad:", "Error. Igrese una edad valida: ", 2) == 0)
		   {
		      jug_setEdad(auxJugador, auxEdad);

		   }
		   else
		   {
		     printf("\nLLego al limite de reintentos!");

		   }

		break;
		case 3:
		    printf("\n\nElija una nueva posicion: \n");
		    if(menuPosiciones(auxPosicion))
		    {
			printf("\nSe cambio la posicion con exito!\n");
			jug_setPosicion(auxJugador, auxPosicion);
		    }
		    else
		    {
			printf("\nProblemas al modificar la posicion!\n");
		    }

		break;
		case 4:
		    printf("ingrese un nueva Nacionalidad:");
		    fflush(stdin);
		    gets(auxNacionalidad);
		    while(strlen(auxNacionalidad) >= 50 || atoi(auxNacionalidad))
		    {
			fflush(stdin);
			printf("Error. Ingrese un nacionalida validad: ");
			gets(auxNacionalidad);
		    }
		    strlwr(auxNacionalidad);
		    auxNacionalidad[0] = toupper(auxNacionalidad[0]);
		    jug_setNacionalidad(auxJugador, auxNacionalidad);
		break;
		default:
		    printf("Opcion invalida!\n");
		break;
	      }
	  }
	  else
	  {
	      printf("Modificacion Cancelada! \n");
	      retorno = 0;
	  }
      }
  }
  if(auxJugador != NULL)
  {
      ll_set(pArrayListJugador, indice, auxJugador);
      auxJugador = NULL;
  }
  return retorno;
}

/** \brief Baja del jugador
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 1 si se hizo la baja y 0 si hubo un error
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
  int retorno = 0;
  char confirmar;
  int indice;
  int id;

  if(pArrayListJugador != NULL)
  {
      printf("\n      Baja Alumno     \n");
      printf("     =============     \n\n");
      controller_listarJugadores(pArrayListJugador);
      printf("Ingrese el ID del jugador: ");
      scanf("%d", &id);
      indice = controller_buscarJugador(pArrayListJugador, id);
      if(indice == -1)
      {
          printf("ID no registrado en el sistema!");
      }
      else
      {
          mostrarJugador((Jugador*) ll_get(pArrayListJugador,indice));
          printf("Confirma baja? s/n:  ");
          fflush(stdin);
          confirmar = tolower(getchar());
          if(confirmar == 's')
          {
              ll_remove(pArrayListJugador, indice);
              retorno = 1;
          }
          else
          {
              printf("Baja Cancelada! \n");
          }
      }
  }
  return retorno;
}

/** \brief Ordenar jugadores por edad
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna -1 si hubo un error 0 si se ordeno la lista
 *
 */
int controller_ordenarJugadoresEdad(LinkedList* pArrayListJugador)
{
  int retorno = -1;
  if(pArrayListJugador != NULL)
  {
      for(int i = 0; i < ll_len(pArrayListJugador); i ++)
      {
           ll_sort(pArrayListJugador, Jug_cmEdad, 1);
      }
      retorno = 0;
  }
  return retorno;
}

/** \brief Ordenar jugadores por Nacionalidad
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna -1 si hubo un error 0 si se ordeno la lista
 *
 */
int controller_ordenarJugadoresNacionalidad(LinkedList* pArrayListJugador)
{
  int retorno = -1;
  if(pArrayListJugador != NULL)
  {
      for(int i = 0; i < ll_len(pArrayListJugador); i ++)
      {
           ll_sort(pArrayListJugador, Jug_cmNacionalida, 1);
      }
      retorno = 0;
  }
  return retorno;
}

/** \brief Ordenar jugadores por Nombre
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna -1 si hubo un error 0 si se ordeno la lista
 *
 */
int controller_ordenarJugadoresNombre(LinkedList* pArrayListJugador)
{
  int retorno = -1;
  if(pArrayListJugador != NULL)
  {
      for(int i = 0; i < ll_len(pArrayListJugador); i ++)
      {
           ll_sort(pArrayListJugador, Jug_cmNombre, 1);
      }
      retorno = 0;
  }
  return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char* archivo que quiero escribir
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 0 si se guardo el archivo -1 si hubo un error
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
  int retorno = -1;
  char confirma = 's';
  int i;
  FILE* pFile;
  Jugador* jugador;
  int id;
  char nombreCompleto[100];
  int edad;
  char posicion[30];
  char nacionalidad[30];
  int idSeleccion;

  if(path != NULL && pArrayListJugador != NULL)
  {
     pFile = fopen(path, "r");
     if(pFile != NULL)
     {
       printf("Cuidado! El archivo existe!\n");
       printf("Quiere sobrescribirla? s/n:");
       fflush(stdin);
       confirma = tolower(getchar());
     }
     fclose(pFile);
     if(confirma == 's')
     {
       pFile = fopen(path, "w");
       if(pFile != NULL)
       {
	 fprintf(pFile, "id,Nombre,edad,posicion,nacionalidad,idSeleccion \n");
	 for(i = 0; i < ll_len(pArrayListJugador); i ++)
	 {
	   jugador = (Jugador*) ll_get(pArrayListJugador, i);
	   if(jugador!= NULL)
	   {
	     if(jug_getId(jugador, &id)&&
		jug_getNombreCompleto(jugador, nombreCompleto) &&
		jug_getEdad(jugador, &edad) &&
		jug_getPosicion(jugador, posicion) &&
		jug_getNacionalidad(jugador, nacionalidad) &&
		jug_getIdSeleccion(jugador, &idSeleccion))
		{
		   fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
		   retorno = 0;
		}
		else
		{
		   jugador = NULL;
		   free(jugador);
		   printf("\nOcurrio un error el guardar los datos en el archivo");
		}
	   }
	 }
	 fclose(pFile);
       }
     }
  }
  return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char* archivo que quiero escribir
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \return int retorna 0 si se guardo el archivo -1 si hubo un error
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
  int retorno = -1;
  int i;
  char confirma = 's';
  FILE* pFile;
  Jugador* jugador;

  if(path != NULL && pArrayListJugador != NULL)
  {
      pFile = fopen(path, "rb");
      if(pFile != NULL)
      {
	printf("Cuidado! El archivo existe!\n");
	printf("Quiere sobrescribirla? s/n:");
	fflush(stdin);
	confirma = tolower(getchar());
      }
      fclose(pFile);
      if(confirma == 's')
      {
	pFile = fopen(path, "wb");
	if(pFile != NULL)
	{
	  for(i = 0; i < ll_len(pArrayListJugador); i ++)
	  {
	      jugador = (Jugador*) ll_get(pArrayListJugador, i);
	      if(jugador!= NULL)
	      {
		  fwrite(jugador, sizeof(Jugador), 1, pFile);
	      }
	  }
	  fclose(pFile);
	  retorno = 0;
	}
      }

  }
  return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char* archivo que quiero leer
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 1 si se cargo el archivo -1 si hubo un error
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
  int retorno = -1;
  FILE* pFile;

  if(path != NULL && pArrayListSeleccion != NULL)
  {
      retorno = 0;
      pFile = fopen(path, "r");
      if(pFile != NULL)
      {
	parser_SeleccionFromText(pFile, pArrayListSeleccion);
	retorno = 1;
      }
      fclose(pFile);
  }
  return retorno;
}

/** \brief Busca una Seleccion por ID dentro de la lista
 *
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \param id int Id a procurar
 * \return int retorno el indice si esta todo ok -1 si hubo un error
 *
 */
int controller_buscarSeleccion(LinkedList* pArrayListSeleccion, int id)
{
    int indice = -1;
    Seleccion* seleccion;
    if(pArrayListSeleccion != NULL)
    {
        for(int i = 0; i < ll_len(pArrayListSeleccion); i ++)
        {
            seleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
            if(seleccion!= NULL)
            {
                if(!ll_isEmpty(pArrayListSeleccion) && seleccion->id == id)
                {
                    indice = i;
                    break;
                }
            }
        }
    }
    return indice;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar de las selecciones
 *
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si hubo un error y 1 si esta todo ok
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
  int retorno = 0;
  if(pArrayListSeleccion != NULL)
  {
      limpiarPantalla();
      printf("===================================================================\n");
      printf("|                   ** lista Selecciones ***                      |\n");
      printf("===================================================================\n");
      printf("|   Id   |     Pais           |  Confederacion    |   Convocados  |\n");
      printf("===================================================================\n");
      for(int i = 0; i < ll_len(pArrayListSeleccion); i ++)
      {
	      mostrarSeleccion((Seleccion*) ll_get(pArrayListSeleccion,i));
      }
      if(ll_isEmpty(pArrayListSeleccion))
      {
	  printf("\n|                         Lista vacia!                            |\n\n");
      }
      printf("===================================================================\n");
      printf("\n\n");
      retorno = 1;
  }
  return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si esta todo ok  y -1 si hubo un error
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
  int retorno = -1;
  if(pArrayListSeleccion != NULL)
  {
      for(int i = 0; i < ll_len(pArrayListSeleccion); i ++)
      {
           ll_sort(pArrayListSeleccion, selec_cmConfederacion, 1);
      }
      retorno = 0;
  }
  return retorno;
}
/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char* archivo que quiero escribir
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si se guardo el archivo -1 si hubo un error
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
  int retorno = -1;
  int i;
  char confirma = 's';
  FILE* pFile;
  Seleccion* seleccion;
  int id;
    char pais[30];
    char confederacion[30];
    int convocados;

  if(path != NULL && pArrayListSeleccion != NULL)
  {
      pFile = fopen(path, "r");
      if(pFile != NULL)
      {
	printf("Cuidado! El archivo existe!\n");
	printf("Quiere sobrescribirla? s/n:");
	fflush(stdin);
	confirma = tolower(getchar());
      }
      fclose(pFile);
      if(confirma == 's')
      {
	  pFile = fopen(path, "w");
	  if(pFile != NULL)
	  {
	      fprintf(pFile, "id,Pais,Confederacion,Convocados\n");
	      for(i = 0; i < ll_len(pArrayListSeleccion); i ++)
	      {
		  seleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
		  if(seleccion!= NULL)
		  {
		    if(selec_getId(seleccion, &id)&&
		       selec_getPais(seleccion, pais) &&
		       selec_getConfederacion(seleccion, confederacion) &&
		       selec_getConvocados(seleccion, &convocados))
		       {
			  fprintf(pFile, "%d,%s,%s,%d\n", id, pais, confederacion, convocados);
			  retorno = 0;
		       }
		       else
		       {
			  seleccion = NULL;
			  free(seleccion);
			  printf("\nOcurrio un error el guardar los datos en el archivo");
		       }
		  }
	      }
	      fclose(pFile);
	  }
      }
  }
  return retorno;
}

/** \brief convoca un jugador a una seleccion
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si hubo un error y 1 si se convoco al jugador
 *
 */
int controller_convocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
  int retorno = 0;
  char confirmar;
  int idSeleccion;
  int idJugador;
  int indiceSeleccion;
  int indiceJugador;
  int convocado;
  int seleccionDelJugador;
  Seleccion* auxSeleccion = NULL;
  Jugador* auxJugador = NULL;

  if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
  {
      printf("\n      Convocar Jugador     \n");
      printf("     ==================     \n\n");
      controller_listarSelecciones(pArrayListSeleccion);
      printf("Ingrese el ID de la  Seleccion: ");
      scanf("%d", &idSeleccion);
      indiceSeleccion = controller_buscarSeleccion(pArrayListSeleccion, idSeleccion);
      if(indiceSeleccion == -1)
      {
	      printf("ID no registrado en el sistema!");
      }
      else
      {
	  auxSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);
	  if(auxSeleccion != NULL)
	  {
	      selec_getConvocados(auxSeleccion, &convocado);
	      if(convocado < 26)
	      {
		  controller_listarJugadores(pArrayListJugador);
		  printf("Ingrese el ID del jugador: ");
		  scanf("%d", &idJugador);
		  indiceJugador = controller_buscarJugador(pArrayListJugador, idJugador);
		  if(indiceJugador == -1)
		  {
		      printf("ID no registrado en el sistema!");
		  }
		  else
		  {
		      mostrarJugador((Jugador*) ll_get(pArrayListJugador,indiceJugador));
		      printf("Confirma convocacion? s/n:  ");
		      fflush(stdin);
		      confirmar = tolower(getchar());
		      if(confirmar == 's')
		      {
			  auxJugador = ll_get(pArrayListJugador, indiceJugador);
			  if(auxJugador != NULL)
			  {
			      jug_getIdSeleccion(auxJugador, &seleccionDelJugador);
			      if(seleccionDelJugador == 0)
			      {
				  jug_setIdSeleccion(auxJugador, idSeleccion);
				  selec_setConvocados(auxSeleccion, convocado+1);
				  retorno = 1;
			      }
			      else
			      {
				  printf("El jugador seleccionado ya esta convocado\n");
			      }
			      auxJugador = NULL;
			  }
		      }
		      else
		      {
			  printf("Convocacion Cancelada! \n");
		      }
		  }
	      }
	      else
	      {
		  printf("Esta seleccion llego al limite de convocados\n");
	      }
	      auxSeleccion  = NULL;
	  }
      }

    }
    return retorno;
}
/** \brief quita la convocacion de un jugador
 *
 * \param pArrayListJugador LinkedList* lista de los jugadores
 * \param pArrayListSeleccion LinkedList* lista de las selecciones
 * \return int retorna 0 si hubo un error y 1 si se dio de baja
 *
 */
int controller_quitarConvocado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
  int retorno = 0;
  char confirmar;
  int idJugador;
  int indiceJugador;
  int indiceSeleccion;
  int setearId = 0;
  int convocado;
  int seleccionDelJugador;
  Seleccion* auxSeleccion = NULL;
  Jugador* auxJugador = NULL;
  if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
  {
	  controller_listarJugadoresConvocados(pArrayListJugador);
    printf("Ingrese el ID del jugador: ");
    scanf("%d", &idJugador);
    indiceJugador = controller_buscarJugador(pArrayListJugador, idJugador);
    if(indiceJugador == -1)
    {
	printf("ID no registrado en el sistema!");
    }
    else
    {
       mostrarJugador((Jugador*) ll_get(pArrayListJugador,indiceJugador));
       printf("Confirma baja? s/n:  ");
       fflush(stdin);
       confirmar = tolower(getchar());
       if(confirmar == 's')
       {
	    auxJugador = ll_get(pArrayListJugador, indiceJugador);
	    if(auxJugador != NULL)
	    {
		jug_getIdSeleccion(auxJugador, &seleccionDelJugador);
		if(seleccionDelJugador != 0)
		{
		    indiceSeleccion = controller_buscarSeleccion(pArrayListSeleccion, seleccionDelJugador);
		    if(indiceSeleccion == -1)
		    {
			printf("ID no registrado en el sistema!");
		    }
		    else
		    {
			auxSeleccion = ll_get(pArrayListSeleccion, indiceSeleccion);
			jug_setIdSeleccion(auxJugador, setearId);
			selec_getConvocados(auxSeleccion, &convocado);
			selec_setConvocados(auxSeleccion, convocado-1);
			retorno = 1;
			printf("El jugador ya no esta convocado!\n");
		    }
		}
		else
		{
		    printf("Este jugador  no esta convocado!\n");
		}
	    }
       }
       else
       {
	    printf("Baja de convocacion cancelada!\n");
       }
    }
    if(auxJugador != NULL)
    {
	 auxJugador = NULL;
    }
  }
  return retorno;
}

/** \brief menu principal
 *
 * \return int retorna la opcion elegida
 *
 */
int menu()
{
    int respuesta;
    int opcion;

    respuesta = utn_getNumero(&opcion,"     ABM jugador\n---------------------\n"
				      "1 - Carga de archivos  \n"
				      "2 - Alta de jugador  \n"
				      "3 - Modificar jugador\n"
				      "4 - Baja de jugador \n"
				      "5 - Listado\n"
				      "6 - Convocar Jugadores \n"
				      "8 - Generar archivo binario \n"
				      "9 - Cargar archivo binario \n"
				      "10 - Guardar archivos .CSV \n"
				      "11 - SALIR \nIngrese opcion:\n", "No es una opcion valida\n", 1, 11, 4);
    if(respuesta == -1)
    {
        printf("\nLLego al limite de reintento! \nCerraremos el programa!\n");
        opcion = 11;
    }
    return opcion;
}
/** \brief menu de la lista de ordenamiento
 *
 * \return char retorna la opcion elegida
 *
 */
char menuListadoOrden()
{
    char opcion;
    int respuesta;

    respuesta = utn_getCaracter(&opcion,"*Listado\n---------\n"
					"A) JUGADORES POR NACIONALIDAD.\n"
					"B) SELECCIONES POR CONFEDERACIÓN.\n"
					"C) JUGADORES POR EDAD. \n"
					"D) JUGADORES POR NOMBRE. \n"
					"E) Regrasar al menu principal \n"
					"Ingrese opcion:\n", "No es una opcion valida\n", 'A', 'e', 4);
    opcion = toupper(opcion);
    if(respuesta == -1)
    {
        printf("\nLLego al limite de reintento! \nVolvemos al menu principal!\n");
        opcion = 'E';
    }
    return opcion;
}

/** \brief menu de todos los listados
 *
 * \return char retorna la opcion elegida
 *
 */
char menuListado()
{
    char opcion;
    int respuesta;

    respuesta = utn_getCaracter(&opcion,"*Listado\n---------\n"
					"A) Todos los jugadores.\n"
					"B) Todas las selecciones .\n"
					"C) Jugadores convocados. \n"
					"D) Regrasar al menu principal .\n"
					"Ingrese opcion:\n", "No es una opcion valida\n", 'A', 'd', 4);
    opcion = toupper(opcion);
    if(respuesta == -1)
    {
        printf("\nLLego al limite de reintento! \nVolvemos al menu principal!\n");
        fflush(stdin);
        opcion = 'D';
    }
    return opcion;
}

/** \brief menu de convocar
 *
 * \return char retorna la opcion elegida
 *
 */
char menuCovocados()
{
    char opcion;
    int respuesta;
    respuesta = utn_getCaracter(&opcion,"*Listado\n---------\n"
						      "A) CONVOCAR.\n"
						      "B) QUITAR DE LA SELECCION.\n"
						      "C) Regrasar al menu principal .\n"
						      "Ingrese opcion:\n", "No es una opcion valida\n", 'A', 'c', 4);
    opcion = toupper(opcion);
    if(respuesta == -1)
    {
        printf("\nLLego al limite de reintento! \nVolvemos al menu principal!\n");
        fflush(stdin);
        opcion = 'C';
    }
    return opcion;
}
