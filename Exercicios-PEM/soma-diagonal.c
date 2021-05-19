/******************************************************************************

Tarefa PEM - Matrizes
2) Faça um programa (ou uma função) que some os elementos da diagonal principal 
de uma matriz quadrada.

*******************************************************************************/
#include <stdio.h>

int somaDiagonalPrinc(int N, int mat[N][N])	
{	int i, soma = 0;
    for(i=0; i<N; i++)
	{	soma = soma + mat[i][i];
	}
	return soma; 
}

int main()
{	int 	somarMatriz[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	
	printf("\nA soma da diagonal principal da matriz é: %d\n", somaDiagonalPrinc(4, somarMatriz));
	return 0;
}

