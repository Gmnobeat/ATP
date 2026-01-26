#include<stdio.h>
int main ()
{
	int canal,qtde,aud4=0,aud5=0,aud7=0,aud12=0;
	float porc4,porc5,porc7,porc12;
	printf("Digite o numero do canal:\n");
	scanf("%d",&canal);
	while (canal)
	{
		printf("Quantidade de pessoas assistindo:\n");
		scanf("%d",&qtde);
		switch (canal)
		{
			case 4: aud4+=qtde;
					break;
			case 5: aud5+=qtde;
					break;
			case 7: aud7+=qtde;
					break;
			case 12: aud12+=qtde;
					break;
			default : printf("nao existe esse canal:\n");
		}
		printf("Digite o numero do canal:\n");
		scanf("%d",&canal);
	}
	porc4=(float)aud4/(aud4+aud5+aud7+aud12)*100;
	porc5=(float)aud5/(aud4+aud5+aud7+aud12)*100;
	porc7=(float)aud7/(aud4+aud5+aud7+aud12)*100;
	porc12=(float)aud12/(aud4+aud5+aud7+aud12)*100;
	printf("canal4 = %.2f%%, canal5 = %.2f%%, canal7 = %.2f%%, canal12 = %.2f%%:\n",porc4,porc5,porc7,porc12);
}
