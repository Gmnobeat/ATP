#include <stdio.h>
#define tf 9
int main()
{
	int vet[tf],i,div,cont,resto;
	for(i=0;i<tf;i++)
	{
		printf("Digite o %do numero\n",i+1);
		scanf("%d",&vet[i]);
	}
	for(i=0;i<tf;i++)
	{
		div=2;
		cont=0;
		while(div<=vet[i]/2)
		{
			resto=vet[i]%div;
			if(resto==0)
				cont++;
			div++;
		}
		if(cont==0)
			printf("O numero %d e primo na posicao %d\n",vet[i],i);
	}
		
	
}
