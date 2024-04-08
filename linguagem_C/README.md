## 1. Pré-Requisitos:

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
** Função cadastrar_cliente **
Esta função solicita ao usuário os dados de um novo cliente, incluindo nome, idade e documento. Em seguida, ela aloca memória para armazenar os dados do cliente, atribui um ID ao cliente com base no total de clientes na lista, e o cadastra na lista encadeada de clientes
```c
void cadastrar_cliente(ListaClientes** lista);
```