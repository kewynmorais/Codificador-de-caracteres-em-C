#include <stdio.h>
#include <math.h>

void valorPicole(
    int *QTDpicole1,
    int *QTDpicole2,
    int *QTDpicole3,
    float *valorPicole1,
    float *valorPicole2,
    float *valorPicole3
) {

    float picole1 = 0.50;
    float picole2 = 0.60;
    float picole3 = 0.75;

    *valorPicole1 = picole1 * (*QTDpicole1);
    *valorPicole2 = picole2 * (*QTDpicole2);
    *valorPicole3 = picole3 * (*QTDpicole3);
}

int main() {

    int QTDpicole1;
    int QTDpicole2;
    int QTDpicole3;
    float valorPicole1;
    float valorPicole2;
    float valorPicole3;

    printf("Qual a quantidade desejada do picolé 1? ");
    scanf("%d", &QTDpicole1);

    printf("Qual a quantidade desejada do picolé 2? ");
    scanf("%d", &QTDpicole2);

    printf("Qual a quantidade desejada do picolé 3? ");
    scanf("%d", &QTDpicole3);

    valorPicole(
        &QTDpicole1,
        &QTDpicole2,
        &QTDpicole3,
        &valorPicole1,
        &valorPicole2,
        &valorPicole3
    );

    printf("Picolé 1: %d unidades - Total: R$ %.2f\n",
           QTDpicole1, valorPicole1);
    printf("Picolé 2: %d unidades - Total: R$ %.2f\n",
           QTDpicole2, valorPicole2);
    printf("Picolé 3: %d unidades - Total: R$ %.2f\n",
           QTDpicole3, valorPicole3);
    return 0;
}

