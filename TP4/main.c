#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include <time.h>
#include "mascota.h"
#include "comparisons.h"

void valor(void* m);
void asignarGenero(void* peli);

int main()
{
    srand(time(NULL));
    eMascota* auxMascota;

    LinkedList* lista = ll_newLinkedList();
    if(lista == NULL)
    {
      printf("No se pudo crear el linkedList");
      exit(1);
    }
    // creo las mascotas
    auxMascota = new_MascotaParam(123, "pancho", 0, 'm');
    ll_add(lista, auxMascota);
    auxMascota = new_MascotaParam(124, "sirius", 0, 'm');
    ll_add(lista, auxMascota);
    auxMascota = new_MascotaParam(125, "perrito", 0, 'm');
    ll_add(lista, auxMascota);
    auxMascota = new_MascotaParam(126, "dalila", 0, 'h');
    ll_add(lista, auxMascota);
    auxMascota = new_MascotaParam(127, "emma", 0, 'h');
    ll_add(lista, auxMascota);
    auxMascota = new_MascotaParam(129, "preta", 0, 'h');
    ll_add(lista, auxMascota);
    // mustro la lista
    mostrarMascotas(lista);
    LinkedList* listaMap = ll_map(lista, valor);
    mostrarMascotas(listaMap);
    LinkedList* listaRango = ll_map(lista, asignarGenero);
    mostrarMascotas(listaRango);
    printf("Cantidad mascotas: %d\n\n", ll_len(lista));
    // mustro la lista filtrada con solos mascotas machos
    printf("\nMascotas machos:\n");
    LinkedList* listaFiltrada = ll_filter(lista, esMacho);
    mostrarMascotas(listaFiltrada);
    //muestro a la mascota uqe esta en la posicion 3 (dalila)
    printf("Mascota en la posicion 3(cuarta de la lista):\n");
    mostrarMascota((eMascota*) ll_get(lista, 3));

    // ahora a firulais la quiero agregar en el medio
    auxMascota = new_MascotaParam(128, "firulais", 0, 'h');
    ll_push(lista, 2, auxMascota);
    // ahora firulais esta tercera en la lista
    printf("\nLista mascota con firulais agregada:\n");
    mostrarMascotas(lista);

    ll_remove(lista, 2);// elimino a firulais
    printf("Elimino a firulais: \n");
     mostrarMascotas(lista);
    // contrario al push
    auxMascota = (eMascota*) ll_pop(lista, 5);// elimino al que este en esa posicion
    printf("Muestro a preta: \n");
    mostrarMascota(auxMascota);
    printf("\nElimino a preta: \n");
    mostrarMascotas(lista);
    //ordeno la lista por id
    ll_sort(lista, mascCmId, 1);
    printf("\nOrdeno por Id: \n");
    mostrarMascotas(lista);
    // creo una nueva lista con 3 de los nodos de la primera lista
    LinkedList* lista2 = ll_subList(lista, 2, 4);
    printf("\nMuestro segunda lista: \n");
    mostrarMascotas(lista2);
    // modifico los datos de perrito, en este caso solo el nombre
    auxMascota = new_MascotaParam(125, "pichono", 0, 'm');
    ll_set(lista, 2, auxMascota);
    printf("\nModifique a perrito: \n");
    mostrarMascotas(lista);

    // elimino los elementos de esta lista
    ll_clear(lista2);
    printf("\nelimino la lista 2: \n");
    mostrarMascotas(lista2);
     printf("\nY ahora quiero saber si la lista esta vacia!\n");
    if(ll_isEmpty(lista2))
    {
        printf("La lista esta vacia!\n");
    }

    printf("\n-------------------------------------------------");
    printf("\nQuiero saber si la lista contiene elementos");
    printf("\nSi retorno me devuelve 1 es porque hay elementos: \n");
    printf("retorno: %d \n", ll_contains(lista, auxMascota));
    printf("-------------------------------------------------\n");

    LinkedList* lista3 = ll_clone(lista);
    printf("\nMuetro la lista clonada: \n");
    mostrarMascotas(lista3);

    printf("\n----------------------------------------------------");
    printf("\nQuiero saber si los elementos de la lista estan");
    printf("\ncontenidas en la lista 3!\n");
    printf("Si retorno me devuelve 1 es porque estan contenidos:\n");
    printf("retorno: %d \n", ll_containsAll(lista, lista3));
    printf("----------------------------------------------------\n");

    printf("\n---------------------------------------------------------------------------");
    printf("\nBusca el indice de la primer ocurrencia del elemento pasado como parametro");
    printf("\nSi esta todo bien el  retorno me devuelve el indice del elemento:\n");
    printf("retorno: %d \n", ll_indexOf(lista, auxMascota));
    printf("---------------------------------------------------------------------------\n");

    // elimino los elementos de esta lista y la lista
    ll_deleteLinkedList(lista);

    return 0;
}


void valor(void* m)
{
    eMascota* unaMascota = NULL;//casteo
    if(m != NULL)//valido por que si viene NULL y queremos acceder al campo se cuelga la maquina
    {
        unaMascota = (eMascota*) m; // casteo
        if(unaMascota->edad == 0)
        {
            unaMascota->edad = rand() % 10 + 1;

        }
    }
}

void asignarGenero(void* peli)
{
     eMascota* unaMascota = NULL;
     int rango;
    if(peli != NULL)
    {
        unaMascota = (eMascota*) peli;
        rango = rand() % 4 + 1;

        if(rango == 1)
        {
            printf("\nNumero: %d\n", rango);
            strcpy(unaMascota->nombre, "Drama");

        }
        else if(rango == 2)
        {
            printf("\nNumero: %d\n", rango);
            strcpy(unaMascota->nombre, "Comedia");
        }
        else if(rango == 3)
        {
            printf("\nNumero: %d\n", rango);
            strcpy(unaMascota->nombre, "Accion");
        }
        else
        {
            printf("\nNumero: %d\n", rango);
            strcpy(unaMascota->nombre, "Terror");
        }
    }
}















