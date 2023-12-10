#include "tad_cad.h" 
/**MODULOS PRIVADO**/ 
void limpiabuffer (){
	char c ; 
	c=getchar () ;
	if (c!=EOF && c!='\n')
		limpiabuffer(); 
}
void leecad_rec (tcad v , int tam , int i ){
	char c ; 
	c=getchar(); 
	if (i<tam-1 && c!=EOF && c!='\n'){
		v[i]=c  ; 
		leecad_rec (v,tam,i+1) ; 
	}
	else {
		v[i]='\0' ; 
		if (c!=EOF && c!='\n')
			limpiabuffer() ; 
	}
}
/**MODULO PUBLICO**/ 
void ing_cad (tcad v ){
	leecad_rec (v,MAXIMO,0) ; 
}
			
