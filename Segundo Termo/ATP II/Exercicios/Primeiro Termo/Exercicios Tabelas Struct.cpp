#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include<time.h>

#define TF 2

struct TpAlunos
{
	char RA[13],Nome[20];	
};

struct TpDisciplinas
{
	int Cod;
	char Disc[20];
};

struct TpNotaAlu
{
	int Cod;
	char RA[13];
	float Nota;
};

int BuscaAlunos(TpAlunos Aluno[TF],int TL,char RA[13])		//Busca do RA na struct TpAlunos
{
	int i=0;
	while (i<TL && stricmp(Aluno[i].RA,RA)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return-1;
}

int BuscaDisciplina(TpDisciplinas Disciplina[TF],int TL,int Cod)	//busca do Cod na struct TpDisciplina
{
	int i=0;
	while (i<TL && Disciplina[i].Cod!=Cod)
		i++;
	if(i<TL)
		return i;
	else
		return-1;
}

int BuscaRA_Notas(TpNotaAlu Nota[TF],int TL, char RA[13])		//Busca do RA na struct TpNotaAlu
{
	int i=0;
	while (i<TL && stricmp(Nota[i].RA,RA)!=0)
		i++;
	if(i<TL)
		return i;
	else
		return-1;
}

int BuscaCod_Notas(TpNotaAlu Nota[TF],int TL,int Cod)	//busca do Cod na struct TpNotaAlu
{
	int i=0;
	while (i<TL && Nota[i].Cod!=Cod)
		i++;
	if(i<TL)
		return i;
	else
		return-1;
}

void CadasatroAluno (TpAlunos Aluno[TF], int &TL)
{
	int Achou;
	char Aux,AuxRA[13];
	do 
	{
		if(TL<TF)
		{
			printf("Digite o RA do aluno:\n");
			fflush(stdin);
			gets(AuxRA);
			Achou = BuscaAlunos(Aluno,TL,AuxRA);
			if(Achou != -1)
			{
				printf("Esse RA ja existe, Deseja cadastrar outro?\n[S] Sim\n[N] Nao\n");
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'N')
					printf("Aperte em algum botao para sair\n");
				else
						if(Aux == 'S')
						printf("Aperte em algum botao para continuar com o cadastro\n");
					else
					{
						printf("Nao existe esta opcao, voce saira do cadastro\n");
						Aux = 'N';
					}	
			}
			else
			{
				strcpy(Aluno[TL].RA,AuxRA);
				printf("Digite o nome do aluno:\n");
				gets(Aluno[TL].Nome);
					printf("Deseja continuar cadastrando?\n[S] Sim\n[N] Nao\n");
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'N')
					printf("Aperte em algum botao para sair\n");
				else
					if(Aux == 'S')
						printf("Aperte em algum botao para continuar com o cadastro\n");
					else
					{
							printf("Nao existe esta opcao, voce saira do cadastro\n");
						Aux = 'N';
				}	
				TL++;
			}
		}
		else
		{
			printf("O vetor esta cheio!!\n");
			Aux = 'N';
		}
		getch();
	}while(Aux != 'N');	
}

void CadasatroDisciplina (TpDisciplinas Disciplina[TF], int & TL)
{
	int Achou, AuxCod;
	char Aux;
	do 
	{
		if(TL<TF)
		{
			printf("Digite o Codigo da Disciplina:\n");
			scanf("%d",&AuxCod);
			Achou = BuscaDisciplina(Disciplina,TL,AuxCod);
			if(Achou != -1)
			{
				printf("Esse Cod ja existe, Deseja cadastrar outro?\n[S] Sim\n[N] Nao\n");
				fflush(stdin);
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'N')
					printf("Aperte em algum botao para sair\n");
				else
					if(Aux == 'S')
						printf("Aperte em algum botao para continuar com o cadastro\n");
					else
					{
						printf("Nao existe esta opcao, voce saira do cadastro\n");
						Aux = 'N';
					}	
			}
			else
			{
				Disciplina[TL].Cod = AuxCod;
				printf("Digite o nome da Disciplina:\n");
				fflush(stdin);
				gets(Disciplina[TL].Disc);
				printf("Deseja continuar cadastrando?\n[S] Sim\n[N] Nao\n");
				fflush(stdin);
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'N')
					printf("Aperte em algum botao para sair\n");
				else
					if(Aux == 'S')
						printf("Aperte em algum botao para continuar com o cadastro\n");
					else
					{
						printf("Nao existe esta opcao, voce saira do cadastro\n");
						Aux = 'N';
					}	
				TL++;
			}
		}
		else
		{
			printf("O vetor esta cheio!!\n");
			Aux = 'N';
		}
		getch();
	}while(Aux != 'N');	
}

