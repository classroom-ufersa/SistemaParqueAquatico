import streamlit as st
from cliente import Cliente, listar_clientes, remover_cliente, editar_cliente, buscar_cliente
from piscina import Piscina, listar_piscinas, remover_piscina, adicionar_banhistas

def main():
    """ Função principal que exibe o menu de opções para o usuário
    """
    
    st.sidebar.title("Menu")
    menu_options = ["Adicionar piscina", "Remover piscina", "Adicionar cliente", "Listar clientes", "Remover cliente", 
                    "Editar informações do cliente", "Buscar cliente por nome", 
                    "Listar piscinas e o número de clientes presentes", "Sair"]
    choice = st.sidebar.selectbox("Escolha uma opção", menu_options)
    
    if choice == "Adicionar piscina":
        piscina = Piscina()
        piscina.adiciona_piscina()
    elif choice == "Remover piscina":
        remover_piscina()
    elif choice == "Adicionar cliente":
        cliente = Cliente()
        cliente.adiciona_cliente()
    elif choice == "Listar clientes":
        listar_clientes()    
    elif choice == "Remover cliente":
        remover_cliente()
    elif choice == "Editar informações do cliente":
        editar_cliente()
    elif choice == "Buscar cliente por nome":
        buscar_cliente()
    elif choice == "Listar piscinas e o número de clientes presentes":
        listar_piscinas()
        