//Brenno Bayan dos santos
//Gustavo Malacrida Mazetti
//Igor Nakamura Moretto
//Leonardo Gabriel Santos Mineo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio2.h>
#include <windows.h>
#include <ctype.h>

#define TF 2

struct TPClientes 
{
	char CPF[16],Nome[50],Telefone[10];
};

struct TPCarros
{
	int CodCar;
	char Modelo[15],Categoria[15];	
	float PrecoDiaria;
};
struct TPLocacao
{
	char CPF[16];
	int CodCar,QtdeDias;
	float ValorLoc;
};

int BuscaCliente(TPClientes TabClint[TF], int TC, char ChaveCPF[16]) 
{
	 int i=0;
	 while(i<TC && strcmp(ChaveCPF,TabClint[i].CPF)!=0)
	 	i++;
	if(i<TC)
		return i;
	else
		return -1;
	
}

int BuscaCarro(TPCarros TabCarros[TF+1],int TCA,int ChaveCar) 
{
	int i=0;
	TabCarros[TCA].CodCar=ChaveCar;
	while(ChaveCar!=TabCarros[i].CodCar)
		i++;
	if(i<TCA)
		return i;
	else
		return -1;
}

int BuscaNaLocCPFeCod (TPLocacao TabLoc[TF], int TCL, char ChaveAux[16] , int ChaveAux2)  
{
	int i=0;
	while(i<TCL && stricmp(ChaveAux,TabLoc[i].CPF)==0 && ChaveAux2==TabLoc[i].CodCar)
		i++;
	if(i<TCL)
		return i;
	else
		return -1;
}

int BuscaLocacaoCPF (TPClientes TabClint[TF], int TC, char ChaveAux[16] )	
{
	int i=0;
	strcpy(TabClint[TC].CPF,ChaveAux);
	while( stricmp(ChaveAux,TabClint[i].CPF)!=0)
		i++;
	if(i<TC)
		return i;
	else
		return -1;
}

int BuscaNaLocCPF (TPLocacao TabLoc[TF], int TCL, char ChaveAux[16] )
{
	int i=0;
	strcpy(TabLoc[TCL].CPF,ChaveAux);
	while( stricmp(ChaveAux,TabLoc[i].CPF)!=0)
		i++;
	if(i<TCL)
		return i;
	else
		return -1;
}

int BuscaLocacaoCod(TPCarros TabCarros[TF], int TCA, int ChaveCod)	
{
	int i=0;
	while(i<TCA && ChaveCod!=TabCarros[i].CodCar)
		i++;
	if(i<TCA)
		return i;
	else
		return -1;
}

int BuscaNaLocCod(TPLocacao TabLoc[TF], int TCL, int ChaveCod )	
{
	int i=0;
	while(i<TCL && ChaveCod!=TabLoc[i].CodCar)
		i++;
	if(i<TCL)
		return i;
	else
		return -1;
}

int BuscaDaCat(TPCarros TabCarros[TF], int TCA, char ChaveCod[15])
{
	int i=0;
	while(i<TCA && stricmp(ChaveCod,TabCarros[i].Categoria)!=0)
		i++;
	if(i<TCA)
		return i;
	else
		return -1;
}

void OrdenaClientesPorCPF(TPClientes TabClint[TF], int TC)
{
    int i, j;
    TPClientes temp;

    for(i = 1; i < TC; i++)
    {
        temp = TabClint[i];
        j = i - 1;

        
        while(j >= 0 && strcmp(temp.CPF, TabClint[j].CPF) < 0)
        {
            TabClint[j+1] = TabClint[j];
            j--;
        }
        TabClint[j+1] = temp;
    }
}
int BuscaCPF (TPClientes TabClint[TF], int TC, char ChaveAux[16] )	
{ 
	OrdenaClientesPorCPF(TabClint,TC);
	int i=0; 
	while (i<TC   &&  stricmp(ChaveAux,TabClint[i].CPF)!=0) 
		i++; 
	if (i<TC  &&  stricmp(ChaveAux,TabClint[i].CPF)==0)      
		return i; 
	else  
		return -1; 
}

