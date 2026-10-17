#include <stdio.h>

int main() {
    int numero;
    int fatorial = 1;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        fatorial = fatorial * i;
    }

    printf("Fatorial: %d\n", fatorial);

    return 0;
}
//O limite compativel de fatorial é 12. Pelos testes que fiz, o fatorial de 13 já dá erro. (Overflow)
//Não entendo bem fatorial, mas de acordo com o que pesquisei, seria isso
//o código. Por favor, me corrija se estiver errado.
