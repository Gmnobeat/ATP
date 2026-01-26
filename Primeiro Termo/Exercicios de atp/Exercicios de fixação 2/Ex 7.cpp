#include<stdio.h>
int main ()
{
	int i;
	printf("Digite sua idade\n");
	scanf("%d",&i);
	if(i>=5 && i<=7)
		printf("sua categoria e infantil A");
	else
		if(i>=8 && i<=10)
			printf("sua categoria e infantil B");
		else
			if(i>=11 && i<=13)
				printf("sua categoria e juvenil A");
			else
				if(i>=14 && i<=17)
					printf("sua categoria e juvenil B");
				else
					if(i>=18)
						printf("sua categoria e senior");
	return 0;
}
