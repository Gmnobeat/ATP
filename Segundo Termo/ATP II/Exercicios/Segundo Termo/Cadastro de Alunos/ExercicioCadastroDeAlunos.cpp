#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//organizacao dos estudos
//1- entender pelo menos uma ordenacao, uma busca e uma inserindo ordenado
//2- Continuar esse exercicio sem olhar no arquivo do trabalho
//3- garantir que nao vou esquecer coisas pequenas como fechar o arquivo
//4- Estudar Teste de mesa
struct TpAluno
{
	char RA[13],Nome[30];
	int Status;
};

struct TpDisciplina
{
	int	Cod,Status;
	char Disciplina[30];
};

struct TpNota
{
	char RA[13];
	int Cod,Status;
	float Nota;
};

void Moldura(void)
{
	int CI=5,CF=20,LI=5,LF=60,i;
	gotoxy(LI,CI);
	printf("%c",222);
	gotoxy(LF,CF);
	printf("%c",222);
	gotoxy(LF,CI);
	printf("%c",222);
	gotoxy(LI,CF);
	printf("%C",222);
	for(i = LI+1; i < LF; i++)
    {
        gotoxy(i,CI);
        printf("%c",205);
        gotoxy(i,CF);
        printf("%c",205);
    }
    for(i = CI+1; i < CF; i++)
    {
        gotoxy(LI,i);
        printf("%c",186);
        gotoxy(LF,i);
        printf("%c",186);
    }
	getch();
}

void BoublesortRA(void)
{
	FILE * PtrAlu = fopen("Aluno.dat","rb+");
	TpAluno Rga,Rgb;
	int TL,a,b;
	fseek(PtrAlu,0,2);
	TL = ftell(PtrAlu)/sizeof(TpAluno);
	for(a=0 ;a<TL-1; a++)
	{
		fseek(PtrAlu,a*sizeof(TpAluno),0);
		fread(&Rga,sizeof(TpAluno),1,PtrAlu);
		for(b=a+1;b < TL; b++)
		{
			fseek(PtrAlu,b*sizeof(TpAluno),0);
			fread(&Rgb,sizeof(TpAluno),1,PtrAlu);
			if(stricmp(Rga.Nome,Rgb.Nome)>0)
			{
				//troca
				fseek(PtrAlu,a*sizeof(TpAluno),0);
				fwrite(&Rgb,sizeof(TpAluno),1,PtrAlu);
				
				fseek(PtrAlu,b*sizeof(TpAluno),0);
				fwrite(&Rga,sizeof(TpAluno),1,PtrAlu);
			}
		}
	}
	fclose(PtrAlu);
}

void InserirOrdenado(FILE *PtrAlu, TpAluno Rg1)
{
    TpAluno Rg2;
    int pos = 0, TL;
    // voltar ao início
    fseek(PtrAlu, 0, 0);
    fread(&Rg2, sizeof(TpAluno), 1, PtrAlu);
    // achar a posição onde inserir
    while(!feof(PtrAlu) && stricmp(Rg1.Nome, Rg2.Nome) > 0 && Rg2.Status == 1)
    {
        pos++;
        fread(&Rg2, sizeof(TpAluno), 1, PtrAlu);
    }
    // descobrir total de registros
    fseek(PtrAlu, 0, 2);
    TL = ftell(PtrAlu) / sizeof(TpAluno);
    // se não é último, precisamos deslocar os outros
    if(pos < TL)
    {
        // desloca do final até 'pos'
        for(int i = TL; i > pos; i--)
        {
            fseek(PtrAlu, (i-1)*sizeof(TpAluno), 0);
            fread(&Rg2, sizeof(TpAluno), 1, PtrAlu);

            fseek(PtrAlu, i*sizeof(TpAluno), 0);
            fwrite(&Rg2, sizeof(TpAluno), 1, PtrAlu);
        }
    }
    // agora grava o novo aluno na posição
    fseek(PtrAlu, pos*sizeof(TpAluno), 0);
    fwrite(&Rg1, sizeof(TpAluno), 1, PtrAlu);
}

int BuscaRAAluno(FILE*PtrAlu, char AuxRA[13])// busca exaustiva
{
	TpAluno Rg;
	fseek(PtrAlu,0,0);//ou rewind(PtrAlu)
	fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	while(!feof(PtrAlu) && !(strcmp(Rg.RA,AuxRA)==0 && Rg.Status == 1))
		fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	if(!feof(PtrAlu))
		return ftell(PtrAlu) - sizeof(TpAluno);
	else
		return -1;
}