void CadastroCliente(TPClientes TabClint[TF], int &TC)
{
	char AuxCPF[16],opcao;
	int Pos;
	clrscr();
	printf(" # # # Cadastrar Cliente :\n");
	printf("\nCPF (EX: 111.111.111-11) : "); fflush(stdin);
	gets(AuxCPF);
	while(TC<TF && strcmp(AuxCPF,"\0")!=0)
	{
		Pos=BuscaCliente(TabClint,TC,AuxCPF);
		if(Pos == -1)
		{
			
			strcpy(TabClint[TC].CPF,AuxCPF);
			printf("\nNome:"); fflush(stdin);
			gets(TabClint[TC].Nome);
			printf("\nTelefone ( EX: 22222-2222) : "); fflush(stdin);
			gets(TabClint[TC].Telefone);
			textcolor(10);
			printf("\nCadastrado!\n");
			TC++;
			OrdenaClientesPorCPF(TabClint, TC);
		}
	
		else
		{
			textcolor(4);
			printf("\nCPF ja Esta Cadastrado!\n");
		}
		
		textcolor(7);
		printf("\nDeseja Cadastrar um Novo Cliente?\n \n[s]SIM\n \n[Enter]Sair");
		opcao=tolower(getch());
		if(TC<TF)
		{
			if(opcao == 's')
			{	
				clrscr();
				printf(" # # # Novo Cadastro # # # ");
				printf("\nCPF ( EX: 111.111.111-11 ) : "); fflush(stdin);
				gets(AuxCPF);
			}
			else
				AuxCPF[0]='\0';
		}
		else
		{
			textcolor(4);
			printf("\nNao tem mais espaco");
			getch();
		}
		
	}
}

void OrdenaCarrosPorCodigo(TPCarros TabCarros[TF], int TCA)
{
    int i, j, minIndex;
    TPCarros temp;

    for(i = 0; i < TCA - 1; i++)
    {
        minIndex = i;
        for(j = i + 1; j < TCA; j++)
        {
            if(TabCarros[j].CodCar < TabCarros[minIndex].CodCar)
                minIndex = j;
        }
        if(minIndex != i)
        {
            temp = TabCarros[i];
            TabCarros[i] = TabCarros[minIndex];
            TabCarros[minIndex] = temp;
        }
    }
}

void CadastroCarros(TPCarros TabCarros[TF],int &TCA)
{
	int pos,AuxCod;
	char opcao;
	clrscr();
	printf("# # # Cadastrar Carro: # # #\n");
	printf("\nCodigo do Carro:");
	scanf("%d",&AuxCod);
	while(TCA<TF  && AuxCod>0)
	{
		pos=BuscaCarro(TabCarros,TCA,AuxCod);
		if(pos == -1)
		{
			TabCarros[TCA].CodCar = AuxCod;
			printf("\nModelo:"); fflush(stdin);
			gets(TabCarros[TCA].Modelo);
			printf("\nCategoria:"); fflush(stdin);
			gets(TabCarros[TCA].Categoria);
			printf("\nPreco da Diaria:"); 
			scanf("%f",& TabCarros[TCA].PrecoDiaria);
			textcolor(10);
			printf("\nCadastrado!\n");
			textcolor(7);
			TCA++;
			OrdenaCarrosPorCodigo(TabCarros, TCA);
		}
		else
		{
			textcolor(4);
			printf("\nCodigo do carro ja esta Cadastrado!\n");
		}
		textcolor(7);	
		printf("\nDeseja Cadastrar um Novo Carro?\n \n[s]SIM\n \n[Enter]Sair");fflush(stdin);
		opcao=tolower(getch());
		if(TCA<TF)	
		{
			if(opcao == 's')
			{	
				clrscr();
				printf(" # # # Novo Cadastro # # # ");
				printf("\nCodigo do Carro:");
				scanf("%d",&AuxCod);
			
			}
			else
				AuxCod=0;
		}
		else
		{
			textcolor(4);
			printf("\nNao tem mais espaco");
			getch();
		}	
	}
}


