/******************************************************************************
Todos estes exercícios a seguir têm por base o código-base abaixo, que é um mini 
CRUD (Create-Read-Update-Delete, ou Criar-Ler-Atualizar-Remover).

1) Inclua novos campos, como endereço, e-mail, data de nascimento, etc.

2) Crie uma função procurar, com a assinatura abaixo, de modo que ela possa ser 
aproveitada tanto na funcionalidade procurar, quanto na excluir:

	int procurar(char procurado[], struct ficha vetor[], int num_fichas)

O retorno dessa função será o índice do elemento encontrado, ou -1, caso o mesmo 
não tenta sido localizado.

3) Refaça a funcionalidade de exclusão de modo a não ter que copiar todos os 
elementos abaixo do excluído.

Código a ser substituído:
	int j;
       for(j=i+1; j<fichas_existentes; j++)
       {
   	 agenda[j-1] = agenda[j];
       }
       fichas_existentes--;
       proxima--;


4) Refaça o procurar de modo a trabalhar mesmo com pedaços de nomes (dica: 
pesquise uma função chamada "strstr").

DICA: exemplo de uso da função strstr()
--------

#include <stdio.h>
#include <string.h>
int main () {
	char texto[20] = "Joao da Silva";
	char pedaco1[10] = "Silva";
	char pedaco2[10] = "Santos";

	if(strstr(texto, pedaco1) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
			pedaco1, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco1, texto);

	if(strstr(texto, pedaco2) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
			pedaco2, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco2, texto);
	return 0;
}


*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
	char endereco[50];
	char email[40];
	bool ativo;
	//char dataNascimento[];
};

void minusculo(char str[])
{   int i, tam=strlen(str);
    for(i=0; i<tam; i++)
        str[i] = tolower(str[i]);
}

int procurar(char procurado[], struct ficha vetor[], int num_fichas)
{
    int i;
    char confirmacao[20], nomeMinusculo[40];
    minusculo(procurado);
    
    for(i=0; i<num_fichas; i++){
        strcpy(nomeMinusculo, vetor[i].nome);
        minusculo(nomeMinusculo);
        if(strstr(vetor[i].nome, procurado) != NULL)
        {
            printf("Achei esta ficha: %s, Telefone: %s\n", vetor[i].nome, vetor[i].telefone);
            printf("É esta que procura? (S/N)\n");
            gets(confirmacao);
            if(confirmacao[0] == 's' || confirmacao[0] == 'S')
                return i;
        }
        return -1;
    }
}

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0"; 
        setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '5')
	{

		printf("\nEntre com a opção desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') //inserir
		{
			printf("\nDigite um nome para incluir na agenda:");
			gets(agenda[proxima].nome);
			printf("\nDigite o telefone:");
			gets(agenda[proxima].telefone);
			printf("\nDigite o endereço:");
			gets(agenda[proxima].endereco);
			printf("\nDigite o e-mail:");
			gets(agenda[proxima].email);
			agenda[proxima].ativo = true;
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome a ser procurado:");
			gets(procurado);
			int resposta = procurar(procurado, agenda, fichas_existentes);
			if(resposta != -1){
			    printf("Dados de %s:\n Telefone: %s\n Endereço: %s\n E-mail: %s\n\n",
			    agenda[resposta].nome, agenda[resposta].telefone, agenda[resposta].endereco, agenda[resposta].email);
			}    
			else 
			    printf("\n\nNome não encontrado!\n");
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    if (agenda[i].ativo)
			      printf("Dados de %s:\n Telefone: %s\n Endereço: %s\n E-mail: %s\n\n",
			      agenda[i].nome, agenda[i].telefone, agenda[i].endereco, agenda[i].email);
			}
			if(fichas_existentes == 0)
				printf("A base de dados está vazia!\n");
		}
		if(opcao[0] == '4') //excluir	
		{
			char procurado[40];
			printf("\nEntre com o nome que será excluído:");
			gets(procurado);
            int resposta = procurar(procurado, agenda, fichas_existentes);
			if(resposta != -1){
			    printf("\n\nOs dados de %s foram removidos da agenda!\n(Telefone: %s, Endereço: %s e E-mail: %s)\n",
			    agenda[resposta].nome, agenda[resposta].telefone, agenda[resposta].endereco, agenda[resposta].email);
			    agenda[resposta].ativo = false;
			 }
			else
			  printf("\n\nNome não encontrado!\n");
		}
	}
	return 0;
}




