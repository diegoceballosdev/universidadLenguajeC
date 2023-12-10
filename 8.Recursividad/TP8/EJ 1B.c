/*Dado un dígito D, determinar si pertenece a un número entero positivo N. 
Realizar la traza para D=1 y X= 45673*/

#include <stdio.h>

int pertenece (int X, int D);

int main(int argc, char *argv[]) {
	
	int num, dig;
	
	printf("\n Ingrese un numero entero positivo: ");
	scanf("%d", &num);
	printf("\n Ingrese el digito a buscar: ");
	scanf("%d", &dig);
	
	if (pertenece(num, dig))
		printf("\n El digito %d pertenece al numero %d", dig, num);
	else
		printf("\n El digito %d no pertenece al numero %d", dig, num);
	return 0;
}


int pertenece (int X, int D){
	
	if (X != 0)
		if (D == X%10)
			return 1;
		else
			return pertenece (X/10, D);
	else
		return 0;
}
