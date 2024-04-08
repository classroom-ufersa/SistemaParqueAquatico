#include "../include/sistema.h"

void pressiona_enter() {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

void LimpaBuffer() {
    int valorLido;
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}