#include <stdio.h>
#include <stdlib.h> // para NULL
typedef struct {
	int edad, peso;
}TRdato;
typedef TRdato* T_ptr;

T_ptr CreaNodo();
void Mostrar_Nodo(T_ptr);
void DeMenorAMayor(T_ptr*,T_ptr*,T_ptr*);

int main(void) {
   T_ptr PtroX, PtroY, PtroZ;
    PtroX= PtroY= PtroZ= NULL;
    PtroX= CreaNodo();
	PtroY= CreaNodo();
	PtroZ= CreaNodo();
	DeMenorAMayor(&PtroX,&PtroY,&PtroZ);
	Mostrar_Nodo(PtroX);
	Mostrar_Nodo(PtroY);
	Mostrar_Nodo(PtroZ);
	return 0;
}

T_ptr CreaNodo(){
	T_ptr Nvo;
	Nvo=(T_ptr) malloc(sizeof(TRdato));
	printf("\nIngrese edad: ");
	scanf("%d",&Nvo->edad);
	printf("\nIngrese peso: ");
	scanf("%d",&Nvo->peso);
	return Nvo;
}
void Mostrar_Nodo(T_ptr Aux){
	printf("\nEdad= %d", Aux->edad);
	printf("\nPeso= %d", Aux->peso);
}
void DeMenorAMayor(T_ptr* A, T_ptr* B, T_ptr* C) {
	T_ptr Aux;
	if((*B)->edad < (*A)->edad && (*B)->edad < (*C)->edad) {
		Aux=*A;
		*A=*B;
		*B=Aux;
		if ((*C)->edad < (*B)->edad){
		   Aux=*B;
		   *B=*C;
		   *C=Aux;
	    }
	}
	else
		if((*C)->edad < (*A)->edad && (*C)->edad < (*B)->edad) {
			Aux=*A;
			*A=*C;
			*C=Aux;
			if ((*C)->edad < (*B)->edad){
				Aux=*B;
				*B=*C;
				*C=Aux;
			}
		}
		else
			if ((*C)->edad < (*B)->edad){
				Aux=*B;
				*B=*C;
				*C=Aux;
			}
}
	
