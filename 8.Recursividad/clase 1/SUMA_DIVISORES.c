/* EJEMPLO 3: Mostrar la suma de los divisores positivos de un nro natural */

#include <stdio.h>

int Suma_Div(int,int );

int main(int argc, char *argv[]) {
	int nro,suma;
	
	printf("\n Ingrese un nro natural: "); /** validar despues*/
	scanf("%d",&nro);
	suma=Suma_Div(nro,1);
	printf("\nLa suma los divisores del nro %d es %d ",nro,suma);
	
	return 0;
}


int Suma_Div(int num,int i)
{
	if(i<=num){
		if(num % i==0)
			return(i+Suma_Div(num,i+1));
		else return(Suma_Div(num,i+1));		
	}
	else return 0;
}

