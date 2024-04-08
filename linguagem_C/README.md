## 1. Pré-Requisitos

Para executar o código é necessário um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/).

## 2. Organização do Repositório
A organização desta parte está disposta da seguinte forma:

``` 
📁 - SistemaParqueAquático
│
├──linguagem_C
│
├───include
├───resources
├───src
└───README.md
```

## 3. Listas Encadeadas
Neste projeto, um sistema de gerenciamento de um parque aquático foi implementado utilizando listas encadeadas. Essa estrutura de dados permite percorrer a lista somente em uma direção, do início para o fim, facilitando a manipulação de coleções dinâmicas de dados. Embora ofereça apenas acesso sequencial, as listas encadeadas são eficientes para diversas aplicações de gerenciamento de dados, especialmente quando a ordem dos elementos é relevante e as operações de inserção e remoção são frequentes.

## 4. Funções Cliente
**Função cadastrar_cliente:**
Esta função solicita ao usuário os dados de um novo cliente, incluindo nome, idade e documento. Em seguida, ela aloca memória para armazenar os dados do cliente, atribui um ID ao cliente com base no total de clientes na lista, e o cadastra na lista encadeada de clientes
```c
void cadastrar_cliente(ListaClientes** lista);
```

**Função remover_cliente:**
Esta função imprime a lista de clientes atualmente cadastrados e solicita ao usuário o documento do cliente que deseja remover. Em seguida, percorre a lista encadeada de clientes para encontrar o cliente com o documento fornecido e o remove da lista.
```c
void remover_cliente(ListaClientes** lista);
```

**Função buscar_cliente:**
Esta função solicita ao usuário o nome do cliente que deseja buscar e percorre a lista encadeada de clientes para encontrar todos os clientes com o nome fornecido. Para cada cliente encontrado com o nome fornecido, a função imprime os detalhes do cliente, incluindo ID, nome, idade e documento.
```c
void buscar_cliente(ListaClientes* lista);
```

**Função editar_cliente:**
Esta função imprime a lista de clientes atualmente cadastrados e solicita ao usuário o ID do cliente que deseja editar. Em seguida, percorre a lista encadeada de clientes para encontrar o cliente com o ID fornecido e permite que o usuário edite seus dados, incluindo nome, idade e documento. Após a edição dos dados, o cliente é removido da lista, atualizado com os novos dados e reinserido na lista.
```c
void editar_cliente(ListaClientes** lista);
```

## 5. Funções Piscina
**Função adicionar_piscina:**
Esta função recebe um ponteiro para o ponteiro do início da lista encadeada de piscinas. Inicializa uma nova estrutura de piscina alocando memória dinamicamente. Verifica o próximo ID disponível para a nova piscina, garantindo que seja único na lista. Solicita ao usuário informações sobre a nova piscina, como capacidade máxima e profundidade. E por fim, insere a nova piscina na lista encadeada de piscinas.
```c
void adicionar_piscina(ListaPiscinas** lista);
```

**Função remover_piscina:**
 Esta função recebe um ponteiro para o ponteiro do início da lista encadeada de piscinas. Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina a ser removida. Solicita ao usuário o ID da piscina que deseja remover. Percorre a lista encadeada até encontrar a piscina com o ID fornecido e a remove da lista. E por fim, libera a memória alocada para a estrutura da piscina removida.
 ```c
void remover_piscina(ListaPiscinas** lista);
```

**Função quantidade_banhistas:**
Esta função recebe um ponteiro para o início da lista encadeada de piscinas. Percorre a lista encadeada e imprime o ID de cada piscina juntamente com o número de clientes (banhistas) presentes. Para cada piscina na lista, imprime o ID da piscina e a quantidade de clientes atualmente na piscina.
 ```c
void quantidade_banhistas(ListaPiscinas* lista);
```

**Função adicionar_banhistas:**
Esta função recebe um ponteiro para o início da lista encadeada de piscinas. Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina desejada. Solicita ao usuário o ID da piscina à qual deseja adicionar banhistas. Percorre a lista encadeada até encontrar a piscina com o ID fornecido. Se a piscina for encontrada, solicita ao usuário a quantidade de banhistas a serem adicionados. Adiciona a quantidade de banhistas informada à piscina selecionada.
 ```c
void adicionar_banhistas(ListaPiscinas* lista);
```

**Função remover_banhistas:**
Esta função recebe um ponteiro para o início da lista encadeada de piscinas. Imprime a lista de piscinas disponíveis para que o usuário selecione a piscina desejada. Solicita ao usuário o ID da piscina à qual deseja remover banhistas. Percorre a lista encadeada até encontrar a piscina com o ID fornecido. Se a piscina for encontrada, solicita ao usuário a quantidade de banhistas a serem removidos. Verifica se a quantidade de banhistas a ser removida é válida. Se a quantidade for válida, remove a quantidade de banhistas informada da piscina selecionada.
 ```c
void remover_banhistas(ListaPiscinas* lista);
```

## 6. Execução do Projeto
### 6.1 Compilação do Código
Para compilar o código, abra o terminal e navegue até a pasta `linguagem_c` e execute o seguinte comando:
```
gcc -o main main.c 
```
### 6.2 Execução do Código
Para executar o código, digite o comando:
```
./main
```

## REFERÊNCIAS UTILIZADAS
CELES, W.; CERQUEIRA, R.; RANGEL, J. L. **Introdução a Estruturas de Dados: com técnicas de programação em C.** Rio de Janeiro: Ed. Campus-Elsevier, 2004.