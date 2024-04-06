#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

/* Definição do tipo estururado Piscina */
typedef struct piscina Piscina;

/* Definição do tipo estruturado ListaPiscinas*/
typedef struct lista_piscinas ListaPiscinas;

/* Definição do tipo estruturado ListaTodosClientes */
typedef struct lista_todos_clientes ListaTodosClientes;

/* Função que cria uma lista encadeada de piscinas */
ListaPiscinas* cria_lista_piscinas(); 

/* Função que verifica se a lista de piscinas está vazia */
int lista_vazia_piscinas(ListaPiscinas* lista);

/* Função que insere um elemento do tipo Piscina na lista de piscinas */
ListaPiscinas* insere_elemento_piscinas(ListaPiscinas* lista, Piscina* piscina);

/* Função que lê o arquivo piscinas.txt e retorna uma lista encadeada de piscinas */
ListaPiscinas* listar_piscinas();

/* Função que imprime as piscinas cadastradas */
void imprime_lista_piscinas(ListaPiscinas* lista);

/* Função que calcula o total de piscinas cadastradas */
int total_piscinas(ListaPiscinas* lista);

/* Função que adicona piscinas a lista encadeada */
void adicionar_piscina(ListaPiscinas** lista);

/* Função que remove uma piscina da lista encadeada */
void remover_piscina(ListaPiscinas** lista);

/* Função que busca uma piscina a partir do ID */
Piscina* buscar_piscina(ListaPiscinas* lista);

/* Função que adicona um cliente a uma piscina */
void adiciona_cliente_a_piscina(ListaPiscinas* lista_piscinas, ListaClientes* lista_clientes);

/* Função que atualiza o arquivo piscinas.txt ao final da execução do programa */
void atualiza_arquivo_piscinas(ListaPiscinas* lista);