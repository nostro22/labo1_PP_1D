/*
 * Duenio.c
 *
 *  Created on: Oct 15, 2021
 *      Author: Usuario
 */

#include "Duenio.h"

int Duenio_initLista(eDuenio list[], int len)
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
int Duenio_addDuenio(eDuenio list[], int len, int id, char name[],int telefono)
{
	int retorno =-1;
	int index = Duenio_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta un Duenio...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				strcpy(list[index].nombre, name);
				list[index].telefono= telefono;
				list[index].isEmpty=0;
				printf("\nSe cargo del Duenio!\n\n");
			}
			else
			{
				printf("\nSe cancelo el alta del Duenio.\n\n");
			}
			retorno = 1;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}
int Duenio_buscarEspacioLibre(eDuenio list[], int tam)
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
int Duenio_findById(eDuenio list[], int len,int id)
{
	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].id == id && list[i].isEmpty==0)
		{
			index = i;
			break;
		}
	}
	return index;
}
int Duenio_removeDuenio(eDuenio list[], int len, int id)
{
	int retorno =-1;
	int index = Duenio_findById(list, len, id);

		if(index != -1) //Si existe el perro
		{
			printf("\nDando de baja un Duenio...\n\n");
			if(list!=NULL&&list[index].isEmpty==0)
			{
				list[index].isEmpty=1;

				printf("\nSe bajo el Duenio!\n\n");
			}
			else
			{
				printf("\nSe cancelo la baja del Duenio.\n\n");
			}
			retorno = 0;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}
int Duenio_contarDuenioActivos(eDuenio list[],int len)
{
	int retorno =-1;
		if(list!=NULL)
		{
			int i;
				for(i=0; i<len; i++)
				{
					if(list[i].isEmpty == 0)
					{
						retorno++;
					}
				}
		}
		if(retorno!=-1)
		{
			retorno++;
		}
		return retorno;
}

int Duenio_printLista(eDuenio list[], int length)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			printf("\nMostrando lista de Duenios...\n\n"
				   "%-5s %-20s %-20s \n", "ID", "NOMBRE", "telefono");
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0)
				{
					Duenio_printOne(list[i]);
				}
			}
			printf("\n");
	}
	return retorno;
}
void Duenio_printEncabezado()
{
	printf("%-5s %-20s %-20s  \n", "ID", "NOMBRE", "telefono");
}
void Duenio_printOne(eDuenio duenio)
{
	printf("%-5d %-20s %-20d \n", duenio.id, duenio.nombre, duenio.telefono);
}

int Duenio_CargaBaseDatos(eDuenio list[], int length)
{
	int retorno=-1;
	if (length>3)
	{
		Duenio_addDuenio( list, length,  1,"Alberto",1100000000);
		Duenio_addDuenio( list, length,  2,"Alan",1100000002);
		Duenio_addDuenio( list, length,  3,"Beatriz",1100000007);
		Duenio_addDuenio( list, length,  4,"Carlos",1100000005);
		Duenio_addDuenio( list, length,  5,"Eduardo",1100000003);
		retorno=1;
	}
	return retorno;
}
