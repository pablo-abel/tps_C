#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jugador.h"

/** \brief consigo lugar en memoria
 *
 * \return Jugador* retorno ese espacio conseguido
 *
 */
Jugador* jug_new()
{
    Jugador* auxP = NULL;
    auxP = (Jugador*) malloc(sizeof(Jugador));
    return auxP;
}

/** \brief creo un nuevo jugador
 *
 * \param idStr char* id del jugador
 * \param nombreCompletoStr char* nombre completo del jugador
 * \param edadStr char* edad del jugador
 * \param posicionStr char* posicion del jugador
 * \param nacionalidadStr char* nacionalidad del jugador
 * \param idSelccionStr char* id de la seleccion que lo convoque
 * \return Jugador* retorno al muevo jugador creado
 *
 */
Jugador* jug_newParametros(char* idStr, char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
  Jugador* this = NULL;
  this = jug_new();
  if(this != NULL)
  {
    if(jug_setId(this, atoi(idStr)) == -1 ||
       jug_setNombreCompleto(this, nombreCompletoStr) == -1 ||
       jug_setEdad(this, atoi(edadStr)) == -1 ||
       jug_setPosicion(this, posicionStr) == -1 ||
       jug_setNacionalidad(this, nacionalidadStr) == -1 ||
       jug_setIdSeleccion(this, atoi(nacionalidadStr)) == -1)
    {
	jug_delete(this);
	this = NULL;
    }

  }
  return this;
}
/** \brief
 *
 * \param id int id del jugador
 * \param nombreCompletoStr char* nombre completo del jugador
 * \param edad int  edad del jugador
 * \param posicionStr char* posicion del jugador
 * \param nacionalidadStr char* nacionalidad del jugador
 * \param idSelccion int id de la seleccion que lo convoque
 * \return Jugador* retorno al muevo jugador creado
 *
 */
Jugador* jug_newParametrosPorTipo(int id, char* nombreCompletoStr,int edad, char* posicionStr, char* nacionalidadStr, int idSelccion)
{
    Jugador* this = NULL;
    this = jug_new();
    if(this != NULL)
    {
        if(jug_setId(this, id) == -1 ||
           jug_setNombreCompleto(this, nombreCompletoStr) == -1 ||
           jug_setEdad(this, edad) == -1 ||
           jug_setPosicion(this, posicionStr) == -1 ||
           jug_setNacionalidad(this, nacionalidadStr) == -1 ||
           jug_setIdSeleccion(this, idSelccion) == -1)
        {
            jug_delete(this);
            this = NULL;
        }

    }
    return this;
}

/** \brief Le hago un free al jugador
 *
 * \param this Jugador* puntero del jugador
 * \return void
 *
 */
