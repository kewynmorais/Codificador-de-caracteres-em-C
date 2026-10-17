#ifndef DECODIFICACAO_H
#define DECODIFICACAO_H

#include <stdio.h>
#include <stdlib.h>
#include "Tabela.h"
#include "Codificação.h"

void decodificar_mensagem(int codigos[], int tamanho)
{
    printf("Mensagem decodificada: ");

    for (int i = 0; i < tamanho; i++)
    {
        int codigo = codigos[i];
        int ascii = codigo / 128;
        int fator = codigo % 128;

        if (ascii < 0 || ascii > 127)
        {
            printf("\nCódigo inválido: %d", codigo);
        }
        else
        {
            char caractere = (char)ascii;
            int fator_correto = obterFator(caractere);

            if (fator_correto == -1)
            {
                printf("\nCaractere não suportado: %c\n", caractere);
            }
            else if (fator == fator_correto)
            {
                printf("%c", caractere);
            }
            else
            {
                printf("?");
                printf("\nCódigo inválido: %d", codigo);
            }
        }
    }

    printf("\n");
}

#endif
