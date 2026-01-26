#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio2.h>
#include<windows.h>
#include<stdlib.h>
#define TF 50
// Breno Brayan dos Santos
// Gustavo Malacrida Mazetti
// Igor Nakamura Moretto
// Leonardo Gabriel Santos Mineo
// por favor não retire os nomes e dps q ver essa mensagem pode apagar essa linha  se quiser
// Usei o TF para todos os que são char menos no Cpf pq são 14 caracteres
// declarei os campos um embaixo do outro para ter facilidade de visibilidade

struct TpClientes
{
	char CPF[15];
	char Nome[TF];
	char Telefone[11];
	int Status;
	// pelo q parece o status 1 é ativo e 0 inativo pq  no exemplo lá no trabalho tá 1 
};

struct TpCarros
{
	int CodCar;
	char Modelo[TF];
	char Categoria[TF];
	float PrecoDiaria;
	int Status;
};

struct TpLocacoes
{
	char CPF[15];	
	int CodCar;
	int QtdeDia;
	float ValorLocacao;
	int Status;
};

void InsertionSortCPFClient(FILE * PtrCli,int TL) //ordena o arquivo Cliente por CPF nao pode trocar
{
    TpClientes Rg1, Rg2;
    int p;
    p = TL - 1; // começa do último registro
    while (p > 0)
    {
        // lê os dois registros que serão comparados
        fseek(PtrCli, (p - 1) * sizeof(TpClientes), SEEK_SET);
        fread(&Rg2, sizeof(TpClientes), 1, PtrCli); // anterior

        fseek(PtrCli, p * sizeof(TpClientes), SEEK_SET);
        fread(&Rg1, sizeof(TpClientes), 1, PtrCli); // atual
        
        // se estiver fora de ordem, troca
        if (strcmp(Rg2.CPF, Rg1.CPF) > 0)
        {
            fseek(PtrCli, (p - 1) * sizeof(TpClientes), SEEK_SET);
            fwrite(&Rg1, sizeof(TpClientes), 1, PtrCli);

            fseek(PtrCli, p * sizeof(TpClientes), SEEK_SET);
            fwrite(&Rg2, sizeof(TpClientes), 1, PtrCli);
        }
        p--; 
    }
}

void InsertionSortCPFLoc(FILE * PtrLoc,int TL) //ordena o arquivo Locacoes por CPF 	pode trocar bubble
{
    TpLocacoes Rg1, Rg2;
    int p;
    p = TL - 1; // começa do último registro
    while (p > 0)
    {
        // lê os dois registros que serão comparados
        fseek(PtrLoc, (p - 1) * sizeof(TpLocacoes), SEEK_SET);
        fread(&Rg2, sizeof(TpLocacoes), 1, PtrLoc); // anterior

        fseek(PtrLoc, p * sizeof(TpLocacoes), SEEK_SET);
        fread(&Rg1, sizeof(TpLocacoes), 1, PtrLoc); // atual
        
        // se estiver fora de ordem, troca
        if (strcmp(Rg2.CPF, Rg1.CPF) > 0)
        {
            fseek(PtrLoc, (p - 1) * sizeof(TpLocacoes), SEEK_SET);
            fwrite(&Rg1, sizeof(TpLocacoes), 1, PtrLoc);

            fseek(PtrLoc, p * sizeof(TpLocacoes), SEEK_SET);
            fwrite(&Rg2, sizeof(TpLocacoes), 1, PtrLoc);
        }
        p--; 
    }
}

void InsertionSortCodLoc(FILE * PtrLoc,int TL) //ordena o arquivo Locacoes por Cod	pode trocar bubble
{
    TpLocacoes Rg1, Rg2;
    int p;
    p = TL - 1; // começa do último registro
    while (p > 0)
    {
        // lê os dois registros que serão comparados
        fseek(PtrLoc, (p - 1) * sizeof(TpLocacoes), SEEK_SET);
        fread(&Rg2, sizeof(TpLocacoes), 1, PtrLoc); // anterior

        fseek(PtrLoc, p * sizeof(TpLocacoes), SEEK_SET);
        fread(&Rg1, sizeof(TpLocacoes), 1, PtrLoc); // atual
        
        // se estiver fora de ordem, troca
        if (strcmp(Rg2.CPF,Rg1.CPF) > 0) // Faltou comprar com strcmp aqui Gustavo , resolvi
        {
            fseek(PtrLoc, (p - 1) * sizeof(TpLocacoes), SEEK_SET);
            fwrite(&Rg1, sizeof(TpLocacoes), 1, PtrLoc);

            fseek(PtrLoc, p * sizeof(TpLocacoes), SEEK_SET);
            fwrite(&Rg2, sizeof(TpLocacoes), 1, PtrLoc);
        }
        p--; 
    }
}

int PosicaoMaior (FILE * PtrCar, int TL) 
{
    TpCarros Rg;
	int PosMaior =0, Maior, i, PosAtual;
	rewind(PtrCar);
	fread(&Rg,sizeof(TpCarros),1,PtrCar);
	Maior = Rg.CodCar; 
	for (i=1;i<TL;i++)
    {
        fread(&Rg, sizeof(TpCarros), 1, PtrCar);
        PosAtual = ftell(PtrCar) - sizeof(TpCarros);
        if (Rg.CodCar > Maior)
        {
            Maior = Rg.CodCar;
            PosMaior = PosAtual;
        }
    }
	return PosMaior; 	
}
void SelectionSortCodCar(FILE * PtrCar)// ordena o arquivo carros por codigo nao pode trocar
{
	TpCarros Rg1,Rg2;
	int PosMaior, PosUltimo, TL;
	fseek(PtrCar, 0, 2);
	TL = ftell(PtrCar)/sizeof(TpCarros);
	while(TL > 0)
	{
		PosMaior = PosicaoMaior(PtrCar,TL);
		PosUltimo = (TL-1)*sizeof(TpCarros);

		if (PosMaior != PosUltimo)
        {
            fseek(PtrCar, PosMaior, 0);
            fread(&Rg1, sizeof(TpCarros), 1, PtrCar);
            
            fseek(PtrCar, PosUltimo, 0);
            fread(&Rg2, sizeof(TpCarros), 1, PtrCar);
            
            fseek(PtrCar, PosMaior, 0);
            fwrite(&Rg2, sizeof(TpCarros), 1, PtrCar);
            fseek(PtrCar, PosUltimo, 0);
            fwrite(&Rg1, sizeof(TpCarros), 1, PtrCar);
        }
        TL--;
	}
	//	fclose(PtrCar); deixei comentando pq se vc faz a ordenação acho q não precisa dar fclose aqui tem q ser aonde vc chamou a função
}

int BuscaCPFCliente(FILE *PtrCli, char CPF[15])// Busca sequncial Indexada (Busca o cpf no arqivo clientes) nao pode mudar
{
	TpClientes Reg;
	rewind(PtrCli);
	fread(&Reg,sizeof(TpClientes),1,PtrCli);
	
	while(!feof(PtrCli) && !(strcmp(CPF,Reg.CPF)==0 && Reg.Status==1))
		fread(&Reg,sizeof(TpClientes),1,PtrCli);
		
	if (!feof(PtrCli) && (strcmp(CPF,Reg.CPF)==0 && Reg.Status==1))
		return ftell(PtrCli)-sizeof(TpClientes);
	else
		return -1;
}

