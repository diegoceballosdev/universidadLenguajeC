/*Dado un número natural, indicar si el mismo es perfecto, abundante o deficiente.*/

/*Nota: Un número natural X se dice que es:
deficiente si la suma de sus divisores (sin contarse a sí mismo) es menor a X. 
Si la suma de sus divisores es mayor a X se dice que el número es abundante y 
si es igual a X se dice que es perfecto.*/

#include <stdio.h>

int sumDiv (int num, int i);

int main() {
	
	int num, suma;
	
	printf("\n Ingrese un numero entero positivo: ");
	scanf("%d", &num);
	
	suma = sumDiv(num, 1);
	
	if (suma < num) 
		printf("\n Es un numero deficiente ");
	else if (suma > num)
		printf("\n Es un numero abundante ");
	else
		printf("\n Es un numero perfecto ");
	return 0;
}

int sumDiv (int num, int i){
	
	if (i <= num/2)
		if (num % i == 0)
			return i + sumDiv(num, i+1);
		else
			return sumDiv(num, i+1);
	else
		return 0;
}
