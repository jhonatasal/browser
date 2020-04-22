//NOME DO ALUNO: JHONATAS ALVES DE SOUZA
//jhonatasa_s@hotmail.com
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//ESSE HISTORICO TEM UM TAMANHO MAXIMO
#define TAMANHHODOHISTORICO  20

//STRUCTS
typedef struct Hora
{
	int hora;
	int minuto;
};

typedef struct Site
{
	int id;
	char nome[255];
	Hora momentoAcesso;
};

//CHAMADAS DE FUNCOES
void imprimeCabecalho();
void acessarSite(Site *historico, int posicao);
void limpaTela();
void imprimeFuncoesSistema();
void excluirAcessos(Site *historico, int qtd);
void imprimeListaDeSites(Site *historico, int qtd);
void deletaTodoHistorico(Site *historico, int qtd);

//PROGRAMA PRINCIPAL
int main()
{
	//DECLARANDO VARIAVEIS
	int opcao = 0, quantidadeAcesso = 0;

	//ARMAZENA O HISTORICO DO SISTEMA
	Site historicoSites[TAMANHHODOHISTORICO];
	
	//MENU PRINCIPAL
	while(opcao != 4)
	{
		//FUNCOES DO SISTEMA
		imprimeFuncoesSistema();

		scanf("%d", &opcao);

		switch(opcao)
		{
		case  1  :

			acessarSite(historicoSites, quantidadeAcesso);
			quantidadeAcesso++;
			system("pause");
			break;
		case 2 :
			excluirAcessos(historicoSites, quantidadeAcesso);
			system("pause");
			break;
		case  3 :
			imprimeListaDeSites(historicoSites, quantidadeAcesso);
			system("pause");
			break;
		case 4 :
			printf("ATÉ MAIS!!!!", opcao);
			break;
		default:
			printf("Opcao ivalida");
			break;
		}
	}
	system("pause");
	return 0;
}
//DETALHAMENTO DE FUNCOES
void imprimeCabecalho()
{
	printf("-------------Por favor escolha a opcao desejada------------- \n");
}

//FUNCAO QUE ACESSA SITE
void acessarSite(Site *historico, int posicao)
{
	time_t timer;
	struct tm *horarioLocal;
	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local
	limpaTela();//limpa a tela
	printf("Digite o endereco que deseja acessar \n");
	Site site;
	site.id = rand() % 3;
	scanf("%s", &site.nome);
	site.momentoAcesso.hora = horarioLocal->tm_hour;
	site.momentoAcesso.minuto = horarioLocal->tm_min;
	printf("Bem vindo ao site %s\n", &site.nome);
	historico[posicao] =  site;
}
void limpaTela()
{
	system("CLS");
}


//INTERFACE QUE EXCLUI HISTORICO
void excluirAcessos(Site *historico, int qtd)
{
	printf("DESEJA DELETAR TODOS OS SITES OU UM ESPECIFICO:\n");
	printf("1 - TODOS \n2 - ESPECIFICO \n");
	int opcao;
	scanf("%d", &opcao);
	if(opcao == 1 )
	{
		deletaTodoHistorico(historico, qtd);
		system("pause");
		imprimeListaDeSites(historico, qtd);
	}
	else if(opcao == 2)
	{
		imprimeListaDeSites(historico, qtd);
	}

}

//FUNCAO QUE IMPRIME FUCOES DO SISTEMA
void imprimeFuncoesSistema()
{
	limpaTela();
	imprimeCabecalho();
	printf("1 - PARA ABRIR O NAVEGADOR \n");
	printf("2 - PARA EXCLUIR O ACESSOS DO NAVEGADOR \n");
	printf("3 - IMPRIMIR HISTORICO DO NAVEGADOR \n");
	printf("4 - SAIR DO PROGRAMA \n");
}

//FUNCAO QUE IMPRIME SITES VISITADOS
void imprimeListaDeSites(Site *historico, int qtd)
{
	limpaTela();
	int i ;
	printf("ESSA EH A LISTA DE SITES ACESSADOS: \n");

	for( i = 0;  i < qtd; i++)
	{
		printf(" %d - Site: %s, Horario(HH:MM): %d:%d\n", i, historico[i].nome, historico[i].momentoAcesso.hora, historico[i].momentoAcesso.minuto);
	}
}

//FUNCAO DELETA TODO O HISTORICO
void deletaTodoHistorico(Site *historico, int qtd)
{
	limpaTela();
	Site aux[TAMANHHODOHISTORICO];
	historico = aux;
	printf("TODOS OS ACESSOS FORAM EXCLUIDOS \n");
}

//FUNCAO DELETA ACESSO ESPECIFICO
void deletaAcessoEspecifico(Site *historico)
{
	int acesso;
	printf("DIGITE O NUMERO DO ACESSO A DELETAR: \n ");
	scanf("%d", &acesso);
}
