/*
 * Duenio.h
 *
 *  Created on: Oct 15, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"
#ifndef DUENIO_H_
#define DUENIO_H_

typedef struct
{
	int id;
	char nombre[21];
	int telefono;
	int isEmpty;
}eDuenio;

/**
 * @fn int Duenio_initLista(ePerro[], int)
 * @brief Inicializa la lista de duenio para que todos sus espacios esten disponibles
 * @param list lista de duenio a inicializar
 * @param len longitud de la lista
 * @return -1 si hubo error 1 si se realizo la inicializacion correctamente
 */
int Duenio_initLista(eDuenio list[], int len);

/**
 * @fn int Duenio_addDuenio(eDuenio[], int, int, char[], int)
 * @brief agrega un duenio a la lista de duenio en el primer espacio vacio tomando sus partes por parametro siemrpe y cuando exista un espacio vacio
 * @param list lista de duenio donde se agregara el duenio
 * @param len longitud de la lista
 * @param id del duenio a guardar
 * @param name nombre del duenio a guardar
 * @param telefono telefono del duenio a guardar
 * @return -1 si hubo error, 1 si se cargo correctamente el duenio o se cancelo por espacio
 */
int Duenio_addDuenio(eDuenio list[], int len, int id, char name[],int telefono);
/**
 * @fn int Duenio_buscarEspacioLibre(ePerro[], int)
 * @brief Recorre la lista y busca el primer espacio libre
 * @param list lista de duenio
 * @param tam longitd de la lista a recorrer
 * @return -1 no se encontro espacio vacio o hubo error, 1 se encontro espacio vacio y se devuelve la posicion de este en la lista
 */
int Duenio_buscarEspacioLibre(eDuenio list[], int tam);
/**
 * @fn int Duenio_findById(ePerro[], int, int)
 * @brief Recorre la lista y busca el id de un duenio activo en esta
 * @param list lista de duenio a recorrer
 * @param tam longitd de la lista a recorrer
 * @param id a buscar en la lista
 * @return-1 no se encontro el id  o hubo error, 1 se encontro id y se devuelve la posicion de este en la lista
 */
int Duenio_findById(eDuenio list[], int len,int id);
/**
 * @fn int Duenio_removePerro(ePerro[], int, int)
 * @brief Recorre la lista y busca el id de un duenio activo en esta y luego hace la baja logica
 * @param list lista de duenio a recorrer
 * @param tam longitd de la lista a recorrer
 * @param id a buscar en la lista para ser removido
 * @return-1 no se encontro el id  o hubo error, 1 se encontro id y se hizo la baja logica del duenio con ese id
 */
int Duenio_removeDuenio(eDuenio list[], int len, int id);
/**
 * @fn int Duenio_contarPerrosActivos(ePerro[], int)
 * @brief recorre la lista y cuenta a todos los duenio activos devolviendo este numero al final
 * @param list lista de duenio a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n con la cantidad de duenio activos contados
 */
int Duenio_contarDuenioActivos(eDuenio list[],int len);
/**
 * @fn float Duenio_TotalSumaEdades(ePerro[], int)
 * @brief recorre la lista y suma la edad de todos los duenio activos devolviendo este numero al final
 * @param list lista de duenio a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n con suma de la edad de todos los duenio activos
 */
float Duenio_TotalSumaEdades(eDuenio list[],int len);
/**
 * @fn float Duenio_PromedioEdades(ePerro[], int)
 * @brief recorre el array y cuenta y suma la edad de todos los duenio activos en el array para luego calcular el promedio
 * @param list lista de duenio a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n el promedio de edad de los perros de la lista
 */
float Duenio_PromedioEdades(eDuenio list[],int len);
/**
 * @fn int Duenio_printLista(ePerro[], int)
 * @brief Recorre la lista eimprime a todos los duenio activos en esta
 * @param list lista de duenio a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, 1 se imprimio correctamente la lista
 */
int Duenio_printLista(eDuenio list[], int length);
/**
 * @fn void Duenio_printEncabezado()
 * @brief Imprime el encabezado de la estructura perro siguiendo este formato "ID", "NOMBRE", "RAZA", "EDAD"
 */
void Duenio_printEncabezado();
/**
 * @fn void Duenio_printOne(ePerro)
 * @brief Imprime un perro sin encabezado solo los datos siguiendo este formato "ID", "NOMBRE", "RAZA", "EDAD"
 * @param duenio
 */
void Duenio_printOne(eDuenio perro);
/**
 * @fn int Duenio_CargaBaseDatos(ePerro[], int)
 * @brief Harcode con varios duenio para ser cargados en la base de datos, verifica que tenga minimo de longitud tres
 * @param list lista de duenio a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, 1 se cargo correctamente los duenio harcodeados
 */
int Duenio_CargaBaseDatos(eDuenio list[], int length);


#endif /* DUENIO_H_ */
