#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabela.h"
#include "Codificação.h"
#include "Decodificação.h"

int main()
{
    char mensagem[1000];
    int codigos[1000];

    int tamanho = 0;
    int opcao = 0;

    while (opcao != 3)
    {

        printf("\n========================================\n");
        printf("        SISTEMA DE CODIFICACAO\n");
        printf("========================================\n");
        printf("\n");
        printf("1 - Codificar mensagem\n");
        printf("2 - Decodificar mensagem\n");
        printf("3 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado (LEMBRAR DE USAR ISSO APÓS O SCANF)

        if (opcao == 1)
        {
            printf("Digite a mensagem a ser codificada: ");
            fgets(mensagem, sizeof(mensagem), stdin);

            for (int i = 0; mensagem[i] != '\0'; i++)
            {
                if (mensagem[i] == '\n')
                {
                    mensagem[i] = '\0'; // Remove o caractere de nova linha
                }
            }
            tamanho = codificar_mensagem(mensagem, codigos);
        }
        else if (opcao == 2)
{
    char entrada[1000];

    printf("Digite os códigos a serem decodificados (separados por espaço): ");
    fgets(entrada, sizeof(entrada), stdin);

    char *numero = strtok(entrada, " \n");
    tamanho = 0;

    while (numero != NULL)
    {
        int valido = 1;

        for (int i = 0; numero[i] != '\0'; i++)
        {
            if (numero[i] < '0' || numero[i] > '9')
            {
                valido = 0;
            }
        }

        if (valido)
        {
            codigos[tamanho] = atoi(numero);
            tamanho++;
        }
        else
        {
            printf("Código inválido: %s\n", numero);
        }

        numero = strtok(NULL, " \n");
    }

    decodificar_mensagem(codigos, tamanho);
}
        else if (opcao == 3)
        {
            printf("Saindo do programa.\n");
        }
        else
        {
            printf("Opção inválida.\n");
        }
    }
    return 0;
}

/*PESQUISAR COMO FAZER O ARQUIVO .H*/