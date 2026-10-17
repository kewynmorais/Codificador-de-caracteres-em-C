#include <stdio.h>

int main() {
    char nome[50];
    int parafusos, porcas, arruelas;

    float precoParafuso = 2.00;
    float precoPorca = 1.50;
    float precoArruela = 1.00;

    float totalParafusos;
    float totalPorcas;
    float totalArruelas;
    float desconto;
    float total;

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    printf("Digite a quantidade de parafusos: ");
    scanf("%d", &parafusos);

    printf("Digite a quantidade de porcas: ");
    scanf("%d", &porcas);

    printf("Digite a quantidade de arruelas: ");
    scanf("%d", &arruelas);

    totalParafusos = parafusos * precoParafuso;
    totalPorcas = porcas * precoPorca;
    totalArruelas = arruelas * precoArruela;

    desconto = totalParafusos * 0.20;
    desconto = desconto + totalPorcas * 0.10;
    desconto = desconto + totalArruelas * 0.30;

    total = totalParafusos + totalPorcas + totalArruelas - desconto;

    printf("\nCliente: %s\n", nome);
    printf("Parafusos: %d\n", parafusos);
    printf("Porcas: %d\n", porcas);
    printf("Arruelas: %d\n", arruelas);
    printf("Total de desconto: R$ %.2f\n", desconto);
    printf("Total a pagar: R$ %.2f\n", total);

    return 0;
}

