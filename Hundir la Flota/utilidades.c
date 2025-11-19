#include "utilidades.h"

const char* MENSAJE_ERROR_VALIDACION = "Error: valor no reconocido por teclado.\n";

void limpiar_buffer()
{
	int car;
	
	while((car = getchar()) != '\n' && car != EOF);
}