/*
 * EstadiaDiaria.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Usuario
 */
#include "EstadiaDiaria.h"

void EstadiaDiaria_printEncabezado()
{
	printf("%-20s %-20s %-20s %-20s %-20s \n", "ID", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA");
}

void EstadiaDiaria_printOne(eEstadiaDiaria estadia)
{
	printf("%-20d %-20s %-20d %-20d %d/%d/%d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto, estadia.idPerro, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
}

int EstadiaDiaria_removeEstadia(eEstadiaDiaria list[], int len, int id)
{
	int retorno =-1;
	int index = EstadiaDiaria_findById(list, len, id);

		if(index != -1) //Si existe la estadia
		{
			printf("\nDando de baja una estadia...\n\n");
			if(list!=NULL&&list[index].isEmpty==0)
			{
				list[index].isEmpty=1;

				printf("\nSe bajo la estadia!\n\n");
			}
			else
			{
				printf("\nSe cancelo la baja de la estadia.\n\n");
			}
			retorno = 0;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}

int EstadiaDiaria_findById(eEstadiaDiaria list[], int len,int id)
{
	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int EstadiaDiaria_addEstadiaDiaria(eEstadiaDiaria list[], int len, int id, char nombreduenio[],int telefonoContacto, int idPerro, eFecha fecha)
{
	int retorno =-1;
	int index = EstadiaDiaria_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta una estadia...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				strcpy(list[index].nombreDuenio, nombreduenio);
				list[index].telefonoContacto= telefonoContacto;
				list[index].idPerro= idPerro;
				list[index].fecha= fecha;
				list[index].isEmpty=0;
				printf("\nSe cargo la estadia!\n\n");
			}
			else
			{
				printf("\nSe cancelo el alta de la estadia.\n\n");
			}
			retorno = 1;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}

int EstadiaDiaria_addEstadiaDiariaHardcode(eEstadiaDiaria list[], int len, int id, char nombreduenio[],int telefonoContacto, int idPerro, int dia, int mes, int anio)
{
	int retorno =-1;
	int index = EstadiaDiaria_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta una estadia...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				strcpy(list[index].nombreDuenio, nombreduenio);
				list[index].telefonoContacto= telefonoContacto;
				list[index].idPerro= idPerro;
				list[index].fecha.dia= dia;
				list[index].fecha.mes= mes;
				list[index].fecha.anio= anio;
				list[index].isEmpty=0;
				printf("\nSe cargo la estadia!\n\n");
			}
			else
			{
				printf("\nSe cancelo el alta de la estadia.\n\n");
			}
			retorno = 1;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}

int EstadiaDiaria_buscarEspacioLibre(eEstadiaDiaria list[], int tam)
{
	int i;
		int index = -1;

		for(i=0; i<tam; i++)
		{
			if(list[i].isEmpty == 1)
			{
				index = i;
				break;
			}
		}
		return index;
}

int EstadiaDiaria_printLista(eEstadiaDiaria list[], int length)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			printf("\nMostrando lista de Estadias...\n\n"
					"%-5s %-20s %-20s %-20s %-20s \n", "ID", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA");
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0)
				{
					EstadiaDiaria_printOne(list[i]);
				}
			}
			printf("\n");
	}
	return retorno;
}

int EstadiaDiaria_PedirIdPerro(ePerro list[], int length, int *idPerro,int cantidadIntentosPermitidos)
{
	int retorno=-1;
	int intentos=0;
	int aux;
	do
	{
		printf("El ID de perro debe existente en el sistema. Valores permitidos 7000-9999");
		pedirEntero(&aux, "Ingrese el Id del perro", "Reingrese Id invalido", 7000, 9999,1);
		if(Perro_findById(list, length, aux)==-1)
		{
			intentos++;
		}
	}while(Perro_findById(list, length, aux)==-1&&intentos<cantidadIntentosPermitidos);

	if(Perro_findById(list, length, aux)!=-1)
	{
		*idPerro=aux;
		retorno=1;
	}
	return retorno;
}

int EstadiaDiaria_initLista(eEstadiaDiaria list[], int len)
{
	int retorno=-1;

	if(list != NULL)
	{
		int i;
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno=0;
	}
 return retorno;
}

int EstadiaDiaria_sortEstadia(eEstadiaDiaria list[], int len, int order)
{
	int retorno=-1;
	int i;
	int j;
	eEstadiaDiaria auxEstadia;

	switch (order) {
		case 1://Decendente
			if(list !=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{

							if(Fecha_comparacion(list[i].fecha, list[j].fecha) == 1)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}
							else if((Fecha_comparacion(list[i].fecha, list[j].fecha) == 0) && strcmp(list[i].nombreDuenio, list[j].nombreDuenio) < 0)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}
						}
					}
				retorno=0;
			}
			break;
		case 0://Acendente
			if(list !=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{
							if(Fecha_comparacion(list[i].fecha, list[j].fecha) == 2)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}
							else if((Fecha_comparacion(list[i].fecha, list[j].fecha) == 0) && strcmp(list[i].nombreDuenio, list[j].nombreDuenio) > 0)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}
						}
					}
				retorno=0;
			}
					break;
	}
return retorno;

}
