        Sistema de Codificação e Decodificação de Mensagens:

Esse programa foi feito pra codificar e decodificar mensagens usando um
método criado por mim. A ideia é simples: cada caractere da mensagem vira um
número, calculado da seguinte forma:


    código = (valor ASCII do caractere × 128) + fator

O "fator" é um número que definimos numa tabela: cada letra tem o seu (ex.:
A/a = 3, B/b = 5, C/c = 7...), números (0-9) valem 107, espaço vale 109 e
caracteres especiais (!, ., ?, etc.) valem 113. Pra decodificar, é só fazer
o caminho contrário: dividir o código por 128 pra achar o caractere, e usar
o resto da divisão pra conferir se o fator está correto.

    Como usar:

O programa mostra um menu com 3 opções: codificar mensagem, decodificar
mensagem e sair. É só digitar o número da opção desejada e seguir as
instruções na tela.

    Limitações:

Como a tabela só cobre o alfabeto sem acentuação (A-Z), números,
espaço e os caracteres especiais mais comuns, o sistema NÃO RECONHECE:

- Letras acentuadas (á, é, í, ó, ú, â, ê, ã, õ...);
- O "Ç"/"ç";
- Emojis e símbolos de outros idiomas.

Se a mensagem tiver algum desses caracteres, o programa avisa que ele não é
suportado e não consegue codificar. Por isso, é importante digitar as
mensagens sem acento pra tudo funcionar corretamente.
