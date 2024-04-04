#include "../include/piscina.h"
// #include <stdio.h>
// #include <stdlib.h>

typedef struct piscina {
    int id;
    int capacidade_max;
    float profundidade;
    int clientes;
} Piscina;

typedef struct lista_piscinas {
    Piscina* piscina;
    struct lista_piscinas* prox_elemento;
} ListaPiscinas;

ListaPiscinas* cria_lista_piscinas() {
    return NULL;
}

int lista_vazia(ListaPiscinas* lista) {
    return lista == NULL;
}

ListaPiscinas* insere_elemento_piscinas(ListaPiscinas* lista, Piscina* piscina) {
    ListaPiscinas* novo_elemento = malloc(sizeof(ListaPiscinas));
    if (novo_elemento == NULL) {
        printf("Erro ao alocar memoria! Encerrando o programa...\n");
        exit(1);
    }

    novo_elemento->piscina = piscina;
    novo_elemento->prox_elemento = lista;

    
    return novo_elemento;
}

ListaPiscinas* listar_piscinas() {
    ListaPiscinas* lista = cria_lista_piscinas();
    
    FILE* arquivo = fopen("piscinas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    int id, capacidade_max, clientes;
    float profundidade;
    while (fscanf(arquivo, "%d\t%d\t%f\t%d\n", &id, &capacidade_max, &profundidade, &clientes) == 4) {
        Piscina* piscina = malloc(sizeof(Piscina));
        if (piscina == NULL) {
            printf("Erro ao alocar memoria! Encerrando o programa...\n");
            exit(1);
        }
        piscina->id = id;
        piscina->capacidade_max = capacidade_max;
        piscina->profundidade = profundidade;
        piscina->clientes = clientes;

        lista = insere_elemento_piscinas(lista, piscina);
    }

    fclose(arquivo);
    
    return lista;
}

void imprime_lista(ListaPiscinas* lista) {
    ListaPiscinas* elemento_atual = lista;
    
    while (elemento_atual != NULL) {
        printf("PISCINA %d\n", elemento_atual->piscina->id);
        printf("Capacidade maxima: %d\n", elemento_atual->piscina->capacidade_max);
        printf("Profundidade: %.2f\n", elemento_atual->piscina->profundidade);
        printf("Clientes: %d\n\n", elemento_atual->piscina->clientes);
        
        elemento_atual = elemento_atual->prox_elemento;
    }
}

int total_piscinas(ListaPiscinas* lista) {
    int total_piscinas = 0;
    ListaPiscinas* elemento_atual = lista;

    while (elemento_atual != NULL) {
        total_piscinas++;
        elemento_atual = elemento_atual->prox_elemento;
    }

    return total_piscinas;    
}

void adiconar_piscina(ListaPiscinas** lista) {
    Piscina* piscina = malloc(sizeof(Piscina));
    if (piscina == NULL) {
        printf("Erro ao alocar memória! Encerrando o programa...\n");
        exit(1);
    }

    piscina->id = total_piscinas(*lista) + 1;
    printf("PISCINA %d\n", piscina->id);
    printf("Informe a capacidade maxima: ");
    scanf("%d", &piscina->capacidade_max);
    printf("Informe a profundidade: ");
    scanf("%f", &piscina->profundidade);

    piscina->clientes = 0;
    
    *lista = insere_elemento_piscinas(*lista, piscina);

    printf("Piscina cadastrada com sucesso!\n\n");
}

void remover_piscina(ListaPiscinas** lista) {
    imprime_lista(*lista);

    int id;
    printf("Informe o ID da piscina que deseja remover: ");
    scanf("%d", &id);

    ListaPiscinas* elemento_atual = *lista;
    ListaPiscinas* elemento_anterior = NULL;

    while (elemento_atual != NULL && elemento_atual->piscina->id != id) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->prox_elemento;
    }

    if (elemento_atual == NULL) {
        printf("Piscina nao encontrada!\n");
        return;
    }

    if (elemento_anterior == NULL) {
        *lista = elemento_atual->prox_elemento;
    } else {
        elemento_anterior->prox_elemento = elemento_atual->prox_elemento;
    }

    free(elemento_atual->piscina);
    free(elemento_atual);

    printf("Piscina removida com sucesso!\n");
}

void atualiza_arquivo(ListaPiscinas* lista) {
    FILE* arquivo = fopen("piscinas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    ListaPiscinas* atual = lista;
    while (atual != NULL) {
        fprintf(arquivo, "%d\t%d\t%.2f\t%d\n", atual->piscina->id, atual->piscina->capacidade_max, atual->piscina->profundidade, atual->piscina->clientes);
        
        atual = atual->prox_elemento;
    }

    fclose(arquivo);
}

// int main() {
//     ListaPiscinas* lista = listar_piscinas();

//     lista_vazia(lista) ? printf("Lista vazia\n") : printf("Lista nao vazia\n");
    
//     // for (int i = 0; i < 5; i++) {
//     //     adiconar_piscina(&lista);
//     // }

//     // lista_vazia(lista) ? printf("Lista vazia\n") : printf("Lista nao vazia\n");
    
//     // remover_piscina(&lista);

//     imprime_lista(lista);

//     // atualiza_arquivo(lista);

//     while (lista != NULL) {
//         ListaPiscinas* prox_elemento = lista->prox_elemento;
//         free(lista);
//         lista = prox_elemento;
//     }

//     return 0;
// }