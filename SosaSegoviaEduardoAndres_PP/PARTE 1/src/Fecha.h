/*
 * Fecha.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "INPUTS.h"

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

/**
 * @fn int Fecha_verificar(eFecha)
 * @brief Verifica que la fecha recibida como parametro sea un fecha posible en el calendario
 * @param fecha estructura que consta de tres int para definir fecha int dia,mes,anio
 * @return retorna -1 si la fecha contiene errores, 1 si es una fecha aceptable
 */
int Fecha_verificar(eFecha fecha);

/**
 * @fn int Fecha_pedir(eFecha*, int)
 * @brief Pide una fecha por parte verificando errores,
 * @param fecha estructura que consta de tres int para definir fecha int dia,mes,anio
 * @param cantidadIntentosPermitidos si se superan la cantidad de intentos se sale de las verificacion y termina la funcion
 * @return -1 si contenia errores o se superaron la cantidad de intentos, 1 si fue exitosa la fecha obtenida
 */
int Fecha_pedir(eFecha* fecha, int cantidadIntentosPermitidos);
/**
 * @fn void Fecha_print(eFecha)
 * @brief Imprime una fecha siguiendo la estructura dia/mes/año
 * @param fecha  estructura que consta de tres int para definir fecha int dia,mes,anio
 */
void Fecha_print(eFecha fecha);

/**
 * @fn int Fecha_comparacion(eFecha, eFecha)
 * @brief Compara dos fechas que y las compara retornando mayor, menor o igual
 * @param fecha1 estructura que consta de tres int para definir fecha int dia,mes,anio
 * @param fecha2 estructura que consta de tres int para definir fecha int dia,mes,anio
 * @return 1 si uno es mayor que dos 0 si son iguales las fechas 2 si esta es nayor que fecha uno y -1 si hubo algun error
 */
int Fecha_comparacion(eFecha fecha1,eFecha fecha2);

#endif /* FECHA_H_ */
