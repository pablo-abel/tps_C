#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);
Jugador* jug_newParametrosPorTipo(int id, char* nombreCompletoStr,int edad, char* posicionStr, char* nacionalidadStr, int idSelccion);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_setIdTxt(Jugador* this, char* id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_setEdadTxt(Jugador* this, char* edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_setIdSeleccionTxt(Jugador* this, char* idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

int mostrarJugador(Jugador* this);

#endif // jug_H_INCLUDED

void limpiarPantalla();
