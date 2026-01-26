#include<stdio.h>
#include<math.h>
int main ()
{
	int qtde_la;
	float area_b,area_l,h,r,custo,qtde_l,area_c;
	printf("Digite a altura e o raio do tanque\n");
	scanf("%f%f",&h,&r);
	area_b=3.1415*pow(r,2);
	area_l=2*3.1415*r*h;
	area_c=area_b+area_l;
	qtde_l=area_c/3;
	qtde_la=qtde_l/5;
	custo=qtde_la*50;
	printf("A qunatidade de latas de tintas a serem gastas e %d\n",qtde_la);
	printf("O custo foi de %.2f\n",custo);
	
	return 0;
}