void CadasatroNota (TpNotaAlu NotaAlu[TF], int & TLN, TpDisciplinas Disciplina[TF], int & TLD, TpAlunos Aluno[TF], int &TLA)
{
	int Achou, AuxCod;
	char Aux,AuxRA[13];
	do 
	{
		if(TLN<TF)
		{
			printf("Digite o RA do aluno:\n");
			fflush(stdin);
			gets(AuxRA);
			Achou = BuscaAlunos(Aluno,TLA,AuxRA);
			if(Achou != -1)
			{
				strcpy(NotaAlu[TLN].RA,AuxRA);
				printf("Digite o Cod da disciplina:\n");
				scanf("%d",&AuxCod);
				Achou = BuscaDisciplina(Disciplina,TLD,AuxCod);
				if(Achou != -1)
				{
					NotaAlu[TLN].Cod = AuxCod;
					printf("Digite a nota desse aluno:\n");
					scanf("%f",&NotaAlu[TLN].Nota);
					printf("Deseja continuar cadastrando?\n[S] Sim\n[N] Nao\n");
					fflush(stdin);
					scanf("%c",&Aux);
					Aux = toupper(Aux);
					if(Aux == 'N')
						printf("Aperte em algum botao para sair\n");
					else
						if(Aux == 'S')
							printf("Aperte em algum botao para continuar com o cadastro\n");
						else
						{
							printf("Nao existe esta opcao, voce saira do cadastro\n");
							Aux = 'N';
						}	
					TLN++;	
				}
				else
				{
					printf("Esse Cod nao existe, volte ao menu e cadastre um novo\n");
					Aux = 'N';	
				}						
			}
			else
			{
				printf("Esse RA nao existe, volte ao menu e cadastre um novo\n");
				Aux = 'N';	
			}	
		}
		else
		{
			printf("O vetor esta cheio!!\n");
			Aux = 'N';
		}
		getch();
	}while(Aux != 'N');	
}

void CodExclusaoAluno(TpAlunos Aluno[TF],int &TL, int Pos)
{
	int i;
	for(i=Pos;i<TL-1;i++)
		Aluno[i] = Aluno[i+1];
	TL--;	
}

void CodExclusaoNotaAlu(TpNotaAlu Nota[TF],int &TL, int Pos)
{
	int i;
	for(i=Pos;i<TL-1;i++)
		Nota[i] = Nota[i+1];
	TL--;	
}

void CodExclusaoDisciplina(TpDisciplinas Disciplina[TF], int & TL, int Pos)
{
	int i;
	for(i=Pos;i<TL-1;i++)
		Disciplina[i] = Disciplina[i+1];
	TL--;	
}

void ExlusaoAluno(TpAlunos Aluno[TF],int & TLA, TpNotaAlu Nota[TF],int &TLN)
{
	int Achou,Achou1;
	char AuxRA[13],Aux;
	do
	{
		printf("Digite o RA que deseja Excluir:\n");
		fflush(stdin);
		gets(AuxRA);
		Achou = BuscaAlunos(Aluno,TLA,AuxRA);
		if(Achou != -1)
		{
			Achou1 = BuscaRA_Notas(Nota,TLN,AuxRA);
			if(Achou1 != -1)
			{
				printf("Esse RA esta cadastrado No boletim\n");
				printf("Voce deseja realmente excluir dos 2?\n[S] Sim\n[N] Nao\n");
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'S')
				{
					CodExclusaoAluno(Aluno,TLA,Achou);
					CodExclusaoNotaAlu(Nota,TLN,Achou1);
					printf("O Aluno foi excluido dos 2 vetor\n");
				}
				else
				{
					printf("O Aluno nao foi excluido\n");
					Aux = 'N';
				}	
			}
			else
			{
				CodExclusaoAluno(Aluno,TLA,Achou);
				printf("O Aluno ja foi excluido\n");
			}		
		}
		else
		{
			printf("Esse RA nao existe para ser excluido!\n");
			Aux = 'N';
		}
		getch();
		printf("Deseja continuar Excluindo?\n[S] Sim\n[N] Nao\n");
		scanf("%c",&Aux);
		Aux = toupper(Aux);
		if(Aux == 'N')
			printf("Aperte em algum botao para sair\n");
		else
			if(Aux == 'S')
				printf("Aperte em algum botao para continuar com a exclusao\n");
			else
			{
				printf("Nao existe esta opcao, voce saira da exclusao\n");
				Aux = 'N';
			}	
		getch();	
	}while(Aux != 'N');
}

