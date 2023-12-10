#include "TAD_ListaPacientes.h"

TLista inicializa_lista(){
	TLista aux;
	aux.tam=0;
	return aux;
}

int retorna_tam(TLista A){
	return A.tam;
}

void carga_rec(TVector L, int tam){ 
	if (tam>0) { 
		carga_rec(L, tam-1);
		printf("\nIngrese A[%d]= ", tam);
		L[tam]=cargar_paciente(); 
	}
}
TLista carga_pacientes(){ 
	TLista L;
	printf("\nIngrese la cantidad de pacientes: ");
	scanf("%d", &L.tam);
	carga_rec(L.lis, L.tam);
	return L;
}
int busq_sec_rec(TVector A, int N, long DNI){ 
	if(N>0&& compara_DNI(A[N], DNI)!=1) return busq_sec_rec(A, N-1, DNI);
	else if(N==0) return -1;
		 else   return N;
}
void agrega_pacientes(TLista *L){ 
	int pos;
	RPaciente nvo;
	nvo= cargar_paciente();
	pos= busq_sec_rec(L->lis, L->tam, retorna_DNI(nvo));
	if(pos==-1){
		L->tam++;
		L->lis[L->tam]= nvo;;
		printf("\nSe agrego exitosamente el nuevo paciente");
	}
	else printf("\nEl paciente ya esta cargado");
}
void elimina_rec(TVector A, int N, int pos){ 
	if(pos<N){ 	
		A[pos] = A[pos+1];
		elimina_rec(A, N, pos+1);}
}
void elimina_pacientes(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del paciente a eliminar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->lis, A->tam, DNI);
	if (pos!=-1){
		elimina_rec(A->lis, A->tam, pos);
		A->tam--;
	}
	else printf("\nEl cliente no se encuentra");
}
void modifica_pacientes(TLista *A){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del cliente a modificar: ");
	scanf("%ld", &DNI);
	pos= busq_sec_rec(A->lis, A->tam, DNI);
	if (pos!=-1){
		modificar_paciente(&A->lis[pos]);
		printf("\nSe modifico exitosamente el paciente");
	}
	else printf("\nEl cliente no se encuentra");
}
void mostra_rec(TVector A, int tam){ 
	if (tam>0) {	
		mostra_rec(A, tam-1);
		mostrar_paciente(A[tam]); }
}
void mostra_pacientes(TLista A){
	mostra_rec(A.lis, A.tam);
}

void genera_rec(TVector A, int N, TVector D, int *M, long f1, int tipo){
	if(N>0) {
		if(compara_fecha_tipo(A[N], f1, tipo)==1) { 
			(*M)++;
			D[*M]= A[N];
			genera_rec(A, N-1, D, M, f1, tipo); 
		}
		else genera_rec(A, N-1, D, M, f1, tipo);
	} 
}
void genera_atencion(TLista A, TLista *D){
	long f1;
	int tipo;
	*D=inicializa_lista();
	printf("\nIngrese fecha : ");
	scanf("%ld", &f1);
	printf("\nIngrese tipo de atencion 1=Clinica, 2=Odontologica, 3=Traumatologia: ");
	scanf("%d", &tipo);
	if (tipo>0 && tipo <4)
		genera_rec(A.lis, A.tam, D->lis, &D->tam, f1, tipo);
	else printf ("\n mal ingreso del tipo de atencion");
}
void QSort_rec(TVector A, int ini, int fin){
	RPaciente piv;
	int izq, der, med;
	if (ini<fin) { 	
		piv=A[ini];
		izq=ini;
		der=fin;
		while (izq<der) {
			while (der>izq && compara_apellidos(A[der], piv)==1)
				der--;
			if (der>izq) {	
				A[izq]=A[der];
				izq++; 
			}
			while (izq<der && compara_apellidos(A[izq], piv)==-1)
				izq++;
			if (izq<der){
				A[der]=A[izq];
				der--; 
			}
									
		}
		A[der]=piv; 
		med=der;
		QSort_rec(A,ini,med-1);
		QSort_rec(A,med+1,fin);
	}
}
void ordena_pacientes(TLista *D){  
	int ini, fin;
	ini=1;
	fin= D->tam;
	QSort_rec(D->lis, ini, fin);
}
int cantidad_rec(TVector A, int N, long f1, long f2){
	if (N>0) {
		if(compara_fecha(A[N], f1, f2)==1) 
			return 1 + cantidad_rec(A, N-1, f1, f2);
		else return cantidad_rec(A, N-1, f1, f2); }
	else return 0;
}
int cantidad_pacientes(TLista A){  
	long f1, f2;
	printf("\nIngrese fecha inicio aaaammdd: ");
	scanf("%ld", &f1);
	printf("\nIngrese fecha fin aaaammdd: ");
	scanf("%ld", &f2);
	return cantidad_rec(A.lis, A.tam, f1, f2);
	
}
