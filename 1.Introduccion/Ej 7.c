#include <stdio.h>

int main(){
	float seg, min, hs;
	printf("ingrese la cantidad de segundos:\n");
	scanf("%f", &seg);
	min = seg / 60;
	hs = seg / 3600;
	
	printf("%f seg es equivakente a %f minutos", seg, min);
	printf("%f seg es equivalente a %f hs", seg, hs);
}
