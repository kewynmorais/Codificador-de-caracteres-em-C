#include <stdio.h>

int main() {
    int quantidade;
    char nome[50];
    float salario;
    float soma = 0;
    float maior = 0;
    float menor = 0;
    float media;

    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &quantidade);

    for (int i = 1; i <= quantidade; i++) {
        printf("\nDigite o nome do funcionario: ");
        scanf("%s", nome);

        printf("Digite o salario: ");
        scanf("%f", &salario);

        soma = soma + salario;

        if (i == 1) {
            maior = salario;
            menor = salario;
        }

        if (salario > maior) {
            maior = salario;
        }

        if (salario < menor) {
            menor = salario;
        }
    }

    media = soma / quantidade;

    printf("\nMedia dos salarios: R$ %.2f\n", media);
    printf("Maior salario: R$ %.2f\n", maior);
    printf("Menor salario: R$ %.2f\n", menor);

    return 0;
}