/*
 * EstadiaDiaria.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"
#include "Perro.h"
#include "Fecha.h"
#include "Duenio.h"
#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_


typedef struct
{
	int id;
	int idDuenio;
	int idPerro;
	eFecha fecha;
	int isEmpty;
}eEstadiaDiaria;

/**
 * @fn int EstadiaDiaria_initLista(eEstadiaDiaria[], int)
 * @brief Inicia la lista de estadias recorriendo el array y poniendo isEmpty=1 en cada posicion del mismo
 * @param list array de eEstadiaDiaria
 * @param len longitud del array list
 * @return 1 si se inicializo correctamente -1 si hubo algun error
 */
int EstadiaDiaria_initLista(eEstadiaDiaria list[], int len);
/**
 * @fn int EstadiaDiaria_addEstadiaDiaria(eEstadiaDiaria[], int, int, char[], int, int, eFecha)
 * @brief Añade una estadiaDiaria a la lista en la primera posicion libre que consiga, asignandole los valores a la parte de esta estructura por parametro recibido
 * @param list lista de estadiasDiarias
 * @param len tamaño de la lista de estadias diarias
 * @param id ID numerico asignado a la lista
 * @param nombreduenio cadena de char que solo contiene letras y espacio blanco
 * @param telefonoContacto int numerico de 10 digitos que debe inicia en 1 para tomar los telefonos tipicos estilo 11 14 15
 * @param idPerro int numerico que identifica al perro asociado a esta estadia
 * @param fecha estructura que contine tres int para determinar dia,mes,anio donde se reserva la estadia
 * @return -1 si hubo algun error, se agotaron los intentos y o espacios (no se agrega la estadia). 1 si se agrego la estadia exitosamente a la lista
 */

int EstadiaDiaria_PedirIdDuenio(eDuenio list[], int length, int *idDuenio,int cantidadIntentosPermitidos);

int EstadiaDiaria_addEstadiaDiaria(eEstadiaDiaria list[], int len, int id, int idDuenio, char nombreduenio[],int telefonoContacto, int idPerro, eFecha fecha);

/**
 * @fn int EstadiaDiaria_addEstadiaDiariaHardcode(eEstadiaDiaria[], int, int, char[], int, int, int, int, int)
 * @brief  Añade una estadiaDiaria a la lista en la primera posicion libre que consiga, asignandole los valores a la parte de esta estructura por parametro recibido
 * con la diferencia que en vez de recibir la estructura fecha por parametro este recibe tres int para setear a la estructura.
 * @param list lista de estadiasDiarias
 * @param len tamaño de la lista de estadias diarias
 * @param id ID numerico asignado a la lista
 * @param nombreduenio cadena de char que solo contiene letras y espacio blanco
 * @param telefonoContacto int numerico de 10 digitos que debe inicia en 1 para tomar los telefonos tipicos estilo 11 14 15
 * @param idPerro int numerico que identifica al perro asociado a esta estadia
 * @param dia se usara parasetear a la parte dia que compone a la parte fecha
 * @param mes se usara parasetear a la parte mes que compone a la parte fecha
 * @param anio se usara parasetear a la parte anio que compone a la parte fecha
 * @return -1 si hubo algun error, se agotaron los intentos y o espacios (no se agrega la estadia). 1 si se agrego la estadia exitosamente a la lista
 */
int EstadiaDiaria_addEstadiaDiariaHardcode(eEstadiaDiaria list[], int len, int id, int idDuenio, char nombreduenio[],int telefonoContacto, int idPerro, int dia, int mes, int anio);

/**
 * @fn int EstadiaDiaria_buscarEspacioLibre(eEstadiaDiaria[], int)
 * @brief Busca el primer espacio libre en el array de estadiaDiaria y retorna la posicion de este
 * @param list lista de estadiasDiarias
 * @param tam tamaño de la lista de estadias diarias
 * @return -1 si hubo algun error, retorna un numero n que representa la posicon donde se encontro el primer espacio vacio
 */
int EstadiaDiaria_buscarEspacioLibre(eEstadiaDiaria list[], int tam);

