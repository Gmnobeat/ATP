#include <stdio.h>
#define tf 6
int main ()
{
	int vet1[tf],i,rest,cont1=0,cont2=0;
	for(i=0;i<tf;i++)
	{
		printf("Digite o %do numero\n",i+1);
		scanf("%d",&vet1[i]);
	}
	for(i=0;i<tf;i++)
	{
		rest=vet1[i]%2;
		if(rest==1)
			cont1++;
		if(rest==0)
			cont2++;
	}
	printf("A quantidade de pares foi de %d e de imperes foi de %d\n",cont2,cont1);
}
