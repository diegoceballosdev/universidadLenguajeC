#include "tad_cadena.h"
void limpiabuffer (){
	char c ; 
	c=getchar(); 
	if (c!=EOF && c!='\n')
		limpiabuffer (); 
}
void leecad_rec(tcad v , int tam , int i ){
	char c ; 
	c=getchar () ;
	if (i<tam-1 && c!=EOF && c!='\n'){
		v[i]=c ; 
		leecad_rec(v,tam,i+1) ; 
	}
	else {
		v[i]='\0' ; 
		if (c!=EOF && c!='\n')
			limpiabuffer () ; 
	}
	}
/**MODULOS PUBLICOS**/ 
void ing_nomb (tcad cad ){
	leecad_rec (cad, MAXCAD , 0 );
	}
int compara_cadenas (tcad a , tcad b){
	if (strcmp (a,b)<0)
	    return -1 ; 
	else {
		if (strcmp (a,b)>0)
			return 1 ; 
		else 
			return 0;
	}
}
