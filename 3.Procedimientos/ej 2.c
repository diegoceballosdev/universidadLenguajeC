#include <stdio.h>

void conversorDeHora (int *, int *, int *);

int main(void) {
	int S, M, H;
	printf("Ingrese la cantidad de segundos: \n");
	scanf("%d", &S);
	
	conversorDeHora(&S,&M,&H);
	printf("Horas:%d - Minutos: %d - Segundos:%d", H,M,S);
	return 0;
}

void conversorDeHora (int *seg, int *min, int *hs){
	*hs = *seg/3600;
	*seg = *seg%3600;
	*min = *seg/60;
	*seg = *seg%60;
}
