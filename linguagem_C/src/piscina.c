#include "../include/piscina.h"

struct piscina {
    int id;
    int capacidade_max;
    float profundidade;
    int clientes;
};

struct lista_piscinas {
    Piscina* piscina;
    struct lista_piscinas* prox_elemento;
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

    FILE* arquivo = fopen("../resources/piscinas.txt", "r");
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

    if (lista_vazia_piscinas(lista) == 1) {
        printf("Nenhuma piscina cadastrada!\n");
    } else {
        printf("Piscinas carregadas com sucesso!\n");
    }

    return lista;
}

void imprime_lista_piscinas(ListaPiscinas* lista) {
    ListaPiscinas* elemento_atual = lista;

    while (elemento_atual != NULL) {
        printf("PISCINA %03d\n", elemento_atual->piscina->id);
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

int verifica_id_piscinas(ListaPiscinas* lista, int id) {
    ListaPiscinas* atual = lista;
    while (atual != NULL) {
        if (atual->piscina->id == id) {
            return 1;
        }
        atual = atual->prox_elemento;
    }
    return 0;
}

void adicionar_piscina(ListaPiscinas** lista) {
    Piscina* piscina = malloc(sizeof(Piscina));
    if (piscina == NULL) {
        printf("Erro ao alocar memória! Encerrando o programa...\n");
        exit(1);
    }

    piscina->id = total_piscinas(*lista) + 1;
    while (verifica_id_piscinas(*lista, piscina->id)) {
        piscina->id++;
    }

    printf("PISCINA %03d\n", piscina->id);
    printf("Informe a capacidade maxima: ");
    scanf("%d", &piscina->capacidade_max);
    printf("Informe a profundidade: ");
    scanf("%f", &piscina->profundidade);

    piscina->clientes = 0;

    *lista = insere_elemento_piscinas(*lista, piscina);

    printf("Piscina cadastrada com sucesso!\n");
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

void quantidade_banhistas(ListaPiscinas* lista) {
    ListaPiscinas* atual = lista;
    while (atual != NULL) {
        printf("PISCINA %03d\n", atual->piscina->id);
        printf("Clientes: %d\n\n", atual->piscina->clientes);

        atual = atual->prox_elemento;
    }
}

void adicionar_banhistas(ListaPiscinas* lista) {
    imprime_lista_piscinas(lista);

    int id;
    printf("Informe o ID da piscina que deseja adicionar banhistas: ");
    scanf("%d", &id);

    ListaPiscinas* atual = lista;
    while (atual != NULL && atual->piscina->id != id) {
        atual = atual->prox_elemento;
    }

    if (atual == NULL) {
        printf("Piscina nao encontrada!\n");
        return;
    }

    int quantidade;
    printf("Informe a quantidade de banhistas: ");
    scanf("%d", &quantidade);

    atual->piscina->clientes += quantidade;

    printf("Banhistas adicionados com sucesso!\n");
}

void remover_banhistas(ListaPiscinas* lista) {
    imprime_lista_piscinas(lista);

    int id;
    printf("Informe o ID da piscina que deseja remover banhistas: ");
    scanf("%d", &id);

    ListaPiscinas* atual = lista;
    while (atual != NULL && atual->piscina->id != id) {
        atual = atual->prox_elemento;
    }

    if (atual == NULL) {
        printf("Piscina nao encontrada!\n");
        return;
    }

    int quantidade;
    printf("Informe a quantidade de banhistas: ");
    scanf("%d", &quantidade);

    if (atual->piscina->clientes < quantidade) {
        printf("Nao e possivel remover essa quantidade de banhistas!\n");
        return;
    }

    atual->piscina->clientes -= quantidade;

    printf("Banhistas removidos com sucesso!\n");
}

void atualiza_arquivo_piscinas(ListaPiscinas* lista) {
    FILE* arquivo = fopen("../resources/piscinas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    ListaPiscinas* atual = lista;
    while (atual != NULL) {
        fprintf(arquivo, "%03d\t%d\t%.2f\t%d\n", atual->piscina->id, atual->piscina->capacidade_max, atual->piscina->profundidade, atual->piscina->clientes);

        atual = atual->prox_elemento;
    }

    fclose(arquivo);
}