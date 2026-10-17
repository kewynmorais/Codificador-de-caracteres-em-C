/* =========================================================================
   CIFRA E DECIFRA - Metodo proprio de codificacao (versao em C)
   =========================================================================

   Nome do metodo: Cifra por Fatores Foneticos (CFF)

   Este metodo usa de fato o FONEMA de cada letra da mensagem, e nao
   apenas a posicao dela no texto. A tabela de fonemas do portugues
   fornecida define, para cada som, um simbolo e um "fator" numerico
   (os 26 primeiros numeros primos):

     ------------------------------------------------------------------
      Fonema | Classificacao                    | Simbolo | Fator
     ------------------------------------------------------------------
      /p/    | oclusiva bilabial surda           |   #     |   3
      /b/    | oclusiva bilabial vozeada         |   @     |   5
      /t/    | oclusiva alveolar surda           |   &     |   7
      /d/    | oclusiva alveolar vozeada         |   %     |  11
      /k/    | oclusiva velar surda              |   K     |  13
      /g/    | oclusiva velar vozeada            |   G     |  17
      /f/    | fricativa labiodental surda       |   F     |  19
      /v/    | fricativa labiodental vozeada     |   V     |  23
      /s/    | fricativa alveolar surda          |   $     |  29
      /z/    | fricativa alveolar vozeada        |   Z     |  31
      /x/    | fricativa pos-alveolar surda      |   X     |  37
      /j/    | fricativa pos-alveolar vozeada    |   J     |  41
      /m/    | nasal bilabial                    |   M     |  43
      /n/    | nasal alveolar                    |   N     |  47
      /nh/   | nasal palatal                     |   Y     |  53
      /l/    | lateral alveolar                  |   L     |  59
      /lh/   | lateral palatal                   |   W     |  61
      /r/    | tepe alveolar                     |   R     |  67
      /rr/   | fricativa / "r forte"             |   H     |  71
      /a/    | vogal baixa central               |   A     |   2
      /e/    | vogal media-alta anterior         |   E     |  73
      /e ab/ | vogal media-baixa anterior        |   E`    |  79
      /i/    | vogal alta anterior               |   I     |  83
      /o/    | vogal media-alta posterior        |   O     |  89
      /o ab/ | vogal media-baixa posterior       |   O`    |  97
      /u/    | vogal alta posterior              |   U     | 101
     ------------------------------------------------------------------

   ONDE ENTRA O FONEMA DE VERDADE:

   Cada LETRA do alfabeto foi associada ao fonema que ela realmente
   representa na lingua portuguesa (aproximacao didatica, ja que a
   pronuncia exata de algumas letras muda de acordo com o contexto -
   isso e uma simplificacao consciente, comentada mais abaixo):

       a -> /a/  (fator  2)      j -> /j/  (fator 41)     s -> /s/  (fator 29)
       b -> /b/  (fator  5)      k -> /k/  (fator 13)     t -> /t/  (fator  7)
       c -> /k/  (fator 13)      l -> /l/  (fator 59)     u -> /u/  (fator 101)
       d -> /d/  (fator 11)      m -> /m/  (fator 43)     v -> /v/  (fator 23)
       e -> /e/  (fator 73)      n -> /n/  (fator 47)     w -> /v/  (fator 23)
       f -> /f/  (fator 19)      o -> /o/  (fator 89)     x -> /x/  (fator 37)
       g -> /g/  (fator 17)      p -> /p/  (fator  3)     y -> /i/  (fator 83)
       h -> muda (fator  1)      q -> /k/  (fator 13)     z -> /z/  (fator 31)
       i -> /i/  (fator 83)      r -> /r/  (fator 67)

   Observacoes sobre a simplificacao:
     - 'c', 'k' e 'q' compartilham o fonema /k/ (som de "casa", "kilo",
       "quilo"), pois nesta tabela nao existe um fonema separado para
       o "c" com som de /s/ (como em "cedo").
     - 'h' sozinho nao tem som proprio no portugues (ex.: "hoje"), por
       isso recebe fator 1 (nao altera o codigo ASCII).
     - 'r' foi associado ao tepe /r/ (fator 67) e nao ao "r forte"
       /rr/, que so ocorre em contextos especificos (inicio de palavra
       ou "rr" duplo).
     - 'y' e 'w' nao existem no alfabeto tradicional portugues; foram
       aproximados para os fonemas mais proximos (/i/ e /v/).
     - Letras maiusculas usam o MESMO fonema (e o mesmo fator) da
       versao minuscula.
     - Caracteres SEM fonema correspondente (espacos, numeros, sinais
       de pontuacao) recebem fator 1, ou seja, nao sao alterados pela
       multiplicacao - eles atravessam o processo de forma neutra.
     - Este metodo foi pensado para mensagens SEM acentuacao grafica
       (a, e, i, o, u sem acento). Caracteres acentuados em UTF-8 usam
       bytes acima de 127, que nao fazem parte da tabela de fonemas e
       podem gerar ambiguidade na decodificacao (ver comentario na
       funcao inicializar_tabela_reversa).

   ALGORITMO DE CODIFICACAO:

       Para cada caractere da mensagem:
           1) Descobre-se o FATOR do fonema associado aquela LETRA
              especifica (obter_fator), e nao mais um fator que muda
              conforme a posicao do caractere no texto.
           2) Multiplica-se o codigo ASCII do caractere por esse fator:

                  numero_codificado = codigo_ASCII(caractere) * fator(caractere)

       Como o produto ultrapassa 255, a mensagem codificada e uma
       sequencia de NUMEROS separados por espaco, por exemplo:

              "194 195 348 ..."

   ALGORITMO DE DECODIFICACAO (processo inverso):

       Como o fator agora depende da LETRA (e nao da posicao), nao da
       para simplesmente dividir cada numero por um fator "conhecido de
       antemao" - e preciso descobrir de qual caractere aquele numero
       veio. Para isso, o programa monta, uma unica vez, uma TABELA
       REVERSA: para cada valor ASCII possivel, calcula-se o produto
       (ascii * fator) que ele geraria na codificacao, e guarda-se esse
       par (produto -> ascii) em um vetor.

       Na decodificacao, cada numero da mensagem codificada e usado
       diretamente como indice dessa tabela reversa, recuperando o
       ASCII original (e, portanto, o caractere original) em tempo
       constante - sem precisar adivinhar nada.
   ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 1000          /* tamanho maximo da mensagem original */
