#include<stdio.h>
#define tf 10
int main ()
{
	int i,qtde[tf],tqtde=0;
	float valor,val1[tf];
	printf("Digite o preco da peca\n");
	scanf("%f",&valor);
	for(i=0;i<tf;i++)
	{
		printf("Digite a quantidade de peca\n");
		scanf("%d",&qtde[i]);
		val1[i]=qtde[i]*valor;
		tqtde+=qtde[i];
	}
	printf("O total de pecas vendidas foi de %d\n",tqtde);
	for(i=0;i<tf;i++)
		printf("O vendedor %d vendeu um valor de %.2f\n",i+1,val1[i]);
	return 0;
}
