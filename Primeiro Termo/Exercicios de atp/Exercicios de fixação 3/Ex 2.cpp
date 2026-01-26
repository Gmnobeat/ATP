#include<stdio.h>
int main ()
{
	int n,i=1,exn=1,resto,impar=0,par=0;
	while(i<=132)
	{
		printf("digite o numero %d\n",exn);
		scanf("%d",&n);
		resto=n%2;
		if(resto==1)
			impar++;
		else
			par++;
		i++;
		exn++;
	}
	printf("A quantidade de impar e de %d e de par e de %d\n",impar,par);
}
