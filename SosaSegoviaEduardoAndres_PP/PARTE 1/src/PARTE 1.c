/*
 ============================================================================
 Name        : PARTE.c
 Author      : Eduardo Andres Sosa Segovia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Perro.h"
#include"INPUTS.h"
#include"EstadiaDiaria.h"


#define QTY_ESTADIAS 1000
#define QTY_PERROS 1000
#define NOMBRERAZALENGTH 21
#define EDADMINIMA 1
#define EDADMAX 30
#define INTENTOS_PERMITIDOS 2
#define ESTADIAMAX 200000
#define ESTADIAMIN 100000

int main(void) {

ePerro listaPerros[QTY_PERROS];
eEstadiaDiaria listaEstadias[QTY_ESTADIAS];
int idContadorPerros=7003;
int auxIndex;
ePerro auxPerro;
eEstadiaDiaria auxEstadia;
eFecha auxFecha;

int idContadorEstadias=100000;
int estadiasActivas =0;
int opcion;
int salir=0;
char confirmacion;
float sumatoriaEdad=0;
float promedioEdad;
setbuf(stdout,NULL);
Perro_initLista(listaPerros, QTY_PERROS);
Perro_CargaBaseDatos(listaPerros,QTY_PERROS);

Fecha_pedir(&auxFecha, 2);
Fecha_print(auxFecha);

int datosObtenidosEstadia[]={-1,-1,-1,-1};


do
{

	printf("Base de datos de Estadias ver.0\n\n"
			"1)Reservar Estadia\n"
			"2)Modificar Estadia\n"
			"3)Cancelar Estadia\n"
			"4)Listar Estadias\n"
			"5)Listar Perros\n"
			"6)Promedio de Edad de los perros\n"
			"7)SALIR\n");
	pedirEntero(&opcion, "Opcion:", "ERROR", 1, 7);
	switch (opcion) {
		case 1:

			auxIndex=EstadiaDiaria_buscarEspacioLibre(listaEstadias, QTY_ESTADIAS);
			if(auxIndex!=-1)
			{
				auxEstadia.id=idContadorEstadias;
				printf("Ingresando nueva estadia en la base, estadia n° %d\n",auxIndex);
				printf("Maximo de longitud permitido %d caracteres\n",NOMBRERAZALENGTH);
				datosObtenidosEstadia[0]=pedirCadena(auxEstadia.nombreDuenio, "Ingrese el nombre del dueño\n", "Reingrese nombre invalido\n", NOMBRERAZALENGTH);
				printf("Valores aceptados %d-%d \n",1000000000, 1999999999);
				datosObtenidosEstadia[1]=pedirEntero(&auxEstadia.telefonoContacto, "Ingrese el telefono de contacto", "Reingrese telefono invalido", 1000000000, 1999999999);
				datosObtenidosEstadia[2]=EstadiaDiaria_PedirIdPerro(listaPerros, QTY_PERROS, &auxEstadia.idPerro,INTENTOS_PERMITIDOS);
				datosObtenidosEstadia[3]=Fecha_pedir(&auxFecha, INTENTOS_PERMITIDOS);

				if(datosObtenidosEstadia[0]!=-1&&datosObtenidosEstadia[1]!=-1&&datosObtenidosEstadia[2]!=-1&&datosObtenidosEstadia[3]!=-1)
				{
					EstadiaDiaria_printEncabezado();
					EstadiaDiaria_printOne(auxEstadia);
					pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea agregar al empleado a nomina ingrese  Y para confirmar");
					if(confirmacion=='Y'||confirmacion=='y')
					{
						EstadiaDiaria_addEstadiaDiaria(listaEstadias, QTY_ESTADIAS, idContadorEstadias, auxEstadia.nombreDuenio, auxEstadia.telefonoContacto, auxEstadia.idPerro, auxEstadia.fecha);
						idContadorEstadias++;
						estadiasActivas++;
						printf("Estadia Agregada Exitosamente \n");
					}
					else
					{
						printf("Volviendo al menu \n");
					}
				}
				else
				{
					printf("Volviendo al menu intentos agotados");
				}

			}
			else
			{
				printf("Esta full la lista de estadias ya no podemos albergar mas perritos \n");
			}
			system("pause");

			break;
		case 2:

			printf("Bienvenido al menu de modificacion\n\n");
			if(estadiasActivas>0)
			{
				pedirEntero(&auxEstadia.id, " ingrese el numero de Estadia que desea modificar\n", "Ingreso invalido, reingrese\n", ESTADIAMIN, ESTADIAMAX);
				int estadiaConseguida=-1;
				estadiaConseguida= EstadiaDiaria_findById(listaEstadias, QTY_ESTADIAS, estadiaConseguida);
				if(estadiaConseguida!=-1 && listaEstadias[estadiaConseguida].isEmpty!=1)
				{   auxEstadia=listaEstadias[estadiaConseguida];
					EstadiaDiaria_printEncabezado();
					EstadiaDiaria_printOne(auxEstadia);
					pedirEntero(&opcion, "Ingrese:\n"
							"1)Modificar el telefono de contacto\n"
							"2)Modificar Ael perro\n"
							"3)Volver al menu\n",
							"Opcion invalidad reingrese:\n"
							"1)Modificar el telefono de contacto\n"
							"2)Modificar Ael perro\n"
							"3)Volver al menu\n", 1, 3);
					switch (opcion)
					{
						case 1:
							printf("Valores aceptados %d-%d \n",1000000000, 1999999999);
							datosObtenidosEstadia[1]=pedirEntero(&auxEstadia.telefonoContacto, "Ingrese el telefono de contacto", "Reingrese telefono invalido", 1000000000, 1999999999);
							break;
						case 2:

												break;
						case 3:
							printf("Volviendo al menu \n");
												break;

					}
						EstadiaDiaria_printEncabezado();
						EstadiaDiaria_printOne(auxEstadia);
						pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea realizar este cambio; ingrese  Y para confirmar");
						if(confirmacion=='Y'||confirmacion=='y')
						{
							listaEstadias[estadiaConseguida]=auxEstadia;
							printf("Empleado Actualizado Exitosamente \nVolviendo al menu \n");
						}


				}
				else
				{
					printf("El Id:%d no existe en la bade de datos.\n volviendo al menu\n",auxEstadia.id);
				}
			}
			else
			{
				printf("Aun no ha agregado ninguna estadia solo puede modificar estadias activas \nVolviendo al menu\n");
			}
			system("pause");

					break;
		case 3:
			printf("Bienvenido al menu de Cancelacion de estadia\n\n");
			if(estadiasActivas>0)
			{
				pedirEntero(&auxEstadia.id, " ingrese el numero de empleado que desea dar de baja\n", "Ingreso invalido, reingrese rango permitido (1-32767)\n", 1, 32767);
				int estadiaConseguida=-1;
				estadiaConseguida=EstadiaDiaria_findById(listaEstadias, QTY_ESTADIAS, auxEstadia.id);
				if(estadiaConseguida!=-1 && listaEstadias[estadiaConseguida].isEmpty!=1)
				{
					EstadiaDiaria_printEncabezado();
					EstadiaDiaria_printOne(auxEstadia);
					pedirCaracter(&confirmacion, "\n\nEsta Seguro que desea dar de baja a esta estadia; ingrese  Y para confirmar");
					if(confirmacion=='Y'||confirmacion=='y')
					{
						listaEstadias[estadiaConseguida].isEmpty=1;
						estadiasActivas--;
						printf("Estadia dado de baja Exitosamente \nVolviendo al menu \n");
					}
				}
			}
			else
			{
				printf("Aun no ha agregado ningun empleado solo puede dar de baja a empleados registrados y activos \nVolviendo al menu\n");
			}
			system("pause");
					break;
		case 4:
			printf("Bienvenido al menu de Informes \nListado de Estadias ordenados por fecha y nombre de dueño.\n\n\n");
			if(estadiasActivas>0)
			{
				pedirEntero(&opcion, "Ingrese:\n"
								"1)Orden Acendente.\n"
								"2)Orden Decendente. \n",
								"Ingreso Invalido reingrese:\n"
								"1)Orden Acendente.\n"
								"2)Orden Decendente. \n",1,2);
				if(opcion==1)//Ascendente
				{
					EstadiaDiaria_sortEstadia(listaEstadias, QTY_ESTADIAS, 0);
				}

				else//Descendente
				{
					EstadiaDiaria_sortEstadia(listaEstadias, QTY_ESTADIAS, 1);
				}
			EstadiaDiaria_printLista(listaEstadias, QTY_ESTADIAS);
			system("pause");
			}
			else
			{
				printf("Aun no ha agregado ningun empleado nada que informar \nVolviendo al menu\n");
			}
			system("pause");
					break;
		case 5:
			printf("Bienvenido al menu de Informes \nListado de Perros\n\n");
			Perro_printLista(listaPerros, QTY_PERROS);
					break;
		case 6:
			printf("Bienvenido al menu de Informes \nEdad Promedio de edad de los perros\n\n");
			promedioEdad=Perro_PromedioEdades(listaPerros, QTY_PERROS);
			printf("EL promedio de edad de los perros es %.2f",promedioEdad);
							break;
		case 7:
						salir=1;
							break;
	}
	printf("Ingrese una tecla para continuar");
getchar();
}while(!salir);


}
