#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definição do tipo estruturado Cliente */
typedef struct cliente Cliente;

/* Definição do tipo estururado ListaClientes */
typedef struct lista_clientes ListaClientes;

/* Função que cria uma lista estruturada */
ListaClientes* cria_lista_clientes();

/* Função que insere um elemento na lista de clientes */
ListaClientes* insere_elemento_clientes(ListaClientes* lista, Cliente* cliente);

/* Função que lê os clientes cadastrados no banco de dados */
ListaClientes* listar_clientes();

/* Função que imprime a lista de clientes */
void imprime_lista(ListaClientes* lista);

/* Função que calcula o total de clientes cadastrados */
int total_clientes(ListaClientes* lista);

/* Função que adiciona um cliente */
void adicionar_cliente(ListaClientes** lista);

/* Função que remove um cliente */
void remover_cliente(ListaClientes** lista);

/* Função que busca um cliente por nome */
void buscar_cliente(ListaClientes* lista);

/* Função que edita as informações dos clientes cadastrados */
void editar_cliente(ListaClientes* lista);