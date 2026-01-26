#include<stdio.h>
int main ()
{
	int n,cont;
	scanf("%d",&n);
	while(n!=0)
	{
		if(n<=cont)
		{
			cont=-1;
			while(n<=cont)
		{
			if(cont==n)
				printf("%d\n",cont);
			else
				printf("%d ",cont);
			cont--;
		}
		}
		else
		{
			cont=1;
			while(n>=cont)
		{
			if(cont==n)
				printf("%d\n",cont);
			else
				printf("%d ",cont);
			cont++;
		}
		scanf("%d",&n);
		}
	}
	return 0;
}
