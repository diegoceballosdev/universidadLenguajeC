#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

//ORDENAR USANDO UNA LISTA AUXILIAR

void ordena_otralista(Tlista *cab,Tlista *cab2){
	Tlista aux;	
	aux = *cab;
	
	while (aux != NULL){
		agregaNodoOrdenadamente (cab2, aux);
		aux = aux->sig;
	}
	*cab = *cab2;
}
void ordena_lista(Tlista *cab){
	Tlista cab2;
	if(*cab !=NULL){
		cab2 = NULL;
		ordena_otralista(cab, &cab2);
	}
	else 
		printf("\n lista vacia");
}

