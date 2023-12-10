#include "tadreg.h" 
treg carga_pedido (long nro ) {
	treg aux ; 
	aux.pedido=nro ; 
	printf ("\nIngrese el monto abonado: "); 
	scanf ("%f",&aux.abonado); 
	printf("\nIngrese Fecha aaaammdd: ");
	scanf ("%ld",&aux.fecha) ; 
	printf ("\nIngrese la descripcion del problema: "); 
	fflush (stdin) ;
	leecad(aux.descripcion) ; 
	fflush (stdin); 
	return aux ; 
}
void mostrar_pedido (treg aux ){
	int d , m , a ; 
	long f ; 
	f= aux.fecha;
	d= f%100;
	f= f/100;
	m= f%100;
	a= f/100;
	printf ("\n====DATOS DEL PEDIDO===="); 
	printf ("\nNRO : %ld ----- FECHA: %d/ %d/ %d", aux.pedido, d, m, a);
	printf ("\nMONTO ABONADO: AR %f ", aux.abonado );
	printf ("\nDECRIPCION DEL PROBLEMA: %s",aux.descripcion) ;
}
long retorna_fecha (treg aux){
	return aux.fecha ; 
}
long retorna_nro (treg aux){
	return aux.pedido ; 
}