int BuscaBinariaCodCar(FILE *PtrCar, int cod) // Busca Cod no arquivo Carros  nao pode mudar
{
    int Inicio = 0, Fim, Meio, TL;
    TpCarros Reg;


    fseek(PtrCar, 0, SEEK_END);
    TL = ftell(PtrCar) / sizeof(TpCarros);
    Fim = TL - 1;

    while (Inicio <= Fim)
    {
        Meio = (Inicio + Fim) / 2;

        fseek(PtrCar, Meio * sizeof(TpCarros), SEEK_SET);
        fread(&Reg, sizeof(TpCarros), 1, PtrCar);

        // ***** IGNORAR DESATIVADOS (Status = 0) *****
        if (Reg.Status == 0)
        {
            if (cod > Reg.CodCar)
                Inicio = Meio + 1;
            else
                Fim = Meio - 1;
        }
        else
        {
            // registro ativo — compara normalmente
            if (cod == Reg.CodCar)
                return Meio * sizeof(TpCarros);

            if (cod > Reg.CodCar)
                Inicio = Meio + 1;
            else
                Fim = Meio - 1;
        }
    }

    return -1;
}

int BuscaSentinelaCodLoc(FILE * PtrLoc, int cod) //Busca Cod no arquivo Locacoes  Errado
{
    TpLocacoes Reg, Ultimo, Sent;
    long tamArq, posUltimo, posAtual;

    // ir até o fim do arquivo para descobrir tamanho
    fseek(PtrLoc, 0, SEEK_END);
    tamArq = ftell(PtrLoc);

    if(tamArq == 0) // arquivo vazio
        return -1;

    // posição do último registro real
    posUltimo = tamArq - sizeof(TpLocacoes);

    // ler o último registro original
    fseek(PtrLoc, posUltimo, SEEK_SET);
    fread(&Ultimo, sizeof(TpLocacoes), 1, PtrLoc);

    // criar a sentinela
    Sent = Ultimo;
    Sent.CodCar = cod;   // sentinela no código
    Sent.Status = 1;     // sentinela deve ser considerada "ativa"

    // escrever sentinela NO LUGAR do último registro
    fseek(PtrLoc, posUltimo, SEEK_SET);
    fwrite(&Sent, sizeof(TpLocacoes), 1, PtrLoc);

    // --- Início da busca ---
    rewind(PtrLoc);
    fread(&Reg, sizeof(TpLocacoes), 1, PtrLoc);

    posAtual = 0;

    // só para quando achar ativo (Status = 1)
    while(Reg.CodCar != cod || Reg.Status != 1)
    {
        fread(&Reg, sizeof(TpLocacoes), 1, PtrLoc);
        posAtual += sizeof(TpLocacoes);
    }

    // restaurar o último registro original
    fseek(PtrLoc, posUltimo, SEEK_SET);
    fwrite(&Ultimo, sizeof(TpLocacoes), 1, PtrLoc);

    // se achou na posição da sentinela ? NÃO existe ativo com esse código
    if(posAtual == posUltimo)
        return -1;

    // retorno posição em bytes
    return posAtual;
}

int BuscaBinariaCPFLoc(FILE * PtrLoc, char CPF[15]) //Busca CPF no arquivo Locacoes nao pode mudar
{
	int Fim , Inicio= 0 , Meio,TL;
	TpLocacoes Reg;
	fseek(PtrLoc,0,2);
	TL = ftell(PtrLoc) /sizeof(TpLocacoes);
	Fim = TL-1;
	Meio = Fim/2;
	InsertionSortCPFLoc(PtrLoc,TL);
	rewind(PtrLoc);// pq não sabemos aonde ele esta
	while(Inicio <= Fim )
	{
		fseek(PtrLoc,Meio*sizeof(TpLocacoes),0);// SEEK_SET
		// aponta o ponteiro para o meio e começa na posicao meio
		fread(&Reg,sizeof(TpLocacoes),1,PtrLoc);
		if(strcmp(CPF,Reg.CPF)>0)
		{
			Inicio = Meio + 1;
		}
		else 
		{
			Fim = Meio - 1;
		}
		
		Meio = (Inicio+Fim)/2;
		
	}
	if (strcmp(CPF,Reg.CPF)==0)
	{	
		return Meio;	
	}
	else 
	{
		return -1;
	}
}

int BuscaExalstivaCPFeCodLoc(FILE * PtrLoc, FILE * PtrCar, int AuxCod, char AuxCPF[15]) //Busca CPF e Cod em conjunto no arquivo Locacoes
{
    TpLocacoes Rg;
    rewind(PtrLoc);
    fread(&Rg, sizeof(TpLocacoes), 1, PtrLoc);
    while (!feof(PtrLoc) &&	(Rg.Status != 1 || Rg.CodCar != AuxCod || strcmp(AuxCPF, Rg.CPF) != 0))
        fread(&Rg, sizeof(TpLocacoes), 1, PtrLoc);
    if (!feof(PtrLoc))
        return ftell(PtrLoc) - sizeof(TpLocacoes); // Achou

    return -1; // Não achou
}

void BubbleSortCarModelo(FILE *PtrCar)
{
	int TL;
	int a,b;
	TpCarros RegA, RegB;
	if (PtrCar == NULL)
	{
		printf("ERRO de abertura \n");
	}
	else
	{		
		fseek(PtrCar,0,SEEK_END);	
		TL = ftell(PtrCar) / sizeof(TpCarros);
		for(a=0 ; a < TL-1 ; a++)
			for(b = a+1 ; b <TL; b++)
			{
				fseek(PtrCar,a*sizeof(TpCarros),0); //SEEK_SET
				fread(&RegA,sizeof(TpCarros),1,PtrCar);
					
				fseek(PtrCar,b*sizeof(TpCarros),0);
				fread(&RegB,sizeof(TpCarros),1,PtrCar);
					
				if(stricmp(RegA.Modelo,RegB.Modelo)>0)
				{
					fseek(PtrCar,a*sizeof(TpCarros),0);
					fwrite(&RegB,sizeof(TpCarros),1,PtrCar);
					
					fseek(PtrCar,b*sizeof(TpCarros),0);
					fwrite(&RegA,sizeof(TpCarros),1,PtrCar);
				}	
			}
	}

}

void ExibirLocacaoCPF(FILE * PtrLoc,char AuxCPF[15])
{
	TpLocacoes Rg;
	rewind(PtrLoc);
	fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	while(!feof(PtrLoc))
	{
		if(strcmp(AuxCPF,Rg.CPF)==0 && Rg.Status == 1)
		{
			printf("CPF = %s\n",Rg.CPF);
			printf("CodCar = %d\n",Rg.CodCar);
			printf("QtdeDias = %d\n",Rg.QtdeDia);
			printf("ValorLoc = %.2f\n",Rg.ValorLocacao);
			printf("\n");
		}
		fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	}
}

