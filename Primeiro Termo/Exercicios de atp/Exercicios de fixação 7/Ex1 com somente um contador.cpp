#include <stdio.h>
#define tf 5
int main()
{
	int vet1[tf],vet2[tf],vet3[tf*2],i,j;
	for(i=0;i<tf;i++)
	{
		printf("Digite o %do numero\n",i+1);
		scanf("%d",&vet1[i]);
	}
	for(i=0;i<tf;i++)
	{
		printf("Digite o %do numero\n",i+1);
		scanf("%d",&vet2[i]);
	}
	i=0;
	for(i=0;i<tf*2;i++)//ou pode usar tmb dois contadores no for  ex for(x;x<y;x++,j++)
	{
		vet3[i*2]=vet1[i];
		vet3[i*2+1]=vet2[i];
	}
	for(i=0;i<tf*2;i++)
		printf("%d,",vet3[i]);
	return 0;
}
