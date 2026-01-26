#include<stdio.h>
#include<math.h>
int main ()
{
	float valorpc,prest_fixa,parcela,juros,somajuros=0,valorjuros,menor=pow(2,31);
	int mes=0;
	
	printf("Digite o valor do computador:\n");
	scanf("%f",&valorpc);
	prest_fixa=valorpc/20;
	juros=valorpc;
	while (juros>0)
	{
		valorjuros=juros*0.02;
		juros=juros+valorjuros;
		juros-=prest_fixa;
		somajuros+=valorjuros;
		if(parcela<menor)
			menor=parcela;
		mes++;
		
	}
	printf("O valor de juros sera de %.2f\n",somajuros);
	printf("A quantidade de meses foi de %d\n",mes);
	printf("O valor da ultima prestacao foi de %.2f\n",menor);
}
