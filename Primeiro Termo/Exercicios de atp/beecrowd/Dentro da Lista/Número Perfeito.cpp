#include<stdio.h>
int main ()
{
	int n,cont=0,resto,div=1,soma=0,n1;
	scanf("%d",&n);
	while (n>cont)
	{
		scanf("%d",&n1);
		while(div<=n1/2)
		{
			resto=n1%div;
			if(resto==0)
				soma+=div;
			div++;
		}
		if(soma==n1)
			printf("%d eh perfeito\n",n1);
		else
			printf("%d nao eh perfeito\n",n1);
		cont++;
		soma=0;
		div=1;
	}
	return 0;
}
