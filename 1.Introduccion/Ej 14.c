#include <stdio.h>
#include <math.h>

int main() {
	
	int tipo, N, dig, X, i, sum1, aux, b, cont1, cont2, decimal2, aux3;
	float Y, sum2, prom, prom2, decimal;
	double aux2;
	
	sum1 = sum2 = cont1 = cont2 = 0;
	
	printf("MARQUE 1 SI LA LISTA ES DE N° ENTEROS: \n");
	printf("MARQUE 2 SI LA LISTA ES DE N° REALES: \n");
	scanf("%d", &tipo);
	
	printf("Ingrese la cant. de numeros: \n");
	scanf("%d", &N);
	
	switch(tipo){
	case 1://Lista de enteros
		
		for(i=1; i<=N; i++){
			
			printf("Ingrese el %d° numero: \n", i);
			scanf("%d", &X);
			
			aux = X;
			b = 0;
			while(X!=0 && b==0){
				dig = X%10;
				if (dig%2 == 0)
					X = X/10;
				else
					b=1;
			}
			if (b==0){
				sum1 += aux;
				cont1++;
			}
			printf("suma actual: %d y cont actual: %d\n", sum1, cont1);
		}
		prom = (float)sum1/cont1;
		printf("El promedio de los num con digitos pares es: %f \n", prom);
		break;
		
	case 2://Lista de reales
		
		for(i=1; i<=N; i++){
			
			printf("Ingrese el %d° numero: \n", i);
			//Suponremos que a lo sumo seran 2 deciamles
			scanf("%f", &Y);

			decimal = modf(Y, &aux2); //aux2 guarda parte entera
			aux3 = (int)aux2;
			decimal2 = decimal*100;
			b = 0;
			printf("Parte entera: %d - Parte decimal: %d \n", aux3, decimal2);
			
			while(aux3!=0 && b==0){
				dig = aux3%10;
				if (dig%2 == 0)
					aux3 = aux3/10;
				else
					b=1;
			}
			while(decimal2!=0 && b==0){
				dig = decimal2%10;
				if (dig%2 == 0)
					decimal2 = decimal2/10;
				else
					b=1;
			}
			if (b==0){
				sum2 += Y;
				cont2++;
			}
			printf("suma actual: %f y cont actual: %d \n", sum2, cont2);
		}
		prom2 = sum2/cont2;
		printf("El promedio de los num con digitos pares es: %f \n", prom2);
		break;
		
		break;
	}
	return 0;
}

