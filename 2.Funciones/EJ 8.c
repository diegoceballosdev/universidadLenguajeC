#include <stdio.h>

int ingresarNatural ();
int sumDivisores (int);
int determinarTipo (int, int);

int main() {

	int num, sumaDiv;
	
	num = ingresarNatural();
	sumaDiv = sumDivisores (num);
	printf("La suma de los divisores de %d es: %d \n", num, sumaDiv);
	determinarTipo (num, sumaDiv);
	return 0;
}

int ingresarNatural (){
	int X;
	float Y;
	do{
		printf("Ingrese un numero natural:\n");
		scanf("%f",&Y);
		X = (float) Y;
	} while(X<0 || X==0 || X != Y);
	return X;
}
int sumDivisores (int num){
	int sum, i;
	sum= 0;
	for (i=1; i<=(num/2); i++){
		if (num % i == 0)
			sum += i;
	}
	return sum;
}
int	determinarTipo (int num, int suma){
	if (suma < num)
		printf("El numero %d es un numero deficiente", num);
	else if (suma == num)
		printf("El numero %d es un numero perfecto", num);
	else 
		printf("El numero %d es un numero abundante", num);
	return 0;
}
