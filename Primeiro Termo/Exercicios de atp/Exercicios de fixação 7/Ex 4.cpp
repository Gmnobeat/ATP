#include<stdio.h>
#define tf 12
int main ()
{
	int	i,j,f;
	float temp[tf],menor=9999,maior=0;
	for(i=0;i<tf;i++)
	{
		printf("Diigte a temp. media do mes %d\n",i+1);
		scanf("%f",&temp[i]);
	}
	for(i=0;i<tf;i++)
	{
		if(temp[i]<menor)
		{
			menor=temp[i];
			f=i;
		}
		if(temp[i]>maior)
		{
			maior=temp[i];
			j=i;
		}
	}
	printf("A temp maior foi %.2f na posição %d\n",maior,j);
	printf("A menor temp foi %.2f na posição %d\n",menor,f);
	return 0;
	
}
