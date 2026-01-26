#include<stdio.h>
#include<math.h>
int main ()
{
	int lab,tempo,menort,labaluno=0,mlab,ra,menorra,totalm=0,totalh=0,total1m=0,total1h=0,labmaior=0;
	float porcm,porch;
	char sexo;
	printf("Digite o numero do lab\n");
	scanf("%d",&lab);
	while(lab>0)
	{
		totalh=0;
		totalm=0;
		menort=pow(2,31);
		porcm=0;
		labaluno=0;
		printf("Digite o numero do micro lab\n");
		scanf("%d",&mlab);
		while(mlab>0)
		{
			printf("Digite o ra\n");
			scanf("%d",&ra);
			printf("Digite o sexo\n");
			scanf(" %c",&sexo);
			printf("Digite o tempo\n");
			scanf("%d",&tempo);
			if(tempo<menort)
			{
				menort=tempo;
				menorra=ra;
			}
			if(sexo=='F')
			{
				totalm++;
				total1m++;
			}
			if(sexo=='M')
			{
				totalh++;
				total1h++;
			}
			labaluno++;
			printf("Digite o numero do micro lab\n");
			scanf("%d",&mlab);
		}
		printf("O aluno que esta a menos tempo nesse lab e %d\n",menorra);
		porcm=(float)totalm/(totalm+totalh)*100;
		printf("A porc. de mulheres foi de %.2f\n",porcm);
		if(labaluno>labmaior)
		{
			labaluno=mlab;
			labmaior=lab;
		}
		printf("Digite o numero do lab\n");
		scanf("%d",&lab);
	}
	printf("o lab maior = %d\n",labmaior);
	porch=(float)total1h/(total1m+total1h)*100;
	printf("A porc. de homens é de %.2f\n",porch);
	return 0;
}
