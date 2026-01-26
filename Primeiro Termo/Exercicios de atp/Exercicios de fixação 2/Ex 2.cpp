#include <stdio.h>
int main ()
{
	float s,r1,r2;
	printf("digite o salario do funcionario\n");
	scanf("%f", &s);
	if (s<=300)
	{
		r1=s+s*50/100;
		printf("o novo salario do funcionario sera de %.2f\n",r1);
	}
	else
	{
		r2=s+s*30/100;
		printf("o novo salario sera de %.2f\n",r2);
	}
	return 0;
}