#define TAM_SAIDA 10000       /* tamanho maximo da mensagem codificada (numeros) */
#define TAM_TABELA_REVERSA 25856  /* maior produto possivel + folga */

/* ---------------- Fator de cada letra (fonema real associado) ---------------- */
/* indice 0 = 'a', indice 1 = 'b', ..., indice 25 = 'z' */
int fator_por_letra[26] = {
 /* a */  2,
 /* b */  5,
 /* c */ 13,
 /* d */ 11,
 /* e */ 73,
 /* f */ 19,
 /* g */ 17,
 /* h */  1,   /* muda: sem fonema proprio */
 /* i */ 83,
 /* j */ 41,
 /* k */ 13,
 /* l */ 59,
 /* m */ 43,
 /* n */ 47,
 /* o */ 89,
 /* p */  3,
 /* q */ 13,
 /* r */ 67,
 /* s */ 29,
 /* t */  7,
 /* u */101,
 /* v */ 23,
 /* w */ 23,
 /* x */ 37,
 /* y */ 83,
 /* z */ 31
};

int tabela_reversa[TAM_TABELA_REVERSA];

/*
 * Retorna o fator do fonema que corresponde de fato ao caractere.
 * Letras (maiusculas ou minusculas) usam o fonema da tabela.
 * Qualquer outro caractere (espaco, numero, pontuacao) nao possui
 * fonema correspondente e recebe fator 1 (permanece inalterado).
 */
int obter_fator(unsigned char c) {
    if (isalpha(c)) {
        int indice = tolower(c) - 'a';
        return fator_por_letra[indice];
    }
    return 1;
}

/*
 * Monta a tabela reversa (produto -> ascii original), necessaria
 * para a decodificacao. E chamada uma unica vez, no inicio do
 * programa.
 */