int BuscaCodDisciplina(FILE*PtrDisc, int AuxCod)// busca exaustiva
{
	TpDisciplina Rg;
	fseek(PtrDisc,0,0);//ou rewind(PtrAlu)
	fread(&Rg,sizeof(TpDisciplina),1,PtrDisc);
	while(!feof(PtrDisc) && !(Rg.Cod == AuxCod && Rg.Status == 1))
		fread(&Rg,sizeof(TpDisciplina),1,PtrDisc);
	if(!feof(PtrDisc))
		return ftell(PtrDisc) - sizeof(TpDisciplina);
	else
		return -1;
}

void ListagemAlunos(FILE * PtrAlu)
{
	TpAluno Rg;
	rewind(PtrAlu);
	fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	while(!feof(PtrAlu))
	{
		if(Rg.Status == 1)
		{
			printf("RA: %s\n",Rg.RA);
			printf("Nome: %s\n",Rg.Nome);
			printf("\n");
		}
		fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	}
}

void ListagemAlunosParaForaDeFuncoes(void)
{
	FILE * PtrAlu = fopen("Aluno.dat","rb");
	TpAluno Rg;
	fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	while(!feof(PtrAlu))
	{
		if(Rg.Status == 1)
		{
			printf("RA: %s\n",Rg.RA);
			printf("Nome: %s\n",Rg.Nome);
			printf("\n");
		}
		fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	}
	getch();
	fclose(PtrAlu);
}

void CadastroAluno(void)
{
	TpAluno Rg;
	char AuxRA[13];
	int pos;
	FILE *PtrAlu = fopen("Aluno.dat","rb+");
	clrscr();
	if(PtrAlu == NULL)
	{
		textcolor(4);// vermelho de erro
		printf("Erro de Abertura do Arquivo \n");
	}
	else 
	{
		textcolor(2);//verde de correto 
		printf("\n * * * Cadastro De Alunos * * * \n");		
		printf("\nQual o RA a ser cadastrado :(EX: 11.11.1111-1)[Enter] para sair\n");
		fflush(stdin);
		gets(AuxRA);
		while(strcmp(AuxRA,"\0") != 0) 
		{	
			pos = BuscaRAAluno(PtrAlu,AuxRA);
			if(pos == -1)
			{
				strcpy(Rg.RA,AuxRA);
				printf("\nQual o nome do Aluno: \n");
				fflush(stdin);
				gets(Rg.Nome);
				if(strcmp(Rg.Nome,"\0")==0)
				{
					textcolor(4);// vermelho de erro
					printf("Nao pode cadastrar sem pelo menos 1 caracter! \n");	
				}	
				else
				{
					Rg.Status = 1;
					//InsertionSortCPFClient(PtrCli,Rg);
					fseek(PtrAlu,0,2);
					fwrite(&Rg,sizeof(TpAluno),1,PtrAlu);	
				}
			}
			else 
			{	
				textcolor(4);
				printf("\nAluno ja cadastrado  \n");
				
			}
			textcolor(2);
			printf("\nQual o RA a ser cadastrado :(EX: 111.111.111-11)[Enter] para sair\n");
			fflush(stdin);
			gets(AuxRA);
		}
		fclose(PtrAlu);
	}
}

void ExclusaoAlunos(void)
{
	TpAluno Rg;
	FILE * PtrAlu = fopen("Aluno.dat","rb+");
	char AuxRA[13],Op;
	int pos;
	if(PtrAlu == NULL)
	{
		textcolor(4);// vermelho de erro
		printf("Erro de Abertura do Arquivo \n");
	}
	else
	{
		textcolor(2);
		ListagemAlunos(PtrAlu);
		printf("Qual o RA do Aluno que deseja excluir: \n");
		fflush(stdin);
		gets(AuxRA);
		while(strcmp(AuxRA,"\0")!=0)
		{
			pos = BuscaRAAluno(PtrAlu,AuxRA);
			if(pos == -1)
			{
				textcolor(4);// vermelho de erro
				printf("RA nao esta cadastrado! \n");
			}
			else
			{
				fseek(PtrAlu,pos,0);
				fread(&Rg,sizeof(TpAluno),1,PtrAlu);
				printf("RA: %s\n",Rg.RA);
				printf("Nome: %s\n",Rg.Nome);
				printf("Deseja realmente excluir este RA? [S/N]");
				fflush(stdin);
				scanf("%c",&Op);
				Op = toupper(Op);
				if(Op == 'N')
				{
					textcolor(4);// vermelho de erro
					printf("RA nao nao foi excluido! \n");
				}
				else
				{
					Rg.Status = 0;
					fseek(PtrAlu,pos,0);
					fwrite(&Rg,sizeof(TpAluno),1,PtrAlu);
					textcolor(2);
					printf("RA excluido! \n");
				}
			}
			textcolor(2);//verde de correto 
			ListagemAlunos(PtrAlu);
			printf("Digite outro RA do Aluno que deseja excluir [ENTER] para sair: \n");
			fflush(stdin);
			gets(AuxRA);
		}
		fclose(PtrAlu);
	}
}