void CadastroClientes(void)
{
	TpClientes Reg;
	char AuxCPF[15];
	int pos,TL;
	char resp;
	FILE *PtrCli = fopen("clientes.dat","rb+"); // ab+ , pq ta no inicio de arquivo e ele adiciona no final ou seja adiciona no inicio dele ja q esta sendo aberto agr
// com wb+  ,Se o arquivo não existir, ele será criado do zero (vazio).Se o arquivo já existir, em    nC zera completamente o conteúdo por isso coloquei ab+ pq em vez
// zerar o ab+ não zera o arquivo ele mantém , entendeu o pq de ab+
	clrscr();
	if(PtrCli == NULL)
	{
		textcolor(4);// vermelho de erro
		printf(" Erro de Abertura do Arquivo \n");
	}
	else 
	{
		
		textcolor(2);//verde de correto 
		printf("\n * * * Cadastro De Clientes * * * \n");
		printf("Deseja Cadastrar o cliente [S] ou [N]\n");
		resp = toupper(getche());
		if(resp != 'S' && resp != 'N')
		{
			textcolor(4);
			printf("\nOpcao invalida! Digite apenas S ou N.\n");
			textcolor(2);
		}		
		
		if(resp == 'S')
		{
			fseek(PtrCli, 0, SEEK_END);
			TL = ftell(PtrCli) / sizeof(TpClientes);
			printf("\nQual o CPF a ser cadastrado :(EX: 111.111.111-11)[Enter] para sair\n");
			fflush(stdin);
			gets(AuxCPF);
			while(strcmp(AuxCPF,"\0") != 0)// enquanto CPF diferente de \0 ele continua e se for 0 são iguais ele para 
			{	
				pos = BuscaCPFCliente(PtrCli,AuxCPF);
				if(pos == -1)
				{
					strcpy(Reg.CPF,AuxCPF);
					printf("\nQual o nome do cliente: \n");
					fflush(stdin);
					gets(Reg.Nome);	
					printf("Qual o telefone do cliente :(11111-1111)\n");
					fflush(stdin);
					gets(Reg.Telefone);
					Reg.Status = 1;
					fseek(PtrCli,0,2);
					fwrite(&Reg,sizeof(TpClientes),1,PtrCli);
					TL++;
					InsertionSortCPFClient(PtrCli,TL);
				}
				else 
				{	
					textcolor(4);
					printf("\n Cliente ja cadastrado  \n");
					
				}
					textcolor(2);
					printf("\nQual o CPF a ser cadastrado :(EX: 111.111.111-11)[Enter] para sair\n");
					fflush(stdin);
					gets(AuxCPF);
			}
		}
		else 
		{
			textcolor(1);
			printf("\nPara voltar ao Menu do cliente  aperte qualquer tecla: \n");
			getch();
		}
	
		fclose(PtrCli);// coloquei aqui pq se for entra no else ou no if ele sempre vai fechar o arquivo , tanto se for usa-lo ou ñ para cadastrar
	}	
}

void ExclusaoLogicaCliente(void)//Status = 0 Mexendo Gustavo  (Lembrar de quando for exibir conferir o Status pois so pode exibir se for 1)
{
	TpClientes Rg;
	char AuxCPF[16],cad;
	int Pos,Pos2;
	FILE * PtrCli = fopen("clientes.dat","rb+");
	FILE * PtrLoc = fopen("locacoes.dat","rb+");
	clrscr();
	textcolor(2);
	printf(" # # # Excluir Clientes Logicamente # # #:\n");
	printf(" # # # [Enter] para sair # # #\n");
	printf("\nCPF:"); fflush(stdin);
	gets(AuxCPF);
	Pos = BuscaCPFCliente(PtrCli, AuxCPF);
	if(Pos==-1)
	{
		textcolor(4);
		printf("Esse cliente nao foi encontrado!!\n");
		textcolor(2);
	}
	else
	{
		Pos2 = BuscaBinariaCPFLoc(PtrLoc,AuxCPF);
		if(Pos2==-1)
		{
			fseek(PtrCli,Pos,0);
			fread(&Rg,sizeof(TpClientes),1,PtrCli);
			printf("Tem certeza que deseja excluir esse cliente? S ou N\n");
			printf("CPF = %s\n",Rg.CPF);
			printf("Nome = %s\n",Rg.Nome);
			printf("Telefone = %s\n",Rg.Telefone);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				Rg.Status = 0;
				fseek(PtrCli,Pos,0);
				fwrite(&Rg,sizeof(TpClientes),1,PtrCli);
				textcolor(10);
				printf("Cliente Excluido");
			}
			else
			{
				textcolor(4);
				printf("O cliente nao foi excluido!!");
				textcolor(2);
			}
		}
		else
		{
			textcolor(4);
			printf("O Cliente nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo, volte e exclua na locacao!!");	
			textcolor(2);
		}
		getch();
	}
	fclose(PtrCli);
	fclose(PtrLoc);		

}

void ExclusaoFisicaCliente(void)
{
	TpClientes Rg;
	char AuxCPF[16],cad;
	int Pos,Pos2;
	FILE * PtrCli = fopen("clientes.dat","rb");
	FILE * PtrLoc = fopen("locacoes.dat","rb");
	clrscr();
	textcolor(2);
	printf(" # # # Excluir Clientes Fisicamente # # #:\n");
	printf(" # # # [Enter] para sair # # #:\n");
	printf("\nCPF:"); fflush(stdin);
	gets(AuxCPF);
	Pos = BuscaCPFCliente(PtrCli, AuxCPF);
	if(Pos==-1)
	{
		textcolor(4);
		printf("Esse cliente nao foi encontrado!!\n");
		fclose(PtrCli);
	}
	else
	{
		Pos2 = BuscaBinariaCPFLoc(PtrLoc,AuxCPF);
		if(Pos2==-1)
		{
			fseek(PtrCli,Pos,0);
			fread(&Rg,sizeof(TpClientes),1,PtrCli);
			printf("Tem certeza que deseja excluir esse cliente? S ou N\n");
			printf("CPF = %s\n",Rg.CPF);
			printf("Nome = %s\n",Rg.Nome);
			printf("Telefone = %s\n",Rg.Telefone);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				FILE *PtrTemp = fopen("Temp.dat","wb");
				rewind(PtrCli);
				fread(&Rg,sizeof(TpClientes),1,PtrCli);
				while (!feof(PtrCli))
				{      
					if (stricmp(AuxCPF,Rg.CPF)!=0)
						fwrite(&Rg,sizeof(TpClientes),1,PtrTemp);
					
					fread(&Rg,sizeof(TpClientes),1,PtrCli);
				}
				fclose(PtrCli);
				fclose(PtrTemp);
				remove("clientes.dat");
				rename("Temp.dat","clientes.dat");
				textcolor(10);
				printf("Cliente Excluido");
			}
			else
			{
				textcolor(4);
				printf("O cliente nao foi excluido!!");
				textcolor(2);
				fclose(PtrCli);
			}
		}
		else
		{
			textcolor(4);
			printf("O Cliente nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo, volte e exclua na locacao!!");
			textcolor(2);
			fclose(PtrCli);	
		}
		getch();
	}
	fclose(PtrLoc);	
}

