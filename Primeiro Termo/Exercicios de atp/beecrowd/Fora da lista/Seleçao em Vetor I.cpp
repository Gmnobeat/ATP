#include<stdio.h>
#define tf 100
int main ()
{
	int i;
	float vet[tf],n1;
	for(i=0;i<tf;i++)
	{
		scanf("%f",&vet[i]);
		if(vet[i]<=10)
			printf("A[%d] = %.1f\n",i,vet[i]);
	}
}
