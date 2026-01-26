#include<stdio.h>
int main ()
{
	int n,cont=1,n2,n3;
	scanf("%d",&n);
	while(cont<=n)
	{
		n2=cont*cont;
		n3=n2*cont;
		printf("%d %d %d\n",cont,n2,n3);
		cont++;
	}
}
