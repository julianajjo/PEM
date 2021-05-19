/******************************************************************************

Dadas duas sequências com n números inteiros entre 0 e 9, interpretadas como 
dois números inteiros de n algarismos, calcular a sequência de números que 
representa a soma dos dois inteiros.
Exemplo: n = 8,
		1ª sequência		8 2 4 3 4 2 5 1
		2ª sequência		3 3 7 5 2 3 3 7  +
					     -----------------------
					     1 1 6 1 8 6 5 8 8

*******************************************************************************/
#include <stdio.h>

int main()
{
    int vet1[]={8, 2, 4, 3, 4, 2, 5, 1}, N=8; //aqui terá que colocar em ordem contrária
    int vet2[]={3, 3, 7, 5, 2, 3, 3, 7};
    int vet3[N+1];
    int i, vaium=0, somaaux;
    
    for(i=0; i<N; i++)
    {
        somaaux = vet1[i] + vet2[i] + vaium;
        vet3[i] = somaaux % 10;
        vaium = somaaux / 10;
    }
    
    //outra alteranativa, sem utilizar módulo e divisão
    //for(i=0; i<N; i++)
    // {   somaaux = vet1[i] + vet2[i] + vaium;
    //     if(somaaux < 10)
    //    {   vet3[i] = somaaux;
    //        vaium = 0;
    //    }
    //    else
    //    {   vet3[i] = somaaux-10;
    //        vaium = 1;
    //    }
    //}
    
    
    vet3[N] = vaium;
    for(i=N; i>=0; i--)
        printf("%d", vet3[i]);
    return 0;
}

