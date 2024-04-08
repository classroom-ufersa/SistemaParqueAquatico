#ifndef CLIENTE_H
#define CLIENTE_H

#include "sistema.h"

/* Definição do tipo estruturado Cliente */
typedef struct cliente Cliente;


/* Definição do tipo estruturado ListaClientes */
typedef struct lista_clientes ListaClientes;


/**
 * Cria uma nova lista encadeada de clientes vazia.
 *
 * @return Ponteiro para o início da lista de clientes, que está vazia.
 */
ListaClientes* cria_lista_clientes();


/**
 * Verifica se a lista encadeada de clientes está vazia.
 *
 * @param lista Ponteiro para o início da lista de clientes.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_vazia_clientes(ListaClientes* lista);


/**
 * Insere um novo cliente na lista encadeada de clientes, mantendo a lista ordenada alfabeticamente pelo nome do cliente.
 *
 * @param lista Ponteiro para o início da lista de clientes.
 * @param cliente Ponteiro para o cliente a ser inserido na lista.
 * @return Ponteiro para o início da lista atualizada.
 */
ListaClientes* insere_elemento_clientes(ListaClientes* lista, Cliente* cliente);


/**
 * Lista os clientes armazenados em um arquivo e os carrega em uma lista encadeada de clientes.
 *
 * Esta função lê os dados dos clientes de um arquivo de texto e os insere em uma lista encadeada de clientes.
 * O arquivo deve estar formatado com cada linha contendo os dados de um cliente no formato: id nome idade documento.
 *
 * @return Ponteiro para o início da lista encadeada de clientes carregada com os dados do arquivo.
 */
ListaClientes* listar_clientes();


/**
 * Imprime os dados dos clientes armazenados em uma lista encadeada de clientes.
 *
 * Esta função percorre a lista encadeada de clientes e imprime os dados de cada cliente, incluindo o ID, nome, idade e documento.
 * A função imprime os dados formatados para cada cliente, separando-os por linhas e adicionando uma linha em branco entre cada cliente.
 *
 * @param lista Ponteiro para o início da lista encadeada de clientes.
 */
void imprime_lista_clientes(ListaClientes* lista);


/**
 * Calcula o total de clientes armazenados em uma lista encadeada de clientes.
 *
 * Esta função percorre a lista encadeada de clientes e conta quantos clientes estão armazenados nela.
 * Ela incrementa um contador cada vez que um novo cliente é encontrado na lista.
 *
 * @param lista Ponteiro para o início da lista encadeada de clientes.
 * @return O número total de clientes na lista.
 */
int total_clientes(ListaClientes* lista);


/**
 * Solicita ao usuário os dados de um novo cliente e o cadastra na lista encadeada de clientes.
 *
 * Esta função solicita ao usuário os dados de um novo cliente, incluindo nome, idade e documento.
 * Em seguida, ela aloca memória para armazenar os dados do cliente, atribui um ID ao cliente com base no total de clientes na lista, e o cadastra na lista encadeada de clientes.
 *
 * @param lista Ponteiro para o ponteiro do início da lista encadeada de clientes.
 */
void cadastrar_cliente(ListaClientes** lista);


/**
 * Remove um cliente da lista encadeada de clientes com base no documento fornecido pelo usuário.
 *
 * Esta função imprime a lista de clientes atualmente cadastrados e solicita ao usuário o documento do cliente que deseja remover.
 * Em seguida, percorre a lista encadeada de clientes para encontrar o cliente com o documento fornecido e o remove da lista.
 * Se o cliente for encontrado e removido com sucesso, exibe uma mensagem de confirmação.
 * Se o cliente não for encontrado na lista, exibe uma mensagem informando que o cliente não foi encontrado.
 *
 * @param lista Ponteiro para o ponteiro do início da lista encadeada de clientes.
 */
void remover_cliente(ListaClientes** lista);


/**
 * Busca um cliente na lista encadeada de clientes com base no nome fornecido pelo usuário.
 *
 * Esta função solicita ao usuário o nome do cliente que deseja buscar e percorre a lista encadeada de clientes para encontrar todos os clientes com o nome fornecido.
 * Para cada cliente encontrado com o nome fornecido, a função imprime os detalhes do cliente, incluindo ID, nome, idade e documento.
 * Se nenhum cliente for encontrado com o nome fornecido, a função não imprime nada.
 *
 * @param lista Ponteiro para o início da lista encadeada de clientes.
 */
void buscar_cliente(ListaClientes* lista);


/**
 * Edita os dados de um cliente na lista encadeada de clientes com base no ID fornecido pelo usuário.
 *
 * Esta função imprime a lista de clientes atualmente cadastrados e solicita ao usuário o ID do cliente que deseja editar.
 * Em seguida, percorre a lista encadeada de clientes para encontrar o cliente com o ID fornecido e permite que o usuário edite seus dados, incluindo nome, idade e documento.
 * Após a edição dos dados, o cliente é removido da lista, atualizado com os novos dados e reinserido na lista.
 * Se o cliente for encontrado e editado com sucesso, a função retorna. Caso contrário, exibe uma mensagem informando que o cliente não foi encontrado na lista.
 *
 * @param lista Ponteiro para o ponteiro do início da lista encadeada de clientes.
 */
void editar_cliente(ListaClientes** lista);


/**
 * Atualiza o arquivo de clientes com base nos dados armazenados na lista encadeada de clientes.
 *
 * Esta função abre o arquivo "clientes.txt" em modo de escrita e percorre a lista encadeada de clientes.
 * Para cada cliente na lista, escreve os seus dados no arquivo no formato "ID NOME IDADE DOCUMENTO".
 * Após escrever todos os clientes no arquivo, fecha o arquivo.
 * Se ocorrer algum erro ao abrir o arquivo, exibe uma mensagem de erro e encerra o programa.
 *
 * @param lista Ponteiro para o início da lista encadeada de clientes.
 */
void atualiza_arquivo_clientes(ListaClientes* lista);

#endif // CLIENTE_H