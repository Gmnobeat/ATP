#include<stdio.h>
int main ()
{
	float n1,n2,n3,n4,media;
	printf("digite as 4 medias do aluno\n");
	scanf("%f%f%f%f", &n1,&n2,&n3,&n4);
	media= (n1+n2+n3+n4)/4;
	if (media>=7)
		printf ("aprovado");
	else
		printf("reprovado");
	return 0;
}
