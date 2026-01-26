#include<stdio.h>
#include<math.h>
int main ()
{
	int op,n3;
	float n1,n2,soma,raiz;
	printf("digite 1 para soma\n");
	printf("digite 2 para raiz quadrada\n");
	printf("digite 3 para finalizar\n");
	scanf("%d", &op);
	switch(op)
	{
		case 1: printf("digite os numeros desejados para fazer a soma\n");
				scanf("%f%f", &n1,&n2);
				soma=n1+n2;
				printf("o resultado da soma foi de %.2f\n",soma);
				break;
		case 2: printf("digite o numero desejado para descobrir a raiz\n");
				scanf("%d",&n3);
				raiz=sqrt(n3);
				printf("o resultado da raiz foi de %.2f\n",raiz);
				break;
		case 3: printf("o programa foi finalizado\n");
		
		default: printf("algo deu errado");		
	}
	return 0;
}
