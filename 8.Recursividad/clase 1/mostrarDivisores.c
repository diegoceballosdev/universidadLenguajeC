/* EJEMPLO 2: Mostrar loa divisores positivos de un nro natural */

#include <stdio.h>
void MostraDiv(int,int);

int main(int argc, char *argv[]) {
	int nro;
	
	printf("\n Ingrese un nro: ");
	scanf("%d",&nro);
	MostraDiv(nro,1);
	
	return 0;
}
void MostraDiv(int num,int i)
{
	
	if(i<=num)
	{
		if(num%i==0)
			printf("\n %d",i);			
		//i++;
		MostraDiv(num,i+1);
	}	
}
