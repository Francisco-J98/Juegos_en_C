#include "funciones.h"
#include "utilidades.h"

static const char* MSJ_FILA = "FILA(i): ";
static const char* MSJ_COLUMNA = "COLUMNA(j): ";

static const char* MSJ_INFO_TABL_JUG = "Tu tablero es este: \n";
static const char* MSJ_INFO_TABL_ENEM = "Y el del enemigo es este: \n";
static const char* MSJ_SEP_LINEA = "\n--------------------------------\n";



void rellman_barcojug(char tablero_jug[TAM_TABLERO][TAM_TABLERO], char carbarc)
{
	char inic = 32;
	int i, j, validador, barcos_disp = 5;
	
	for (i = 0; i < TAM_TABLERO; i++)
		for (j = 0; j < TAM_TABLERO; j++)
			tablero_jug[i][j] = inic;
	
	do
	{
		printf("Queda(n) por colocar %d barco(s)\n", barcos_disp);
		do
		{
			do
			{
				printf("%s", MSJ_FILA);
				validador = scanf("%d", &i);
				limpiar_buffer();
				if(validador == 0 || i < 0 || i > (TAM_TABLERO - 1))
					printf("%s", MENSAJE_ERROR_VALIDACION);
			}while(validador == 0 || i < 0 || i > (TAM_TABLERO - 1));
			
			do
			{
				printf("%s", MSJ_COLUMNA);
				validador = scanf("%d", &j);
				limpiar_buffer();
				if(validador == 0 || j < 0 || j > (TAM_TABLERO - 1))
					printf("%s", MENSAJE_ERROR_VALIDACION);
			}while(validador == 0 || j < 0 || j > (TAM_TABLERO - 1));
		}while(tablero_jug[i][j] == carbarc);
		
		tablero_jug[i][j] = carbarc;
		printf("Barco colocado en [%d][%d]\n", i, j);
		barcos_disp--;
	}while(barcos_disp > 0);
}

void vista_previa(char tablero_jug[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO])
{
	int i, j;
	printf("%s", MSJ_INFO_TABL_JUG);
	
	for (i = 0; i < TAM_TABLERO; i++)
	{
		for (j = 0; j < TAM_TABLERO; j++)
			printf(" %c |", tablero_jug[i][j]);
		printf("%s", MSJ_SEP_LINEA);
	}
	
	printf("%s", MSJ_INFO_TABL_ENEM);
	
	for (i = 0; i < TAM_TABLERO; i++)
	{
		for (j = 0; j < TAM_TABLERO; j++)
			printf(" %c |", tab_enem2[i][j]);
		printf("%s", MSJ_SEP_LINEA);
	}
}

void rellauto_barcoene(char tablero_enem[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO], char carbarc)
{
	int i, j, barcos_disp = 5;
	char inic = 32;
	
	for (i = 0; i < TAM_TABLERO; i++)
		for (j = 0; j < TAM_TABLERO; j++)
		{
			tablero_enem[i][j] = inic;
			tab_enem2[i][j] = tablero_enem[i][j];
		}
	do
	{
		do
		{
			i = rand() % TAM_TABLERO;
			j = rand() % TAM_TABLERO;
		}while(tablero_enem[i][j] == carbarc);
		
		tablero_enem[i][j] = carbarc;
		barcos_disp--;
	}while(barcos_disp > 0);
}

void ataque_enem(char tablero_jug[TAM_TABLERO][TAM_TABLERO], int * conta_barco_tu, char carbarc)
{
	int i, j;
	
	do
	{
		i = rand() % TAM_TABLERO;
		j = rand() % TAM_TABLERO;
	}while(tablero_jug[i][j] == 'w' || tablero_jug[i][j] == 'x');
	
	printf("EL ENEMIGO ATACA EN [%d][%d]!\n", i, j);
	
	if (tablero_jug[i][j] == carbarc)
	{
		*conta_barco_tu = *conta_barco_tu - 1;
		printf("Tocado y hundido en [%d][%d]\n", i, j);
		tablero_jug[i][j] = 'x';
	}
	if (tablero_jug[i][j] == 32)
	{
		printf("Agua en [%d][%d]\n", i, j);
		tablero_jug[i][j] = 'w';
	}
}

void ataque_jug(char tablero_enem[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO], int * conta_barco_enem, char carbarc)
{
	int i, j, validador;
	
	do
	{
		do
		{
			printf("%s", MSJ_FILA);
			validador = scanf("%d", &i);
			limpiar_buffer();
			if(validador == 0 || i < 0 || i > (TAM_TABLERO - 1))
				printf("%s", MENSAJE_ERROR_VALIDACION);
		}while(validador == 0 || i < 0 || i > (TAM_TABLERO - 1));
		
		do
		{
			printf("%s", MSJ_COLUMNA);
			validador = scanf("%d", &j);
			limpiar_buffer();
			if(validador == 0 || j < 0 || j > (TAM_TABLERO - 1))
				printf("%s", MENSAJE_ERROR_VALIDACION);
		}while(validador == 0 || j < 0 || j > (TAM_TABLERO - 1));
	}while(tablero_enem[i][j] == 'w' || tablero_enem[i][j] == 'x');
	
	printf("ATACASTE EN [%d][%d]!\n", i, j);
	
	if(tablero_enem[i][j] == 32)
	{
		printf("Agua en [%d][%d]\n", i, j);
		tab_enem2[i][j] = 'w';
		tablero_enem[i][j] = 'w';
	}
	
	if(tablero_enem[i][j] == carbarc)
	{
		*conta_barco_enem = *conta_barco_enem - 1;
		printf("Tocado y hundido en [%d][%d]\n", i, j);
		tab_enem2[i][j] = 'x';
		tablero_enem[i][j] = 'x';
	}
}