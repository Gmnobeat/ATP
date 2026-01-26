#include<stdio.h>
int main ()
{
	int idade;
	char grupo;
	printf("Digite sua idade:\n");
	scanf("%d",&idade);
	while (idade>=18 && idade<=70)
	{
		printf("Qual seu grupo de risco?\n");
		scanf(" %c",&grupo);
		if(idade>=18 && idade<=24)
			if(grupo=='b'||grupo=='B')
				printf("O codigo e 7\n");
			else
				if(grupo=='M'||grupo=='m')
					printf("O codigo e 8\n");
				else
					printf("O codigo e 9\n");	
		else
			if(idade>=25 && idade<=40)
				if(grupo=='b'||grupo=='B')
					printf("O codigo e 4\n");
				else
					if(grupo=='M'||grupo=='m')
						printf("O codigo e 5\n");
					else
						printf("O codigo e 6\n");	
			else
				if(idade>=41 && idade<=70)
					if(grupo=='b'||grupo=='B')
						printf("O codigo e 1\n");
					else
						if(grupo=='M'||grupo=='m')
							printf("O codigo e 2\n");
						else
							printf("O codigo e 3\n");	
		printf("Digite sua idade:\n");
		scanf("%d",&idade);
	}
	return 0;
}

