#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

/* Definição do tipo estruturado Piscina */
typedef struct piscina Piscina;

/* Definição do tipo estruturado ListaPiscina */
typedef struct lista_piscinas ListaPiscinas;

/* Fução que cria uma lista de piscinas*/
ListaPiscinas* cria_lista_piscinas();

/* Função que verifica se a lista está vazia */
int lista_vazia_piscinas(ListaPiscinas* lista);

/* Função que insere um novo elemento na lista de piscinas*/
ListaPiscinas* insere_elemento_piscinas(ListaPiscinas* lista, Piscina* piscina);

/* Função que lê os dados do arquivo */
ListaPiscinas* listar_piscinas();

/* Função que imprime a lista de piscinas */
void imprime_lista_piscinas(ListaPiscinas* lista);

/* Função que calcula o total de piscinas cadastradas */
int total_piscinas(ListaPiscinas* lista);

/* Função que verifica se o ID da piscina cadastrada já existe */
int verifica_id_piscinas(ListaPiscinas* lista, int id);

/* Função que adiciona uma nova piscina a lista encadeada */
void adicionar_piscina(ListaPiscinas** lista);

/* Função que remove uma pisicna da lista encadeada */
void remover_piscina(ListaPiscinas** lista);

/* Função que verifica a quantidade de banhistas na piscina */
void quantidade_banhistas(ListaPiscinas* lista);

/* Função que adiciona banhistas as piscinas */
void adicionar_banhistas(ListaPiscinas* lista);

/* Função que remove banhistas das piscinas */
void remover_banhistas(ListaPiscinas* lista);

/* Função que atualiza o arquivo piscinas.txt ao final da execução do programa */
void atualiza_arquivo_piscinas(ListaPiscinas* lista);

#endif // PISCINA_H