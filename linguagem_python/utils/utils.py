import streamlit as st
from cliente import Cliente, listar_clientes, remover_cliente, editar_cliente

def main():
    """ Função principal que exibe o menu de opções para o usuário
    """
    
    st.sidebar.title("Menu")
    menu_options = ["Adicionar piscina", "Remover piscina", "Adicionar cliente", "Listar clientes", "Remover cliente", 
                    "Editar informações do cliente", "Buscar cliente por nome", 
                    "Listar piscinas e o número de clientes presentes", "Sair"]
    choice = st.sidebar.selectbox("Escolha uma opção", menu_options)
    
    if choice == "Adicionar piscina":
        st.write("Adicionar piscina")
    elif choice == "Remover piscina":
        pass
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
        pass
    elif choice == "Listar piscinas e o número de clientes presentes":
        pass
        