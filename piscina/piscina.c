// #include "piscina.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct piscina {
    int id;
    int capacidade_max;
    float profundidade;
    int clientes;
} Piscina;

int usuarios_max(float comprimento, float largura, float profundidade) {
    return (comprimento * largura * profundidade) / 4; 
}

void adicona_piscina(Piscina* piscina) {
    float comprimento, largura, profundiade;

    printf("Informe o ID da piscina: ");
    scanf("%d", &piscina->id);
    printf("Informe o comprimento da piscina: ");
    scanf("%f", &comprimento);
    printf("Informe a largura da piscina: ");
    scanf("%f", &largura);
    printf("Informe a profundiade da piscina: ");
    scanf("%f", &profundiade);

    piscina->capacidade_max = usuarios_max(comprimento, largura, profundiade);

    FILE* arquivo = fopen("piscinas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }
    
    fprintf(arquivo, "%d\t", piscina->id);
    fprintf(arquivo, "%.2f\t\t", comprimento);
    fprintf(arquivo, "%.2f\t\t", largura);
    fprintf(arquivo, "%.2f\t\t", profundiade);
    fprintf(arquivo, "%d\n", piscina->capacidade_max);

    fclose(arquivo);

    printf("Piscina cadastrada com sucesso!\n");
}

void listar_piscinas() {
    FILE* arquivo = fopen("piscinas.txt", "r");
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

void remover_piscina(Piscina* piscina) {
    printf("----------------------------------------------------------------------\n");
    listar_piscinas();
    printf("----------------------------------------------------------------------\n");

    int id_aux;
    printf("Informe o ID da piscina que deseja remover: ");
    scanf("%d", &id_aux);

    FILE* arquivo = fopen("piscinas.txt", "r");
    FILE* arquivo_temp = fopen("piscinas_temp.txt", "w");
    if (arquivo == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo! Encerrando o programa...\n");
        exit(1);
    }

    char linha[255];
    while (fgets(linha, 255, arquivo) != NULL) {
        int id;
        sscanf(linha, "%d", &id);
        if (id != id_aux) {
            fprintf(arquivo_temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivo_temp);

    remove("piscinas.txt");
    rename("piscinas_temp.txt", "piscinas.txt");

    printf("Piscina removida com sucesso!\n");
}

int main() {
    Piscina piscina_user;
    
    adicona_piscina(&piscina_user);
    // a função listar_piscinas já está sendo chamada dentro da função remover_piscina
    // listar_piscinas(); 
    remover_piscina(&piscina_user);

    return 0;
}