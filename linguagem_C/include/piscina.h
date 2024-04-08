#ifndef PISCINA_H
#define PISCINA_H

#include "cliente.h"

/* Definição do tipo estruturado Piscina */
typedef struct piscina Piscina;


/* Definição do tipo estruturado ListaPiscina */
typedef struct lista_piscinas ListaPiscinas;


/**
 * Cria uma nova lista encadeada de piscinas e a inicializa como vazia.
 *
 * Esta função cria uma nova lista encadeada de piscinas e a inicializa como vazia, ou seja, atribui NULL ao ponteiro para o início da lista.
 * Retorna o ponteiro para o início da lista encadeada de piscinas.
 *
 * @return Ponteiro para o início da lista encadeada de piscinas (NULL, indicando uma lista vazia).
 */
ListaPiscinas* cria_lista_piscinas();


/**
 * Verifica se a lista encadeada de piscinas está vazia.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas e verifica se a lista está vazia.
 * Retorna 1 se a lista estiver vazia (ponteiro para o início da lista é NULL), caso contrário, retorna 0.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 * @return 1 se a lista estiver vazia, 0 caso contrário.
 */
int lista_vazia_piscinas(ListaPiscinas* lista);


/**
 * Insere um novo elemento (piscina) no início da lista encadeada de piscinas.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas e um ponteiro para a estrutura de dados da piscina a ser inserida.
 * Aloca memória para um novo elemento da lista, verifica se a alocação foi bem-sucedida.
 * Em seguida, atribui o ponteiro para a piscina ao novo elemento e o ponteiro para o início da lista ao campo próximo elemento do novo elemento.
 * Retorna o ponteiro para o novo elemento inserido no início da lista encadeada de piscinas.
 * Se ocorrer um erro ao alocar memória, exibe uma mensagem de erro e encerra o programa.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 * @param piscina Ponteiro para a estrutura de dados da piscina a ser inserida.
 * @return Ponteiro para o novo elemento inserido no início da lista encadeada de piscinas.
 */
ListaPiscinas* insere_elemento_piscinas(ListaPiscinas* lista, Piscina* piscina);


/**
 * Lista as piscinas carregadas a partir de um arquivo e as armazena em uma lista encadeada de piscinas.
 *
 * Esta função cria uma nova lista encadeada de piscinas e a inicializa como vazia.
 * Em seguida, abre o arquivo "piscinas.txt" em modo de leitura e percorre o arquivo.
 * Para cada linha do arquivo, lê os dados da piscina, aloca memória para uma nova estrutura de dados da piscina, e insere a piscina na lista encadeada.
 * Após ler todos os dados do arquivo e inserir as piscinas na lista, fecha o arquivo.
 * Se ocorrer algum erro ao abrir o arquivo, exibe uma mensagem de erro e encerra o programa.
 * Retorna o ponteiro para o início da lista encadeada de piscinas contendo as piscinas carregadas.
 * Se nenhuma piscina for carregada do arquivo, exibe uma mensagem informando que nenhuma piscina foi cadastrada.
 *
 * @return Ponteiro para o início da lista encadeada de piscinas contendo as piscinas carregadas.
 */
ListaPiscinas* listar_piscinas();


/**
 * Imprime os dados das piscinas armazenadas em uma lista encadeada de piscinas.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas e percorre a lista.
 * Para cada elemento da lista, imprime os dados da piscina, incluindo ID, capacidade máxima, profundidade e quantidade de clientes.
 * A função continua a percorrer a lista até que o último elemento seja alcançado (quando o ponteiro para o próximo elemento for NULL).
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 */
void imprime_lista_piscinas(ListaPiscinas* lista);


/**
 * Calcula o total de piscinas armazenadas em uma lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas e calcula o total de piscinas na lista.
 * Inicializa uma variável de contagem do total de piscinas como zero e percorre a lista, incrementando a contagem para cada piscina encontrada.
 * A função continua a percorrer a lista até que o último elemento seja alcançado (quando o ponteiro para o próximo elemento for NULL).
 * Retorna o total de piscinas na lista encadeada.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 * @return O total de piscinas na lista encadeada.
 */
int total_piscinas(ListaPiscinas* lista);


