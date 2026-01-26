#include<stdio.h>
int main ()
{
	int idade,i=0;
	float altura,alturatotal,media;
	printf("Digite a sua idade e sua altura\n");
	scanf("%d%f",&idade,&altura);
	while(idade>0)
	{
		if(idade>50)
		{
			alturatotal+=altura;
			i++;
		}
		printf("Digite a idade e sua altura\n");
		scanf("%d%f",&idade,&altura);
	}
	media=alturatotal/i;
	printf("A media de altura de pessoas com mais de 50 anos e de %.2f\n",media);

	
}
