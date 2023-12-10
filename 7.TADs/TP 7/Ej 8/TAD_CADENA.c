#include <stdio.h>
#include <string.h>
#include "TAD_CADENA.h"

/****** INGRESAR CADENA ******/

void leeCad(Tcad cad, int tam){
	int j;
	char c;
	j = 0;
	while (j<tam-1 && (c=getchar())!=EOF && c!='\n'){
		cad[j] = c;
		j++;
	}
	cad[j] = '\0';
	if (c!=EOF && c!='\n')
		while ((c=getchar())!=EOF && c!='\n');
}

void ingresarCadena (Tcad cadena, int tam){
	leeCad (cadena, tam); 
}
	
/****** COMPARAR CADENAS ******/
	
int comparaCadena (Tcad A, Tcad B){
	return strcmp (A, B);
}