void CadastroLocacao(TPLocacao TabLoc[TF], int &TCL, TPClientes TabClint[TF], int TC, TPCarros TabCarros[TF], int TCA)
{
	int pos,AuxCod,Pos;
	char AuxCPF[16],opcao;
	clrscr();
	printf(" # # # Cadastrar Locacao:\n");
	printf("\nCPF para Locacao (EX: 111.111.111-11): "); fflush(stdin);
	gets(AuxCPF);
	while (TCL<TF && strcmp(AuxCPF,"\0")!= 0)
	{
		pos = BuscaLocacaoCPF(TabClint, TC, AuxCPF); 
		if(pos == -1)
		{
			printf("Cliente nao cadastrado!\n");
			printf("Deseja Cadastrar Cliente?\n [s]Sim\n [n]Nao\n");fflush(stdin);
			opcao=tolower(getch());
			if(opcao == 's')
			{
				if(TC<TF)
				{	
					strcpy(TabClint[TC].CPF,AuxCPF);
					printf("\nNome:"); fflush(stdin);
					gets(TabClint[TC].Nome);
					printf("\nTelefone:"); fflush(stdin);
					gets(TabClint[TC].Telefone);
					clrscr();
					TC++;
					printf("Cliente cadastrado!!");
					getch();		
				}	
				else
					printf("Nao a mais espaço para novos clientes!");
			}	
			else 
				printf("OK\n");		
		}
		else 
		{
			strcpy(TabLoc[TCL].CPF,AuxCPF);
			printf("\nCodigo do Carro para Locacao: ");
			scanf("%d",&AuxCod);
			pos=BuscaLocacaoCod(TabCarros,TCA,AuxCod);
			if(pos < 0)
			{
				printf("\nCarro nao registrado!");
				printf("\nDeseja Cadastrar Carro?\n [s]SIM\n [n]Nao\n "); fflush(stdin);
				opcao = tolower(getch());
				if(opcao == 's')
				{	
					if (TCL<TF)
					{
						TabCarros[TCA].CodCar = AuxCod;
						printf("\nModelo:"); fflush(stdin);
						gets(TabCarros[TCA].Modelo);
						printf("\nCategoria:"); fflush(stdin);
						gets(TabCarros[TCA].Categoria);
						printf("\nPreco da Diaria:"); 
						scanf("%f",&TabCarros[TCA].PrecoDiaria);
						TCA++;	
						printf("Carro cadastrado!!");
						getch();
					}
					else
						printf("\nSem Esapco no vetor!!");
				}	
				else
					printf("\nOK");
			}	
			else
			{
				TabLoc[TCL].CodCar= AuxCod;
				printf("\nQuantidade de dias desejados : ");
				scanf("%d",&TabLoc[TCL].QtdeDias);
				TabLoc[TCL].ValorLoc = TabLoc[TCL].QtdeDias * TabCarros[pos].PrecoDiaria;
			}
		}
		TCL++;
		textcolor(7);	
		printf("\nDeseja Cadastrar uma Nova Locacao?\n \n[s]SIM\n \n[Enter]Sair");fflush(stdin);
		opcao=tolower(getch());
		if(TCA<TF)	
		{
			if(opcao == 's')
			{	
				clrscr();
				printf(" # # # Cadastrar Locacao:\n");
				printf("\nCPF para Locacao (EX: 111.111.111-11): "); fflush(stdin);
				gets(AuxCPF);
			}
			else
				AuxCPF[0]='\0';
		}
		else
		{
			textcolor(4);
			printf("\nNao tem mais espaco");
			getch();
		}	
	}
}

void CodExclusaoCliente (TPClientes TabClint[TF],int &TC,int pos)
{
	while(pos<TC-1)
	{
		strcpy(TabClint[pos].CPF,TabClint[pos+1].CPF);
		strcpy(TabClint[pos].Nome,TabClint[pos+1].Nome);
		strcpy(TabClint[pos].Telefone,TabClint[pos+1].Telefone);
		pos++;
	}	
	TC--;
}

void ExclusaoCliente(TPClientes TabClint[TF],int & TC,TPLocacao TabLoc[TF], int TCL)
{
	char AuxCPF[16],cad;
	int Pos,Pos2;
	clrscr();
	if(TCL>0)
	{
		printf(" # # # Excluir Clientes # # #:\n");
		printf("\nCPF:"); fflush(stdin);
		gets(AuxCPF);
		Pos = BuscaCliente(TabClint,TC,AuxCPF);
		if(Pos<0)
		{
			textcolor(4);
			printf("Esse cliente nao foi encontrado!!\n");
		}

		else
		{
			Pos2 = BuscaNaLocCPF (TabLoc,TCL,AuxCPF);
			if(Pos2<0)
			{
				printf("Tem certeza que deseja excluir esse cliente? S ou N\n");
				printf("CPF = %s\n",TabClint[Pos].CPF);
				printf("Nome = %s\n",TabClint[Pos].Nome);
				printf("Telefone = %s\n",TabClint[Pos].Telefone);
				cad = toupper ( getch());
				if(cad == 'S')
				{
					CodExclusaoCliente (TabClint,TC,Pos);
					textcolor(10);
					printf("Cliente Excluido");
					getch();
				}
				else
				{
					textcolor(4);
					printf("O cliente nao foi excluido!!");
					getch();
				}
			}
			else
			{
				printf("O Cliente nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo, volte e exclua na locacao!!");
				getch();	
			}
		}		
	}
	else
	{
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}
}

