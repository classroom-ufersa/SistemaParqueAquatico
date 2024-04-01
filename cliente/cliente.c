// #include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
    char nome[50];
    int idade;
    char documento[15];
} Cliente;  

void adicionar_cliente(Cliente* cliente) {
    printf("Informe o nome do cliente: ");
    scanf("%99[^\n]", cliente->nome);
    printf("Informe a idade do cliente: ");
    scanf("%d", &cliente->idade);
    printf("Informe o documento do cliente: ");
    scanf("%s", cliente->documento);

    FILE* arquivo = fopen("clientes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }
    
    fprintf(arquivo, "%s\t", cliente->nome);
    fprintf(arquivo, "%d\t", cliente->idade);
    fprintf(arquivo, "%s\n", cliente->documento);

    fclose(arquivo);

    printf("Cliente cadastrado com sucesso!\n");
}

// int compara_string(const void* a, const void* b) {
//     return strcmp((char*)a, (char*)b);
// }

// void ordenar_clientes() {
//     FILE* arquivo = fopen("clientes.txt", "r");
//     FILE* arquivo_temp = fopen("clientes_temp.txt", "w");
//     if (arquivo == NULL || arquivo_temp == NULL) {
//         printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
//         exit(1);
//     }

//     char* lines[1000];
//     char buffer[255];
//     int numero_linhas = 0;

//     while (fgets(buffer, 255, arquivo) != NULL && numero_linhas < 1000) {
//         lines[numero_linhas] = strdup(buffer);
//         numero_linhas++;
//     }

//     fclose(arquivo);

//     qsort(lines, numero_linhas, sizeof(const char*), compara_string);

//     arquivo = fopen("clientes.txt", "w");
//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
//         exit(1);
//     }

//     for (int index = 0; index < numero_linhas; index++) {
//         fprintf(arquivo, "%s", lines[index]);
//         free(lines[index]);
//     }

//     fclose(arquivo);

//     printf("Clientes ordenados com sucesso!\n");
// }

void listar_clientes() {
    FILE* arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    char linha[255];
    while (fgets(linha, 255, arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void remover_cliente(Cliente* cliente) {
    listar_clientes();
    
    char documento_aux[11];

    printf("Informe o documento do cliente que deseja remover: ");
    scanf("%s", documento_aux);

    FILE* arquivo = fopen("clientes.txt", "r");
    FILE* arquivo_temp = fopen("clientes_temp.txt", "w");
    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    char linha[255];
    while (fgets(linha, 255, arquivo) != NULL) {
        char documento[11];
        sscanf(linha, "%s\t%*d\t%*s", documento);
        if (strcmp(documento, documento_aux) != 0) {
            fprintf(arquivo_temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("clientes.txt");
    rename("clientes_temp.txt", "clientes.txt");

    printf("Cliente removido com sucesso!\n");
}


int main() {
    Cliente cliente_user;
    
    // adicionar_cliente(&cliente_user);
    
    // ao chamar a função remover será listado os clientes cadastrados
    remover_cliente(&cliente_user);
    listar_clientes();

    // ordenar_clientes();

    return 0;
}