/*
 ============================================================================
 Name        : TP1.c
 Author      : Pablo Toledo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int main(void)
{
    setbuf(stdout, NULL);

    char seguir = 'n';
    int retorno;
    float ingresoCosto;
    int numeroCamiseta;
    float acumHospedaje = 0;
    float acumComida = 0;
    float acumTransporte = 0;
    int contadorArquero = 0;
    int contadorDefensor = 0;
    int contadorMediocampo = 0;
    int contadorDelantero = 0;
    int iAfc = 0;
    int iCaf = 0;
    int iConcacaf = 0;
    int iConmebol = 0;
    int iUefa = 0;
    int iOfc = 0;
    int flagCarga = 0;
    int flagCosto = 0;
    int flagCalculos = 0;
    int flagAumento = 0;
    float costoTotal;
    float aumento;
    int contadorJugadores = 0;
    int flagAfc = 0;
    int flagCaf = 0;
    int flagConcacaf = 0;
    int flagConmebol = 0;
    int flagUefa = 0;
    int flagOfc = 0;
    int sumaFlag;
    int sumaConfederaciones;

    do
    {
        switch (menu())
        {
            case 1:
		if(utn_getFloatPositivo(&ingresoCosto, 7,"\nIngrese el precio del costo: ", "Error. Igrese un precio del costo valido!", 4) == 0)
		{
		   printf("\nElija la opcion de la cual se debe ese costo: \n");
		   switch(subMenuCostos(acumHospedaje, acumComida, acumTransporte))
		   {
		     case 1:
			 acumHospedaje += ingresoCosto;
		     break;
		     case 2:
			 acumComida += ingresoCosto;
		     break;
		     case 3:
			acumTransporte += ingresoCosto;
		     break;
		     default:
		       limpiarPantalla();
		       printf("\nOpcion invalida!\nNo se registro el costo! \n");
		     break;
		   }
		   if(acumHospedaje > 0 || acumComida > 0 || acumTransporte > 0)
		   {
		       flagCosto = 1;
		   }
		}
		else
		{
		    limpiarPantalla();
		    printf("\nLLego al limite de reintentos!\nNo se pudo hacer el ingreso del costo! \n\n");
		}
            break;
            case 2:
            	limpiarPantalla();
                switch (subMenuPosicion(contadorArquero, contadorDefensor, contadorMediocampo, contadorDelantero))
                {
                    case 1:
                        retorno = validarLimite(&contadorArquero, contadorArquero, 2);
                    break;
                    case 2:
                        retorno = validarLimite(&contadorDefensor, contadorDefensor, 8);
                    break;
                    case 3:
                        retorno = validarLimite(&contadorMediocampo ,contadorMediocampo , 8);
                    break;
                    case 4:
                        retorno = validarLimite(&contadorDelantero, contadorDelantero, 4);
                    break;
                    default:
                    	mensajeError();
		    break;
		}
		limpiarPantalla();
		if(retorno == 0)
		{
		    printf("se llego al limite de ingresos!\n");
		}
		else
		{
		    switch(subMenuConfederacion())
		    {
		      case 1:
			      iAfc ++;
			      flagAfc = 1;
		      break;
		      case 2:
			      iCaf ++;
			      flagCaf = 1;
		      break;
		      case 3:
			      iConcacaf ++;
			      flagConcacaf = 1;
		      break;
		      case 4:
			      iConmebol ++;
			      flagConmebol = 1;
		      break;
		      case 5:
			      iUefa ++;
			      flagUefa = 1;
		      break;
		      case 6:
			      iOfc ++;
			      flagOfc = 1;
		      break;
		      default:
			      mensajeError();
		      break;
		    }
		    limpiarPantalla();
		    printf("\nIngrese el numero de camiseta: ");
		    scanf("%d", &numeroCamiseta);
		    if(contadorJugadores > 14)
		    {
		    flagCarga = 1;
		    }
		    contadorJugadores ++;
		}
            break;
            case 3:
		if(validarFlagCalculos(&flagCarga,&flagCosto,&flagCalculos))
		{
		  sumaConfederaciones = iAfc + iCaf + iConcacaf + iConmebol + iUefa + iOfc ;
		  sumaFlag = flagAfc + flagCaf + flagConcacaf + flagConmebol + flagUefa + flagOfc;
		  calcularPromedio(sumaConfederaciones, sumaFlag);
		  costoTotal = acumHospedaje + acumComida + acumTransporte;
		  if(iUefa > iAfc && iUefa > iCaf && iUefa > iConcacaf && iUefa > iConmebol && iUefa > iOfc)
		  {
		    aumento = costoTotal + (costoTotal * 35)/100;
		    flagAumento = 1;
		  }
		}
	    break;
            case 4:
            	if(validarFlagResultado(&flagCalculos))
		{
		  printf("a) El promedio de jugadores es: %.2f\n",  calcularPromedio(sumaConfederaciones, sumaFlag));
		  printf("b) El costo de mantenimiento es: %.2f\n", costoTotal);

		  if(flagAumento)
		  {
			   printf("c)Al completar el aquipo con la mayor parte de jugadores de la UEFA\n");
			   printf("el mantenimiento recibe un aumento del 35 con un total de:  $%.2f\n", aumento);
		  }
		}
            break;
            case 5:
                confirmarSalida(&seguir);
            break;
            default:
            	mensajeError();
            break;
        }
        system("pause");
    }while(seguir == 'n');

	return EXIT_SUCCESS;
}
