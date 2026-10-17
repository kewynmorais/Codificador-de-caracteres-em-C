#include <stdio.h>
#include <math.h>

float comissao( float venda) {
    float comissao;

    if (venda > 50000) {
        comissao = (venda * 0.12);
    } else if (venda <= 50000 && venda >=30000) {
        comissao = (venda * 0.095);
    } else {comissao = (venda * 0.07);
    }
    return comissao;
}

int main() {
    float valorVENDA;
    float valorCOMISSAO;
    float totalVENDAS=0;
    char vendedor[50];

    for (int i=0; i < 3; i ++) {
    printf("Qual o nome do vendedor? ");
    scanf("%s", vendedor);

    printf("Qual o valor da venda? ");
    scanf("%f", &valorVENDA);

    totalVENDAS= (totalVENDAS+valorVENDA);
    valorCOMISSAO= comissao(valorVENDA);

    printf("Vendedor: %s\n", vendedor);
    printf("Valor da venda: R$%.2f\n", valorVENDA);
    printf("Comissão da venda: R$%.2f\n", valorCOMISSAO);
} printf("O valor total em vendas é igual a R$%.2f\n", totalVENDAS);
return 0;
}
