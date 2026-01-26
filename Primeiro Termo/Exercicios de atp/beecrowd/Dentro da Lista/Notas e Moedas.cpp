#include<stdio.h>
int main ()
{
	int exibir100,exibir50,exibir20,exibir10,exibir5,exibir2,n2,n100,n50,n20,n10,n5;
	float n;
	scanf("%f",&n);
	
	n100=n%100;
	n50=n100%50;
	n20=n50%20;
	n10=n20%10;
	n5=n10%5;
	n2=n5%2;
	exibir100=n/100;
	exibir50=n100/50;
	exibir20=n50/20;
	exibir10=n20/10;
	exibir5=n10/5;
	exibir2=n5/2;
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n",exibir100);
	printf("%d nota(s) de R$ 50.00\n",exibir50);
	printf("%d nota(s) de R$ 20.00\n",exibir20);
	printf("%d nota(s) de R$ 10.00\n",exibir10);
	printf("%d nota(s) de R$ 5.00\n",exibir5);
	printf("%d nota(s) de R$ 2.00\n",exibir2);
	printf("MOEDAS:\n");
	printf("%d moedas(s) de R$ 1.00\n",exibir100);
	printf("%d moedas(s) de R$ 0.50\n",exibir50);
	printf("%d moedas(s) de R$ 0.25\n",exibir20);
	printf("%d moedas(s) de R$ 0.10\n",exibir10);
	printf("%d moedas(s) de R$ 0.05\n",exibir5);
	printf("%d moedas(s) de R$ 0.01\n",exibir2);
	
	
	return 0;
	
	
}
