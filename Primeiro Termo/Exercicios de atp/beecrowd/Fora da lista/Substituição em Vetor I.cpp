#include<stdio.h>
#define tf 11
int main ()
{
	int vet[tf],i,n1;
	for(i=0;i<=10;i++)
	{
		scanf("%d",&vet[i]);
		if(vet[i]<=0)
			vet[i]=1;
		printf("X[%d] = %d\n",i,vet[i]);
	}
	return 0;
}
