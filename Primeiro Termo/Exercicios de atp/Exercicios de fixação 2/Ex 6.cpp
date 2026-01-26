#include<stdio.h>
int main ()
{
	int n;
	float al,pim,pif;
	printf("digite 1 se for homem\n");
	printf("digite 2 se for mulher\n");
	printf("em seguida digite sua altura\n");
	scanf("%d%f", &n,&al);
	switch(n)
	{
		case 1: pim=(72.7*al)-58;
				printf("seu peso ideal e de %.2f\n",pim);
				break;
		case 2: pif=(62.1*al)-44.7;
				printf("seu peso ideal e de %.2f\n",pif);
				break;
		default:printf("algo deu errado");
	}
	return 0;
}