void AlteracaoCliente(void)
{
	TpClientes Rg;
	int pos;
	FILE *PtrCli = fopen("clientes.dat","rb+");
	clrscr();
	textcolor(2);
	printf("\n## Altera clientes pelo CPF ##\n");
	if (PtrCli == NULL)
	{
		textcolor(4);
		printf("\nErro de Abertura!\n");
		textcolor(2);
	}
	else
	{
		textcolor(2);
		printf("CPF a qual voce deseja alterar os dados:[Enter] para sair \n");
		printf("CPF nao pode ser alterado !!\n");
		fflush(stdin);
		gets(Rg.CPF);
		while(stricmp(Rg.CPF,"\0")!=0)
		{
			pos = BuscaCPFCliente(PtrCli,Rg.CPF);
			if(pos==-1)
			{
				textcolor(4);
				printf("\nCliente nao Cadastrado!\n");
				printf("Se quiser cadastrar volte ao menu do cliente\n");
			}
			else
			{			
				fseek(PtrCli,pos,0); //SEEK_SET  SEEK_CUR  SEEK_END
				fread(&Rg,sizeof(TpClientes),1,PtrCli); //Ler Registro
				printf("** Detalhes do Cliente **\n");
				printf("CPF: %s\n",Rg.CPF);
				printf("Nome: %s\n",Rg.Nome);
				printf("Telefone: %s\n",Rg.Telefone);
				printf("\nDeseja Alterar (S/N)? ");
				if (toupper(getche())=='S')
				{
					printf("\nNovo Nome: ");
					fflush(stdin);
					gets(Rg.Nome);
					printf("\nNovo Telefone: ");
					fflush(stdin);
					gets(Rg.Telefone);
					fseek(PtrCli,pos,0);
					fwrite(&Rg,sizeof(TpClientes),1,PtrCli);
					printf("\nDados do Cliente alterados!\n\n");
				}
			}
			getch();
			textcolor(2);
			printf("CPF a qual voce deseja alterar os dados: [Enter] para sair\n");
			printf("CPF nao pode ser alterado !!\n");
			fflush(stdin);
			gets(Rg.CPF);	
		}
		fclose(PtrCli);
	}
}

void ListagemClientes(void)
{
	FILE *PtrCli = fopen("clientes.dat","rb");
	TpClientes Rg;
	clrscr();
	textcolor(2);
	printf("** Detalhes dos Clientes **\n");

	if(PtrCli == NULL)
	{
		textcolor(4);
		printf("Erro de abertura \n");
	}
	else
	{	
		rewind(PtrCli);
		fread(&Rg,sizeof(TpClientes),1,PtrCli);
		while(!feof(PtrCli))
		{
			if(Rg.Status == 1)
			{
				printf("CPF: %s\n",Rg.CPF);
				printf("Nome: %s\n",Rg.Nome);
				printf("Telefone: %s\n",Rg.Telefone);
				printf("\n");
			}
			
			fread(&Rg,sizeof(TpClientes),1,PtrCli);
		}
	}
	getch();
	
	fclose(PtrCli);
}

void CadastroCarros(void)
{
	TpCarros Reg;
	int cod, pos, TL;
	FILE *PtrCar = fopen("carros.dat","rb+");
	char resp;
	clrscr();
	
	if (PtrCar == NULL)
	{
		textcolor(4);// vermelho de erro
		printf(" Erro de Abertura do Arquivo \n");
		textcolor(2);
	}
	else 
	{	
		fseek(PtrCar, 0, SEEK_END);
		TL = ftell(PtrCar) / sizeof(TpCarros);
		textcolor(2);
		printf("\n# * # * # * Cadastro De Carros * # * # * # \n");
		printf("Deseja cadastrar o carro [S] ou [N]\n");
		resp= toupper(getche());
		if(resp != 'S' && resp != 'N')
		{
			textcolor(4);
			printf("\nOpcao invalida! Digite apenas S ou N.\n");
			textcolor(2);
		}		
		if(resp == 'S')
		{
			printf("\nQual o codigo do carro a ser cadastrado :(EX: 100 )tecle [0] para sair do cadastro\n");
			scanf("%d",&cod);
			while(cod>0) 
			{
				pos = BuscaBinariaCodCar(PtrCar,cod);
				if(pos == -1)
				{
					Reg.CodCar = cod;
					printf("Qual e o modelo do carro : EX: [Civic]\n");
					fflush(stdin);
					gets(Reg.Modelo);
					printf("Qual a categoria do carro : EX: [Sedan]\n");
					fflush(stdin);
					gets(Reg.Categoria);
					printf("Qual o preco diario :\n");
					scanf("%f",&Reg.PrecoDiaria);
					Reg.Status = 1;
					
					fseek(PtrCar, 0, SEEK_END);
					fwrite(&Reg,sizeof(TpCarros),1,PtrCar);
					
			
				}
				else 
				{	
					textcolor(4);
					printf(" Carro ja cadastrado , aperte qualquer tecla para continuar \n");
					getch();
					cod = 0;
				}
					textcolor(2);
					printf("Qual o codigo do carro a ser cadastrado :(EX: 100 ) tecle [0] para sair do cadastro\n");
					scanf("%d",&cod);
			}
			fseek(PtrCar, 0, SEEK_SET);
            SelectionSortCodCar(PtrCar);
		}
		else
		{
			textcolor(1);
			printf("\n Para voltar ao Menu do cliente  aperte qualquer tecla: \n");
			getch();
		}
	
		fclose(PtrCar);
	}
}

void ExclusaoLogicaCarros(void)//Status = 0 Mexendo Gustavo  (Lembrar de quando for exibir conferir o Status pois so pode exibir se for 1)
{
	TpCarros Rg;
	char cad;
	int AuxCod,Pos,Pos2;
	FILE * PtrCar = fopen("carros.dat","rb+");
	FILE * PtrLoc = fopen("locacoes.dat","rb+");
	clrscr();
	textcolor(2);
	printf(" # # # Excluir Carros Logicamente # # #:\n");
	printf(" # # # [0] para sair # # #\n");
	printf("\nCod:"); 
	scanf("%d",&AuxCod);
	Pos = BuscaBinariaCodCar(PtrCar,AuxCod);
	if(Pos<0)
	{
		textcolor(4);
		printf("Esse codigo nao foi encontrado!!\n");
	}	
	else
	{
		Pos2 = BuscaSentinelaCodLoc(PtrLoc,AuxCod);
		if(Pos2<0)
		{
			fseek(PtrCar,Pos,0);
			fread(&Rg,sizeof(TpCarros),1,PtrCar);
			printf("Tem certeza que deseja excluir esse codigo? S ou N\n");
			printf("CODIGO = %d\n",Rg.CodCar);
			printf("MODELO = %s\n",Rg.Modelo);
			printf("CATEGORIA = %s\n",Rg.Categoria);
			printf("PRECO DA DIARIA = %f\n",Rg.PrecoDiaria);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				Rg.Status = 0;
				fseek(PtrCar,Pos,0);
				fwrite(&Rg,sizeof(TpCarros),1,PtrCar);
				textcolor(4);
				printf("O codigo Excluido!!");
			}
			else
			{
				textcolor(4);
				printf("O codigo nao foi excluido!!");
				textcolor(2);
			}
		}
		else
		{
			textcolor(4);
			printf("O codigo nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo volte e exclua na locacao!!");
			textcolor(2);
		}
		getch();	
	}
	fclose(PtrCar);
	fclose(PtrLoc);
}

