/******************************************************************************

Imprimir as n primeiras linhas do triângulo de Pascal. Você pode fazer com uma 
matriz ou mesmo utilizando um único vetor.
Dicas:
a) a primeira coluna sempre contém 1.
b) o último elemento de cada linha sempre é 1.
c) todos os outros elementos podem ser calculados somando-se o de cima com o de 
cima à esquerda.

1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5 10  10   5  1
1   6 15  20  15  6  1
1   7  21 35  35  21 7  1
1   8  28 56  70  56 28 8  1

*******************************************************************************/
#include <stdio.h>

int main()
{   
    int N;
    printf("Qual o número de linhas do triângulo de Pascal? ");
    scanf("%d", &N);
    
    int mat[N][N];
    int l, c;
    
    for(l=0; l<N; l++)
    {
        for(c=0; c<=l; c++)
        {
            if(c==0) mat[l][c] = 1;
            else if(l==c) mat[l][c] = 1;
            else mat[l][c] = mat[l-1][c] + mat[l-1][c-1];
            
            printf("%4d", mat[l][c]);
        }
        
        printf("\n");
    }
    return 0;
}



