#include <stdio.h>

int main() {
    char texto[100];
    int alfabeto[26] = {0};
    int ordem[26];

    fgets(texto, 100, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        char caractere = texto[i];

        if (caractere >= 'A' && caractere <= 'Z') { // Maiusculas para minusculas
            caractere = caractere + 32;
        }

        if (caractere >= 'a' && caractere <= 'z') { // Converte para valor no vetor alfabeto
            alfabeto[caractere - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) { 
        ordem[i] = i;
    }

    for (int i = 0; i < 25; i++) { //Bubble sort para ordenar o vetor
        for (int j = 0; j < 25 - i; j++) {
            if (alfabeto[ordem[j]] < alfabeto[ordem[j + 1]]) {
                int temp = ordem[j];
                ordem[j] = ordem[j + 1];
                ordem[j + 1] = temp; // temp = Variavel temporária
            }   
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alfabeto[ordem[i]] > 0) {
            printf("%c: %d\n", ordem[i] + 'a', alfabeto[ordem[i]]);
        }
    }

    return 0;
}