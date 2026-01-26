#include<stdio.h>
#define tf 10
int main ()
{
	int i,conta=0,contr=0,contm=0;
	float n1[tf],n2[tf],media[tf],mediag;
	for(i=0;i<tf;i++)
	{
		printf("Digte a nota da primeira prova:\n");
		scanf("%f",&n1[i]);
	}
	for(i=0;i<tf;i++)
	{
		printf("Digte a nota da segunda prova:\n");
		scanf("%f",&n2[i]);
	}
	for(i=0;i<tf;i++)
	{
		media[i]=(n1[i]+n2[i])/2;
		if(media[i]>=7)
			conta++;
		if(media[i]<7)
			contr++;
	}
	for(i=0;i<tf;i++)
		mediag+=media[i];
	mediag=mediag/10;
	for(i=0;i<tf;i++)
		if(mediag>media[i])
			contm++;
	printf("qtde de alunos a cima da media da turma = %d\n",contm);
	printf("qtde de alunos aprovados = %d\n",conta);
	printf("qtde de alunos reprovados = %d\n",contr);
	return 0;
}
