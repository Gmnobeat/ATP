#include<stdio.h>
int main ()
{
	int parar=1,angulo,frag=0;
	printf("Digite a medida do angulo:\n");
	scanf("%d",&angulo);
	while (parar!=0)
	{
		if(frag==2)
		{
			printf("Digite a medida do angulo:\n");
			scanf("%d",&angulo);
		}
			if(angulo>360)
				angulo %= 360;
			if((angulo>=0 &&angulo <=90)||(angulo<0&&angulo >=-90))
				printf("Primeiro quadrante\n");
			else
				if((angulo>90&&angulo <=180)||(angulo<-90&&angulo >=-180))
					printf("Segundo quadrante\n");
				else
					if((angulo>180&&angulo <=270)||(angulo<=-180&&angulo >=-240))
						printf("Terceiro quadrante\n");
					else
						printf("Quarto quadrante\n");
		printf("Deseja continuar? se sim digite 1 se nao digite 0\n");
		scanf("%d",&parar);
		frag=2;
	}
	return 0;
}
