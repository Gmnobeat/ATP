#include<stdio.h>
int main ()
{
	int numero,frag=1,maiorn;
	printf("digite um numero\n");
	scanf("%d",&numero);
	while(numero!=0)
	{
		if(frag==1)
		{
			maiorn=numero;
			frag++;
		}
		if(maiorn<numero)
			maiorn=numero;
		if(numero<0)
			printf("Esse numero nao entrara nos calculos\n");
		printf("Digite o proximo numero\n");
		scanf("%d",&numero);				
	}
	printf("O maior numero e %d\n",maiorn);
	return 0;
}