void CodExclusaoCarro(TPCarros TabCarros[TF],int & TCA,int pos)
{
	int AuxCod;
	float AuxPreco;
	while(pos<TCA-1)
	{
		AuxCod = TabCarros[pos].CodCar;
		TabCarros[pos].CodCar = TabCarros[pos+1].CodCar;
		TabCarros[pos+1].CodCar = AuxCod;
		strcpy(TabCarros[pos].Modelo,TabCarros[pos+1].Modelo);
		strcpy(TabCarros[pos].Categoria,TabCarros[pos+1].Categoria);
		AuxPreco = TabCarros[pos].PrecoDiaria;
		TabCarros[pos].PrecoDiaria = TabCarros[pos+1].PrecoDiaria;
		TabCarros[pos+1].PrecoDiaria = AuxPreco;
		pos++;
	}	
	TCA--;
}

void ExclusaoCarros(TPCarros TabCarros[TF],int &TCA,TPLocacao TabLoc[TF], int TCL)
{
	char cad;
	int AuxCod,Pos,Pos2;
	clrscr();
	if(TCA>0)
	{
		printf(" # # # Excluir Carros # # #:\n");
		printf("\nCod:"); 
		scanf("%d",&AuxCod);
		Pos = BuscaCarro(TabCarros,TCA,AuxCod);
		if(Pos<0)
		{
			textcolor(4);
			printf("Esse codigo nao foi encontrado!!\n");
		}	
		else
		{
			Pos2 = BuscaNaLocCod(TabLoc,TCL,AuxCod);
			if(Pos2<0)
			{
				printf("Tem certeza que deseja excluir esse codigo? S ou N\n");
				printf("CODIGO = %d\n",TabCarros[Pos].CodCar);
				printf("MODELO = %s\n",TabCarros[Pos].Modelo);
				printf("CATEGORIA = %s\n",TabCarros[Pos].Categoria);
				printf("PRECO DA DIARIA = %f\n",TabCarros[Pos].PrecoDiaria);
				cad = toupper ( getch());
				if(cad == 'S')
				{
					CodExclusaoCarro (TabCarros,TCA,Pos);
					textcolor(10);
					printf("O codigo Excluido!!");
					getch();
				}
				else
				{
					textcolor(4);
					printf("O codigo nao foi excluido!!");
					getch();
				}
			}
			else
			{
				textcolor(4);
				printf("O codigo nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo volte e exclua na locacao!!");
				getch();
			}	
		}
	}
	else	
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}
	
}

void ExibirNaLoc(TPLocacao TabLoc[TF], int TCL, char ChaveCPF[16])
{
	int i=0;
	for(i=0;i<TCL;i++)
		if(stricmp(TabLoc[i].CPF,ChaveCPF)==0)
		{
			printf("%s   %d   %d   %f\n",TabLoc[i].CPF,TabLoc[i].CodCar,TabLoc[i].QtdeDias,TabLoc[i].ValorLoc);
		}
}

void CodExclusaoLoc(TPLocacao TabLoc[TF],int &TCL,int pos)
{
	int AuxCod;
	float AuxPreco;
	while(pos<TCL-1)
	{
		strcpy(TabLoc[pos].CPF,TabLoc[pos+1].CPF);
		AuxCod = TabLoc[pos].CodCar;
		TabLoc[pos].CodCar = TabLoc[pos+1].CodCar;
		TabLoc[pos+1].CodCar = AuxCod;
		AuxCod = TabLoc[pos].QtdeDias;
		TabLoc[pos].QtdeDias = TabLoc[pos+1].QtdeDias;
		TabLoc[pos+1].QtdeDias = AuxCod;
		AuxPreco = TabLoc[pos].ValorLoc;
		TabLoc[pos].ValorLoc = TabLoc[pos+1].ValorLoc;
		TabLoc[pos+1].ValorLoc = AuxPreco;
		pos++;
	}	
	TCL--;	
}

