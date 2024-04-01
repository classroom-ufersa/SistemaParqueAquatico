import streamlit as st

from cliente import Cliente
from piscina import Piscina

from .cliente_functions import listar_clientes, remover_cliente, editar_cliente, buscar_cliente
from .piscina_functions import remover_piscina, adicionar_banhistas, listar_piscinas, remover_banhista


def main():
    """ Função principal que exibe o menu de opções para o usuário
    """
    
    st.markdown("""
                <style>
                body {
                    background-image: image("image.jpg");
                    background-size: cover;
                }
                </style>
                """, unsafe_allow_html=True)
    
    st.sidebar.title("Gerenciamento Parque Aquático")
    
    # adicionando a logo ao sidebar
    st.sidebar.image("linguagem_python/logo.png", width=200)
    
    menu_options = ["Pagina Inicial", "Gerenciar Piscinas", "Gerenciar Clientes", "Sair"]
    
    
    choice = st.sidebar.selectbox("Escolha uma opção", menu_options)
    
    if choice == "Pagina Inicial":
        pagina_inicial()
    elif choice == "Gerenciar Piscinas":
        st.sidebar.header("Piscinas")
        opcoes_piscinas = ["Adicionar piscina", "Remover piscina", "Listar piscinas", "Adicionar banhistas", "Remover banhistas"]
        opcao_piscina = st.sidebar.radio("Escolha uma opção", opcoes_piscinas)
        if opcao_piscina == "Adicionar piscina":
            piscina = Piscina()
            piscina.adiciona_piscina()
        elif opcao_piscina == "Remover piscina":
            remover_piscina()
        elif opcao_piscina == "Listar piscinas":
            listar_piscinas()
        elif opcao_piscina == "Adicionar banhistas":
            adicionar_banhistas()
        elif opcao_piscina == "Remover banhistas":
            remover_banhista()
            
    elif choice == "Gerenciar Clientes":
        st.sidebar.header("Clientes")
        opcoes_clientes = ["Adicionar cliente", "Remover cliente", "Editar informações do cliente", "Buscar cliente por nome", "Listar clientes"]
        opcao_cliente = st.sidebar.radio("Escolha uma opção", opcoes_clientes)
        if opcao_cliente == "Adicionar cliente":
            cliente = Cliente()
            cliente.adiciona_cliente()
        elif opcao_cliente == "Remover cliente":
            remover_cliente()
        elif opcao_cliente == "Editar informações do cliente":
            editar_cliente()
        elif opcao_cliente == "Buscar cliente por nome":
            buscar_cliente()
        elif opcao_cliente == "Listar clientes":
            listar_clientes()
    elif choice == "Sair":
        st.title("Obrigado por utilizar o sistema de piscinas")
        st.balloons()

def pagina_inicial():
    st.title("Bem-vindo ao sistema de piscinas")
    col1, col2, col3 = st.columns([1,6,1])

    with col1:
        st.write("")

    with col2:
        st.image("logo.png", width=500)

    with col3:
        st.write("")
        
    st.markdown("""
    Este sistema permite que você gerencie as piscinas e os clientes do parque aquático. Aqui estão as funcionalidades disponíveis:
    
    ## Piscinas 
    
    """)
    
    st.image("https://odypark.com.br/parque-aquatico/wp-content/uploads/sites/2/2020/08/Piscina-InfantilOdy-Tower.jpg")
    
    st.markdown("""
                ###### Imagem ilustrativa. Fonte: [Ody Park](https://odypark.com.br/parque-aquatico/wp-content/uploads/sites/2/2020/08/Piscina-InfantilOdy-Tower.jpg)
                
                É possivel fazer o gerenciamento das piscinas do parque aquático. Para isso, você seleciona a opção "Gerenciar Piscinas" no menu lateral. As opções disponíveis são:
    
                - Adicionar piscina: Adiciona uma nova piscina ao parque aquático;
                - Remover piscina: Remove uma piscina do parque aquático;
                - Listar piscinas: Lista as piscinas do parque aquático e permite adicionar e remover banhistas de cada piscina.
                - Adicionar banhistas: Adiciona banhistas a uma piscina;
                - Remover banhistas: Remove banhistas de uma piscina.
                
                ## Clientes
                """)
    st.image("https://campinas.com.br/wp-content/uploads/2022/03/unnamed-69-e1646333930815.jpg")
    
    st.markdown("""
                ###### Imagem ilustrativa. Fonte: [Campinas.com.br](https://campinas.com.br/wp-content/uploads/2022/03/unnamed-69-e1646333930815.jpg)
                
                É possível fazer o gerenciamento dos clientes do parque aquático. Para isso, você seleciona a opção "Gerenciar Clientes" no menu lateral. As opções disponíveis são:
                
                - Adicionar cliente: Adiciona um novo cliente ao parque aquático;
                - Remover cliente: Remove um cliente do parque aquático;
                - Editar informações do cliente: Edita as informações de um cliente;
                - Buscar cliente por nome: Busca um cliente pelo nome;
                - Listar clientes: Lista os clientes do parque aquático.
                """
                )
    
    # criando um footer
    st.markdown("""
                ---
                Desenvolvido por [Letícia Gonçalves](https://www.github.com/letsticia)
                """)