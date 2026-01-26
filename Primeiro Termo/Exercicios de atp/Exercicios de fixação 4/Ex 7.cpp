#include<stdio.h>
int main ()
{
	int	n=0,totalf=0,totalm=0,sim=0,nao=0,soma;
	float porcf,porcm;
	char sexo,resp;
	while (n<4)
	{
		if(n==0)
		{
			printf("Digite o seu sexo F/M\n");
			scanf("%c",&sexo);
		}
		else
		{
			printf("Digite o seu sexo F/M\n");
			scanf(" %c",&sexo);
		}
		printf("Resposta sim ou nao S/N\n");
		scanf(" %c",&resp);
		if(sexo=='F' && resp=='S')
			totalf++;
		if(sexo=='M' && resp=='N')	
			totalm++;
		if(resp=='S')
			sim++;
		else
			nao++;
		n++;
	}
	soma=sim+nao;
	porcf=(float)totalf/soma*100;
	porcm=(float)totalm/soma*100;
	printf("Numero de sim = %d\n",sim);
	printf("Numero de nao = %d\n",nao);
	printf("Porcentagem de mulheres que disseram sim = %.2f\n",porcf);
	printf("Porcentagem de homens que disseram nao = %.2f\n",porcm);
	return 0;
}
