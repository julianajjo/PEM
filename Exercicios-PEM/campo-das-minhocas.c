/******************************************************************************

Tarefa PEM - Matrizes
5) Resolva o problema (que já caiu numa prova de PEM) chamado Campo das Minhocas:

https://www.urionlinejudge.com.br/judge/pt/problems/view/2293


*******************************************************************************/
#include <stdio.h>

int somarLinha(int L, int C, int mat[L][C], int linha)
{
    int y, soma=0;
    for(y=0; y<C; y++)
    { soma = soma + mat[linha][y];
    }
    return soma;
}

int somarColuna(int L, int C, int mat[L][C], int coluna)
{
    int x, soma=0;
    for(x=0; x<L; x++)
    { soma = soma + mat[x][coluna];
    }
    return soma;
}

int main()
{
    int L, C, x, y, maior;
    scanf("%d%d", &L, &C);
    int mat[L][C];
    
    for(x=0; x<L; x++)
    {
        for(y=0; y<C; y++)
        {
            scanf("%d", &mat[x][y]);
        }
    }
    
    maior = somarLinha(L, C, mat, 0);
    for(x=1; x<L; x++)
    {
        int s = somarLinha(L, C, mat, x);
        if(s > maior)
        {
            maior = s;
        }
    }
    
    for(y=0; y<C; y++)
    {
        int s = somarColuna(L, C, mat, y);
        if(s > maior)
        {
            maior = s;
        }
    }
    
    
    printf("%d\n", maior);
    
    return 0;
}

