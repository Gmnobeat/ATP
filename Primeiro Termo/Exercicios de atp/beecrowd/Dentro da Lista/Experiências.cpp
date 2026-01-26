#include<stdio.h>
int main ()
{
	float percs,percr,percc;
	int	qtd,i=1,quantia,total_cobaia=0,total_coelhos=0,total_ratos=0,total_sapos=0;
	char cobaia;
	scanf("%d",&qtd);
	while(qtd>=i)
	{
		scanf("%d %c",&quantia, &cobaia);
		total_cobaia=total_cobaia+quantia;
		if(cobaia=='C')
			total_coelhos=total_coelhos+quantia;
		else
			if(cobaia=='R')
				total_ratos=total_ratos+quantia;
			else
				if(cobaia=='S')
					total_sapos=total_sapos+quantia;
		i=i+1;
		
	}
	percc=total_coelhos*100.0/total_cobaia;
	percr=total_ratos*100.0/total_cobaia;
	percs=total_sapos*100.0/total_cobaia;
	printf("Total: %d cobaias\n",total_cobaia);
	printf("Total de coelhos: %d\n",total_coelhos);
	printf("Total de ratos: %d\n",total_ratos);
	printf("Total de sapos: %d\n",total_sapos);
	printf("Percentual de coelhos: %.2f %%\n",percc);
	printf("Percentual de ratos: %.2f %%\n",percr);
	printf("Percentual de sapos: %.2f %%\n",percs);

	
	return 0;
}
