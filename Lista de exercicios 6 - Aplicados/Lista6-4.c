#include <stdio.h>
#include <stdlib.h>

void calcularTroco()
{
    int compra, pagamento, troco;
    int notas100, notas10, notas1;
    int totalNotas;

    printf("Digite o valor da compra: ");
    scanf("%d", &compra);

    printf("Digite o valor pago: ");
    scanf("%d", &pagamento);

    troco = pagamento - compra;

    notas100 = troco / 100;
    troco = troco % 100;

    notas10 = troco / 10;
    troco = troco % 10;

    notas1 = troco;

    totalNotas = notas100 + notas10 + notas1;

    printf("\nValor da compra: R$ %d\n", compra);
    printf("Valor do troco: R$ %d\n", pagamento - compra);

    printf("Notas de R$100: %d\n", notas100);
    printf("Notas de R$10: %d\n", notas10);
    printf("Notas de R$1: %d\n", notas1);

    printf("Quantidade minima de notas: %d\n", totalNotas);
}

int main()
{
    calcularTroco();

    return 0;
}