void ExclusaoDisciplina(TpDisciplinas Disciplina[TF], int &TLD, TpNotaAlu Nota[TF],int &TLN )
{
	int Achou,Achou1,AuxCod;
	char Aux;
	do
	{
		printf("Digite o cod da Disciplina que deseja Excluir:\n");
		scanf("%d",&AuxCod);
		Achou = BuscaDisciplina(Disciplina,TLD,AuxCod);
		if(Achou != -1)
		{
			Achou1 = BuscaCod_Notas(Nota,TLN,AuxCod);
			if(Achou1 != -1)
			{
				printf("Essa Disciplina esta cadastrada No boletim\n");
				printf("Voce deseja realmente excluir dos 2?\n[S] Sim\n[N] Nao\n");
				fflush(stdin);
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'S')
				{
					CodExclusaoDisciplina(Disciplina,TLD,Achou);
					CodExclusaoNotaAlu(Nota,TLN,Achou1);
					printf("A Disciplina foi excluida dos 2 vetor\n");
				}
				else
				{
					printf("A Disciplina nao foi excluida\n");
					Aux = 'N';
				}
			}
			else
			{
				CodExclusaoDisciplina(Disciplina,TLD,Achou);
				printf("A Disciplina ja foi excluida\n");
			}	
		}
		else
		{
			printf("Esse Codigo nao existe para ser excluido!\n");
			Aux = 'N';	
		}
		getch();
		printf("Deseja continuar Excluindo?\n[S] Sim\n[N] Nao\n");
		fflush(stdin);
		scanf("%c",&Aux);
		Aux = toupper(Aux);
		if(Aux == 'N')
			printf("Aperte em algum botao para sair\n");
		else
			if(Aux == 'S')
				printf("Aperte em algum botao para continuar com a exclusao\n");
			else
			{
				printf("Nao existe esta opcao, voce saira da exclusao\n");
				Aux = 'N';
			}
		getch();		
	}while(Aux != 'N');
}

void ExclusaoNota(TpNotaAlu Nota[TF], int &TLN, TpDisciplinas Disciplina[TF], int &TLD, TpAlunos Aluno[TF],int & TLA)
{

	int Achou,Achou1;
	char AuxRA[13],Aux;
	do
	{
		printf("Digite o RA que deseja Excluir:\n");
		fflush(stdin);
		gets(AuxRA);
		Achou = BuscaAlunos(Aluno,TLA,AuxRA);
		if(Achou != -1)
		{
			Achou1 = BuscaRA_Notas(Nota,TLN,AuxRA);
			if(Achou1 != -1)
			{
				printf("Esse RA esta cadastrado No boletim\n");
				printf("Voce deseja realmente excluir dos 2?\n[S] Sim\n[N] Nao\n");
				scanf("%c",&Aux);
				Aux = toupper(Aux);
				if(Aux == 'S')
				{
					CodExclusaoAluno(Aluno,TLA,Achou);
					CodExclusaoNotaAlu(Nota,TLN,Achou1);
					printf("O Aluno foi excluido dos 2 vetor\n");
				}
				else
				{
					printf("O Aluno nao foi excluido\n");
					Aux = 'N';
				}	
			}
			else
			{
				CodExclusaoAluno(Aluno,TLA,Achou);
				printf("O Aluno ja foi excluido\n");
			}		
		}
		else
		{
			printf("Esse RA nao existe para ser excluido!\n");
			Aux = 'N';
		}
		getch();
		printf("Deseja continuar Excluindo?\n[S] Sim\n[N] Nao\n");
		scanf("%c",&Aux);
		Aux = toupper(Aux);
		if(Aux == 'N')
			printf("Aperte em algum botao para sair\n");
		else
			if(Aux == 'S')
				printf("Aperte em algum botao para continuar com a exclusao\n");
			else
			{
				printf("Nao existe esta opcao, voce saira da exclusao\n");
				Aux = 'N';
			}	
		getch();	
	}while(Aux != 'N');	
}
char Menu (void)
{
	printf("### Menu ###\n");
	printf("[A] Alunos\n");
	printf("[B] Disciplinas\n");
	printf("[C] Notas\n");
	printf("[ESC] Sair\n");
	return toupper(getch());
}

char Menu1 (char nome[20])
{
	printf("### %s ###\n",nome);
	printf("[A] Cadastro\n");
	printf("[B] Exclusao\n");
	printf("[C] Alteracao\n");
	printf("[ESC] Voltar\n");
	return toupper(getch());
}

int main (void)
{
	TpAlunos TabAluno[TF];
	TpDisciplinas TabDisciplina[TF];
	TpNotaAlu TabNotaAlu[TF];
	int TLA=0 , TLD=0 , TLN=0;
	char Op,Op1;
	do
	{
		clrscr();
		Op = Menu();
		switch(Op)
		{
			case 'A':	clrscr();
						Op1 = Menu1 ("Alunos");
						switch(Op1)
						{
							case 'A':	clrscr();
										CadasatroAluno (TabAluno,TLA);
										break;
							case 'B':	clrscr();
										ExlusaoAluno(TabAluno,TLA,TabNotaAlu,TLN);
										break;
							case 'C':	clrscr();
										break;
						}
						break;
			case 'B':	clrscr();
						Op1 = Menu1 ("Disciplina");
						switch(Op1)
						{
							case 'A':	clrscr();
										CadasatroDisciplina (TabDisciplina,TLD);
										break;
							case 'B':	clrscr();
										ExclusaoDisciplina(TabDisciplina,TLD,TabNotaAlu,TLN);
										break;
							case 'C':	clrscr();
										break;
						}
						break;
			case 'C':	clrscr();
						Op1 = Menu1 ("Notas");
						switch(Op1)
						{
							case 'A':	clrscr();
										CadasatroNota (TabNotaAlu,TLN,TabDisciplina,TLD,TabAluno,TLA);
										break;
							case 'B':	clrscr();
										break;
										
							case 'C':	clrscr();
										break;
						}
						break;
		}				
	}while(Op!=27);
	return 0;
}