void ExclusaoFisicaCarros(void)
{
	TpCarros Rg;
	char cad;
	int AuxCod,Pos,Pos2;
	FILE * PtrCar = fopen("carros.dat","rb+");
	FILE * PtrLoc = fopen("locacoes.dat","rb+");
	clrscr();
	textcolor(2);
	printf(" # # # Excluir Carros Fisicamente # # #:\n");
	printf(" # # # [0] para sair # # #\n");
	printf("\nCod:"); 
	scanf("%d",&AuxCod);
	Pos = BuscaBinariaCodCar(PtrCar,AuxCod);
	if(Pos<0)
	{
		textcolor(4);
		printf("Esse codigo nao foi encontrado!!\n");
		textcolor(2);
		fclose(PtrCar);
	}	
	else
	{
		Pos2 = BuscaSentinelaCodLoc(PtrLoc,AuxCod);// substituir para busca exalstiva com sentinela
		if(Pos2<0)
		{
			fseek(PtrCar,Pos,0);
			fread(&Rg,sizeof(TpCarros),1,PtrCar);
			printf("Tem certeza que deseja excluir esse codigo? S ou N\n");
			printf("CODIGO = %d\n",Rg.CodCar);
			printf("MODELO = %s\n",Rg.Modelo);
			printf("CATEGORIA = %s\n",Rg.Categoria);
			printf("PRECO DA DIARIA = %f\n",Rg.PrecoDiaria);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				FILE *PtrTemp = fopen("Temp.dat","wb");
				rewind(PtrCar);
				fread(&Rg,sizeof(TpCarros),1,PtrCar);
				while (!feof(PtrCar))
				{      
					if (AuxCod != Rg.CodCar)
						fwrite(&Rg,sizeof(TpCarros),1,PtrTemp);
					
					fread(&Rg,sizeof(TpCarros),1,PtrCar);
				}
				fclose(PtrCar);
				fclose(PtrTemp);
				remove("carros.dat");
				rename("Temp.dat","carros.dat");
				textcolor(2);
				printf("O codigo Excluido!!");
			}
			else
			{
				textcolor(4);
				printf("O codigo nao foi excluido!!");
				textcolor(2);
				fclose(PtrCar);
			}
		}
		else
		{
			textcolor(4);
			printf("O codigo nao pode ser excluido pois ele esta na locacao, caso deseje excluir mesmo volte e exclua na locacao!!");
			textcolor(2);
			fclose(PtrCar);
		}
		getch();	
	}
	fclose(PtrLoc);
}

void AlteracaoCarros(void)
{
	TpCarros Rg;
	int pos;
	FILE *PtrCar = fopen("carros.dat","rb+");
	clrscr();
	textcolor(2);
	printf("\n## Altera Carros pelo Codigo ##\n");
	if (PtrCar == NULL)
	{
		textcolor(4);
		printf("\nErro de Abertura!\n");
	}
	else
	{
		textcolor(2);
		printf("Codigo a qual voce deseja alterar os dados:[0] sair \n");
		printf("Codigo nao pode ser alterado !!\n");
		scanf("%d",&Rg.CodCar);
		while(Rg.CodCar!=0)
		{
			pos = BuscaBinariaCodCar(PtrCar,Rg.CodCar);
			if(pos==-1)
			{
				textcolor(4);
				printf("\nCodigo nao Cadastrado!\n");
				printf("Se quiser cadastrar volte ao menu do Carro\n");
				textcolor(2);
			}
			else
			{			
				fseek(PtrCar,pos,0); //SEEK_SET  SEEK_CUR  SEEK_END
				fread(&Rg,sizeof(TpCarros),1,PtrCar); //Ler Registro
				printf("** Detalhes do Carro **\n");
				printf("Codigo: %d\n",Rg.CodCar);
				printf("Categoria: %s\n",Rg.Categoria);
				printf("Modelo: %s\n",Rg.Modelo);
				printf("PrecoDiaria: %.2f\n",Rg.PrecoDiaria);
				printf("\nDeseja Alterar (S/N)? ");
				if (toupper(getche())=='S')
				{
					printf("\nNova Categoria: ");
					fflush(stdin);
					gets(Rg.Categoria);
					printf("\nNovo Modelo: ");
					fflush(stdin);
					gets(Rg.Modelo);
					printf("\nNovo PrecoDiaria : ");
					scanf("%f",&Rg.PrecoDiaria);
					fseek(PtrCar,pos,0);
					fwrite(&Rg,sizeof(TpCarros),1,PtrCar);
					printf("\nDados do Carro alterados!\n");
				}
			}
			getch();
			printf("Codigo a qual voce deseja alterar os dados:[0]sair\n");
			printf("Codigo nao pode ser alterado !!\n");
			scanf("%d",&Rg.CodCar);	
		}
		fclose(PtrCar);
	}
}

void ListagemCarros(void)
{
	FILE * PtrCar = fopen("carros.dat","rb");
	TpCarros Rg;
	clrscr();
	textcolor(2);
	fread(&Rg,sizeof(TpCarros),1,PtrCar);
	while(!feof(PtrCar))	
	{
		if(Rg.Status == 1)
		{
			printf("\nCodigo do carro: %d\n",Rg.CodCar);
			printf("Categoria: %s\n",Rg.Categoria);
			printf("Modelo: %s\n",Rg.Modelo);
			printf("Preco diario: %.2f \n",Rg.PrecoDiaria);
			printf("\n");
		}
		
		fread(&Rg,sizeof(TpCarros),1,PtrCar);
	} 
	getch();
	fclose(PtrCar);
}