void inicializar_tabela_reversa(void) {
    int i;
    long produto;

    for (i = 0; i < TAM_TABELA_REVERSA; i++) {
        tabela_reversa[i] = -1;
    }

    /* A tabela reversa e construida apenas para a faixa ASCII padrao
       (0 a 127): letras, digitos, espacos e pontuacao comuns. Bytes
       acima de 127 (usados na codificacao UTF-8 de letras acentuadas,
       como a, e, c) ficam FORA da tabela de fonemas fornecida e, por
       coincidencia matematica, alguns deles produzem o MESMO produto
       que uma letra valida multiplicada pelo seu fator (por exemplo,
       o byte 194 e o produto de 'a' (97 * 2) coincidem). Por isso,
       este metodo funciona com garantia total para mensagens SEM
       acentuacao grafica. */
    for (i = 0; i < 128; i++) {
        produto = (long) i * obter_fator((unsigned char) i);
        tabela_reversa[produto] = i;
    }
}

/* ------------------------- Funcoes principais ------------------------- */

/*
 * Codifica a mensagem original, gerando uma string "saida" contendo os
 * numeros (codigo_ASCII * fator_do_fonema_da_letra) separados por espaco.
 */
void codificar_mensagem(const char *mensagem, char *saida) {
    int tamanho = (int) strlen(mensagem);
    int i;
    int codigo_ascii;
    int fator;
    long numero_codificado;
    char pedaco[32];

    if (tamanho > TAM_MAX - 1) {
        tamanho = TAM_MAX - 1;
    }

    saida[0] = '\0';

    for (i = 0; i < tamanho; i++) {
        codigo_ascii = (unsigned char) mensagem[i];
        fator = obter_fator((unsigned char) mensagem[i]);
        numero_codificado = (long) codigo_ascii * fator;

        if (i == 0) {
            sprintf(pedaco, "%ld", numero_codificado);
        } else {
            sprintf(pedaco, " %ld", numero_codificado);
        }
        strcat(saida, pedaco);
    }
}

/*
 * Decodifica a mensagem (string de numeros separados por espaco),
 * usando a tabela reversa para recuperar cada caractere original.
 */
void decodificar_mensagem(const char *mensagem_codificada, char *saida) {
    char copia[TAM_SAIDA];
    char *token;
    int i = 0;
    long numero_codificado;
    int codigo_ascii;

    strcpy(copia, mensagem_codificada);
    saida[0] = '\0';

    token = strtok(copia, " ");
    while (token != NULL) {
        numero_codificado = atol(token);

        if (numero_codificado >= 0 && numero_codificado < TAM_TABELA_REVERSA) {
            codigo_ascii = tabela_reversa[numero_codificado];
        } else {
            codigo_ascii = -1;
        }

        if (codigo_ascii == -1) {
            saida[i] = '?'; /* numero nao reconhecido pela tabela */
        } else {
            saida[i] = (char) codigo_ascii;
        }
        i++;

        token = strtok(NULL, " ");
    }
    saida[i] = '\0';
}

/* ------------------------------ Utilitarios ----------------------------- */

void remover_quebra_de_linha(char *texto) {
    int tamanho = (int) strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }
}

void limpar_buffer_entrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta os caracteres restantes */
    }
}

/* ------------------------------ Menu ------------------------------------ */

void exibir_menu(void) {
    printf("\n=================================\n");
    printf("          CIFRA E DECIFRA\n");
    printf("=================================\n");
    printf("1 - Codificar mensagem\n");
    printf("2 - Decodificar mensagem\n");
    printf("3 - Sair\n");
}

int main(void) {
    char mensagem[TAM_SAIDA];
    char resultado[TAM_SAIDA];
    int opcao;
    int continuar = 1;

    inicializar_tabela_reversa();

    while (continuar) {
        exibir_menu();
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("\nOpcao invalida. Tente novamente.\n");
            limpar_buffer_entrada();
            continue;
        }
        limpar_buffer_entrada();

        switch (opcao) {
            case 1:
                printf("\nDigite a mensagem que deseja codificar: ");
                fgets(mensagem, TAM_SAIDA, stdin);
                remover_quebra_de_linha(mensagem);

                codificar_mensagem(mensagem, resultado);

                printf("\nMensagem codificada:\n%s\n", resultado);
                break;

            case 2:
                printf("\nDigite a mensagem codificada (numeros separados por espaco): ");
                fgets(mensagem, TAM_SAIDA, stdin);
                remover_quebra_de_linha(mensagem);

                decodificar_mensagem(mensagem, resultado);

                printf("\nMensagem decodificada:\n%s\n", resultado);
                break;

            case 3:
                printf("\nEncerrando o programa. Ate logo!\n");
                continuar = 0;
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
