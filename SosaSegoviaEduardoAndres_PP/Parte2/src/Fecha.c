/*
 * Fecha.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include "Fecha.h"


int Fecha_verificar(eFecha fecha )
{
int retorno=-1;
if ( fecha.mes >= 1 && fecha.mes <= 12 )
  {
      switch ( fecha.mes )
      {
          case  1 :
          case  3 :
          case  5 :
          case  7 :
          case  8 :
          case 10 :
          case 12 : if ( fecha.dia >= 1 && fecha.dia <= 31 )
        	  retorno = 1;
                    break;

          case  4 :
          case  6 :
          case  9 :
          case 11 : if ( fecha.dia >= 1 && fecha.dia <= 30 )
        	  retorno = 1;
                    break;

          case  2 : if (( fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || fecha.anio % 400 == 0 )
                    {
                        if ( fecha.dia >= 1 && fecha.dia <= 29 )
                        	retorno = 1;
                    }
                    else
                        if ( fecha.dia >= 1 && fecha.dia <= 28 )
                        	retorno = 1;
      }
  }
return retorno;
}

int Fecha_pedir(eFecha *fecha, int cantidadIntentosPermitidos)
{
	int retorno =-1;
	int intentos=0;
	int datos[3];
eFecha auxFecha;
	do
	{
		datos[0]=pedirEntero(&auxFecha.dia, "Ingrese el dia de estadia\n", "Dia invalido reingrese\n", 1, 31,1);
		if(datos[0]==1)
		{
			datos[1]=pedirEntero(&auxFecha.mes, "Ingrese el mes de estadia\n", "Mes invalido reingrese\n", 1, 12,1);
		}
		if(datos[1]==1)
		{
			datos[2]=pedirEntero(&auxFecha.anio, "Ingrese el anio de estadia\n", "Anio invalido reingrese\n", 2021, 3000,1);
		}
		intentos++;
		if(Fecha_verificar(auxFecha)!=1&&intentos<cantidadIntentosPermitidos)
		{

			printf("Fecha invalida, retomando datos intentos restantes %d \n",cantidadIntentosPermitidos-intentos);
		}
		else if(Fecha_verificar(auxFecha)!=1&&intentos==cantidadIntentosPermitidos)
		{
			printf("Se acabaron los reintentos saliendo\n");
		}

	}while(Fecha_verificar(auxFecha)!=1&&intentos<cantidadIntentosPermitidos);

	if(Fecha_verificar(auxFecha)==1)
	{
		*fecha=auxFecha;
		retorno=1;
	}

	return retorno;
}

void Fecha_print(eFecha fecha)
{
	printf("%d/%d/%d ", fecha.dia,fecha.mes,fecha.anio);
}

int Fecha_comparacion(eFecha fecha1,eFecha fecha2)
{
	int retorno =-1;

		if(fecha1.anio>fecha2.anio)
			{
				retorno=1;
			}
			else if(fecha1.anio==fecha2.anio&&fecha1.mes>fecha2.mes)
			{
				retorno=1;
			}
			else if(fecha1.anio==fecha2.anio&&fecha1.mes==fecha2.mes&&fecha1.dia>fecha2.dia)
			{
				retorno=1;
			}
			else if(fecha1.anio==fecha2.anio&&fecha1.mes==fecha2.mes&&fecha1.dia==fecha2.dia)
			{
				retorno=0;
			}
			else
			{
				retorno=2;
			}


	return retorno;
}
