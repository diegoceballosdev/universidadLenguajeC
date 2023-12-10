#include "tad_cad.h"
/**MODULO PRIVADO**/
void limpiabuffer (){
	char c ; 
	c=getchar () ;
	if (c!=EOF && c!='\n')
		limpiabuffer(); 
}
	void leecad_rec (tcad v ,int tam , int i){
		char c ; 
		c=getchar();
		if (c!=EOF && c!='\n'&&i<tam-1){
			v[i]=c ; 
			leecad_rec(v,tam,i+1) ; 
		}
		else {
			v[i]='\0' ; 
			if(c!=EOF&&c!='\n')
				limpiabuffer() ; 
		}
	}
		/**MODULO PUBLICO**/     
		void leecad (tcad v){
			leecad_rec (v,MAX_CADE,0);
		}