/**
 * @fn int EstadiaDiaria_findById(eEstadiaDiaria[], int, int)
 * @brief Recorre la lista de estadias y busca el id ingresado por parametro en la misma verificando que este este activo (is empty=1) retornando la posicion de este en el index del array
 * @param list lista de estadiasDiarias
 * @param len tamaño de la lista de estadias diarias
 * @param id a buscar en la lista
 * @return -1 si hubo algun error, retorna un numero n que representa la posicon donde se encontro el id buscado si este estaba activo
 */
int EstadiaDiaria_findById(eEstadiaDiaria list[], int len,int id);

/**
 * @fn int EstadiaDiaria_removeEstadia(eEstadiaDiaria[], int, int)
 * @brief Recorre la lista de estadias y busca el id ingresado por parametro en la misma verificando que este este activo (is empty=1) y dandole de baja logica
 * @param list lista de estadiasDiarias
 * @param len tamaño de la lista de estadias diarias
 * @param id a buscar en la lista
 * @return -1 si hubo algun error no se elimina, 1 si se realizo la baja logica correctamente
 * */
int EstadiaDiaria_removeEstadia(eEstadiaDiaria list[], int len, int id);

/**
 * @fn int EstadiaDiaria_printLista(eEstadiaDiaria[], int)
 * @brief imprime todos las estadias diarias activas (isEmpty=1)
 * siguiendo este formato "ID", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA"
 * @param list lista de estadiasDiarias
 * @param len tamaño de la lista de estadias diarias
 * @return -1 si hubo algun error no imprime, 1 si se imprime correctamente
 */
int EstadiaDiaria_printLista(eEstadiaDiaria list[],eDuenio listaDuenio[], int length, int lenDuenio);

/**
 * @fn void EstadiaDiaria_printEncabezado()
 * @brief  Imprime el encabezado de la estadia diaria
 * "ID", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA"
 *
 */
void EstadiaDiaria_printEncabezado();

/**
 * @fn void EstadiaDiaria_printOne(eEstadiaDiaria)
 * @brief Imprime una estadia diaria siguiendo este formato "ID", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA"
 * @param estadia que se recibe para ser imprimida accediendo a sus componentes
 */
void EstadiaDiaria_printOne(eEstadiaDiaria estadia,eDuenio duenio);

/**
 * @fn int EstadiaDiaria_PedirIdPerro(ePerro[], int, int*, int)
 * @brief pedi al usuario ingresar un idPerro y verifica que este exista activo en la lista perros
 * @param list lista de perros donde se verificara que el id ingresado existe
 * @param length tamaño de la lista de perro
 * @param idPerro pedido en la funcion para ser devuelto si se consigue
 * @param cantidadIntentosPermitidos antes de cancelarse ysalir la funcion
 * @return -1 si hubo algun error y se sale de la funcion sin realizar cambios en idPerro pasado por referencia, 1 si se consiguio el id y se actualiza este valor en el id pasado por referencia
 */
int EstadiaDiaria_PedirIdPerro(ePerro list[], int length, int *idPerro,int cantidadIntentosPermitidos);

/**
 * @fn int EstadiaDiaria_sortEstadia(eEstadiaDiaria[], int, int)
 * @brief organiza la lista desde fechas mas recientes si estan coinciden se organiza en orden alfabetico
 * @param list lista de estadias a ordenar
 * @param len longitud de la lista de estadias
 * @param order 1 orden acendente 0 orden decendente
 * @return 1 si se ordeno correctamente -1 si hubo error
 */
int EstadiaDiaria_sortEstadia(eEstadiaDiaria list[], eDuenio listaDunios[], int len, int lenDuenios, int order);
int EstadiaDiaria_PerroConMasEstadias(eEstadiaDiaria listEstadias[],ePerro listaPerro[], int length ,int lengthPerro);
int EstadiaDiaria_printTodasEstadiasPorPerro(eEstadiaDiaria listEstadias[],ePerro listaPerro[], eDuenio listaDunio[], int length ,int lengthPerro, int lengthDuenio);
#endif /* ESTADIADIARIA_H_ */


