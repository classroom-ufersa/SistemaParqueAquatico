#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

typedef struct piscina Piscina;

typedef struct lista_piscinas ListaPiscinas;

ListaPiscinas* cria_lista_piscinas();

int lista_vazia_piscinas(ListaPiscinas* lista);

ListaPiscinas* insere_elemento_piscinas(ListaPiscinas* lista, Piscina* piscina);

ListaPiscinas* listar_piscinas();

void imprime_lista_piscinas(ListaPiscinas* lista);

int total_piscinas(ListaPiscinas* lista);

int verifica_id_piscinas(ListaPiscinas* lista, int id);

void adicionar_piscina(ListaPiscinas** lista);

void remover_piscina(ListaPiscinas** lista);

void quantidade_banhistas(ListaPiscinas* lista);

void adicionar_banhistas(ListaPiscinas* lista);

void remover_banhistas(ListaPiscinas* lista);

void atualiza_arquivo_piscinas(ListaPiscinas* lista);

#endif // PISCINA_H