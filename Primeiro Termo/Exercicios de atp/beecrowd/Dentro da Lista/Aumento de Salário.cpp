#include<stdio.h>
int main ()
{
	int percentual;
	double sal,salfinal,reajuste;
	scanf("%lf",&sal);
	if(sal<=400)
	{		
		reajuste=sal*0.15;
		salfinal=sal+reajuste;
		percentual=15;
		}	
	else
		if(sal>400 && sal<=800)
		{
			reajuste=sal*0.12;
			salfinal=sal+reajuste;
			percentual=12;
		}
		else
			if(sal>800 && sal<=1200)
			{
				reajuste=sal*0.1;
				salfinal=sal+reajuste;
				percentual=10;
			}
			
			else
				if(sal>1200 && sal<=2000)
				{
					reajuste=sal*0.07;
					salfinal=sal+reajuste;
					percentual=7;
				}
				else
					if(sal>2000)
					{
						reajuste=sal*0.04;
						salfinal=sal+reajuste;
						percentual=4;			
					}
		printf("Novo salario: %.2lf\n",salfinal);
		printf("Reajuste ganho: %.2lf\n",reajuste);
		printf("Em percentual: %d %%\n",percentual);
	
	return 0;
}
