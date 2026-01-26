#include<stdio.h>
int main ()
{
	int n,i=1,l=1;
	scanf("%d",&n);
	while(l<=n)
	{
		printf("%d %d %d PUM\n",i,i+1,i+2);
		i=i+4;
		l=l+1;
	}
}
