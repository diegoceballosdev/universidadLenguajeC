#include "TAD_CADENA.h"
#include <stdio.h>

void leecad(Tcad A, int tmax)
{
	int j=0; char c;
	c=getchar();
	
	while(j<tmax && c!=EOF && c!='\n'){
		A[j]=c;
		j++;
		c=getchar();}
	A[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}
