#include<stdio.h>
int main ()
{
	int numero,qtdkwh,flag=1,menor,maior,somaR=0,somaC=0,somaI=0,cont=0;
	float total_pagar,mediag,precokwh;
	char tipo;
	printf("preco do kwh:\n");
	scanf("%f",&precokwh);
	printf("numero do consumidor:\n");
	scanf("%d",&numero);
	while (numero>0)
	{
		printf("quatidade de kwh:\n");
		scanf("%d",&qtdkwh);
		printf("tipo do consumidor- residencial, comercial, industrial:\n");
		scanf(" %c",&tipo);
		total_pagar=precokwh*qtdkwh;
		printf("total a pagar %.2f\n",total_pagar);
		if(flag==1)
		{
			menor=maior=qtdkwh;
			flag=2;
		}
		else
		{
			if(qtdkwh>maior)
				maior=qtdkwh;
			if(qtdkwh<menor)
				menor=qtdkwh;
		}
		switch (tipo) //ou daria para usar o if e else, coloquei na folha do exercicio de fixação iv.
		{
			case'R': case'r': 
				somaR=somaR+qtdkwh;
				break;
			case'C': case'c':
				somaC=somaC+qtdkwh;
				break;
			default:
				somaI=somaI+qtdkwh;
				
		}
		cont++; // é a msm coisa de cont=cont+1;, se precisar adicionar mais de 1 fica cont+ou/ou*ou-=5; que é igual cont=cont+5,cont=cont/5,cont=cont*5,cont=cont-5;
		printf("Numero do consumidor\n");
		scanf("%d",&numero);						
	}
	printf("maior consumo = %d\n",maior);	
	printf("menor consumo = %d\n",menor);
	printf("total consumo residencial = %d comercial = %d industrial = %d\n",somaR,somaC,somaI);
	mediag = (float)(somaR+somaC+somaI)/cont;
	printf("media geral = %.2f\n",mediag);
	return 0;
}
