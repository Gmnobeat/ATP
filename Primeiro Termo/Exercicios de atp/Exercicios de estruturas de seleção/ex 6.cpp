#include<stdio.h>
int main ()
{
	char resp;
	printf("e mamifero?\n");
	scanf("%c",&resp);
	if (resp=='s' || resp=='S')
	{
		printf("e quadrupede?\n");
		scanf(" %c",&resp);
		if (resp=='s' || resp=='S')
		{
			printf("e carnivoro?\n");
			scanf(" %c",&resp);
			if (resp=='s' || resp=='S')
				printf("Leao");
			else
			{
				printf("e herbivoro?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("cavalo");
				else
					printf("animal desconhecido");
			}
		}
		else
		{
			printf("e bipede?\n");
			scanf(" %c",&resp);
			if (resp=='s' || resp=='S')
			{
				printf("e onivoro?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("Homem");
				else
				{
					printf("e frutifero?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("macaco");
					else
						printf("animal desconhecido");
				}
			}
			else
			{
				printf("e voador?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("morcego");
				else
				{
					printf("e aquatico?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("baleia");
					else
						printf("animal desconhecido");
				}	
			}
			
		}
		
	}
	else
	{
		printf("e ave?\n");
		scanf(" %c",&resp);
		if (resp=='s' || resp=='S')
		{
			printf("e nao-voador?\n");
			scanf(" %c",&resp);
			if (resp=='s' || resp=='S')
			{
				printf("e topical?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("avestruz");
				else
					printf("e polar?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("pinguim");
					else
						printf("animal desconhecido");
			
			}
			else
			{
				printf("e nadadoras?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("pato");
				else
					printf("e de rapina?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("Aguia");
					else
						printf("animal desconhecido");
			}
				
		}
		else
		{
			printf("e repteis?\n");
			scanf(" %c",&resp);
			if (resp=='s' || resp=='S')
			{
				printf("e com casco?\n");
				scanf(" %c",&resp);
				if (resp=='s' || resp=='S')
					printf("Tartaruga");
				else
				{
					printf("e carnivoro?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("Crocodilo");
					else
					{
						printf("e sem patas?\n");
					scanf(" %c",&resp);
					if (resp=='s' || resp=='S')
						printf("Cobra");
					else
						printf("animal desconhecido");
					}
				}
			}
			else
				printf("animal desconhecido");
		}
	}	
	return 0;
}
