#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void tamanho (int a, int b) {
 if (a > b)
 { printf("%d", a);
 } else if (b > a){
    printf("%d", b);
 }
 }
 
    

int main (){

    int a, b;

    printf("Digite um número: ");
    scanf("%d", &a);

    printf("Digite um número: ");
    scanf("%d", &b);

    tamanho(a, b);
    
    return 0;

}
