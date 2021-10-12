/*
 * Perro.c
 *
 *  Created on: Oct 9, 2021
 *      Author: Usuario
 */
#include"Perro.h"

int Perro_initLista(ePerro list[], int len)
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
int Perro_addPerro(ePerro list[], int len, int id, char name[],char raza[],int edad)
{
	int retorno =-1;
	int index = Perro_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta un perro...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				strcpy(list[index].nombre, name);
				strcpy(list[index].raza, raza);
				list[index].edad= edad;
				list[index].isEmpty=0;
				printf("\nSe cargo el perro!\n\n");
			}
			else
			{
				printf("\nSe cancelo el alta del perro.\n\n");
			}
			retorno = 1;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}
int Perro_buscarEspacioLibre(ePerro list[], int tam)
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
int Perro_findById(ePerro list[], int len,int id)
{
	int i;
	int index = -1;

	for(i=0; i<len; i++)
	{
		if(list[i].id == id&&list[i].isEmpty==0)
		{
			index = i;
			break;
		}
	}
	return index;
}
int Perro_removePerro(ePerro list[], int len, int id)
{
	int retorno =-1;
	int index = Perro_findById(list, len, id);

		if(index != -1) //Si existe el perro
		{
			printf("\nDando de baja un perro...\n\n");
			if(list!=NULL&&list[index].isEmpty==0)
			{
				list[index].isEmpty=1;

				printf("\nSe bajo el perro!\n\n");
			}
			else
			{
				printf("\nSe cancelo la baja del perro.\n\n");
			}
			retorno = 0;
		}
		else
		{
			printf("\nError. No hay espacio disponible.\n\n");
		}

 return retorno;
}
int Perro_contarPerrosActivos(ePerro list[],int len)
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
float Perro_TotalSumaEdades(ePerro list[],int len)
{
	float retorno =-1;
	if(list!=NULL)
	{
		retorno=0;
		int i;
			for(i=0; i<len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					retorno+=list[i].edad;
				}
			}
	}

	return retorno;
}
float Perro_PromedioEdades(ePerro list[],int len)
{
	float retorno =-1;
	int cantidadPerros;
	retorno=Perro_TotalSumaEdades( list,len);
	cantidadPerros=Perro_contarPerrosActivos(list, len);
	if(retorno!=-1&&cantidadPerros>0)
	{
		retorno=retorno/cantidadPerros;
	}
	else
	{
		retorno=-1;
	}

	return retorno;
}
int Perro_printLista(ePerro list[], int length)
{
	int retorno =-1;
	if(list!=NULL)
	{
		int i;
			printf("\nMostrando lista de Perros...\n\n"
				   "%-5s %-20s %-20s %-20s \n", "ID", "NOMBRE", "RAZA", "EDAD");
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0)
				{
					Perro_printOne(list[i]);
				}
			}
			printf("\n");
	}
	return retorno;
}
void Perro_printEncabezado()
{
	printf("%-5s %-20s %-20s %-20s \n", "ID", "NOMBRE", "RAZA", "EDAD");
}
void Perro_printOne(ePerro perro)
{
	printf("%-5d %-20s %-20s %-20d\n", perro.id, perro.nombre, perro.raza, perro.edad);
}

int Perro_CargaBaseDatos(ePerro list[], int length)
{
	int retorno=-1;
	if (length>3)
	{
		Perro_addPerro( list, length,  7000,"Lobo","Sharpei",2);
		Perro_addPerro( list, length,  7001,"Sheila"  ,"Golden",12);
		Perro_addPerro( list, length, 7002,"Reina"  ,"Galgo",13);
		retorno=1;
	}
	return retorno;
}
