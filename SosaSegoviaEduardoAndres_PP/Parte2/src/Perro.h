/*
 * Perro.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include "INPUTS.h"
#ifndef PERRO_H_
#define PERRO_H_

typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int isEmpty;
}ePerro;

/**
 * @fn int Perro_initLista(ePerro[], int)
 * @brief Inicializa la lista de perros para que todos sus espacios esten disponibles
 * @param list lista de perros a inicializar
 * @param len longitud de la lista
 * @return -1 si hubo error 1 si se realizo la inicializacion correctamente
 */
int Perro_initLista(ePerro list[], int len);
/**
 * @fn int Perro_addPerro(ePerro[], int, int, char[], char[], int)
 * @brief agrega un perro a la lista de perros en el primer espacio vacio tomando sus partes por parametro siemrpe y cuando exista un espacio vacio
 * @param list lista de perros donde se agregara el perro
 * @param len longitud de la lista
 * @param id del perro a guardar
 * @param name nombre del perro a guardar
 * @param raza del perro a guardar
 * @param edad del perro a guardar
 * @return
 */
int Perro_addPerro(ePerro list[], int len, int id, char name[],char raza[],int edad);
/**
 * @fn int Perro_buscarEspacioLibre(ePerro[], int)
 * @brief Recorre la lista y busca el primer espacio libre
 * @param list lista de perrros a recorrer
 * @param tam longitd de la lista a recorrer
 * @return -1 no se encontro espacio vacio o hubo error, 1 se encontro espacio vacio y se devuelve la posicion de este en la lista
 */
int Perro_buscarEspacioLibre(ePerro list[], int tam);
/**
 * @fn int Perro_findById(ePerro[], int, int)
 * @brief Recorre la lista y busca el id de un perro activo en esta
 * @param list lista de perrros a recorrer
 * @param tam longitd de la lista a recorrer
 * @param id a buscar en la lista
 * @return-1 no se encontro el id  o hubo error, 1 se encontro id y se devuelve la posicion de este en la lista
 */
int Perro_findById(ePerro list[], int len,int id);
/**
 * @fn int Perro_removePerro(ePerro[], int, int)
 * @brief Recorre la lista y busca el id de un perro activo en esta y luego hace la baja logica
 * @param list lista de perrros a recorrer
 * @param tam longitd de la lista a recorrer
 * @param id a buscar en la lista para ser removido
 * @return-1 no se encontro el id  o hubo error, 1 se encontro id y se hizo la baja logica del perro con ese id
 */
int Perro_removePerro(ePerro list[], int len, int id);
/**
 * @fn int Perro_contarPerrosActivos(ePerro[], int)
 * @brief recorre la lista y cuenta a todos los perros activos devolviendo este numero al final
 * @param list lista de perros a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n con la cantidad de perros activos contados
 */
int Perro_contarPerrosActivos(ePerro list[],int len);
/**
 * @fn float Perro_TotalSumaEdades(ePerro[], int)
 * @brief recorre la lista y suma la edad de todos los perros activos devolviendo este numero al final
 * @param list lista de perros a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n con suma de la edad de todos los perros activos
 */
float Perro_TotalSumaEdades(ePerro list[],int len);
/**
 * @fn float Perro_PromedioEdades(ePerro[], int)
 * @brief recorre el array y cuenta y suma la edad de todos los perros activos en el array para luego calcular el promedio
 * @param list lista de perros a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, un numero n el promedio de edad de los perros de la lista
 */
float Perro_PromedioEdades(ePerro list[],int len);
/**
 * @fn int Perro_printLista(ePerro[], int)
 * @brief Recorre la lista eimprime a todos los perros activos en esta
 * @param list lista de perros a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, 1 se imprimio correctamente la lista
 */
int Perro_printLista(ePerro list[], int length);
/**
 * @fn void Perro_printEncabezado()
 * @brief Imprime el encabezado de la estructura perro siguiendo este formato "ID", "NOMBRE", "RAZA", "EDAD"
 */
void Perro_printEncabezado();
/**
 * @fn void Perro_printOne(ePerro)
 * @brief Imprime un perro sin encabezado solo los datos siguiendo este formato "ID", "NOMBRE", "RAZA", "EDAD"
 * @param perro
 */
void Perro_printOne(ePerro perro);
/**
 * @fn int Perro_CargaBaseDatos(ePerro[], int)
 * @brief Harcode con varios perros para ser cargados en la base de datos, verifica que tenga minimo de longitud tres
 * @param list lista de perros a recorrer
 * @param len tamaño de la lista a recorrer
 * @return -1 hubo algun error, 1 se cargo correctamente los perros harcodeados
 */
int Perro_CargaBaseDatos(ePerro list[], int length);


#endif /* PERRO_H_ */



