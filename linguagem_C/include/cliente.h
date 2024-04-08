#ifndef CLIENTE_H
#define CLIENTE_H

#include "sistema.h"

typedef struct cliente Cliente;

typedef struct lista_clientes ListaClientes;

ListaClientes* cria_lista_clientes();

ListaClientes* insere_elemento_clientes(ListaClientes* lista, Cliente* cliente);

ListaClientes* listar_clientes();

void imprime_lista_clientes(ListaClientes* lista);

int total_clientes(ListaClientes* lista);

void cadastrar_cliente(ListaClientes** lista);

void remover_cliente(ListaClientes** lista);

void buscar_cliente(ListaClientes* lista);

void editar_cliente(ListaClientes** lista);

void atualiza_arquivo_clientes(ListaClientes* lista);

#endif // CLIENTE_H