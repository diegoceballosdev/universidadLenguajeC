#include <stdio.h>

int main(void){
	int N,edad,sum,men,may,I;
	float promedio;
	printf("Ingrese la cantidad de deportistas: \n");
	scanf("%d",&N);
	printf("Ingrese la edad del deportista: \n");
	scanf("%d",&edad);		
	sum=edad,men=edad,may=edad;
	for(I=2;I<=N;I++){
		printf("Ingrese la edad del deportista: \n");
		scanf("%d",&edad);		
		if(edad<men)
			men=edad;
		if(edad>may)
			may=edad;
		sum=sum+edad;
	}
	promedio = sum/N;
	printf("La edad promedio es: %f \n",promedio);
	printf("La edad mas baja es: %d \n",men);
	printf("La edad mas alta es: %d \n",may);
	return 0;
}
