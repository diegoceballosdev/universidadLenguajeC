#include "TADcadena.h"
void leecad (T_cad v, int tam){
	int j=0, m;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		v[j]=m;
		j++;
	}
	v[j]='\0';
	if (m!=EOF && m!='\n'){
		while((m=getchar())!=EOF && m!='\n');
	}
}
