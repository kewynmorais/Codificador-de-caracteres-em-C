#include <stdio.h>

int main() {
    int matriz[4][4];
    int par = 0;
    int impar = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);

            if (matriz[i][j] % 2 == 0) {
                par++;
            } else {
                impar++;
            }
        }
    }

    printf("Quantidade de pares: %d\n", par);
    printf("Quantidade de impares: %d\n", impar);

    return 0;
}