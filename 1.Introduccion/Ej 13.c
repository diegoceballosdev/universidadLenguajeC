#include <stdio.h>

int main() {
	
	int i, X, N, ultDig;
	float c0, c1, c2, c3, c4, c5, c6, c7, c8, c9;
	float s0, s1, s2, s3, s4, s5, s6, s7, s8, s9;
	s0 = s1 = s2 = s3 = s4 = s5= s6 = s7= s8 = s9 = 0;
	c0 = c1 = c2 = c3 = c4 = c5= c6 = c7= c8 = c9 = 0;
	
	printf("Ingrese la cantidad de numeros de la lista:\n");
	scanf("%d", &N);
	
	for(i=1; i<=N; i++){
		
		printf("Ingrese el %d° numero de la lista:\n", i);
		scanf("%d", &X);
		
		ultDig = X % 10;
		
		switch(ultDig)
		{
		case 0: c0++; s0+=X; break;
		case 1: c1++; s1+=X; break;
		case 2: c2++; s2+=X; break;
		case 3: c3++; s3+=X; break;
		case 4: c4++; s4+=X; break;
		case 5: c5++; s5+=X; break;
		case 6: c6++; s6+=X; break;
		case 7: c7++; s7+=X; break;
		case 8: c8++; s8+=X; break;
		case 9: c9++, s9+=X; break;
		}
	}

	if (c0!=0) printf("El promedio de los numeros terminados en 0 es: %f\n", s0/c0);
	if (c1!=0) printf("El promedio de los numeros terminados en 1 es: %f\n", s1/c1);
	if (c2!=0) printf("El promedio de los numeros terminados en 2 es: %f\n", s2/c2);
	if (c3!=0) printf("El promedio de los numeros terminados en 3 es: %f\n", s3/c3);
	if (c4!=0) printf("El promedio de los numeros terminados en 4 es: %f\n", s4/c4);
	if (c5!=0) printf("El promedio de los numeros terminados en 5 es: %f\n", s5/c5);
	if (c6!=0) printf("El promedio de los numeros terminados en 6 es: %f\n", s6/c6);
	if (c7!=0) printf("El promedio de los numeros terminados en 7 es: %f\n", s7/c7);
	if (c8!=0) printf("El promedio de los numeros terminados en 8 es: %f\n", s8/c8);
	if (c9!=0) printf("El promedio de los numeros terminados en 9 es: %f\n", s9/c9);
	
	return 0;
}

