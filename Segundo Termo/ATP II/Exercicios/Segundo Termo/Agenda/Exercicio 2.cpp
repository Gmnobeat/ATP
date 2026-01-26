#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio2.h>
#include<ctype.h>

#define TF 10
struct TpEndereco
{
	int Numero,Cep;
	char Rua[30],Complemento[30],Bairro[30],Cidade[30],Pais[30],Estado[30];
};

struct TpTelefone
{
	int DDD,NumeroTel;
};

struct TpDataAniver
{
	int Dia,Mes,Ano;	
};

struct TpAgenda
{
	TpEndereco Endereco;
	TpTelefone Telefone;
	TpDataAniver Data;
	char Nome[30],Email[20],Obs[30];
};

void AbrirArq(char caminho[80])
{
	char Aux;
	printf("nome do arq: ");
	gets(caminho);
	FILE * PtrAgenda = fopen(caminho,"rb");
	if(PtrAgenda == NULL)
	{
		printf("Arquivo nao encontrado! deseja criar um? (S/N)");
		Aux = toupper(getch());
		if(Aux == 'S')
		{
			FILE * PtrAgenda = fopen(caminho,"wb");
			printf("Arquivo criado!");
		}
		else
			printf("arquivo nao foi criado!");
	}
	else
		printf("Arquivo pronto para uso!");	
	fclose(PtrAgenda);
}
void CadastroPessoas(char caminho[80],TpAgenda Agenda[TF])
{
	FILE * PtrAgenda = fopen(caminho,"ab");
	TpAgenda AuxAgenda;
	printf("nome: ");
	gets(AuxAgenda.Nome);
	while(strlen(AuxAgenda.Nome) != 0)
	{
		printf("Email: ");
		fflush(stdin);
		gets(AuxAgenda.Email);
		printf("Telefone: (DDD depois o numero)");
		scanf("%d",&AuxAgenda.Telefone.DDD);
		scanf("%d",&AuxAgenda.Telefone.NumeroTel);
		printf("Data de Nascimento:");
		scanf("%d",&AuxAgenda.Data.Dia);
		scanf("%d",&AuxAgenda.Data.Mes);
		scanf("%d",&AuxAgenda.Data.Ano);
		printf("Endereco:");
		fflush(stdin);
		printf("Pais:");
		gets(AuxAgenda.Endereco.Pais);
		printf("Estado:");
		gets(AuxAgenda.Endereco.Estado);
		printf("Cidade:");
		gets(AuxAgenda.Endereco.Cidade);
		printf("Rua:");
		gets(AuxAgenda.Endereco.Rua);
		printf("Bairro:");
		gets(AuxAgenda.Endereco.Bairro);
		printf("Complemento:");
		gets(AuxAgenda.Endereco.Complemento);
		printf("Numero:");
		scanf("%d",&AuxAgenda.Endereco.Numero);
		printf("CEP:");
		scanf("%d",&AuxAgenda.Endereco.Cep);
		printf("Observacao:");
		fflush(stdin);
		gets(AuxAgenda.Obs);
	}
}

void BuscaNome(char caminho[80], TpAgenda Agenda[TF])
{
	FILE * PtrAgenda = fopen(caminho,"rb");
	TpAgenda AuxAgenda;
	char AuxNome[30];
	int Qtd;
	printf("Qual nome deseja procurar?");
	gets(AuxNome);
	
}

int main (void)
{
	TpAgenda Agenda[TF];
	char NomeArq[80];
	AbrirArq(NomeArq);
	CadastroPessoas(NomeArq,Agenda);
	return 0;
}