/**
 * Verifica se um determinado ID de piscina existe na lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas e um ID a ser verificado.
 * Inicializa um ponteiro para percorrer a lista de piscinas e compara o ID de cada piscina com o ID fornecido.
 * Se o ID fornecido for encontrado em alguma piscina da lista, a função retorna 1 (verdadeiro), indicando que o ID existe.
 * Se o ID não for encontrado em nenhuma piscina da lista, a função retorna 0 (falso), indicando que o ID não existe.
 * A função continua a percorrer a lista até que o último elemento seja alcançado (quando o ponteiro para o próximo elemento for NULL).
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 * @param id ID a ser verificado na lista de piscinas.
 * @return 1 se o ID existe na lista de piscinas, 0 caso contrário.
 */
int verifica_id_piscinas(ListaPiscinas* lista, int id);


/**
 * Adiciona uma nova piscina à lista encadeada de piscinas.
 *
 * Esta função recebe um ponteiro para o ponteiro do início da lista encadeada de piscinas.
 * Inicializa uma nova estrutura de piscina alocando memória dinamicamente.
 * Verifica o próximo ID disponível para a nova piscina, garantindo que seja único na lista.
 * Solicita ao usuário informações sobre a nova piscina, como capacidade máxima e profundidade.
 * Insere a nova piscina na lista encadeada de piscinas.
 *
 * @param lista Ponteiro para o ponteiro do início da lista encadeada de piscinas.
 */
void adicionar_piscina(ListaPiscinas** lista);


/**
 * Remove uma piscina da lista encadeada de piscinas com base no ID fornecido.
 *
 * Esta função recebe um ponteiro para o ponteiro do início da lista encadeada de piscinas.
 * Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina a ser removida.
 * Solicita ao usuário o ID da piscina que deseja remover.
 * Percorre a lista encadeada até encontrar a piscina com o ID fornecido e a remove da lista.
 * Libera a memória alocada para a estrutura da piscina removida.
 *
 * @param lista Ponteiro para o ponteiro do início da lista encadeada de piscinas.
 */
void remover_piscina(ListaPiscinas** lista);


/**
 * Imprime a quantidade de banhistas em cada piscina da lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas.
 * Percorre a lista encadeada e imprime o ID de cada piscina juntamente com o número de clientes (banhistas) presentes.
 * Para cada piscina na lista, imprime o ID da piscina e a quantidade de clientes atualmente na piscina.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 */
void quantidade_banhistas(ListaPiscinas* lista);


/**
 * Adiciona banhistas a uma piscina específica da lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas.
 * Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina desejada.
 * Solicita ao usuário o ID da piscina à qual deseja adicionar banhistas.
 * Percorre a lista encadeada até encontrar a piscina com o ID fornecido.
 * Se a piscina for encontrada, solicita ao usuário a quantidade de banhistas a serem adicionados.
 * Adiciona a quantidade de banhistas informada à piscina selecionada.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 */
void adicionar_banhistas(ListaPiscinas* lista);


/**
 * Remove banhistas de uma piscina específica da lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas.
 * Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina desejada.
 * Solicita ao usuário o ID da piscina à qual deseja remover banhistas.
 * Percorre a lista encadeada até encontrar a piscina com o ID fornecido.
 * Se a piscina for encontrada, solicita ao usuário a quantidade de banhistas a serem removidos.
 * Verifica se a quantidade de banhistas a ser removida é válida.
 * Se a quantidade for válida, remove a quantidade de banhistas informada da piscina selecionada.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 */
void remover_banhistas(ListaPiscinas* lista);


/**
 * Atualiza o arquivo de piscinas com os dados da lista encadeada.
 *
 * Esta função recebe um ponteiro para o início da lista encadeada de piscinas.
 * Abre o arquivo "piscinas.txt" no modo de escrita.
 * Se ocorrer um erro ao abrir o arquivo, exibe uma mensagem de erro e encerra o programa.
 * Percorre a lista encadeada e escreve os dados de cada piscina no arquivo no formato especificado.
 * Fecha o arquivo após concluir a escrita.
 *
 * @param lista Ponteiro para o início da lista encadeada de piscinas.
 */
void atualiza_arquivo_piscinas(ListaPiscinas* lista);

#endif // PISCINA_H