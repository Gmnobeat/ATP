#include<stdio.h>
int main ()
{
	float precoing=5.00,despesas=200.00,lucro,maior=0, preco_maior;
	int	quanting=120, quant_maior;
	
	printf("Quantidade    Preco Ingreso   Despesas    Lucro\n");
	while (precoing>=1.00)
	{
		lucro=precoing*quanting-despesas;
		printf("%d           %.2f            %.2f      %.2f\n",quanting,precoing,despesas,lucro);
		if(lucro> maior)
		{
			maior=lucro;
			preco_maior=precoing;
			quant_maior=quanting;
		}
		
		
		precoing-=0.50;
		quanting+=26;
	}
	printf("Maior lucro esperado = %.2f\n",maior);
	printf("Quantidade = %d e preco esperado = %.2f correspondente\n",quant_maior,preco_maior);

}
