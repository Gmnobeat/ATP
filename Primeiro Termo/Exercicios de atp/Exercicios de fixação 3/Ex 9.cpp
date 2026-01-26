#include<stdio.h>
int main ()
{
	int horas_extras,horas_faltas,cont=1,frag=0,min_extra,min_faltas,horas_faltas_convertida,horas_extra_convertida;
	float hora;
	printf("Digite o numoero de horas extras e de horas faltas\n");
	scanf("%d%d",&horas_extras,&horas_faltas);
	while (cont!=0)
	{
		if(frag==1)
		{
			printf("Digite o numoero de horas extras e de horas faltas\n");
			scanf("%d%d",&horas_extras,&horas_faltas);
		}

		hora=horas_extras-(2.0/3.0)*horas_faltas;
		horas_extra_convertida = horas_extras / 60;
        min_extra = horas_extras % 60;
        horas_faltas_convertida = horas_faltas / 60;
        min_faltas = horas_faltas % 60;
		if(hora>2400)
			printf("horas extra em horas sao %d e %d min, horas faltas sao %d e %d min com um bonus de 500 reais\n",horas_extra_convertida,min_extra,horas_faltas_convertida,min_faltas);
		else
			if(hora>1800 && hora<=2400)
				printf("horas extra em horas sao %d e %d min, horas faltas sao %d e %d min com um bonus de 400 reais\n",horas_extra_convertida,min_extra,horas_faltas_convertida,min_faltas);
			else
				if(hora>1200 && hora<=1800)
					printf("horas extra em horas sao %d e %d min, horas faltas sao %d e %d min com um bonus de 300 reais\n",horas_extra_convertida,min_extra,horas_faltas_convertida,min_faltas);
				else
					if(hora>600 && hora<=1200)
						printf("horas extra em horas sao %d e %d min, horas faltas sao %d e %d min com um bonus de 200 reais\n",horas_extra_convertida,min_extra,horas_faltas_convertida,min_faltas);
					else
						printf("horas extra em horas sao %d e %d min, horas faltas sao %d e %d min com um bonus de 100 reais\n",horas_extra_convertida,min_extra,horas_faltas_convertida,min_faltas);
		frag=1;
		printf("continua? se sim digite 1 senao digite 0\n");
		scanf("%d",&cont);
	}
	return 0;
}
