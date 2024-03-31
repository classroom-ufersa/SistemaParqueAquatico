// #include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
    char nome[50];
    int idade;
    char documento[11];
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
    
    char documento[11];

    printf("Informe o documento do cliente que deseja remover: ");
    scanf("%s", documento);

    FILE* arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    FILE* arquivo_temp = fopen("clientes_temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    char linha[255];
    while (fgets(linha, 255, arquivo) != NULL) {
        char documento_cliente[11];
        sscanf(linha, "%*s\t%*d\t%s", documento_cliente);
        if (strcmp(documento_cliente, documento) != 0) {
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
    
    remover_cliente(&cliente_user);

    listar_clientes();

    return 0;
}
