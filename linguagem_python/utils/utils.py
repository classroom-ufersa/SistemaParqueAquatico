import streamlit as st
import sys
from cliente import Cliente

def main():
    st.sidebar.title("Menu")
    menu_options = ["Adicionar piscina", "Remover piscina", "Adicionar cliente", "Remover cliente", 
                    "Editar informações do cliente", "Buscar cliente por nome", 
                    "Listar piscinas e o número de clientes presentes", "Sair"]
    choice = st.sidebar.selectbox("Escolha uma opção", menu_options)
    if choice == "Adicionar piscina":
        # Call the function to add a pool
        pass
    elif choice == "Remover piscina":
        # Call the function to remove a pool
        pass
    elif choice == "Adicionar cliente":
        cliente = Cliente()
        cliente.adiciona_cliente()
    elif choice == "Remover cliente":
        # Call the function to remove a client
        pass
    elif choice == "Editar informações do cliente":
        # Call the function to edit client information
        pass
    elif choice == "Buscar cliente por nome":
        # Call the function to search for a client by name
        pass
    elif choice == "Listar piscinas e o número de clientes presentes":
        # Call the function to list pools and the number of clients present
        pass
        