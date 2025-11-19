#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"
#include "utilidades.h"

/* Hundir la flota. Por: Francisco J. Resino Jibaja */

static const char* TITULO_JUEGO = "-----HUNDIR LA FLOTA-----\n";
static const char* MODO_JUEGO = "JUGADOR VS MAQUINA\n";
static const char* FIN_BATALLA = "FIN DE LA BATALLA\n";
static const char* OTRA_VEZ = "Jugar otra vez (* para salir)? ";

static const char* MSJ_MENU1 = "----TURNOS DISPONIBLES----\n";
static const char* MSJ_MENU2 = "1) Atacar primero \n";
static const char* MSJ_MENU3 = "2) Defender primero\n";
static const char* MSJ_ESC_TURNO = "Escoge un turno: \n";

int main(int argc, char *argv[])
{
	srand(time(NULL));
	
	int i, j, turno, conta, validador;
	unsigned conta_barco_tu = 5, conta_barco_enem = 5;
	
	char tablero_jug[TAM_TABLERO][TAM_TABLERO], tablero_enem[TAM_TABLERO][TAM_TABLERO], tab_enem2[TAM_TABLERO][TAM_TABLERO], repetir, carbarc;
	
	do
	{
		printf("%s", TITULO_JUEGO);
		printf("%s", MODO_JUEGO);
		
		conta = 0;
		carbarc = 'o';
		
		rellman_barcojug(tablero_jug, carbarc);
		rellauto_barcoene(tablero_enem, tab_enem2, carbarc);
		
		do
		{
			printf("%s", MSJ_MENU1);
			printf("%s", MSJ_MENU2);
			printf("%s", MSJ_MENU3);
			printf("%s", MSJ_ESC_TURNO);
			validador = scanf("%d", &turno);
			limpiar_buffer();
			if(validador == 0 || turno < 1 || turno > 2)
				printf("%s", MENSAJE_ERROR_VALIDACION);
		}while(validador == 0 || turno < 1 || turno > 2);
		
		switch(turno)
		{
			case 1:
			{
				do
				{
					conta++;
					printf("\nTURNO %d DEL JUGADOR\n", conta);
					ataque_jug(tablero_enem, tab_enem2, &conta_barco_enem, carbarc);
					printf("\nTURNO %d DEL ENEMIGO\n", conta);
					ataque_enem(tablero_jug, &conta_barco_tu, carbarc);
					printf("\nESTADO DE LA BATALLA\n");
					vista_previa(tablero_jug, tab_enem2);
				}while(conta_barco_tu > 0 && conta_barco_enem > 0);
				printf("%s", FIN_BATALLA);
			}break;
			
			case 2:
			{
				do
				{
					conta++;
					printf("\nTURNO %d DEL ENEMIGO\n", conta);
					ataque_enem(tablero_jug, &conta_barco_tu, carbarc);
					printf("\nTURNO %d DEL JUGADOR\n", conta);
					ataque_jug(tablero_enem, tab_enem2, &conta_barco_enem, carbarc);
					printf("\nESTADO DE LA BATALLA\n");
					vista_previa(tablero_jug, tab_enem2);
				}while(conta_barco_tu > 0 && conta_barco_enem > 0);
				printf("FIN DE LA BATALLA\n");
			}break;
		}
		if(conta_barco_tu == 0)
			printf("HAS PERDIDO EN %d TURNOS\n", conta);
		if(conta_barco_enem == 0)
			printf("HAS GANADO EN %d TURNOS\n", conta);
		
		printf("%s", OTRA_VEZ);
		scanf("%c", &repetir);
		limpiar_buffer();
	}while(repetir != '*');
	
	return 0;
}