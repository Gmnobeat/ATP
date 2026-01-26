#include<stdio.h>
int main ()
{
	int cod,al=0,gaso=0,disel=0;
	scanf("%d",&cod);
	while(cod!=4)
	{
		switch(cod)
		{
			case 1: al++;
					break;
			case 2: gaso++;
					break;
			case 3: disel++;
					break;
			default: break;
		}
		scanf("%d",&cod);
	}
	printf("MUITO OBRIGADO\n");
	printf("Alcool: %d\n",al);
	printf("Gasolina: %d\n",gaso);
	printf("Diesel: %d\n",disel);

}
