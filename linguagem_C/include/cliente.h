#ifndef CLIENTE_H
#define CLIENTE_H

#include "sistema.h"

/* Definição do tipo estruturado Cliente */
typedef struct cliente Cliente;

/* Definição do tipo estruturado ListaClientes */
typedef struct lista_clientes ListaClientes;

/* Função que cria uma nova lista de clientes */
ListaClientes* cria_lista_clientes();

/* Função que verifica se a lista de clientes está vazia */
int lista_vazia_clientes(ListaClientes* lista);

/* Função que insere um novo elemento na lista de clientes */
ListaClientes* insere_elemento_clientes(ListaClientes* lista, Cliente* cliente);

/* Função que lê os clientes do arquivo */
ListaClientes* listar_clientes();

/* Função que imprime a lista de clientes */
void imprime_lista_clientes(ListaClientes* lista);

/* Função que calcula o total de clientes cadastrados */
int total_clientes(ListaClientes* lista);

/* Função que cadastra um novo cliente a lista clientes*/
void cadastrar_cliente(ListaClientes** lista);

/* Função que remove um cliente da lista encadeada */
void remover_cliente(ListaClientes** lista);

/* Função que busca um cliente por nome */
void buscar_cliente(ListaClientes* lista);

/* Função que edita as informações de um cliente */
void editar_cliente(ListaClientes** lista);

/* Função que atualiza o arquivo clientes.txt ao final da execução do programa */
void atualiza_arquivo_clientes(ListaClientes* lista);

#endif // CLIENTE_H