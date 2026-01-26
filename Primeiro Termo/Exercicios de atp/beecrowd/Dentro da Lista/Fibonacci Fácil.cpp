#include<stdio.h>
int main ()
{
	int n,n1=0,i=0,n2=1;
	scanf("%d",&n);
	while (n>i)
	{	
		if(i==0)
			printf("%d",n1);
		else
			printf(" %d",n2);
		int temp = n1+n2;
		n1=n2;
		n2=temp;
		i++;
	}
	printf("\n");
	return 0;
}