void jug_delete(Jugador* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Setter de id
 *
 * \param this Jugador* puntero del jugador
 * \param id int id que cargo
 * \return int retorno 0 si esta todo ok - 1 si hubo un problema
 *
 */
int jug_setId(Jugador* this, int id)
{
    int retorno = -1;
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter de id
 *
 * \param this Jugador* puntero del jugador
 * \param id int* variable que guarda el id
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getId(Jugador* this, int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter del nombre completo
 *
 * \param this Jugador* puntero del jugador
 * \param nombreCompleto char* Nombre Completo que cargo
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int jug_setNombreCompleto(Jugador* this, char* nombreCompleto)
{
    int retorno = -1;
    int i = 0;
    char auxCadena[100];
    if(this != NULL && nombreCompleto != NULL && strlen(nombreCompleto) < 100 && strlen(nombreCompleto) > 2)
    {
        strcpy(auxCadena, nombreCompleto);
        strlwr(auxCadena);
        auxCadena[0] = toupper(auxCadena[0]);
        while(auxCadena[i] != '\0')
        {
            if(auxCadena[i] == ' ')
            {
                auxCadena[i + 1] = toupper(auxCadena[i + 1]);
            }
            i++;
        }
        strcpy(this->nombreCompleto, auxCadena);
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter del nombre completo
 *
 * \param this Jugador* puntero del jugador
 * \param nombreCompleto char* variable que guarda el nombre completo
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getNombreCompleto(Jugador* this, char* nombreCompleto)
{
    int retorno = 0;
    if(this != NULL && nombreCompleto != NULL)
    {
        strcpy(nombreCompleto, this->nombreCompleto);
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter de la posicion
 *
 * \param this Jugador* puntero del jugador
 * \param posicion char* posicion que cargo
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int jug_setPosicion(Jugador* this,char* posicion)
{
    int retorno = -1;
    char auxCadena[30];
    if(this != NULL && posicion != NULL && strlen(posicion) < 30 && strlen(posicion) > 2)
    {
        strcpy(auxCadena, posicion);
        strlwr(auxCadena);
        auxCadena[0] = toupper(auxCadena[0]);
        strcpy(this->posicion, auxCadena);
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter de la posicion
 *
 * \param this Jugador* puntero del jugador
 * \param posicion char* variable que guarda la posicion
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getPosicion(Jugador* this,char* posicion)
{
    int retorno = 0;
    if(this != NULL && posicion != NULL)
    {
        strcpy(posicion, this->posicion);
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter de la nacionalidad
 *
 * \param this Jugador* puntero del jugador
 * \param nacionalidad char* nacionalidad que cargo
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
    int retorno = -1;
    char auxCadena[30];
    if(this != NULL && nacionalidad != NULL && strlen(nacionalidad) < 30 && strlen(nacionalidad) > 2)
    {
        strcpy(auxCadena, nacionalidad);
        strlwr(auxCadena);
        auxCadena[0] = toupper(auxCadena[0]);
        strcpy(this->nacionalidad, auxCadena);
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter de la nacionalidad
 *
 * \param this Jugador* puntero del jugador
 * \param nacionalidad char* variable que guarda la nacionalidad
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getNacionalidad(Jugador* this, char* nacionalidad)
{
    int retorno = 0;
    if(this != NULL && nacionalidad != NULL)
    {
        strcpy(nacionalidad, this->nacionalidad);
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter de la edad
 *
 * \param this Jugador* puntero del jugador
 * \param edad int edad que cargo
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int jug_setEdad(Jugador* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 16)
    {
        this->edad = edad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter de la edad
 *
 * \param this Jugador* puntero del jugador
 * \param edad int* variable que guarda la edad
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getEdad(Jugador* this, int* edad)
{
    int retorno = 0;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter del Id de la seleccion
 *
 * \param this Jugador* puntero del jugador
 * \param idSeleccion int id de la seleccion que cargo
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int jug_setIdSeleccion(Jugador* this, int idSeleccion)
{
    int retorno = -1;
    if(this != NULL && idSeleccion >= 0)
    {
        this->idSeleccion = idSeleccion;
        retorno = 0;
    }
    return retorno;
}

/** \brief Getter del Id de la seleccion
 *
 * \param this Jugador* puntero del jugador
 * \param idSeleccion int* variable que guarda el id de la seleccion
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int jug_getIdSeleccion(Jugador* this, int* idSeleccion)
{
    int retorno = 0;
    if(this != NULL && idSeleccion != NULL)
    {
        *idSeleccion = this->idSeleccion;
        retorno = 1;
    }
    return retorno;
}

/** \brief saltos de linea para "limpiae la pantalla"
 *
 * \return void
 *
 */
void limpiarPantalla()
{
    for(int i = 0; i < 10; i ++)
    {
        printf("\n");
    }
}

/** \brief muestro un jugador
 *
 * \param this Jugador* puntero del jugador
 * \return int retorno -1 si hubo un error y 0 si esta todo ok
 *
 */
int mostrarJugador(Jugador* this)
{
    int retorno = -1;
    int id;
    char nombreCompleto[100];
    int edad;
    char posicion[30];
    char nacionalidad[30];
    int idSeleccion;

    if(this != NULL)
    {
        if(jug_getId(this, &id)&&
           jug_getNombreCompleto(this, nombreCompleto) &&
           jug_getEdad(this, &edad) &&
           jug_getPosicion(this, posicion) &&
           jug_getNacionalidad(this, nacionalidad) &&
           jug_getIdSeleccion(this, &idSeleccion))
           {
               printf("|  %4d  |  %-24s|   %d   |  %-20s|  %-16s |      %d       |\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
               retorno = 0;
           }
    }
    return retorno;
}
