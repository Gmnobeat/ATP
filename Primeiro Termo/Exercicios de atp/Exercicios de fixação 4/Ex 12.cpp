#include<stdio.h>
#include<math.h>
int main ()
{
	int aluno=1,mat,aula,reprova=0,reprova_aula=0;
	float n1,n2,n3,maior=0,menor=pow(2,31),media,media_turma=0,porcrep;
	while (aluno<=3)
	{
		printf("Digite o numero da matricula:\n");
		scanf("%d",&mat);
		printf("Digite suas notas:\n");
		scanf("%f%f%f",&n1,&n2,&n3);
		printf("Frequencia de aula:\n");
		scanf("%d",&aula);
		media=(n1+n2+n3)/3;
		if(media>maior)
			maior=media;
		if(media<menor)
			menor=media;
		media_turma+=media;
		if(media<6 || aula<40)
			reprova++;
		if(aula<40)
			reprova_aula++;
		aluno++;
		printf("Sua media foi de %.2f\n",media);
	}
	porcrep=(float)reprova_aula/reprova*100;
	media_turma/=100;
	printf("A media maior = %.2f, media menor = %.2f\n",menor,maior);
	printf("A media da turma foi = %.2f\n",media_turma);
	printf("O total de reprova foi = %d\n",reprova);
	printf("A porcentagem de reprova por falta foi = %.2f",porcrep);
	return 0;
}
