#include "TAD_Medicamento.h"

RMedicamento cargar_medicamento(){
	RMedicamento med;
	printf("\nIngrese Codigo del medicamento: ");
	scanf("%d", &med.cod);
	fflush(stdin);
	printf("\nIngrese Descripcion del medicamento: ");
	leeCad(med.des, 20);
	fflush(stdin);
	printf("\nIngrese Laboratorio del medicamento: ");
	leeCad(med.lab, 20);
	fflush(stdin);
	printf("\nIngrese Fecha de elaboracion del medicamento: aaaammdd ");
	scanf("%ld", &med.felb);
	printf("\nIngrese Fecha de vencimiento del medicamento: aaaammdd");
	scanf("%ld", &med.fvto);
	printf("\nIngrese Cantidad en existencia del medicamento: ");
	scanf("%d", &med.stock);
	return med;
}
void mostrar_medicamento(RMedicamento med){
	printf("\nCodigo: %d ----- Stock: %d", med.cod, med.stock);
	printf("\nDescripcion: %s ----- Laboratorio: %s", med.des, med.lab);
	printf("\nFecha elaboracion: %ld ----- Fecha vencimiento: %ld", med.felb, med.fvto);
}
void modificar_medicamento(RMedicamento *med){
	RMedicamento nmed;
	nmed= *med;
	printf("\n---- Datos actuales del medicamento ----");
	mostrar_medicamento(nmed);
	printf("\n---- Modificar todos los Datos actuales del medicamento ----");
	nmed= cargar_medicamento();
	*med= nmed;
}
int retorna_COD(RMedicamento med){
	return med.cod;
}

int compara_COD(RMedicamento med, int bcod){ /* para buscar un medicamento*/
	if(med.cod==bcod) return 1;
	else return 0;
}
int compara_LABVTO(RMedicamento med, TCadena blab, long bvto ){
	if(compara_cads(med.lab, blab)==0 && med.fvto < bvto) return 1;
	else return 0;
}
int compara_STOCK(RMedicamento med, int bstock){
	if(med.stock < bstock) return 1;
		else return 0;
}
int compara_LABS(RMedicamento med1, RMedicamento med2){
	return compara_cads(med1.lab, med1.lab);
}
