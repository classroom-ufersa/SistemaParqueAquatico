#include "piscina.h"
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
