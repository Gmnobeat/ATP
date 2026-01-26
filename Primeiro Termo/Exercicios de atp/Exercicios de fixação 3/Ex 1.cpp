#include<stdio.h>
int main ()
{
	int id,i=1,total=0;
	while (i<=10)
	{
		printf("Digite a sua idade\n");
		scanf("%d",&id);
		if(id>=18)
			total++;
		i++;
	}
	printf("A quantidade de maioras de idade e de %d pessoas\n",total);
}

