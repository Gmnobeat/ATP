#include<stdio.h>
int main ()
{
	int hri,hrf,mini,minf,final,final2;
	scanf("%d%d%d%d",&hri,&mini,&hrf,&minf);
	if(hri==hrf && mini==minf)
	{
		final=24;
		final2=0;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",final,final2);
	}
	else
	{
		hri*=60;
		hrf*=60;
		mini+=hri;
		minf+=hrf;
		if(minf<mini)
			minf += 24 * 60;
		final2=(minf-mini)%60;
		final=(minf-mini)/60;
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",final,final2);
	}				
	return 0;
}
