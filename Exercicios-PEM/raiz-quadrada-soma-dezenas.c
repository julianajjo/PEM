/******************************************************************************
Qualquer número natural de quatro algarismos pode ser dividido em duas dezenas 
formadas pelos seus dois primeiros e dois últimos  dígitos.
Exemplos:
 1297: 12 e 97.
 5314: 53 e 14.
Escreva um programa que imprime todos os milhares (4 algarismos) cuja raiz 
quadrada seja a soma das dezenas formadas pela divisão acima.

Exemplo: raiz de 9801 = 99 = 98 + 01.
Portanto 9801 é um dos números a ser impresso.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int i, dezena1, dezena2;
    
    for(i = 1000; i < 9999; i++)
    {
        dezena1 = i % 100;
        dezena2 = i / 100;
        if(i == (dezena1+dezena2)*(dezena1+dezena2)){
            printf("%d\n", i);
        }
    }

    return 0;
}