void ExclusaoLoc(TPLocacao TabLoc[TF], int &TCL, TPClientes TabClint[TF], int TC,TPCarros TabCarros[TF], int TCA )
{
	char AuxCPF[16],cad;
	int AuxCod,Pos;
	clrscr();
	if(TCL>0)
	{
		printf(" # # # Excluir Locacao # # #:\n");
		printf("\nCPF:"); fflush(stdin);
		gets(AuxCPF);
		Pos = BuscaNaLocCPF(TabLoc,TCL,AuxCPF);
		if(Pos<0)
		{
			textcolor(4);
			printf("CPF nao encontrado!!");
		}
		else
		{
			printf("Esses sao seus carros locados:\n");
			ExibirNaLoc(TabLoc,TCL,AuxCPF);
			printf("Qual o codigo do carro que voce deseja excluir?\n");
			scanf("%d",&AuxCod);
			Pos = BuscaNaLocCod(TabLoc,TCL,AuxCod);
			if(Pos<0)
			{
				textcolor(4);
				printf("Esse carro nao foi encontrado!!");
			}
			else
			{
				printf("Tem certeza que deseja excluir essa locacao? S ou N\n");
				printf("CPF = %s\n",TabLoc[Pos].CPF);
				printf("CodCar = %d\n",TabLoc[Pos].CodCar);
				printf("QtdeDias = %d\n",TabLoc[Pos].QtdeDias);
				printf("ValorLoc = %.2f\n",TabLoc[Pos].ValorLoc);
				cad = toupper ( getch());
				if(cad == 'S')
				{
					CodExclusaoLoc (TabLoc,TCL,Pos);
					textcolor(10);
					printf("Locacao Excluida");
					getch();
				}
				else
				{
					textcolor(4);
					printf("A locacao nao foi excluida!!");
					getch();
				}	
			}	
		}		
	}
	else	
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}	
	
}

void ListaDosClientes(TPClientes TabClint[TF],int TC)
{
	int i;
	clrscr();
	for(i=0;i<TC;i++)
	{
		printf("[%d]%s  %s  %s\n",i,TabClint[i].CPF,TabClint[i].Nome,TabClint[i].Telefone);
	}
}

void ListaDosCarros(TPCarros TabCarros[TF],int TCA)
{
	int Pos;
	for(Pos=0;Pos<TCA;Pos++)
	{
		printf("[%d]%d  %s  %s %f\n",Pos,TabCarros[Pos].CodCar,TabCarros[Pos].Modelo,TabCarros[Pos].Categoria,TabCarros[Pos].PrecoDiaria);
	}
}

void ListaDaLoc(TPLocacao TabLoc[TF], int TCL)
{
	int Pos;
	clrscr();
	printf("CPF      CodCar  QtdeDias ValorLoc\n");
	for(Pos=0;Pos<TCL;Pos++)
	{
		printf("[%d]%s  %d    %d   %f\n",Pos,TabLoc[Pos].CPF,TabLoc[Pos].CodCar,TabLoc[Pos].QtdeDias,TabLoc[Pos].ValorLoc);
	}
}

void AlteracaoClint (TPClientes TabClint[TF], int TC)
{
	int pos;
	if(TC>0)
	{
		printf("Esses sao os clientes cadastrados\n");
		ListaDosClientes(TabClint,TC);
		printf("Qual o cliente que sera alterado?\n");
		textcolor(4);
		printf("nao pode alterar o CPF!!");
		scanf("%d",&pos);
		if(pos<TC)
		{
			printf("\nNome:"); fflush(stdin);
			gets(TabClint[pos].Nome);
			printf("\nTelefone ( EX: 22222-2222) : "); fflush(stdin);
			gets(TabClint[pos].Telefone);
		}
		else
		{
			textcolor(4);
			printf("Posicao invalida!!");
			getch();
		}	
	}
	else
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}
	
}

void AlteracaoCarro (TPCarros TabCarros[TF], int TCA)
{
	int pos;
	if(TCA>0)
	{
		printf("Esses sao os carros cadastrados\n");
		ListaDosCarros(TabCarros,TCA);
		printf("Qual o Carro que sera alterado?\n");
		textcolor(4);
		printf("nao pode alterar o codigo do carro!!");
		scanf("%d",&pos);
		if(pos<TCA)
		{
			printf("\nModelo:"); fflush(stdin);
			gets(TabCarros[pos].Modelo);
			printf("\nCategoria:"); fflush(stdin);
			gets(TabCarros[pos].Categoria);
			printf("\nPreco da Diaria:"); 
			scanf("%f",& TabCarros[pos].PrecoDiaria);
		}
		else
		{
			textcolor(4);
			printf("Posicao invalida!!");
			getch();
		}	
	}
	else
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}
}

