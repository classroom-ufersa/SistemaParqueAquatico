// #include "../include/cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente{
    int id;
    int idade;
    char nome[50];
    char documento[15];
} Cliente;

typedef struct lista_clientes {
    Cliente* cliente;
    struct lista_clientes* prox_elemento;
} ListaClientes;

ListaClientes* cria_lista_clientes() {
    return NULL;
}

int lista_vazia(ListaClientes* lista) {
    return lista == NULL;
}

ListaClientes* insere_elemento_clientes(ListaClientes* lista, Cliente* cliente) {
    ListaClientes* novo_elemento = malloc(sizeof(ListaClientes));
    if (novo_elemento == NULL) {
        printf("Erro ao alocar memoria! Encerrando o programa...\n");
        exit(1);
    }

    novo_elemento->cliente = cliente;
    novo_elemento->prox_elemento = lista;
    
    return novo_elemento;
}

ListaClientes* listar_clientes() {
    ListaClientes* lista = cria_lista_clientes();

    FILE* arquivo = fopen("clientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    int id, idade;
    char nome[50], documento[11];
    while (fscanf(arquivo, "%d %s %d %s", &id, nome, &idade, documento) == 4) {
        Cliente* cliente = malloc(sizeof(Cliente));
        cliente->id = id;
        strcpy(cliente->nome, nome);
        cliente->idade = idade;
        strcpy(cliente->documento, documento);
        

        lista = insere_elemento_clientes(lista, cliente);
    }

    fclose(arquivo);

    return lista;
}

void imprime_lista(ListaClientes* lista) {
    ListaClientes* elemento_atual = lista;
    
    while (elemento_atual != NULL) {
        printf("CLIENTE %d\n", elemento_atual->cliente->id);
        printf("Nome: %s\n", elemento_atual->cliente->nome);
        printf("Idade: %d\n", elemento_atual->cliente->idade);
        printf("Documento: %s\n\n", elemento_atual->cliente->documento);
        
        elemento_atual = elemento_atual->prox_elemento;
    }
}

int total_clientes(ListaClientes* lista) {
    int total_clientes = 0;
    ListaClientes* elemento_atual = lista;

    while (elemento_atual != NULL) {
        total_clientes++;
        elemento_atual = elemento_atual->prox_elemento;
    }

    return total_clientes;
}

void adicionar_cliente(ListaClientes** lista) {
    Cliente* cliente = malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memoria! Encerrando o programa...\n");
        exit(1);
    }
    
    cliente->id = total_clientes(*lista) + 1;

    printf("CLIENTE %d\n", cliente->id);
    printf("Informe o nome do cliente: ");
    scanf(" %99[^\n]", cliente->nome);
    printf("Informe a idade do cliente: ");
    scanf("%d", &cliente->idade);
    printf("Informe o documento do cliente: ");
    scanf(" %99[^\n]", cliente->documento);

    *lista = insere_elemento_clientes(*lista, cliente);

    printf("Cliente cadastrado com sucesso!\n\n");
}

void remover_cliente(ListaClientes** lista) {
    imprime_lista(*lista);

    char documento[15];
    printf("Informe o documento do cliente que deseja remover: ");
    scanf(" %99[^\n]", documento);

    ListaClientes *ListaAux = *lista;
    ListaClientes *ListaAnt = NULL;

    while (ListaAux != NULL && strcmp(ListaAux->cliente->documento, documento) != 0) {
        ListaAnt = ListaAux;
        ListaAux = ListaAux->prox_elemento;
    }

    if (ListaAux == NULL) {
        printf("Cliente nao encontrado!\n");
        return;
    }

    if(ListaAnt == NULL) {
        *lista = ListaAux->prox_elemento;
    } else {
        ListaAnt->prox_elemento = ListaAux->prox_elemento;
    }

    free(ListaAux);

    printf("Cliente removido com sucesso!\n\n");

    imprime_lista(*lista);
}

void buscar_cliente(ListaClientes* lista) {
    char nome[50];
    printf("Informe o nome do cliente que deseja buscar: ");
    scanf(" %99[^\n]", nome);

    ListaClientes* elemento_atual = lista;
    while (elemento_atual != NULL) {
        if (strcmp(elemento_atual->cliente->nome, nome) == 0) {
            printf("CLIENTE %d\n", elemento_atual->cliente->id);
            printf("Nome: %s\n", elemento_atual->cliente->nome);
            printf("Idade: %d\n", elemento_atual->cliente->idade);
            printf("Documento: %s\n\n", elemento_atual->cliente->documento);
        }
        
        elemento_atual = elemento_atual->prox_elemento;
    }
}

void editar_cliente(ListaClientes* lista) {
    imprime_lista(lista);
    ListaClientes* atual = lista;

    int id;
    printf("Digite o ID do cliente que deseja editar: ");
    scanf("%d", &id);

    while (atual != NULL) {
        if (atual->cliente->id == id) {
            printf("Digite o novo nome do cliente: ");
            scanf(" %49[^\n]", atual->cliente->nome);
            printf("Digite a nova idade do cliente: ");
            scanf("%d", &atual->cliente->idade);
            printf("Digite o novo documento do cliente: ");
            scanf(" %10[^\n]", atual->cliente->documento);
            return;
        }
        atual = atual->prox_elemento;
    }

    printf("Cliente com ID %d não encontrado.\n", id);
}

void atualiza_arquivo(ListaClientes* lista) {
    FILE* arquivo = fopen("clientes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    ListaClientes* atual = lista;
    while (atual != NULL) {
        fprintf(arquivo, "%d %s %d %s\n", atual->cliente->id, atual->cliente->nome, atual->cliente->idade, atual->cliente->documento);
        
        atual = atual->prox_elemento;
    }

    fclose(arquivo);
}

int main() {
    ListaClientes* lista = listar_clientes();

        lista_vazia(lista) ? printf("Lista vazia\n") :

    // for (int i = 0; i < 5; i++) {
    //     adicionar_cliente(&lista);
    // }

    // remover_cliente(&lista);
    // buscar_cliente(lista);
    // editar_cliente(lista);

    imprime_lista(lista);

    while (lista != NULL) {
        ListaClientes* prox_elemento = lista->prox_elemento;
        free(lista);
        lista = prox_elemento;
    }

    return 0;
}