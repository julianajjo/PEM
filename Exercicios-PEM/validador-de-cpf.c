/******************************************************************************

Validador de CPF

- Validação do primeiro e segundo dígito verficador através de uma função
- Checagem de dígitos repetidos
- Retorno do estado de origem do CPF

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include<string.h>

void imprimeEstado(int cpf[])
{
if(cpf[8] == 0) printf("\nRio Grande do Sul");
    else if(cpf[8] == 1) printf("\nDistrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins");
    else if(cpf[8] == 2) printf("\nAmazonas, Pará, Roraima, Amapá, Acre e Rondônia");
    else if(cpf[8] == 3) printf("\nCeará, Maranhão e Piauí");
    else if(cpf[8] == 4) printf("\nParaíba, Pernambuco, Alagoas e Rio Grande do Norte");
    else if(cpf[8] == 5) printf("\nBahia e Sergipe");
    else if(cpf[8] == 6) printf("\nMinas Gerais");
    else if(cpf[8] == 7) printf("\nRio de Janeiro e Espírito Santo");
    else if(cpf[8] == 8) printf("\nSão Paulo");
    else if(cpf[8] == 9) printf("\nParaná e Santa Catarina");
}

bool todosDigitosIguais(int cpf[])
{   int i;
    for(i=0; i<10; i++)
    {   if(cpf[i] != cpf[i+1])
            return false;
    }
    return true;
}

int calculaDigito(int cpf[], int mult[], int N)
{	int soma=0, i;
	for(i=0; i<N; i++)
	{	soma = soma + cpf[i]*mult[i];
	}
	int resto = ((soma*10) % 11)%10;
	return resto;
}

void converterEntrada(char entrada[], int cpf[])
{   int i, j, tamanho;
    //inicializo todo o vetor cpf com zeros
    for(i=0; i<11; i++)
        cpf[i] = 0;
	j=10;
	tamanho = strlen(entrada);
	for(i=tamanho-1; i>=0; i--)
	{   if(entrada[i] >= '0' && entrada[i] <= '9') //é dígito
	    {   cpf[j] = entrada[i] - '0'; //conversão para número
	        j--;
	    }
	    if(j<0) break;  //para proteger de entradas com mais de 11 dígitos
	}
}

int main()
{
    int cpf[10];
    char entrada[50];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	
	printf("Digite os 11 dígitos do CPF:");
	fgets(entrada, 50, stdin);
	
    converterEntrada(entrada, cpf);
	
	if(!todosDigitosIguais(cpf) && 
	   calculaDigito(cpf, m1, 9) == cpf[9] &&
	   calculaDigito(cpf,m2, 10) == cpf[10])
	   {
	       printf("\nCPF válido.");
	       imprimeEstado(cpf);
	   }
	   else printf("\nErro no CPF.");
    return 0;
}


