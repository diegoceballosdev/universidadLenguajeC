#include "TAD_Cadena.h"
#include <string.h>

void leeCad(TCadena cad, int tam){
	int j; 	char c;
	j=0;
	c=getchar();
	while (c!=EOF && c!='\n' && j<tam-1)
	{ cad[j]=c;
	j++;
	c=getchar(); 	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}

