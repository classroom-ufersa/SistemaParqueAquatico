#include "../include/piscina.h"
#include "../include/cliente.h"
// #include <stdio.h>
// #include <stdlib.h>

struct piscina { 
    int id;
    int capacidade_max;
    float profundidade;
    int num_clientes;
    ListaClientes* clientes;
};

struct lista_piscinas {
    Piscina* piscina;
    struct lista_piscinas* prox_elemento;
};

struct lista_todos_clientes {
    Cliente* cliente;
    struct lista_todos_clientes* prox_elemento;
};

ListaPiscinas* cria_lista_piscinas() {
    return NULL;
}

int lista_vazia_piscinas(ListaPiscinas* lista) {
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

    int id, capacidade_max, num_clientes;
    float profundidade;
    while (fscanf(arquivo, "%d\t%d\t%f\t%d\n", &id, &capacidade_max, &profundidade, &num_clientes) == 4) {
        Piscina* piscina = malloc(sizeof(Piscina));
        if (piscina == NULL) {
            printf("Erro ao alocar memoria! Encerrando o programa...\n");
            exit(1);
        }
        piscina->id = id;
        piscina->capacidade_max = capacidade_max;
        piscina->profundidade = profundidade;
        piscina->num_clientes = num_clientes;

        lista = insere_elemento_piscinas(lista, piscina);
    }

    fclose(arquivo);
    
    return lista;
}

void imprime_lista_piscinas(ListaPiscinas* lista) {
    ListaPiscinas* elemento_atual = lista;
    
    while (elemento_atual != NULL) {
        printf("PISCINA %d\n", elemento_atual->piscina->id);
        printf("Capacidade maxima: %d\n", elemento_atual->piscina->capacidade_max);
        printf("Profundidade: %.2f\n", elemento_atual->piscina->profundidade);
        printf("Clientes: %d\n\n", elemento_atual->piscina->num_clientes);
        
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

    piscina->num_clientes = 0;
    
    *lista = insere_elemento_piscinas(*lista, piscina);

    printf("Piscina cadastrada com sucesso!\n\n");
}

void remover_piscina(ListaPiscinas** lista) {
    imprime_lista_piscinas(*lista);

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

Piscina* buscar_piscina(ListaPiscinas* lista) {
    int id;
    printf("Informe o ID da piscina que deseja buscar: ");
    scanf("%d", &id);

    ListaPiscinas* elemento_atual = lista;
    while (elemento_atual != NULL) {
        if (elemento_atual->piscina->id == id) {
            break;
        }
        printf("PISCINA %d\n", elemento_atual->piscina->id);
        printf("Capacidade maxima: %d\n", elemento_atual->piscina->capacidade_max);
        printf("Profundidade: %.2f\n", elemento_atual->piscina->profundidade);
        printf("Clientes: %d\n", elemento_atual->piscina->num_clientes);
        elemento_atual = elemento_atual->prox_elemento;
    }

    if (elemento_atual == NULL) {
        printf("Piscina nao encontrada!\n");
        return NULL;
    }

    return elemento_atual->piscina;
}

void adiciona_cliente_a_piscina(ListaPiscinas* lista_piscinas, ListaClientes* lista_clientes) {

    Piscina* piscina = buscar_piscina(lista_piscinas);
    Cliente* cliente = buscar_cliente(lista_clientes);

    ListaTodosClientes* novo_cliente = malloc(sizeof(ListaTodosClientes));
    if (novo_cliente == NULL) {
        printf("Erro ao alocar memória! Encerrando o programa...\n");
        exit(1);
    }
    
    novo_cliente->cliente = cliente;
    novo_cliente->prox_elemento = NULL;

    if (piscina->clientes == NULL) {
        piscina->clientes = novo_cliente;
    } else {
        ListaTodosClientes* atual = piscina->clientes;
        while (atual->prox_elemento != NULL) {
            atual = atual->prox_elemento;
        }
        atual->prox_elemento = novo_cliente;
    }

    piscina->num_clientes++;
}

void atualiza_arquivo_piscinas(ListaPiscinas* lista) {
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