void AlteracaoAluno(void)
{
	FILE * PtrAlu = fopen("Aluno.dat","rb+");
	TpAluno Rg;
	char AuxRA[13],Op;
	int pos;
	if(PtrAlu == NULL)
	{
		textcolor(4);// vermelho de erro
		printf("Erro de Abertura do Arquivo \n");
	}
	else
	{
		textcolor(2);
		ListagemAlunos(PtrAlu);
		printf("Qual RA deseja alterar\n");
		fflush(stdin);
		gets(AuxRA);
		while(strcmp(AuxRA,"\0") != 0)
		{
			pos = BuscaRAAluno(PtrAlu,AuxRA);
			if(pos == -1)
			{
				textcolor(4);// vermelho de erro
				printf("Aluno nao esta cadastrado \n");
				//perguntar se deseja cadastrar
			}
			else
			{
				fseek(PtrAlu,pos,0);
				fread(&Rg,sizeof(TpAluno),1,PtrAlu);
				printf("\n");
				printf("RA: %s\n",Rg.RA);
				printf("Nome: %s\n",Rg.Nome);
				textcolor(4);// vermelho de erro
				printf("Obs: Nao pode alterar o RA!!\n");
				textcolor(2);
				printf("Ralmente deseja alterar?[S/N]");
				fflush(stdin);
				scanf("%c",&Op);
				Op = toupper(Op);
				if(Op == 'N')
				{
					textcolor(4);// vermelho de erro
					printf("Nao foi alterado! \n");
				}
				else
				{
					printf("Novo Nome: \n");
					fflush(stdin);
					gets(Rg.Nome);
					fseek(PtrAlu,pos,0);
					fwrite(&Rg,sizeof(TpAluno),1,PtrAlu);
					printf("Aluno Alterado!!\n");
				}
			}
			textcolor(2);
			ListagemAlunos(PtrAlu);
			printf("Digite outro RA que deseja alterar ou [ENTER] para sair\n");
			fflush(stdin);
			gets(AuxRA);
		}
		fclose(PtrAlu);
	}
}

void ListagemDisciplina(FILE * PtrDisc)
{
	TpDisciplina Rg;
	rewind(PtrDisc);
	
	while(fread(&Rg,sizeof(TpDisciplina),1,PtrDisc)==1)
		if(Rg.Status == 1)
		{
			printf("Cod: %d\n",Rg.Cod);
			printf("Disciplina: %s\n",Rg.Disciplina);
			printf("Stataus: %d\n",Rg.Status);
		}
}

void CadastroDisciplina(void)
{
	FILE * PtrDisc = fopen("Disciplina.dat","ab+");
	TpDisciplina Rg;
	int AuxCod,pos;
	if(PtrDisc == NULL)
	{
		textcolor(4);// vermelho de erro
		printf("Erro de Abertura do Arquivo \n");
	}
	else
	{
		textcolor(2);
		printf("Digite o codigo que deseja cadastrar\n");
		scanf("%d",&AuxCod);
		while(AuxCod != 0)
		{
			pos = BuscaCodDisciplina(PtrDisc,AuxCod);
			if(pos == -1)
			{
				Rg.Cod = AuxCod;
				Rg.Status = 1;
				printf("Nome da Disciplina:\n");
				fflush(stdin);
				gets(Rg.Disciplina);
				fseek(PtrDisc,0,2);
				fwrite(&Rg,sizeof(TpDisciplina),1,PtrDisc);
				printf("Disciplina cadastrada!!\n");	
			}
			else
			{
				textcolor(4);// vermelho de erro
				printf("Esse cod ja existe!! \n");
			}
			textcolor(2);
			printf("Digite o codigo que deseja cadastrar [0] para sair \n");
			scanf("%d",&AuxCod);
		}
		fclose(PtrDisc);
	}
}

