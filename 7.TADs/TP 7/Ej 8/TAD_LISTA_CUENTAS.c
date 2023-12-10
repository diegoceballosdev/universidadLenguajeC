#include "TAD_LISTA_CUENTAS.h"
#include <stdio.h>

/****** LISTA VACIA ******/

int listaVacia (TRlista L){
	if (L.tam == 0)
		return 1;
	else
		return 0;
}

/****** CARGAR LISTA ******/

void inicializarLista(TRlista *L){
	L->tam = 0;
}

int buscarCuenta (Tvec V, int tam, int bus){
	int i;
	while (i<=tam && bus!=retornaNroCuenta(V[i]) ){
		i++;
	}
	if (i<=tam)
		return i;
	else 
		return 0;
}

int validarCuenta (Tvec V, int tam){
	int cta, res;
	do{
		printf("\n Ingrese Num de cuenta:");
		scanf("%d", &cta);
		res = buscarCuenta (V, tam, cta);
		if (res!=0)
			printf("El Nro de cuenta ya existe, ingrese otro");
	}while(res!=0);
	return cta;
}

void cargarVectorOrdenado (Tvec V, int *tam){
	int i,j, NumCta;
	TRcuenta aux;
	printf("\n Ingrese cantidad de elementos de la lista:");
	scanf("%d", tam);
	for(i=1; i<=*tam; i++){
		NumCta = validarCuenta(V, i);
		aux = cargarCuenta(NumCta);
		j=i-1;
		while(j>0 && comparaCuenta(aux,V[j])==-1){
			V[j+1]=V[j];
			j--;
		}
		V[j+1]=aux;
	}
}

TRlista cargarLista (){
	TRlista aux;
	cargarVectorOrdenado (aux.lis, &aux.tam);
	return aux;
}

/****** ELIMINAR ******/
	
void eliminar(Tvec V, int *tam, int pos){
	int i,N;
	N = *tam;
	for(i=pos; i<=N-1; i++){
		V[i]=V[i+1];
	}
	*tam= N-1;
}

void eliminarCuentaDeLista (TRlista *L){
	int cta, pos;
	printf("\n Ingrese un numero de cuenta");
	scanf("%d", &cta);
	pos = buscarCuenta (L->lis, L->tam, cta);
	if (pos!=0)
		eliminar(L->lis, &L->tam, pos);
	else
		printf("La cuenta ingresada no existe");
}
	
/****** AGREGAR ******/	

int posDeInsercion (Tvec V, int tam, TRcuenta aux){
	int i;
	i=1;
	while (i<=tam && comparaCuenta(aux, V[i])==1)
		i++;
	if (i<=tam)	
		return i;
	else
		return tam+1;
}
	
void agregar (Tvec V, int *tam, int pos, TRcuenta aux){
	int i, N;
	N=*tam;
	for (i=N; i>=pos; i--){
		V[i+1]=V[i];
	}
	V[i]=aux;
	*tam=N+1;
}
	
void agregarCuenta (TRlista *L){
	TRcuenta aux;
	int cta, pos;
	cta = validarCuenta(L->lis, L->tam);
	aux = cargarCuenta(cta);
	pos = posDeInsercion(L->lis, L->tam, aux);
	agregar(L->lis, &L->tam, pos, aux);
}
	
/****** MOSTRAR ******/	
	
void mostrarPorDNI (TRlista L){
	long dni;
	int i;
	printf("\n Ingrese dni del titular");
	scanf("%ld", &dni);
	for (i=1; i<=L.tam; i++){
		if (retornaDNI(L.lis[i])==dni)
			mostrarCuenta(L.lis[i]);
	}
}
	
/****** MOVIMIENTO DE CUENTA ******/
	
void menuMovimientoCuenta (Tvec V, int pos){
	int op;
	do{
		printf("\n MARQUE: 0[SALIR] 1[DEPOSITAR] 2[EXTRAER]");
		scanf("%d", &op);
		switch(op){
		case 0: 
			printf("ADIOS"); 
			break;
		case 1:
			agregarSaldo(&V[pos]);
			break;
		case 2:
			retirarSaldo(&V[pos]);
			break;
		default:
			printf("INGRESE UNA OPCION VALIDA"); 
			break;
		}
	}while(op!=0);
}
	
void movimientoCuenta (TRlista *L){
	int cta, pos;
	printf("\n Ingrese un numero de cuenta");
	scanf("%d", &cta);
	pos = buscarCuenta (L->lis, L->tam, cta);
	if (pos!=0)
		menuMovimientoCuenta (L->lis, pos);
	else
		printf("\n La cuenta ingresada no existe");
}
