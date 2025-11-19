#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_TABLERO 8

void rellman_barcojug(char tablero_jug[TAM_TABLERO][TAM_TABLERO], char carbarc);
void vista_previa(char tablero_jug[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO]);
void rellauto_barcoene(char tablero_enem[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO], char carbarc);
void ataque_enem(char tablero_jug[TAM_TABLERO][TAM_TABLERO], int *conta_barco_tu, char carbarc);
void ataque_jug(char tablero_enem[TAM_TABLERO][TAM_TABLERO], char tab_enem2[TAM_TABLERO][TAM_TABLERO], int *conta_barco_enem, char carbarc);

#endif