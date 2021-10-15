/*
 * EstadiaDiaria.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Usuario
 */
#include "EstadiaDiaria.h"

void EstadiaDiaria_printEncabezado()
{
	printf("%-20s %-20s %-20s %-20s %-20s %-20s \n", "ID","ID_DUEÑO", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA");
}

void EstadiaDiaria_printOne(eEstadiaDiaria estadia,eDuenio duenio)
{

	printf("%-20d %-20d %-20s %-20d  %-20d %d/%d/%d\n", estadia.id, estadia.idDuenio, duenio.nombre, duenio.telefono, estadia.idPerro, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio);
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

int EstadiaDiaria_addEstadiaDiaria(eEstadiaDiaria list[], int len, int id, int idDuenio, char nombreduenio[],int telefonoContacto, int idPerro, eFecha fecha)
{
	int retorno =-1;
	int index = EstadiaDiaria_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta una estadia...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				list[index].idDuenio= idDuenio;
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

int EstadiaDiaria_addEstadiaDiariaHardcode(eEstadiaDiaria list[], int len, int id, int idDuenio, char nombreduenio[],int telefonoContacto, int idPerro, int dia, int mes, int anio)
{
	int retorno =-1;
	int index = EstadiaDiaria_buscarEspacioLibre(list, len);

		if(index != -1) //Si hay lugar en el array
		{
			printf("\nDando de alta una estadia...\n\n");
			if(list!=NULL&&list[index].isEmpty==1)
			{
				list[index].id= id;
				list[index].idDuenio= idDuenio;
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

int EstadiaDiaria_printLista(eEstadiaDiaria list[],eDuenio listaDuenio[], int length, int lenDuenio)
{
	int retorno =-1;
	int auxIdDunio;
	eDuenio auxDuenio;
	if(list!=NULL)
	{
		int i;
			printf("\nMostrando lista de Estadias...\n\n"
					"%-5s %-20s %-20s %-20s %-20s %-20s \n", "ID", "ID_DUENIO", "NOMBRE_DUEÑO", "TELEFONO_CONTACTO", "ID_PERRO", "FECHA");
			for(i=0; i<length; i++)
			{
				if(list[i].isEmpty == 0)
				{
					auxIdDunio=Duenio_findById(listaDuenio, lenDuenio, list[i].idDuenio);
					auxDuenio=listaDuenio[auxIdDunio];

					EstadiaDiaria_printOne(list[i],auxDuenio);
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

int EstadiaDiaria_PedirIdDuenio(eDuenio list[], int length, int *idDuenio,int cantidadIntentosPermitidos)
{
	int retorno=-1;
	int intentos=0;
	int aux;
	do
	{
		printf("El ID de duenio debe existente en el sistema. Valores permitidos 1-9999");
		pedirEntero(&aux, "Ingrese el Id del duenio", "Reingrese Id invalido", 1, 9999,1);
		if(Duenio_findById(list, length, aux)==-1)
		{
			intentos++;
		}
	}while(Duenio_findById(list, length, aux)==-1&&intentos<cantidadIntentosPermitidos);

	if(Duenio_findById(list, length, aux)!=-1)
	{
		*idDuenio=aux;
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

int EstadiaDiaria_sortEstadia(eEstadiaDiaria list[], eDuenio listaDunios[], int len, int lenDuenios, int order)
{
	int retorno=-1;
	int i;
	int j;
	eEstadiaDiaria auxEstadia;

	switch (order) {
		case 1://Decendente
			if(list !=NULL && listaDunios!=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{

							int posDunio1 = Duenio_findById(listaDunios, lenDuenios, list[i].id);
							int posDunio2 = Duenio_findById(listaDunios, lenDuenios, list[j].id);

							if(Fecha_comparacion(list[i].fecha, list[j].fecha) == 1)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}

							else if((Fecha_comparacion(list[i].fecha, list[j].fecha) == 0) && strcmp(listaDunios[posDunio1].nombre, listaDunios[posDunio2].nombre) < 0)
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
			if(list !=NULL && listaDunios!=NULL)
			{
				for(i=0; i<len-1; i++)
					{
						for(j=i+1; j<len; j++)
						{

							int posDunio1 = Duenio_findById(listaDunios, lenDuenios, list[i].id);
							int posDunio2 = Duenio_findById(listaDunios, lenDuenios, list[j].id);
							if(Fecha_comparacion(list[i].fecha, list[j].fecha) == 2)
							{
								auxEstadia = list[i]; //copiamos la estructura ENTERA
								list[i] = list[j]; //copiamos la estructura ENTERA
								list[j] = auxEstadia; //copiamos la estructura ENTERA
							}
							else if((Fecha_comparacion(list[i].fecha, list[j].fecha) == 0) && strcmp(listaDunios[posDunio1].nombre, listaDunios[posDunio2].nombre) > 0)
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

int EstadiaDiaria_printTodasEstadiasPorPerro(eEstadiaDiaria listEstadias[],ePerro listaPerro[], eDuenio listaDunio[], int length ,int lengthPerro, int lengthDuenio)
{

	int retorno =-1;
	int auxIdPerro;
	eDuenio auxDuenio;
	int auxIndex;
	int k=0;
	int i;
	if(listEstadias!=NULL && listaPerro!=NULL && listaDunio!=NULL)
	{
		for (k = 0; k < lengthPerro; k++)
		{
			if(listaPerro[k].isEmpty==0)
			{
				printf("--------------------------------------------------------------------------------------\n");
				auxIdPerro=listaPerro[k].id;
				Perro_printEncabezado();
				Perro_printOne(listaPerro[k]);

				for(i=0; i<length; i++)
				{
					if(listEstadias[i].isEmpty == 0&&listEstadias[i].idPerro==auxIdPerro)
					{
						printf("Fecha de estadia :");
					  Fecha_print(listEstadias[i].fecha);
					  printf("    / Id Duenio : %d", listEstadias[i].idDuenio);

					  auxIndex=Duenio_findById(listaDunio, lengthDuenio,listEstadias[i].idDuenio);
					  auxDuenio=listaDunio[auxIndex];
					  printf("    / nombre Duenio: %s", auxDuenio.nombre);
					  printf("    / numero de contacto: %d\n", auxDuenio.telefono);

					}
				}

			}
		}
	}
	return retorno;
}

int EstadiaDiaria_PerroConMasEstadias(eEstadiaDiaria listEstadias[],ePerro listaPerro[], int length ,int lengthPerro)
{

	int retorno =-1;
	int auxIdPerro;
	ePerro perroConMasEstadias;
	int estadiasMax=0;
	int contadorDeEstadiasActual=0;
	int k=0;
	int i;
	if(listEstadias!=NULL && listaPerro!=NULL)
	{
		for (k = 0; k < lengthPerro; k++)
		{
			if(listaPerro[k].isEmpty==0)
			{

				for(i=0; i<length; i++)
				{

					if(listEstadias[i].isEmpty == 0&&listEstadias[i].idPerro==auxIdPerro)
					{
						contadorDeEstadiasActual++;

					}
				}
				if(contadorDeEstadiasActual>estadiasMax)
				{
					estadiasMax=contadorDeEstadiasActual;
					perroConMasEstadias=listaPerro[k];
				}
			}

		}

			printf("El perro con mas estadias es:\n");
			Perro_printEncabezado();
			Perro_printOne(perroConMasEstadias);
			printf("Con un total de %d Estadias\n", estadiasMax);


	}
	return retorno;
}



