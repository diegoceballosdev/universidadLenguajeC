#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int i, N, X, aux, dig, invertido, contCapicuas, contCapDigImp;
	
	contCapDigImp = contCapicuas = 0;
	
	printf("ingrese cant de numeros de la lista:\n");
	scanf("%d", &N);
	
	for(i=1; i<=N; i++){
		printf("ingrese el num %d de la lista: \n", i);
		scanf("%d", &X);
		
		aux = X;
		invertido = 0;
		
		while(aux!=0){
			dig = aux % 10;
			invertido = invertido*10 + dig;
			aux = aux / 10;
		}
		if(X == invertido){
			printf("%d es capicua\n", X);
			contCapicuas++;
			
			int b = 0;
			while(invertido!=0 && b==0){
				dig = invertido % 10;
				if(dig%2 == 0){
					b = 1;
				}
				invertido = invertido / 10;
			}
			printf("b = %d\n", b);
			if(b!=1){
				printf("%d es capicua formado por digitos impares\n", X);
				contCapDigImp++;
			}
		}
	}
	
	printf("Cant de capicuas: %d\n", contCapicuas);
	printf("Cant de capicuas  formado por digitos impares: %d\n", contCapDigImp);
	
	return 0;
}

