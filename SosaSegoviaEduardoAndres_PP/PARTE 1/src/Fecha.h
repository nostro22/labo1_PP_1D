/*
 * Fecha.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"
#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

int verificarFecha(eFecha fecha )
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




#endif /* FECHA_H_ */
