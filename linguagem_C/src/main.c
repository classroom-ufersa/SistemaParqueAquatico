#include "sistema.c"
#include "piscina.c"
#include "cliente.c"

int main() {
    char opcao;

    printf("Inicializando o Sistema de Piscinas...\n\n");
    ListaPiscinas* lista_piscinas = listar_piscinas();
    sleep(2);
    system("cls");

    printf("Inicializando o Sistema de Clientes...\n\n");
    ListaClientes* lista_clientes = listar_clientes();
    sleep(2);
    system("cls");

    while (1) {
        printf("1|\t Adicionar Piscina\n");
        printf("2|\t Remover Piscina\n");
        printf("3|\t Adicionar Cliente\n");
        printf("4|\t Remover Cliente\n");
        printf("5|\t Editar Informacoes de Cliente\n");
        printf("6|\t Buscar Cliente por Nome\n");
        printf("7|\t Adiciona Clientes na Piscina\n");
        printf("8|\t Remove Clientes da Piscina\n");
        printf("9|\t Sair\n\n");

        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);
        getchar();

        if (opcao == '1') {
            system("cls");
            adicionar_piscina(&lista_piscinas);
            pressiona_enter();
            system("cls");
        } else if (opcao == '2') {
            system("cls");
            remover_piscina(&lista_piscinas);
            pressiona_enter();
            system("cls");
        } else if (opcao == '3') {
            system("cls");
            cadastrar_cliente(&lista_clientes);
            pressiona_enter();
            system("cls");
        } else if (opcao == '4') {
            system("cls");
            remover_cliente(&lista_clientes);
            pressiona_enter();
            system("cls");
        } else if (opcao == '5') {
            system("cls");
            editar_cliente(&lista_clientes);
            pressiona_enter();
            system("cls");
        } else if (opcao == '6') {
            system("cls");
            buscar_cliente(lista_clientes);
            pressiona_enter();
            system("cls");
        } else if (opcao == '7') {
            adicionar_banhistas(lista_piscinas);
            pressiona_enter();
            system("cls");
            imprime_lista_piscinas(lista_piscinas);
            pressiona_enter();
            system("cls");
        } else if  (opcao == '8') {
            remover_banhistas(lista_piscinas);
            pressiona_enter();
            system("cls");
            imprime_lista_piscinas(lista_piscinas);
            pressiona_enter();
            system("cls");
        } else if (opcao == '9') {
            atualiza_arquivo_clientes(lista_clientes);
            atualiza_arquivo_piscinas(lista_piscinas);
            break;
        } else {
            printf("Opcao Invalida!\n");
            sleep(2);
            system("cls");
        }
    }
    
    return 0;
}