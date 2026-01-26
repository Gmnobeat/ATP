#include<stdio.h>
int main ()
{
	int codigo;
	printf("Digite o codigo do funcionario\n");
	scanf("%d",&codigo);
	switch(codigo)
	{
		case 1: printf("Seu cargo e de escrituario com um aumento do percentual de 50%\n");
				break;
		case 2: printf("Seu cargo e de secretario com um aumento do percentual de 35%\n");
				break;
		case 3: printf("Seu cargo e de caixa com um aumento do percentual de 20%\n");
				break;
		case 4: printf("Seu cargo e de gerente com um aumento do percentual de 15%\n");
				break;
		case 5: printf("Seu cargo e de diretor sem aumento\n");
				break;
		default:;
	}
	return 0;
}
