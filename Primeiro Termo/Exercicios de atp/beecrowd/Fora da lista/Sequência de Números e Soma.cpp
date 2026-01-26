#include<stdio.h>
int main ()
{
	int n,m,soma;
	scanf("%d%d",&n,&m);
	while(n>0 && m>0)
	{
		soma=0;
		if(n>m)
		{
		
			while(n>=m)
			{
			printf("%d ",m);
			soma+=m;
			m++;
			}
		}
		else
		{
		
			while(m>=n)
			{
			printf("%d ",n);
			soma+=n;
			n++;
			}
		}
		printf("Sum=%d\n",soma);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
