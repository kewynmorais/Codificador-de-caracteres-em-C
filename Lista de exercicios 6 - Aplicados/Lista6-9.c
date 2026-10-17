#include <stdio.h>


int main() {
    int soma = 0;

    for (int numero = 85; numero <=907; numero ++) {
        if(numero % 2 ==0) {
            printf("%d\n", numero);
            soma = soma + numero;
        }
     }  printf("A soma total é: %d\n", soma);
        return 0;
}
//Está imprimindo todos os números pares entre 85 e 907 e no final imprime 
//a soma total desses números pares.