#include "Inputs.h"

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max, int intentos)
{
	int retorno = -1;
	int numeroIngresado;
	int fallos=0;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max && fallos<intentos)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while((numeroIngresado < min || numeroIngresado > max)&& fallos<intentos)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
			if((numeroIngresado < min || numeroIngresado > max))
			{
				fallos++;
			}
		}

		if(fallos<intentos)
		{
			*entero = numeroIngresado;
			retorno = 1;
		}
	}

	return retorno;
}


int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max, int intentos )
{
	int retorno = -1;
	float numeroIngresado;
	int fallos=0;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max && fallos<intentos)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while((numeroIngresado < min || numeroIngresado > max) && fallos<intentos)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
			if((numeroIngresado < min || numeroIngresado > max))
			{
				fallos++;
			}
		}
		if(fallos<intentos)
		{
			*flotante = numeroIngresado;
			retorno = 1;
		}
	}

	return retorno;
}
int pedirCadenaSoloLetras(char* cadena, char* mensaje, char* mensajeError, int max, int intentos)
{
	int retorno = -1;
	char buffer[256];
	int allLetters;
	int tam;
	int fallos=-1;

		if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0 && fallos<intentos )
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
			allLetters=contieneSoloLetras(buffer);
			fallos++;
			while((allLetters==0 || tam > max)&&fallos<intentos)
			{

				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%[^\n]", buffer);
				tam = strlen(buffer);
				allLetters=contieneSoloLetras(buffer);
				if(allLetters!=1)
				{
					fallos++;
				}
			}
		if(allLetters==1 && tam < max &&fallos<intentos)
		{
			strcpy(cadena, buffer);
			retorno=1;
		}
	}
	return retorno;
}

int contieneSoloLetras(char* cadena)
{
	int retorno=1;
	int i=0;

	while(cadena[i]!='\0')
	{
		if ((cadena[i]!=' ')&&(cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
		{
			retorno=0;
		}
		i++;
	}
	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max, int intentos)
{
	int retorno = -1;
	char buffer[256];
	int tam;
	int fallos=0;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0 && fallos<intentos)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max && fallos<intentos)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
			if(tam > max)
			{
				fallos++;
			}

		}
if( fallos<intentos)
{
	strcpy(cadena, buffer);
	retorno = 1;
}

	}

	return retorno;
}

int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}
