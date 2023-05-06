#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"

/** \brief consigo lugar en memoria
 *
 * \return Seleccion* retorno ese espacio conseguido
 *
 */
Seleccion* selec_new()
{
    Seleccion* auxP = NULL;
    auxP = (Seleccion*) malloc(sizeof(Seleccion));
    return auxP;
}

/** \brief creo un nueva seleccion
 *
 * \param idStr char* id de la seleccion
 * \param paisStr char* pais
 * \param confederacionStr char* confederacion de la seleccion
 * \param convocadosStr char*  convocados por seleccion
 * \return Seleccion* retorno al mueva seleccion creada
 *
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
    Seleccion* this = NULL;
    this = selec_new();
    if(this != NULL)
    {
        this->id = atoi(idStr);
        strcpy(this->pais, paisStr);
        strcpy(this->confederacion, confederacionStr);
        if(selec_setConvocados(this, atoi(convocadosStr)) == -1)
        {
            selec_delete(this);
            this = NULL;
        }
    }
    return this;
}

/** \brief Le hago un free a la seleccion
 *
 * \param this Seleccion* puntero de la seleccion
 * \return void
 *
 */
void selec_delete(Seleccion* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

/** \brief Getter de id
 *
 * \param this Seleccion* puntero de la seleccion
 * \param id int* variable que guarda el id
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int selec_getId(Seleccion* this,int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

/** \brief Getter del pais
 *
 * \param this Seleccion* puntero de la seleccion
 * \param pais char* variable que guarda el pais
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int selec_getPais(Seleccion* this,char* pais)
{
    int retorno = 0;
    if(this != NULL && pais != NULL)
    {
        strcpy(pais, this->pais);
        retorno = 1;
    }
    return retorno;
}

/** \brief Getter de confederacion
 *
 * \param this Seleccion* puntero de la seleccion
 * \param confederacion char* variable que guarda la confederacion
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int selec_getConfederacion(Seleccion* this,char* confederacion)
{
    int retorno = 0;
    if(this != NULL && confederacion != NULL)
    {
        strcpy(confederacion, this->confederacion);
        retorno = 1;
    }
    return retorno;
}

/** \brief Setter de convocados
 *
 * \param this Seleccion* puntero de la seleccion
 * \param convocados int convocado que cargo
 * \return int retorno 0 si esta todo ok - 1 si hubo un problema
 *
 */
int selec_setConvocados(Seleccion* this,int convocados)
{
    int retorno = -1;
    if(this != NULL && convocados >= 0)
    {
        this->convocados = convocados;
        retorno = 0;
    }
    return retorno;
}

/** \brief  Getter de convocados
 *
 * \param this Seleccion* puntero de la seleccion
 * \param convocados int* variable que guarda convocados
 * \return int retorno 1 si esta todo ok 0 si hubo un problema
 *
 */
int selec_getConvocados(Seleccion* this,int* convocados)
{
    int retorno = 0;
    if(this != NULL && convocados != NULL)
    {
        *convocados = this->convocados;
        retorno = 1;
    }
    return retorno;
}

/** \brief  muestro una seleccion
 *
 * \param this Seleccion* puntero de la seleccion
 * \return int retorno 0 si esta todo ok -1 si hubo un problema
 *
 */
int mostrarSeleccion(Seleccion* this)
{
    int retorno = -1;
    int id;
    char pais[30];
    char confederacion[30];
    int convocados;

    if(this != NULL)
    {
        if(selec_getId(this, &id)&&
           selec_getPais(this, pais) &&
           selec_getConfederacion(this, confederacion) &&
           selec_getConvocados(this, &convocados))
           {
               printf("|  %4d  |  %-14s    |    %-10s     |       %d       |\n", id, pais, confederacion, convocados);
               retorno = 0;
           }

    }
    return retorno;
}