void CadastroLocacoes(void)// Verificar em todos os cadastros se a pessoa é ativa 
{
    FILE *PtrCli = fopen("clientes.dat","rb");
    FILE *PtrCar = fopen("carros.dat","rb");
    FILE *PtrLoc = fopen("locacoes.dat","rb+");
    TpCarros RegCar;
    TpLocacoes RegLoc;
	clrscr();
    char resp;
    char AuxCPF[15];
    int posCPF, posCar,Pos;
    int cod;
	textcolor(2);
    if(PtrCli == NULL || PtrCar == NULL || PtrLoc == NULL)
    {
        textcolor(4);
        printf("\nErro de abertura \n");
        textcolor(2);
    }
    else 
    {
        printf("\n# # # * * * Cadastrar Locacao * * * # # # \n");
        printf("Deseja cadastrar a locacao : [S] ou [N]\n");

        resp = toupper(getche());

        if(resp == 'S')
        {
            textcolor(2);
            printf("\n# # # * * * Dados * * * # # # \n");

            printf("\nCPF para Locacao (EX: 111.111.111-11): [Enter] para sair \n");
            fflush(stdin);
            gets(AuxCPF);

            while(strcmp(AuxCPF, "") != 0)
            {
                rewind(PtrCli);
                posCPF = BuscaCPFCliente(PtrCli, AuxCPF);

                if(posCPF == -1)
                {
                    printf("\nCliente nao cadastrado!\n");
                    printf("Volte ao menu e cadastre\n");
                }
                else
                {
                    printf("Qual o codigo do carro para a locacao:\n");
                    scanf("%d", &cod);

                    rewind(PtrCar);
                    posCar = BuscaBinariaCodCar(PtrCar, cod);

                    if(posCar == -1)
                    {
                        printf("\nCarro nao cadastrado!\n");
                        printf("Volte ao menu e cadastre\n");
                    }
                    else
                    {
                        Pos = BuscaExalstivaCPFeCodLoc(PtrLoc,PtrCar,cod,AuxCPF);
                        if(Pos == -1)
	                    {
	                        // LER O CARRO (necessário p/ preco diária)
	                        fseek(PtrCar, posCar, SEEK_SET);
	                        fread(&RegCar, sizeof(TpCarros), 1, PtrCar);
	
	                        strcpy(RegLoc.CPF, AuxCPF);
	                        RegLoc.CodCar = cod;
	
	                        fflush(stdin); // CORRIGE BUG DO SEGUNDO CADASTRO
	
	                        printf("Digite a quantidade de dias para locacao:\n");
	                        scanf("%d", &RegLoc.QtdeDia);
	
	                        RegLoc.ValorLocacao = RegLoc.QtdeDia * RegCar.PrecoDiaria;
	                        RegLoc.Status = 1;
	
	                        fseek(PtrLoc, 0, SEEK_END);
	                        fwrite(&RegLoc, sizeof(TpLocacoes), 1, PtrLoc);
	
	                        printf("\nLocacao cadastrada com sucesso!\n");
	                    }
	                    else
	                    {
	                    	textcolor(4);
	                    	printf("\nEsta Locacao ja esta cadastrada!\n");
	                    	textcolor(2);
						}
                    }
                }
				textcolor(2);
                printf("\nCPF para Locacao (EX: 111.111.111-11): [Enter] para sair \n");
                fflush(stdin);
                gets(AuxCPF);
            }
        }
        else
        {
            textcolor(1);
            printf("\nVoltando ao menu...\n");
        }
    }

    fclose(PtrCli);
    fclose(PtrCar);
    fclose(PtrLoc);
}

void ExclusaoLogicaLocacoes(void)
{
	FILE *PtrCli = fopen("clientes.dat","rb");
	FILE *PtrCar = fopen("carros.dat","rb");
	FILE *PtrLoc = fopen("locacoes.dat","rb+");
	TpLocacoes Rg;
	char AuxCPF[15],cad;
	int AuxCod,PosCPF,Pos;	
	clrscr();	
	textcolor(2);
	printf(" # # # Excluir Logicamente da Locacao # # #:\n");
	printf(" # # # [Enter] para sair# # # \n");
	printf("\nCPF:"); fflush(stdin);
	gets(AuxCPF);
	PosCPF = BuscaBinariaCPFLoc(PtrLoc, AuxCPF);
	if(PosCPF<0)
	{
		textcolor(4);
		printf("CPF nao encontrado!!");
	}
	else
	{
		printf("Esses sao seus carros locados:\n");
		ExibirLocacaoCPF(PtrLoc,AuxCPF);
		printf("Qual o codigo do carro que voce deseja excluir?\n");
		scanf("%d",&AuxCod);
		Pos = BuscaExalstivaCPFeCodLoc(PtrLoc,PtrCar,AuxCod,AuxCPF);
		if(Pos<0)
		{
			textcolor(4);
			printf("Esse carro nao foi encontrado!!");
		}
		else
		{
			fseek(PtrLoc,Pos,0);
			fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
			printf("Tem certeza que deseja excluir essa locacao? S ou N\n");
			printf("CPF = %s\n",Rg.CPF);
			printf("CodCar = %d\n",Rg.CodCar);
			printf("QtdeDias = %d\n",Rg.QtdeDia);
			printf("ValorLoc = %.2f\n",Rg.ValorLocacao);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				Rg.Status = 0;
				fseek(PtrLoc,Pos,0);
				fwrite(&Rg,sizeof(TpLocacoes),1,PtrLoc);
				textcolor(10);
				printf("Locacao Excluida");
			}
			else
			{
				textcolor(4);
				printf("A locacao nao foi excluida!!");
			}	
		}	
	}
	getch();	
	fclose(PtrCli);
	fclose(PtrCar);
	fclose(PtrLoc);
}

void ExclusaoFisicaLocacoes(void)
{
	FILE *PtrCli = fopen("clientes.dat","rb");
	FILE *PtrCar = fopen("carros.dat","rb");
	FILE *PtrLoc = fopen("locacoes.dat","rb+");
	TpLocacoes Rg;
	char AuxCPF[15],cad;
	int AuxCod,PosCPF,Pos;	
	clrscr();	
	textcolor(2);
	printf(" # # # Excluir Fisicamente da Locacao # # #:\n");
	printf(" # # # [Enter] para sair # # #\n");
	printf("\nCPF:"); fflush(stdin);
	gets(AuxCPF);
	PosCPF = BuscaBinariaCPFLoc(PtrLoc, AuxCPF);
	if(PosCPF<0)
	{
		textcolor(4);
		printf("CPF nao encontrado!!");
		textcolor(2);
		fclose(PtrLoc);
	}
	else
	{
		printf("Esses sao seus carros locados:\n");
		ExibirLocacaoCPF(PtrLoc,AuxCPF);
		printf("Qual o codigo do carro que voce deseja excluir?\n");
		scanf("%d",&AuxCod);
		Pos = BuscaExalstivaCPFeCodLoc(PtrLoc,PtrCar,AuxCod,AuxCPF);
		if(Pos<0)
		{
			textcolor(4);
			printf("Esse carro nao foi encontrado!!");
			textcolor(2);
			fclose(PtrLoc);
		}
		else
		{
			fseek(PtrLoc,Pos,0);
			fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
			printf("Tem certeza que deseja excluir essa locacao? S ou N\n");
			printf("CPF = %s\n",Rg.CPF);
			printf("CodCar = %d\n",Rg.CodCar);
			printf("QtdeDias = %d\n",Rg.QtdeDia);
			printf("ValorLoc = %.2f\n",Rg.ValorLocacao);
			cad = toupper ( getch());
			if(cad == 'S')
			{
				FILE *PtrTemp=fopen("Temp.dat","wb");
				rewind(PtrLoc);
				fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
				while (!feof(PtrLoc))
				{      
					if (AuxCod != Rg.CodCar && stricmp(Rg.CPF,AuxCPF)!=0)
						fwrite(&Rg,sizeof(TpLocacoes),1,PtrLoc);
					
					fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
				}
				fclose(PtrLoc);
				fclose(PtrTemp);
				remove("locacoes.dat");
				rename("Temp.dat","locacoes.dat");
				textcolor(10);
				printf("Locacao Excluida");
			}
			else
			{
				textcolor(4);
				printf("A locacao nao foi excluida!!");
				textcolor(2);
				fclose(PtrLoc);
			}	
		}	
	}
	getch();	
	fclose(PtrCli);
	fclose(PtrCar);
	
}

