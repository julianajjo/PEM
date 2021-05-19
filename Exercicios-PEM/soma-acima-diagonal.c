/******************************************************************************

Tarefa PEM - Matrizes
3) Faça um programa (ou uma função) que some os elementos acima da diagonal 
principal de uma matriz quadrada.

*******************************************************************************/
#include <stdio.h>

int acimaDiagPrincipal(int N, int mat[N][N])	
{	int l, c, soma = 0;
	for(l=0; l<N; l++)
	{	for(c=0; c<N; c++)
		{	if( c > l )
				soma = soma + mat[l][c];
		}
	}
	return soma; 
}

int main()
{	int 	somarMatriz[4][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
	
	printf("\nA soma dos elementos acima da diagonal principal é: %d\n", acimaDiagPrincipal(4, somarMatriz));
	return 0;
}


