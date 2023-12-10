#include <stdio.h>
#define tamvec 5
typedef int tvec[tamvec];

void cargar_vec(tvec,int*);
void mostrar_vec(tvec,int);
void reemplazar_num(tvec,int,int);

int main(){
	tvec vec;
	int n,prom,i,sum;
	cargar_vec(vec,&n);
	sum=0;
	for(i=1;i<=n;i++)
		sum=sum+vec[i];
	prom=sum/n;void reemplazar_num(tvec,int,int);
	reemplazar_num(vec,n,prom);
	mostrar_vec(vec,n);
	return 0;
}

void cargar_vec(tvec V,int*n){
	int i,b,aux;
	i=0;
	b=0;
	while(b==0){
		printf("num: ");
		scanf("%d",&V[1]);
		printf("\n0-seguir \n1-parar\n");
		scanf("%d",&b);
		i++;
		if (b==0){
			for(aux=i;aux>=1;aux--)
				V[aux+1]=V[aux];
		}
	}
	*n=i;
}
void reemplazar_num(tvec V,int n,int prom){
	int i;
	for (i=0;i<=n;i++){
		if (V[i]>prom)
			V[i]=V[i]-prom;
	}
}

void mostrar_vec(tvec V,int n){
	int i;
	printf("\nLos elementos del vector son");
	for(i=1;i<=n;i++){
		printf("\n%d",V[i]);
	}
}