void ExclusaoDisciplina(void)
{
    FILE * PtrDisc = fopen("Disciplina.dat","rb+");
    int AuxCod,pos;
    TpDisciplina Rg;
    char Op;
    if(PtrDisc == NULL)
    {
        textcolor(4);// vermelho de erro
        printf("Erro de Abertura do Arquivo \n");
    }
    else
    {
        textcolor(2);
        ListagemDisciplina(PtrDisc);
        printf("Digite o Cod que deseja excluir!!\n");
        scanf("%d",&AuxCod);
        while(AuxCod != 0)
        {
            pos = BuscaCodDisciplina(PtrDisc,AuxCod);
            if(pos == -1)
            {
                textcolor(4);// vermelho de erro
                printf("Esse cod nao existe!! \n");
            }
            else
            {
                // CORREÇÃO AQUI:
                fseek(PtrDisc, pos, SEEK_SET);

                fread(&Rg,sizeof(TpDisciplina),1,PtrDisc);
                printf("Cod: %d\n",Rg.Cod);
                printf("Disciplina: %s\n",Rg.Disciplina);
                printf("Confirme a exclusao [S/N]\n");
                fflush(stdin);
                scanf("%c",&Op);
                if(Op == 'N')
                {
                    textcolor(4);// vermelho de erro
                    printf("Esse cod nao foi excluido!! \n");
                }
                else
                {
                    Rg.Status = 0;

                    // CORREÇÃO AQUI:
                    fseek(PtrDisc, pos, SEEK_SET);

                    fwrite(&Rg,sizeof(TpDisciplina),1,PtrDisc);
                }
            }
            textcolor(2);
            ListagemDisciplina(PtrDisc);
            printf("Digite o Cod que deseja excluir!!\n");
            scanf("%d",&AuxCod);
        }
        fclose(PtrDisc);
    }
}

void ExclusaoFisicaDisciplina(void)
{
	FILE * PtrDisc = fopen("Disciplina.dat","rb+");
	FILE * PtrTem = fopen("Tem.dat","rb+");
	TpDisciplina Rg;
	fread(&Rg,sizeof(TpDisciplina),1,PtrDisc);
	while(!feof(PtrDisc))
	{
		if(Rg.Status == 1)
			fwrite(&Rg,sizeof(TpDisciplina),1,PtrTem);
		fread(&Rg,sizeof(TpDisciplina),1,PtrDisc);
	}
	fclose(PtrDisc);
	fclose(PtrTem);
	remove("Disciplina.dat");
	rename("Tem.dat","Disciplina.dat");
}

void ExclusaoFisicaAlunos(void)
{
	FILE*PtrAlu= fopen("Aluno.dat","rb+");
	FILE*PtrTem= fopen("Temp.dat","wb");
	TpAluno Rg;
	fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	while(!feof(PtrAlu))
	{
		if(Rg.Status == 1)
			fwrite(&Rg,sizeof(TpAluno),1,PtrTem); 
		fread(&Rg,sizeof(TpAluno),1,PtrAlu);
	}
	fclose(PtrAlu);
	fclose(PtrTem);
	remove("Aluno.dat");
	rename("Temp.dat","Aluno.dat");
}

void AbrirArquivo(void)
{
	FILE *PtrAlu = fopen("Aluno.dat","ab");
	fclose(PtrAlu);
	FILE *PtrDisc = fopen("Disciplina.dat","ab");
	fclose(PtrDisc);
	FILE *PtrNota = fopen("Nota.dat","ab");
	fclose(PtrNota);
}

char Menu(void)
{
	clrscr();
	textcolor(2);
	printf("[A] Alunos\n");
	printf("[B] Disciplinas\n");
	printf("[C] Notas\n");
	printf("[D] listagem completa\n");
	printf("[E] outros\n");
	printf("[ESC] sair\n");
	return toupper(getch());
}

char Menu2(char Nome[40])
{
	clrscr();
	textcolor(2);
	printf("[A] Cadastro %s\n",Nome);
	printf("[B] Exclusoes %s\n",Nome);
	printf("[C] Alteracoes %s\n",Nome);
	printf("[D] listagem %s\n",Nome);
	printf("[E] Ordena Arquivo\n");
	printf("[ESC] sair\n");
	return toupper(getch());
}


int main(void)
{
	char Op,Op2;
	AbrirArquivo();
	do
	{
		Op= Menu();	
		switch(Op)
		{
			case 'A':	do
						{
							Op2 = Menu2("Alunos");
							switch(Op2)
							{
								case 'A':	CadastroAluno();
											break;	
								case 'B':	ExclusaoAlunos();
											break;
								case 'C':	AlteracaoAluno();
											break;
								case 'D':	ListagemAlunosParaForaDeFuncoes();
											break;
								case 'E':	BoublesortRA();
											break;
							
							}			
						}while(Op2 != 27);
						break;
			case 'B':	do
						{
							Op2 = Menu2("Disciplina");
							switch(Op2)
							{
								case 'A':	CadastroDisciplina();
											break;	
								case 'B':	ExclusaoDisciplina();
											break;
								case 'C':
											break;
								case 'D':
											break;
							}	
						}while(Op2 != 27);
						break;
			case 'C':	do
						{
							Op2 = Menu2("Notas");
							switch(Op2)
							{
								case 'A':
											break;	
								case 'B':
											break;
								case 'C':
											break;
								case 'D':
											break;
							}	
						}while(Op2 != 27);
						break;
			case 'D':	
						break;
			case 'E':
						break;
						
		}
		
	}while(Op != 27);
	ExclusaoFisicaAlunos();
	ExclusaoFisicaDisciplina();
	return 0;
}
