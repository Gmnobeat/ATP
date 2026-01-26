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
	for(j=0;j<tf*2;j++)//ou pode usar tmb dois contadores no for  ex for(x;x<y;x++;j++)
	{
		vet3[j]=vet1[i];
		j++;
		vet3[j]=vet2[i];
		i++;
	}
	for(j=0;j<tf*2;j++)
		printf("%d,",vet3[j]);
	return 0;
}
