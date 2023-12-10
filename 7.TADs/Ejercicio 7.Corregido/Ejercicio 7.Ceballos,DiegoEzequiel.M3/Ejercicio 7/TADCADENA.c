#include <stdio.h>
#include "TADCADENA.h"

void leeCad (Tcad cadena, int tam){
	int j, m;
	j=0;	
	
	while (j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	
	if(m!=EOF && m!='\n')
		while((m=getchar())!=EOF && m!='\n');
}