void AlteracaoLoc (TPLocacao TabLoc[TF], int TCL, TPCarros TabCarros[TF], int TCA)
{
	int pos,pos1;
	if(TCL>0)
	{
		printf("Essas sao as locacoees cadastradas\n");
		ListaDaLoc(TabLoc,TCL);
		printf("Qual o locacao que sera alterado?\n");
		textcolor(4);
		printf("Nao pode alterar o CPF e nem o codigo do carro!!");
		scanf("%d",&pos);
		if(pos<TCA)
		{
			printf("\nQtdeDias:"); fflush(stdin);
			scanf("%d",&TabLoc[pos].QtdeDias);
			pos1 = BuscaLocacaoCod(TabCarros,TCA,TabLoc[pos].CodCar);
			TabLoc[pos].ValorLoc = TabLoc[pos].QtdeDias * TabCarros[pos1].PrecoDiaria;
		}
		else
		{
			textcolor(4);
			printf("Posicao invalida!!");
			getch();
		}	
	}
	else
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}
}

void Moldura()
{
	int i;
	textcolor(3);
	textbackground(1);
	gotoxy(20,5);
	printf("%c",201);
	gotoxy(60,5);
	printf("%c",187);
	gotoxy(20,20);
	printf("%c",200);
	gotoxy(60,20);
	printf("%c",188);
	for(i=20+1; i<60; i++)
	{
		gotoxy(i,5);
		printf("%c",205);
		gotoxy(i,20);
		printf("%c",205);
	}
	for(i=5+1; i<20; i++)
	{
		gotoxy(20,i);
		printf("%c",186);
		gotoxy(60,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void ListagemCat(TPCarros TabCarros[TF], int TCA)
{
	char AuxCat[15];
	int Pos;
	clrscr();
	if(TCA>0)
	{
		printf("Digite a categoria desejada:\n");
		printf("CodCar   Categoria\n");
		for(Pos=0;Pos<TCA;Pos++)
			printf("%d   %s\n",TabCarros[Pos].CodCar,TabCarros[Pos].Categoria);
		printf("Dessas Categorias qual deseja escolher?\n");
		fflush(stdin);
		gets(AuxCat);
		Pos = BuscaDaCat(TabCarros,TCA,AuxCat);
		if(Pos<0)
		{
			textcolor(4);
			printf("Nao existe essa categoria!!");		
		}	
		else 
		{	
			for(Pos=0;Pos<TCA;Pos++)
				if(stricmp(TabCarros[Pos].Categoria,AuxCat)==0)
					printf("%d   %s\n",TabCarros[Pos].CodCar,TabCarros[Pos].Categoria);	
		}
	}
	else
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}		
}

void ListagemValor(TPLocacao TabLoc[TF], int TCL)
{
	float AuxVal;
	int Pos,cont=0;
	clrscr();
	if(TCL>0)
	{
		printf("Digite o valor para ser o minimo de visualizacao");
		scanf("%f",&AuxVal);
		for(Pos=0;Pos<TCL;Pos++)
			if(TabLoc[Pos].ValorLoc > AuxVal)
			{
				printf("[%d]%s  %d  %d %f\n",Pos,TabLoc[Pos].CPF,TabLoc[Pos].CodCar,TabLoc[Pos].QtdeDias,TabLoc[Pos].ValorLoc);
				cont++;
			}
		if(cont=0)
		{
			textcolor(4);
			printf("Nao existe valores acima desse valor!!");
			getch();
		}
	}
	else	
	{
		textcolor(4);
		printf("Esse vetor Nao tem elementos!!");
		getch();
	}	
	
}


void Menu (TPClientes TabClint[TF], int &TLC, TPCarros TabCarros[TF],int  &TLCA ,TPLocacao TabLoc[TF], int &TCL )
{
	int opcao1;
	char opcao2;
	do
	{
		clrscr();
		Moldura();
		gotoxy(32,9);
		printf("# # # Menu # # #"); 
		gotoxy(32,10);
		printf("[A] Cadastros"); 
		gotoxy(32,11);
		printf("[B] Exclusoes"); 
		gotoxy(32,12);
		printf("[C] Alteracoes"); 
		gotoxy(32,13);
		printf("[D] Listagens"); 
		gotoxy(32,14);
		printf("Opcao :"); 
		opcao2 = toupper ( getch());
		switch(opcao2)
		{
			case 'A': 	clrscr();
						Moldura();
						gotoxy(27,10);
					  	printf("Selecione a Opcao Desejada:");
					  	gotoxy(27,11);
					  	printf("[1] Cadastrar Cliente");
					  	gotoxy(27,12);
					  	printf("[2] Cadastrar Carro");
					  	gotoxy(27,13);
					  	printf("[3] Cadastrar Locacao");
					  	gotoxy(27,14);
					  	printf("Opcao: ");
					  	scanf("%d",&opcao1);
					  	switch(opcao1)
					  	{
					  		case 1: CadastroCliente(TabClint,TLC);
					  				break;
					  	
					  		case 2: CadastroCarros(TabCarros,TLCA);
					  				break;
					  	
					  		case 3: CadastroLocacao(TabLoc,TCL,TabClint,TLC,TabCarros,TLCA);
					  				break;
					  	}	
					  	break;
			case 'B':	clrscr();
						Moldura();
						gotoxy(27,10);
					  	printf("Selecione a Opcao Desejada:\n");
					  	gotoxy(27,11);
					  	printf("[1] Excluir Cliente\n");
					  	gotoxy(27,12);
					  	printf("[2] Excluir Carro\n");
					  	gotoxy(27,13);
					  	printf("[3] Excluir Locacao\n");
					  	gotoxy(27,14);
					  	printf("Opcao: ");
					  	scanf("%d",&opcao1);
					  	switch(opcao1)
					  	{
					  		case 1: ExclusaoCliente(TabClint,TLC,TabLoc,TCL);
					  				break;
					  	
					  		case 2: ExclusaoCarros(TabCarros,TLCA,TabLoc,TCL);
					  				break;
					  	
					  		case 3: ExclusaoLoc(TabLoc,TCL,TabClint,TLC,TabCarros,TLCA);
					  				break;	
					 	}	
					  	break;
			case 'C':	clrscr();
						Moldura();
						gotoxy(27,10);
						printf("Selecione a Opcao Desejada:\n");
						gotoxy(27,11);
					  	printf("[1] Alterar Cliente\n");
					  	gotoxy(27,12);
					 	printf("[2] Alterar Carro\n");
					 	gotoxy(27,13);
					  	printf("[3] Alterar Locacao\n");
					  	gotoxy(27,14);
					  	printf("Opcao: ");
					  	scanf("%d",&opcao1);
					  	switch(opcao1)
					  	{
					  		case 1: AlteracaoClint(TabClint,TLC);
					  				break;
					  	
					  		case 2: AlteracaoCarro(TabCarros,TLCA);
					  				break;	
					  				
					  		case 3:AlteracaoLoc (TabLoc,TCL,TabCarros,TLCA);
					  				break;
					  	}
					  	getch();
						break;	
			case 'D':	clrscr();
						Moldura();
						gotoxy(27,10);
						printf("Selecione a Opcao Desejada:");
						gotoxy(27,11);
					 	printf("[1] Clientes 3X");
					 	gotoxy(27,12);
					 	printf("[2] Categoria escolhida");
					 	gotoxy(27,13);
					 	printf("[3] Locacoes > valor");
					 	gotoxy(27,14);
					 	printf("[4] Relatorio completo");
					 	gotoxy(27,15);
					 	printf("Opcao: ");
					 	scanf("%d",&opcao1);
					 	switch(opcao1)
					  	{
					  		case 1: 
					  				break;
					  		case 2: ListagemCat(TabCarros,TLCA);
					  				break;	
					  		case 3:	ListagemValor(TabLoc,TCL);
					  				break;
					  		case 4:	ListaDaLoc(TabLoc,TCL);
					  				break;
					  	}	
						getch();
						break;	
		}
	}
	while(opcao2!=27);
}

int main(void)
{
	TPClientes TabClint[TF];
	TPCarros TabCarros[TF];
	TPLocacao TabLoc[TF];
	int TLC=0,TLCA=0,TCL=0;
	
	Menu( TabClint, TLC, TabCarros, TLCA , TabLoc, TCL);
	return 0;
}
