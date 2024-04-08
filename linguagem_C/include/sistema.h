#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * Aguarda o usuário pressionar a tecla ENTER para continuar a execução do programa.
 *
 * Esta função exibe uma mensagem para o usuário pressionar a tecla ENTER para continuar.
 * Em seguida, consome qualquer caractere no buffer de entrada até encontrar um caractere de nova linha '\n',
 * indicando que o usuário pressionou a tecla ENTER, e então consome o próprio caractere de nova linha.
 */
void pressiona_enter();


/**
 * Limpa o buffer de entrada até encontrar um caractere de nova linha ou o final do arquivo.
 *
 * Esta função lê caracteres do buffer de entrada até encontrar um caractere de nova linha '\n' ou o final do arquivo (EOF).
 * Ela descarta esses caracteres, removendo-os do buffer de entrada.
 * Isso é útil para limpar o buffer após a leitura de entrada, evitando que caracteres indesejados afetem as próximas operações de entrada.
 */
void LimpaBuffer();

#endif // SISTEMA_H