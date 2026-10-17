#include <stdio.h>

int main() {
    int n;
    int primeiro = 0;
    int segundo = 1;
    int proximo;

    printf("Digite N: ");
    scanf("%d", &n);

    printf("%d %d ", primeiro, segundo);

    for (int i = 2; i < n; i++) {
        proximo = primeiro + segundo;
        printf("%d ", proximo);

        primeiro = segundo;
        segundo = proximo;
    }

    return 0;
}
