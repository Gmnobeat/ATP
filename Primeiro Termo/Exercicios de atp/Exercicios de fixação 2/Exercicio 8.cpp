#include<stdio.h>

int main ()
{
	float preco;
	int codigo;
	printf("digite o preco do produto\n");
	scanf("%f", &preco);
	printf("digite o codigo do produto\n");
	scanf("%d", &codigo);
	switch(codigo)
	{
		case 1: printf("sul");
				break;
		case 2: printf("norte");
				break;
		case 3: printf("leste");
				break;
		case 4: printf("oeste");
				break;
		case 5: case 6:
				printf("nordeste");
		case 7: case 8: case 9:
				printf("sudeste");
				break;
		default:	
				if (10>=codigo && codigo<=20)
					printf("centro oeste");
				else
					if (codigo>=21 && codigo<=30);
					printf("noroeste");
			
	}
	return 0;

}
