/*
 * EstadiaDiaria.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"
#include "Perro.h"
#include "Fecha.h"
#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

typedef struct
{
	int id;
	char nombreDuenio[21];
	int telefonoContacto;
	int idPerro;
	eFecha fecha;
	int isEmpty;
}eEstadiaDiaria;

int EstadiaDiaria_initLista(eEstadiaDiaria list[], int len);
int EstadiaDiaria_addPerro(eEstadiaDiaria list[], int len, int id, char nombreduenio[],int telefonoContacto, int idPerro, eFecha fecha);
int EstadiaDiaria_buscarEspacioLibre(eEstadiaDiaria list[], int tam);
int EstadiaDiaria_findById(eEstadiaDiaria list[], int len,int id);
int EstadiaDiaria_removePerro(eEstadiaDiaria list[], int len, int id);
int EstadiaDiaria_printLista(eEstadiaDiaria list[], int length);
void EstadiaDiaria_printEncabezado();
void EstadiaDiaria_printOne(eEstadiaDiaria estadia);

#endif /* ESTADIADIARIA_H_ */
