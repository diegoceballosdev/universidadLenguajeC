#include <stdio.h>

int main(int argc, char *argv[]) {
	
	int k,i, pd;
	
	do{
		printf("Ingrese un natural de 2 cifras\n");
		scanf("%d", &k);
	} while(k>99 || k<10);
	
	for(i=2; i<k; i++){
		pd = 2;
		while(pd<=i/2 && i%pd!=0){
			pd++;
		}
		if(pd>i/2 && i!=1){
			printf("primo: %d\n", i);
		}
	}
	
	return 0;
}
