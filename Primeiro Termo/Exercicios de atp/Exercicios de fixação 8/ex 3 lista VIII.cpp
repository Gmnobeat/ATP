#include<stdio.h>
#define tf 10
int main()
{
	int vet1[tf],vet2[tf],i=0,j=0,tl=0;
	for(i=0;i<tf;i++)
	{
		printf("Digite o %do numero: \n",i+1);
		scanf("%d",&vet1[i]);
		tl++;
	}
	for(i=0;j<tl;i++)
	{
		if(vet1[i]<0)
		{
			vet2[j]=vet1[i];
			j++;
		}
		else
		{
			vet2[tl-1]=vet1[i];
			tl--;
		}
	}
	for(i=0;i<tf;i++)
		printf("%d ",vet2[i]);
}
