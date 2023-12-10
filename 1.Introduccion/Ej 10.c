#include <stdio.h>

int main() {
	
	float consumo, importeBasico, importePorExcesoM3, exceso1, exceso2, TF1,TF2, TF3;
	
	printf("Ingrese el consumo de agua en metros cubicos:\n");
	scanf("%f", &consumo);
	printf("Ingrese el importeBasico:\n");
	scanf("%f", &importeBasico);
	printf("Ingrese el importe por cada mts cubico excedido del limite:\n");
	scanf("%f", &importePorExcesoM3);
	
	exceso1 = consumo - 1000;
	exceso2 = consumo - 2000;
	TF1 = consumo * importeBasico;
	TF2 = 1000 * importeBasico + exceso1 * importePorExcesoM3;
	TF3 = 2000 * importeBasico + exceso2 * importePorExcesoM3 * 2;

	if (consumo <= 1000)
		printf("La tarifa es: %f \n", TF1);
	if (consumo > 1000 && consumo < 2000)
		printf("La tarifa es: %f \n", TF2);
	if (consumo >= 2000)
	 	printf("La tarifa es: %f \n", TF3);
	
	return 0;
}
