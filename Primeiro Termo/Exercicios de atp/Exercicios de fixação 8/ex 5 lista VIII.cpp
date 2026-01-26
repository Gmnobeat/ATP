#include<stdio.h>
#define tf 10
int main ()
{
	int vet[tf],tl=0,i,num,a; 
	//leitura do vet
	printf("Digite um numero para montar o vet:\n");
	scanf("%d",&num);
	while(tl<tf-1 && num!=0)
	{
		vet[tl]=num;
		tl++;
		printf("Digite um numero para continuar ou 0 para terminar:\n");
		scanf("%d",&num);		
	}
	for(i=0;i<tl;i++)
		printf("%d na pos %d, ",vet[i],i);
	printf("\n");
	printf("Digite uma pos para tirar do vet:\n");
	scanf("%d",&num);
	if(num<tl)
		while(num<=tf && num!=0)
		{
			if(num<tl)
			{
				for(i=num;i<tl;i++)
				{
					a=vet[i];
					vet[i]=vet[i+1];
					vet[i+1]=a;
				}
				tl--;
				printf("O novo vetor ficou da seguinte forma:\n");
				for(i=0;i<tl;i++)
					printf("%d na pos %d, ",vet[i],i);	
				printf("\n");
			}
			else
				printf("Numero invalido!!!\n");
			printf("Digite outra pos ou 0 para terminar:\n",tl);
			scanf("%d",&num);
		}
	else
		printf("Numero invalido!!!\n");
	printf("O vetor ficou da seguinte forma: ");
	for(i=0;i<tl;i++)
		printf("%d ",vet[i]);
	return 0;	
}
