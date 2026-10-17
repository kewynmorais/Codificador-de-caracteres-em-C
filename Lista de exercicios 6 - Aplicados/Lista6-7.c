#include <stdio.h>

void valorDiarias(int diarias, float *valorTotal) {

    float taxaEstadia;

    if (diarias > 15) {
        taxaEstadia = 5.50;
    
    } else if (diarias == 15) {
        taxaEstadia = 6.00;
    } else { taxaEstadia = 8;
    }

    *valorTotal = (60.00 * diarias) + (taxaEstadia * diarias);
}

int main() {
    char nome[50];
    int diarias;
    float valorTotal;

    printf("Digite o nome do cliente: ");
    scanf("%49s", nome);//usar 1 a menos pro \0 do fim da string
    printf("Digite o número de diarias desejadas: ");
    scanf("%d", &diarias);
    
    valorDiarias(diarias, &valorTotal);

    printf("Cliente: %s\n", nome);
    printf("Valor total da conta é R$%.2f\n", valorTotal);
    return 0;

}