#include <stdio.h>

int main() {
    int matriz[5][5];
    int somaLinha4 = 0;
    int somaColuna2 = 0;
    int somaPrincipal = 0;
    int somaSecundaria = 0;
    int somaTotal = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
            somaTotal += matriz[i][j];
        }
    }

    for (int j = 0; j < 5; j++) {
        somaLinha4 += matriz[3][j];
    }

    for (int i = 0; i < 5; i++) {
        somaColuna2 += matriz[i][1];
    }

    for (int i = 0; i < 5; i++) {
        somaPrincipal += matriz[i][i];
        somaSecundaria += matriz[i][4 - i];
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma Linha 4: %d\n", somaLinha4);
    printf("Soma Coluna 2: %d\n", somaColuna2);
    printf("Soma Diagonal principal: %d\n", somaPrincipal);
    printf("Soma Diagonal secundaria: %d\n", somaSecundaria);
    printf("Soma de todos os elementos: %d\n", somaTotal);

    return 0;
}