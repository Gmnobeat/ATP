#include<stdio.h>
#define tf 10
int main()
{
	int i,vet[tf],cont,consulta,vet1[tf],j;
	for(i=0;i<tf;i++)
	{
		printf("Digite o numero do %do vetor:\n",i+1);
		scanf("%d",&vet[i]);
	}
	printf("Deseja condultar um numero? se sim digite 0 numero desejado\n");
	scanf("%d",&consulta);
	while(consulta>0)
	{
		cont=0;
		j=0;
		for(i=0;i<tf;i++)
			if(consulta==vet[i])
			{
				cont++;
				vet1[j]=i;
				j++;
			}
		printf("O total de vezes que esse numero aparece = %d\n",cont);
		printf("Aparece nas seguntes posicoes: ");
		for(i=0;i<tf;i++)
			if(cont>i)
				printf("%d ",vet1[i]);		
		printf("\n");
		printf("Deseja condultar outro numero? se nao digite 0\n");
		scanf("%d",&consulta);
	}
	return 0;
}
