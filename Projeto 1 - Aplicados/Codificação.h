#ifndef CODIFICACAO_H
#define CODIFICACAO_H

#include <stdio.h>
#include <stdlib.h>
#include "Tabela.h"

int obterFator(char caractere)
{
    for (int i = 0; i < (int)(sizeof(tabela) / sizeof(tabela[0])); i++)
    {
        if (tabela[i].caractere == caractere)
        {
            return tabela[i].fator;
        }
    }
    return -1; // Caractere não encontrado
}

int codificar_mensagem(char mensagem[], int *codigos)
{
    printf("Mensagem codificada: ");

    int tamanho = 0;

    for (int i = 0; mensagem[i] != '\0'; i++)
    {
        int fator = obterFator(mensagem[i]);

        if (fator == -1)
        {
            printf("\nCaractere não suportado: %c\n", mensagem[i]);
            return 0;
        }
        else
        {
            int ascii = mensagem[i];
            codigos[tamanho] = ascii * 128 + fator;
            printf("%d ", codigos[tamanho]);

            tamanho++;
        }
    }

    printf("\n");
    return tamanho;
}

#endif