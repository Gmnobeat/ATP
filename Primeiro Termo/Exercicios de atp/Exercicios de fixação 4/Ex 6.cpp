#include<stdio.h>
int main ()
{
	int fat,resp,frag=1;
	printf("Digite o valor desejado\n");
	scanf("%d",&fat);
	while(fat>1)
	{
		if(fat==0)
		{
			resp=1;
			fat=0;
		}
		else
		{
			if(frag==1)
			{
				frag=2;
				resp=fat*(fat-1);
				fat-=2;
			}
			else
			{
				resp*=fat;
				fat--;
			}
		}
	}
	printf("A resposta foi %d\n",resp);
	return 0;
}
