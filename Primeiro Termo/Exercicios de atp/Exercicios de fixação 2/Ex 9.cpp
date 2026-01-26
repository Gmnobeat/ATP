#include<stdio.h>
int main ()
{
	int n2,n1,r1,r2,soma,sub,mul;
	float div;
	printf("digite 2 numeros\ ");
	scanf("%d%d", &n1,&n2);
	r1=n1%2;
	r2=n2%2;
	if(r1=0)
		printf("o numero %d e par\n",n1);
	else
		printf("o numero %d e impar\n",n1);
	if(r2=0)
		printf("o numero %d e par\n",n2);
	else
		printf("o numero %d e impar\n",n2);
	if (r1==0 || r2==0)
		{
			soma=n1+n2;
			printf("o resultado da soma e %d",soma);
		}
	else
		if(r1==1 || r2==1)
			{
				sub=n1-n2;
				printf("o resultado e %d",sub);
			}
		else
			if (r1==0 || r2==1)
			{
				mul=n1*n2;
				printf("o resultado e %d",mul);
			}
			else
				if (r1==1 || r2==0)
					{
						div=n1/n2;
						printf("o resultado é %f",div);
					}
		return 0;
		
}
