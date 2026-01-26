#include<stdio.h>
int main ()
{
	int n,exibir100,exibir50,exibir20,exibir10,exibir5,exibir2,n2,n100,n50,n20,n10,n5;
	scanf("%d",&n);
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
	printf("%d\n",n);
	printf("%d nota(s) de 100,00\n",exibir100);
	printf("%d nota(s) de 50,00\n",exibir50);
	printf("%d nota(s) de 20,00\n",exibir20);
	printf("%d nota(s) de 10,00\n",exibir10);
	printf("%d nota(s) de 5,00\n",exibir5);
	printf("%d nota(s) de 2,00\n",exibir2);
	printf("%d nota(s) de 1,00\n",n2);
	
	return 0;
}
