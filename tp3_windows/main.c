#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"

int main()
{
    setbuf(stdout,NULL);
    int option = 0;
    char archivo[20];
    char optionListado;
    char optionConvocados;
    char optionOrden;
    char confirmar;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    if(listaJugadores == NULL)
    {
        printf("No se pudo crear el linkedList");
    }

    do{
	switch(menu())
	{
	    case 1:
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.csv) de los Jugadores:\n", "no es un archivo\n", 4);
		if(controller_cargarJugadoresDesdeTexto(archivo,listaJugadores) == 1)
		{
		    printf("carga de archivos exitosa!\n");
		}
		else
		{
		   printf("No se pudo cargar el archivo de jugadores\n");
		}
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.csv) de las Selecciones:\n", "no es un archivo\n", 4);
		if( controller_cargarSeleccionesDesdeTexto(archivo, listaSelecciones) == 1)
		{
		    printf("carga de archivos exitosa!\n");
		}
		else
		{
		   printf("No se pudo cargar el archivo de las selecciones\n");
		}
	    break;
	    case 2:
		if(!controller_agregarJugador(listaJugadores))
		{
		    printf("Alta del jugador exitosa!\n");

		}
		else
		{
		   printf("Problemas al generar el alta!\n");
		}
	    break;
	    case 3:
		controller_editarJugador(listaJugadores);
	    break;
	    case 4:
	       if(controller_removerJugador(listaJugadores))
		{
		    printf("Baja del jugador exitosa!\n");

		}
		else
		{
		   printf("Problemas al generar la baja!\n");
		}
	    break;
	    case 5:
		do
		{
		    switch(menuListado())
		    {
			case 'A':
			    controller_listarJugadores(listaJugadores);
			break;
			case 'B':
			    controller_listarSelecciones(listaSelecciones);
			break;
			case 'C':
			    controller_listarJugadoresConvocados(listaJugadores);
			break;
			case 'D':
			     if(confirmarSalida(&confirmar))
			     {
				optionListado = 'D';
			     }
			break;
		    }

		}while(optionListado != 'D');
	    break;
	    case 6:
		do
		{
		    switch(menuCovocados())
		    {
			case 'A':
			    controller_convocarJugador(listaJugadores, listaSelecciones);
			break;
			case 'B':
			    controller_quitarConvocado(listaJugadores, listaSelecciones);
			break;
			case 'C':
			     if(confirmarSalida(&confirmar))
			     {
				optionConvocados = 'C';
			     }
			break;
		    }

		}while(optionConvocados != 'C');
	    break;
	    case 7:
		do
		{
		    switch(menuListadoOrden())
		    {
			case 'A':
			  if(controller_ordenarJugadoresNacionalidad(listaJugadores) == -1)
			  {
			      printf("Problemas al ordenar!");
			  }
			  else
			  {
			       controller_listarJugadores(listaJugadores);
			  }
			break;
			case 'B':
			    if(controller_ordenarSelecciones(listaSelecciones) == -1)
			    {
				printf("Problemas al ordenar!");
			    }
			    else
			    {
				controller_listarSelecciones(listaSelecciones);
			    }
			break;
			case 'C':
			    if(controller_ordenarJugadoresEdad(listaJugadores) == -1)
			    {
				printf("Problemas al ordenar!");
			    }
			    else
			    {
				 controller_listarJugadores(listaJugadores);
			    }
			break;
			case 'D':
			  if(controller_ordenarJugadoresNombre(listaJugadores) == -1)
			  {
			      printf("Problemas al ordenar!");
			  }
			  else
			  {
			       controller_listarJugadores(listaJugadores);
			  }
			break;
			case 'E':
			     if(confirmarSalida(&confirmar))
			     {
				optionOrden = 'E';
			     }
			break;
		    }
		}while(optionOrden != 'E');
	    break;
	    case 8:
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.bin) de los Jugadores:\n", "no es un archivo\n", 4);
		if(controller_guardarJugadoresModoBinario(archivo, listaJugadores) == 0)
		{
		    printf("guardado del archivos exitosa!\n");
		}
		else
		{
		   printf("No se pudo guardar el archivo.bin de jugadores\n");
		}
	    break;
	    case 9:
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.bin) de los Jugadores:\n", "no es un archivo\n", 4);
		if(controller_cargarJugadoresDesdeBinario(archivo,listaJugadores) == 1)
		{
		    printf("carga de archivos exitosa!\n");

		}
		else
		{
		   printf("No se pudo cargar el archivo de jugadores\n");
		}
	    break;
	    case 10:
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.csv) de los Jugadores:\n", "no es un archivo\n", 4);
		if(controller_guardarJugadoresModoTexto(archivo, listaJugadores) == 0)
		{
		    printf("guardado del archivos exitosa!\n");
		}
		else
		{
		   printf("No se pudo guardar el archivo.csv de jugadores\n");
		}
		utn_getArchivo(archivo, 20, "Ingrese nombre del archivo(.csv) de las selecciones:\n", "no es un archivo\n", 4);
		if(controller_guardarSeleccionesModoTexto(archivo, listaSelecciones) == 0)
		{
		    printf("guardado del archivos exitosa!\n");
		}
		else
		{
		   printf("No se pudo guardar el archivo.csv de las selecciones\n");
		}
	    break;
	    case 11:
		if(confirmarSalida(&confirmar))
		{
		      option = 11;
		}
	    break;
	}
    }while(option != 11);

    return 0;
}


