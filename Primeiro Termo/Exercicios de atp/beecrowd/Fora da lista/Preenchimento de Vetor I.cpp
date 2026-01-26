#include<stdio.h>
#include<math.h>
#define tf 10
int main ()
{
	int vet[tf],i,v;
	scanf("%d",&v);
	for(i=0;i<tf;i++)
	{
		if(v==1)
			if(i==0)
				vet[i]=v;
			else
				vet[i]=vet[i-1]*2;
		else		
			if(i==0)
				vet[i]=v;
			else
				vet[i]=vet[i-1]*2;
		printf("N[%d] = %d\n",i,vet[i]);
	}
}
