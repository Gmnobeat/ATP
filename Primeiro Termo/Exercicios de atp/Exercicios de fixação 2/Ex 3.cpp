#include<stdio.h>
int main ()
{
	float n1,n2,n3,media;
	printf("digite as notas do aluno\n");
	scanf("%f%f%f",&n1,&n2,&n3);
	media=(n1*2+n2*3+n3*5)/10;
	if (media>=8)
		printf("A\n");
	else
		if (media>=7 && media<8)
			printf("B\n");
		else
			if(media>=6 && media<7)
				printf ("C\n");
			else
				if(media>=5 && media<6)
					printf("D\n");
				else
					if (media<5)
						printf("E\n");
					else
						printf("Algo deu errado\n");
	return 0;
}
