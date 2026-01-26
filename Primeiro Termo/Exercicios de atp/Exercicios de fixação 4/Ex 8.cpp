#include<stdio.h>
int main ()
{
	int vot,cand1=0,cand2=0,cand3=0,cand4=0,nulo=0,branco=0;
	float porc;
	printf("Digite o codigo desejado\n");
	scanf("%d",&vot);
	while(vot!=0)
	{
		switch(vot)
		{
			case 1: cand1++;
					break;
			case 2: cand2++;
					break;	
			case 3: cand3++;
					break;	
			case 4: cand4++;
					break;
			case 5: nulo++;
					break;
			case 6: branco++;
					break;
			default: printf("Nao existe esse candidato\n");
		}
		printf("Digite o codigo desejado\n");
		scanf("%d",&vot);
	}
	printf("Cand1      Cand2      Cand3       Cand4\n");
	printf(" %d          %d          %d           %d  \n",cand1,cand2,cand3,cand4);
	printf("Votos nulos = %d\n",nulo);
	printf("Votos branco = %d\n",branco);
	porc=(float)(branco+nulo)/(cand1+cand2+cand3+cand4+branco+nulo)*100;
	printf("porcentagem dos votos = %.2f%%\n",porc);
	return 0;
	
	
	
}
