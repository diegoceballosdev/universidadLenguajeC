/*La siguiente funci�n retorna el en�simo elemento de la sucesi�n de Fibonacci, 
realice el �rbol de llamadas para n=4 y para n=7. Pruebe la funci�n fibo, con 
n= 10, 20, 30, 40, 44, 45, 46, 47, 48, 49, 50 y 51. �Qu� observa? �Por qu�?
*/

#include <stdio.h>

int fibo (int);

int main(void) {
	
	int num;
	printf("\nIngrese un numero: ");
	scanf("%d", &num);
	
	printf("\nEl N-esimo elemento de la sucesion de fibonacci para n=%d es: %d", num, fibo(num));
	
	return 0;
}

/******** MODULO RECURSIVO **************/

int fibo (int n){
	if (n < 2)
		return n;
	else
		return fibo(n-1) + fibo(n-2);
	
}
	
/*PARA n=51 me da -12049838.... NEGATIVO Y TARD� MUCHO*/
