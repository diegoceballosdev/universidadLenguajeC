#include "TAD_ListaMedicamentos.h"

int retorna_tam(TLista L){
	return L.tam;
}

TLista iniciliza_lista(){
	TLista aux;
	aux.tam=0;
	return aux;
}
void carga_rec(TVector L, int tam){ /*completar*/

}
TLista carga_medicamentos(){ 
	TLista L;
	printf("\nIngrese la cantidad de elementos: ");
	scanf("%d", &L.tam);
	carga_rec(L.lis, L.tam);
	return L;
}

int busq_sec_rec(TVector L, int N, int bcod){ /*completar retorna posicion o -1 si no lo encuentra*/

}

void agrega_medicamentos(TLista *L){ 
	RMedicamento nvo;
	int pos;
	nvo= cargar_medicamento();
	pos= busq_sec_rec(L->lis, L->tam, retorna_COD(nvo));
	if (pos==-1){
		L->tam++;
		L->lis[L->tam]= nvo;
		printf("\nSe agrego exitosamente el nuevo medicamento");
	}
	else printf("\nEl Medicamento ya esta cargado");
}
	
void elimina_rec(TVector L, int N, int pos){ /*completar*/
	
}
void elimina_medicamentos(TLista *L){ 
	int pos, bcod;
	printf("\nIngrese el Codigo del medicamento a eliminar: ");
	scanf("%d", &bcod);
	pos= busq_sec_rec(L->lis, L->tam, bcod);
	if (pos!=-1) {
		elimina_rec(L->lis, L->tam, pos);
		printf("\nSe elimino exitosamente el medicamento");
		L->tam--;
	}
	else printf("\nEl Medicamento no se encuentra");
}
void modifica_medicamentos(TLista *L){ 
	int pos, bcod;
	printf("\nIngrese el Codigo del medicamento a modificar: ");
	scanf("%d", &bcod);
	pos= busq_sec_rec(L->lis, L->tam, bcod);
	if (pos!=-1) modificar_medicamento(&L->lis[pos]);
	else printf("\nEl medicamento no se encuentra");
}
void mostrar_rec(TVector L, int N){ /*completar*/

}
void mostrar_medicamentos(TLista L){
	mostrar_rec(L.lis, L.tam);
}

void recursivo_lab_vto(TVector L, int N, TCadena blab, long bvto){/*completar*/

}
void mostrar_lab_vto(TLista L){
	TCadena blab;
	long bvto;
	fflush(stdin);
	printf("\nIngrese Laboratorio: ");
	leeCad(blab, 20);
	printf("\nIngrese Fecha de vencimiento: ");
	scanf("%ld", &bvto);
	recursivo_lab_vto(L.lis, L.tam, blab, bvto);
}
void genera_rec(TVector A, int N, TVector D, int *M, int bstock){/*completar*/

}
void genera_stock(TLista A, TLista *D){
	int bstock;
	*D=iniciliza_lista();
	printf("\nIngrese Stock de referencia: ");
	scanf("%d", &bstock);
	genera_rec(A.lis, A.tam, D->lis, &D->tam, bstock);
}
	
void QSort_rec(TVector A, int ini, int fin){
	RMedicamento piv;
	int izq, der, med;
	if (ini < fin) {
		piv = A[ini];
		izq = ini;
		der = fin;
		while (izq < der){
			while (der > izq && compara_LABS(A[der], piv) == 1)
						der--;
			if (der > izq) {
				A[izq] = A[der];
				izq++; 
			}
			while (izq < der && compara_LABS(A[der], piv) == -1)
						izq++;
			if (izq < der){	
				A[der] = A[izq];
				der--; 
			}
		}
		A[der] = piv; 
		med = der;
		QSort_rec(A, ini, med-1);
		QSort_rec(A, med+1, fin);
	}
}
void ordenar_lab(TLista *D){
	int ini, fin;
	ini = 1;
	fin = D->tam;
	QSort_rec(D->lis, ini, fin);
}
