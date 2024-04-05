#include "cliente.c"
#include "piscina.c"

int main() {
    ListaPiscinas* piscinas = cria_lista_piscinas();
    ListaClientes* clientes = cria_lista_clientes();

    /* --- MENU --- */
    // 1- Adiciona piscina;
    // adicionar_piscina(piscinas);

    // 2- Remover piscina;
    // remover_piscina(piscinas);

    // 3- Adiciona cliente;
    // adicionar_cliente(clientes);

    // 4- Remover cliente;
    // remover_cliente(clientes);

    // 5- Editar informação do cliente
    // editar_cliente(clientes);

    // 6- Buscar Cliente por documento
    // buscar_cliente(clientes);

    // 7- Listar piscinas e o número de clientes presentes
    adiciona_cliente_a_piscina(piscinas, clientes); //essa função chama a de buscar_piscina e buscar_cliente
    listar_piscinas(piscinas);
    
    atualiza_arquivo_piscinas(piscinas);
    atualiza_arquivo_clientes(clientes);

    return 0;
}