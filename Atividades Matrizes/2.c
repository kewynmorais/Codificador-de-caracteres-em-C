#include <stdio.h>

int main () {
    int matriz[3][3];
    int vetor[9];
    int soma = 0;
    float media = 0;
    int k = 0;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        scanf("%d", &matriz[i][j]);
        soma += matriz[i][j];
        vetor[k] = matriz[i][j];
        k++;
        }
    }

    for ( int i = 0; i < 9; i++) {
        for (int j = 0; j < 8 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    int mediana = vetor[4];
    media =(float)soma / 9;

    printf("\nA soma da matriz é: %d\n", soma);
    printf("A média é: %f\n", media);
    printf("A mediana é: %d\n", mediana);

}