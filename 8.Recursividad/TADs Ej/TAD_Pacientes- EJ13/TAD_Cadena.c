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
int compara_cadena(TCadena cad1, TCadena cad2){
	if (strcmp(cad1, cad2)==1) return 1; /*cad1 > cad2*/
			else if (strcmp(cad1, cad2)==0) return 0; /*cad1 = cad2*/
						else return -1; /*cad1 < cad2*/
}
