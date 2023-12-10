#include "TAD_LISTA.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	Tlista LISTA=NULL;
	int op;	
	
	do{
		op = menu();
		switch(op)
		{
		case 0: printf("\nFin del programa"); 
		break;
		case 1: agrega_alumno(&LISTA);
		break;
		case 2:	Mostrar_Alumno(LISTA);
		break;
		case 3:	Eliminar_Alumno(&LISTA);
		break;
		case 4: muestra_lista(LISTA);
		break;
		default: printf("\nOpcion no valida");
		}
	} while(op!=0);
	
	return 0;
}
