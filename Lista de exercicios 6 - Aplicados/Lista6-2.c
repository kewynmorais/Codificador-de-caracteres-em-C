#include <stdio.h>
#include <math.h>

void formula(int numero){
    if (numero <=10){
    printf("F1");
    } else if (numero >10 && numero <=100){
        printf("F2");
    } else {printf("F3");
    }
}

int main() {
    int numeral;

    printf("Digite um número aleatório: ");
    scanf("%d", &numeral);

    formula(numeral);
    return 0;
}