void AlteracaoLocacao(void)
{
	TpCarros RegCar;
	TpLocacoes Rg;
	int pos,posCar;
	FILE *PtrCli = fopen("clientes.dat","rb");
	FILE *PtrCar = fopen("carros.dat","rb");
	FILE *PtrLoc = fopen("locacoes.dat","rb+");
	clrscr();
	textcolor(2);
	printf("\n## Altera Locacao pelo Codigo e CPF ##\n");
	if (PtrLoc == NULL)
	{
		textcolor(4);
		printf("\nErro de Abertura!\n");
		textcolor(2);
	}
	else
	{
		// tem que verificar  os dois car e cli
		printf("Codigo e CPF nao pode ser alterado !!\n");
		textcolor(2);
		printf("CPF a qual voce deseja alterar os dados: [Enter] sair\n");
		gets(Rg.CPF);
		printf("Codigo a qual voce deseja alterar os dados: \n");
		scanf("%d",&Rg.CodCar);
		while(Rg.CodCar!=0)
		{
			pos = BuscaExalstivaCPFeCodLoc(PtrLoc,PtrCar,Rg.CodCar, Rg.CPF);
			if(pos==-1)
			{
				textcolor(4);
				printf("\nCodigo nao Cadastrado!\n");
				textcolor(2);
				printf("Se quiser cadastrar volte ao menu do Carro\n");
			}
			else
			{	
				rewind(PtrCar);		
				posCar = BuscaBinariaCodCar(PtrCar,Rg.CodCar);
				fseek(PtrCar, posCar, SEEK_SET);
	            fread(&RegCar, sizeof(TpCarros), 1, PtrCar);
	            
				fseek(PtrLoc,pos,0); //SEEK_SET  SEEK_CUR  SEEK_END
				fread(&Rg,sizeof(TpLocacoes),1,PtrLoc); //Ler Registro
				printf("** Detalhes da Locacao **\n");
				printf("CPF: %s\n",Rg.CPF);
				printf("Codigo: %d\n",Rg.CodCar);
				printf("QtdeDia: %d\n",Rg.QtdeDia);
				printf("ValorLocacao: %.2f\n",Rg.ValorLocacao);
				printf("\nDeseja Alterar (S/N)? ");
				if (toupper(getche())=='S')
				{
					printf("\nNova Quantidades de dias: ");
					scanf("%d",&Rg.QtdeDia);
					Rg.ValorLocacao = Rg.QtdeDia * RegCar.PrecoDiaria;
					printf("\nNovo Valor da Locacao sera de:  %.2f",Rg.ValorLocacao);
					
					fseek(PtrLoc,pos,0);
					fwrite(&Rg,sizeof(TpLocacoes),1,PtrLoc);
					printf("\nDados da Locacao alterados!\n");
				}
			}
			getch();
			printf("Codigo e CPF nao pode ser alterado !![0] sair\n");
			textcolor(2);
			printf("CPF a qual voce deseja alterar os dados: \n");
			fflush(stdin);
			gets(Rg.CPF);
			printf("Codigo a qual voce deseja alterar os dados: [0] PARA SAIR\n");
			scanf("%d",&Rg.CodCar);
		}
		fclose(PtrCli);
		fclose(PtrCar);
		fclose(PtrLoc);
	}
}

void ListagemLocacoes(void)
{
	FILE * PtrLoc = fopen("locacoes.dat","rb");
	TpLocacoes Rg;
	textcolor(2);
	clrscr();
	fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	while(!feof(PtrLoc))
	{
		if(Rg.Status == 1)
		{
			printf("CPF do Cliente: %s\n",Rg.CPF);
			printf("Codigo do carro: %d\n",Rg.CodCar);
			printf("QtdeDias: %d\n",Rg.QtdeDia);
			printf("Valor da Locacao: %.2f \n",Rg.ValorLocacao);
			printf("\n");
		}	
		fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	} 
	getch();
	fclose(PtrLoc);
}

void ListagemCarrosCategoriaUsuario(void)
{
	FILE * PtrCar = fopen("carros.dat","rb");
	TpCarros Rg;
	char AuxCategoria[TF];
	clrscr();
	textcolor(2);
	printf("\nDigite a categoria que deseja ver\n");
	fflush(stdin);
	gets(AuxCategoria);
	fread(&Rg,sizeof(TpCarros),1,PtrCar);
	while(!feof(PtrCar))
	{
		if(stricmp(AuxCategoria,Rg.Categoria)==0 && Rg.Status == 1)
		{
			printf("Categoria: %s\n",Rg.Categoria);
			printf("Codigo do carro: %d\n",Rg.CodCar);
			printf("Modelo: %s\n",Rg.Modelo);
			printf("Preco diario: %.2f \n",Rg.PrecoDiaria);
			printf("\n");
		}
		fread(&Rg,sizeof(TpCarros),1,PtrCar);
	} 
	getch();
	fclose(PtrCar);
}

void ListagemLocacoesValorMin (void)
{
	FILE * PtrLoc = fopen("locacoes.dat","rb");
	TpLocacoes Rg;
	clrscr();
	float AuxValor;
	textcolor(2);
	printf("\nDigite um valor para ver quais locacoes tem um valor maior \n");
	scanf("%f",&AuxValor);
	fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	while(!feof(PtrLoc))
	{
		if(AuxValor < Rg.ValorLocacao && Rg.Status == 1 )
		{
			printf("CPF do Cliente: %s\n",Rg.CPF);
			printf("Codigo do carro: %d\n",Rg.CodCar);
			printf("QtdeDias: %d\n",Rg.QtdeDia);
			printf("Valor da Locacao: %.2f \n",Rg.ValorLocacao);
			printf("\n");
		}
		fread(&Rg,sizeof(TpLocacoes),1,PtrLoc);
	} 
	getch();
	fclose(PtrLoc);
}

void RelatorioCompleto(void) // funciona de acordo com o chat e fiz de 2 formas diferentes
{
	FILE * PtrCli = fopen("clientes.dat","rb");
	FILE * PtrLoc = fopen("Locacoes.dat","rb");
	TpClientes RgCli;
	TpLocacoes RgLoc;
	int cont;
	fread(&RgCli,sizeof(TpClientes),1,PtrCli);
	while(!feof(PtrCli))
	{
		cont=0;
		rewind(PtrLoc);
		fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);
		if(RgCli.Status==1)
		{
			printf("CPF do Cliente: %s\n",RgCli.CPF);
			printf("Suas Locacoes:\n");
		}	
		while(!feof(PtrLoc))
		{
			if(stricmp(RgLoc.CPF,RgCli.CPF)==0 && RgLoc.Status == 1 && RgCli.Status==1)
			{
				printf("Codigo do carro: %d    QtdeDias:  %d    Valor da Locacao: %.2f\n",RgLoc.CodCar,RgLoc.QtdeDia,RgLoc.ValorLocacao);
				cont ++;
			}
			fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);	
		}
		if(cont == 0 && RgCli.Status==1)
			printf("Essa pessoa nao tem nenhuma Locacao feita\n");
		fread(&RgCli,sizeof(TpClientes),1,PtrCli);		
	} 
	fclose(PtrCli);
	fclose(PtrLoc);
}

