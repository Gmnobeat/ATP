#include <stdio.h>
#include <math.h>
#define tf 1000
int main()
{
	int vet[tf],num,menor=pow(2,31)-1,pos,i;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&vet[i]);
		if(vet[i]<menor)
		{
			menor=vet[i];
			pos=i;
		}
	}
	printf("Menor valor: %d\nPosicao: %d\n",menor,pos);
	return 0;
}
