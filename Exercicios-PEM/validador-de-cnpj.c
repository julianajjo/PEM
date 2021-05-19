/******************************************************************************

Projeto Validador de CNPJ
------------------------------------
Nome: Juliana de Jesus de Oliveira
RA: 2040482023005
ADS - Noturno

*******************************************************************************/
#include <stdio.h>
#include<string.h>

int calculaDigito(int cnpj[], int mult[], int N)
{	int soma=0, i;
	for(i=0; i<N; i++)
	{	soma = soma + cnpj[i]*mult[i];
	}
	int resto = soma % 11;
	
	if (resto < 2){
	    resto = 0;
	} else {
	    resto = 11 - resto;
	}
}

void conversaoEntrada(char entrada[], int cnpj[])
{   int i, j, tamanho;
    for(i=0; i<14; i++)
        cnpj[i] = 0;
	j=13;
	tamanho = strlen(entrada);
	for(i=tamanho-1; i>=0; i--)
	{   if(entrada[i] >= '0' && entrada[i] <= '9') 
	    {   cnpj[j] = entrada[i] - '0'; 
	        j--;
	    }
	    if(j<0) break;  
	}
}

int main()
{
    int cnpj[13];
    char entrada[50];
	int multip1[12]={5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	int multip2[13]={6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	
	printf("Entre com os 14 dígitos do CNPJ:");
	fgets(entrada, 50, stdin);
	
	 conversaoEntrada(entrada, cnpj);
	
	if(calculaDigito(cnpj, multip1, 12) == cnpj[12] &&
	    calculaDigito(cnpj, multip2, 13) == cnpj[13])
	       printf("\nO CNPJ é válido.");
	   else printf("\nHá um erro no CNPJ.");

    return 0;
}