void RelatorioCompleto2ponto0(void)
{
	FILE * PtrCli = fopen("clientes.dat","rb");
	FILE * PtrLoc = fopen("Locacoes.dat","rb");
	TpClientes RgCli;
	TpLocacoes RgLoc;
	int cont;
	textcolor(2);
	fread(&RgCli,sizeof(TpClientes),1,PtrCli);
	while(!feof(PtrCli))
	{
		cont=0;
		rewind(PtrLoc);
		fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);
		if(RgCli.Status==1)
		{
			printf("\nCPF do Cliente: %s\n",RgCli.CPF);
			printf("Suas Locacoes:\n");
			while(!feof(PtrLoc))
			{
				if(stricmp(RgLoc.CPF,RgCli.CPF)==0 && RgLoc.Status == 1)
				{
					printf("Codigo do carro: %d    QtdeDias:  %d    Valor da Locacao: %.2f\n",RgLoc.CodCar,RgLoc.QtdeDia,RgLoc.ValorLocacao);
					cont ++;
				}
				fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);	
			}
			if(cont == 0)
				printf("Essa pessoa nao tem nenhuma Locacao feita\n");
		}	
		fread(&RgCli,sizeof(TpClientes),1,PtrCli);		
	} 
	getch();
	fclose(PtrCli);
	fclose(PtrLoc);
}

void RelatorioMaisde3Locacoes(void)
{
	FILE * PtrCli = fopen("clientes.dat","rb");
	FILE * PtrLoc = fopen("Locacoes.dat","rb");
	TpClientes RgCli;
	TpLocacoes RgLoc;
	int cont;
	textcolor(2);
	fread(&RgCli,sizeof(TpClientes),1,PtrCli);
	while(!feof(PtrCli))
	{
		cont=0;
		rewind(PtrLoc);
		fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);
		if(RgCli.Status==1)
		{
			while(!feof(PtrLoc))
			{
				if(stricmp(RgLoc.CPF,RgCli.CPF)==0 && RgLoc.Status == 1)
					cont ++;
				fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);	
			}
			if(cont >= 3)
			{
                printf("\nCliente CPF: %s\n", RgCli.CPF);
                printf("Locacoes:\n");
				rewind(PtrLoc);
				fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);
				while(!feof(PtrLoc))
				{
					if(stricmp(RgLoc.CPF,RgCli.CPF)==0 && RgLoc.Status == 1)
						printf("Codigo do carro: %d    QtdeDias:  %d    Valor da Locacao: %.2f\n",RgLoc.CodCar,RgLoc.QtdeDia,RgLoc.ValorLocacao);
					fread(&RgLoc,sizeof(TpLocacoes),1,PtrLoc);	
				}
			}
		}	
		fread(&RgCli,sizeof(TpClientes),1,PtrCli);		
	} 
	getch();
	fclose(PtrCli);
	fclose(PtrLoc);
}

void CriarArquivos(void)
{
	FILE *PtrArq;
	
	PtrArq = fopen("clientes.dat","ab");
	fclose(PtrArq);
	
	PtrArq = fopen("carros.dat","ab");
	fclose(PtrArq);
	
	PtrArq = fopen("locacoes.dat","ab");
	fclose(PtrArq);
}

void Moldura(void)
{
    int i;
    textcolor(4);
    gotoxy(11,5);  
	printf("%c",201);
    gotoxy(70,5);  
	printf("%c",187);
    gotoxy(11,20); 
	printf("%c",200);
    gotoxy(70,20); 
	printf("%c",188);
    for(i = 11 + 1; i < 70; i++)
    {
        gotoxy(i,5);
        printf("%c",205);
        gotoxy(i,20);
        printf("%c",205);
    }
    for(i = 6; i < 20; i++)
    {
        gotoxy(11,i);
        printf("%c",186);
        gotoxy(70,i);
        printf("%c",186);
    }
}

char Menu1 ()
{	
	clrscr();
	Moldura();
	textcolor(4);
	gotoxy(25,7);
	printf("* * * # # # MENU # # #  * * *");
	gotoxy(15,9);
	printf("[A] Clientes");	
	gotoxy(15,10);
	printf("[B] Carros ");	
	gotoxy(15,11);
	printf("[C] Locacoes");	
	gotoxy(15,12);
	printf("[D] Listagem de Clientes que realizaram ");
	gotoxy(15,13);
	printf("    mais de 3 locacoes");
	gotoxy(15,14);
	printf("[E] Listagem de Carros escolhidos pelo usuario ");
	gotoxy(15,15);
	printf("    por categoria ");
	gotoxy(15,16);
	printf("[F] Listagem de Locacoes cujo valor total seja");
	gotoxy(15,17);
	printf("    maior que o limite informado.");
	gotoxy(15,18);
	printf("[G] Relatorio Completo");		
	gotoxy(15,19);
	printf("[ESC] Sair");
	return toupper(getch());
}

char Menu2 (char Nome[TF])
{
	textcolor(4);
	clrscr();
	Moldura();
	gotoxy(25,7);
	printf("* * * # # # %s # # #  * * *",Nome);
	gotoxy(15,9);
	printf("[A] Cadastro de %s",Nome);		
	gotoxy(15,10);
	printf("[B] Exclusao Logica de %s",Nome);		
	gotoxy(15,11);
	printf("[C] Exclusao Fisica de %s",Nome);		
	gotoxy(15,12);
	printf("[D] Alteracao de Dados por %s",Nome);		
	gotoxy(15,13);
	printf("[E] Listagem de %s ",Nome);
	gotoxy(15,14);
	printf("[ENTER] Voltar");
	return toupper(getch());
}
	
int main (void)
{
	char opcao;
	CriarArquivos();
	do
	{
		opcao = Menu1();	
		switch(opcao)
		{
			case 'A': 	do
						{
							opcao = Menu2("Clientes");
							switch(opcao)
							{
								case 'A': 	CadastroClientes();//Certo
											break;
								case 'B':	ExclusaoLogicaCliente();//Certo
											break;
								case 'C':	ExclusaoFisicaCliente();//Certo
											break;
								case 'D':	AlteracaoCliente();//Certo
											break;
								case 'E':	ListagemClientes();//Certo
											break; 
							}
						}while(opcao != 13);
					  	break;
			case 'B':	do
						{
							opcao = Menu2("Carro");
							switch(opcao)
							{
								case 'A': 	CadastroCarros();//Certo
											break;
								case 'B':	ExclusaoLogicaCarros();//Certo
											break;
								case 'C':	ExclusaoFisicaCarros();//Certo
											break;
								case 'D':	AlteracaoCarros();//Certo
											break;
								case 'E':	ListagemCarros();//Certo
											break; 
							}
						}while(opcao != 13);	
					  	break;
			case 'C':	do
						{
							opcao = Menu2("Locacao");
							switch(opcao)
							{
								case 'A':	CadastroLocacoes();//Certo
											break;
								case 'B':	ExclusaoLogicaLocacoes();//Certo
											break;
								case 'C':	ExclusaoFisicaLocacoes();//Certo
											break;
								case 'D':	AlteracaoLocacao();//Certo
											break;
								case 'E':	ListagemLocacoes();//Certo
											break; 
							}
						}while(opcao != 13);	
					  	break;
			case 'D':	RelatorioMaisde3Locacoes();//Certo
						break;
			case 'E':	ListagemCarrosCategoriaUsuario();//Certo
						break;
			case 'F':	ListagemLocacoesValorMin ();//Certo
						break;
			case 'G':	RelatorioCompleto2ponto0();//Certo
						break;
					  	
		}
		
	}while(opcao != 27);
	
	return 0;
}
