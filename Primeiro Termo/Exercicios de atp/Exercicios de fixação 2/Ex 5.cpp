#include<stdio.h>
int main ()
{
	int i;
	printf("digite sua idade\n");
	scanf("%d",&i);
	if (i>=18)
		printf("sua idade e de %d, voce e de maior",i);
	else
		printf("voce ainda nao e maior de idade pois tem %d anos",i);
	
	return 0;
		
}
