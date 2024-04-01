import streamlit as st
import pandas as pd
from time import sleep
from .validations import *

def listar_clientes():
    """ Lista os clientes cadastrados no arquivo clientes.txt

    Args:
        None
    Returns:
        clientes (list): Lista com os clientes cadastrados
        None: Retorna None caso o arquivo esteja vazio
    """
    arquivo = open('cliente/clientes.txt', 'r', encoding= 'latin-1')
    
    clientes = []
    st.header("Clientes cadastrados")
    
    if arquivoVazio('cliente/clientes.txt'):
        st.warning("O arquivo está vazio")
        return None
    
    if arquivoVazio('cliente/clientes.txt'):
        st.warning("O arquivo está vazio")
        return None
    
    for linha in arquivo:
        cliente = linha.split('\t')
        
        if len(cliente) == 3:
            cliente[2] = cliente[2].replace('\n', '')
            clientes.append(cliente)
    
    nomes = [cliente[0] for cliente in clientes]
    idades = [cliente[1] for cliente in clientes]
    documentos = [cliente[2] for cliente in clientes]
    numero_id = [index + 1 for index in range(len(nomes))]

    data = {'ID': numero_id, 'Nome': nomes, 'Idade': idades, 'Documento (CPF)': documentos}
    
    df = pd.DataFrame(data)
    
    html = df.reset_index(drop=True).to_html(index=False).replace('<th>', '<th style="text-align: center;">')
    st.write(html, unsafe_allow_html=True)
    
    arquivo.close()
    return clientes

def remover_cliente():
    """ Remove um cliente do arquivo clientes.txt
    
    Args:
        None
    Returns:
        None
    
    """
    clientes = listar_clientes()
    
    st.header("Remover cliente")
    
    if clientes == None:
        st.warning("Não há clientes cadastrados")
        return None
    
    
    cliente_id = st.text_input("Digite o ID do cliente que deseja remover:", value='0')
    
    
    if st.button("Deletar cliente"):
        if validInteger(cliente_id) == False:
            st.warning("Por favor insira um ID válido")
        else:
            if (int(cliente_id) > len(clientes)) or (int(cliente_id )<= 0) or (cliente_id == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('cliente/clientes.txt', 'w', encoding= 'latin-1')
                
                for index, cliente in enumerate(clientes):
                    if index + 1 != int(cliente_id):
                        arquivo.write(f'{cliente[0]}\t{cliente[1]}\t{cliente[2]}\n')
                
                arquivo.close()
                st.success("Cliente removido com sucesso!")
                sleep(0.5)
                st.rerun()

def editar_cliente():
    """ Edita as informações de um cliente do arquivo clientes.txt

    Returns:
        Boolean: Retorna False caso haja erro na edição.
    """
    
    clientes = listar_clientes()
    
    st.header("Editar informações do cliente")
    
    if clientes == None:
        st.warning("Não há clientes cadastrados")
        return None
    
    cliente_id = st.text_input("Digite o ID do cliente que deseja editar:", value='0')
    nome_editado = st.text_input("Nome:", value="")
    idade_editada = st.text_input("Idade:", value="")
    documento_editado = st.text_input("CPF (somente números):", value="")
    
    if '' in [cliente_id, nome_editado, idade_editada, documento_editado]:
        st.warning("Por favor preencha todos os campos")
        return False
    
    validations = [validInteger(cliente_id), validString(nome_editado), validInteger(idade_editada), validInteger(documento_editado)]
    
    if st.button("Editar cliente"):
        if (False in validations):
            st.warning("Por favor insira Informações válidas")
        else:
            if (int(cliente_id) > len(clientes)) or (int(cliente_id) <= 0) or (cliente_id == ""):
                st.warning("ID inválido")
            
            elif (int(idade_editada) > 110) or (int(idade_editada) < 0):
                st.warning("Idade inválida")
            else:
                if len(documento_editado) != 11:
                    st.warning("CPF inválido!")
                else:
                    arquivo = open('cliente/clientes.txt', 'w', encoding= 'latin-1')
                
                    for index, cliente in enumerate(clientes):
                        if index + 1 == int(cliente_id):
                            arquivo.write(f'{nome_editado}\t{idade_editada}\t{documento_editado}\n')
                            st.success("Cliente editado com sucesso!")
                        else:
                            arquivo.write(f'{cliente[0]}\t{cliente[1]}\t{cliente[2]}\n')
                    
                    arquivo.close()
                    sleep(0.5)
                    st.rerun()

def buscar_cliente():
    """ Busca um cliente pelo nome no arquivo clientes.txt

    Returns:
        None
    """
    arquivo = open('cliente/clientes.txt', 'r', encoding= 'latin-1')
    
    clientes = []
    st.header("Buscar cliente")
    
    if arquivoVazio('cliente/clientes.txt'):
        st.warning("O arquivo está vazio")
        return None
    
    for linha in arquivo:
        cliente = linha.split('\t')
        
        if len(cliente) == 3:
            cliente[2] = cliente[2].replace('\n', '')
            clientes.append(cliente)
    
    nome = st.text_input("Digite o nome do cliente que deseja buscar:", value="")
    
    if st.button("Buscar"):
        if nome == "":
            st.warning("Por favor insira um nome")
        else:
            resultado = False
            for cliente in clientes:
                if nome.lower() in cliente[0].lower():
                    st.success(f'Cliente encontrado: {cliente[0]}, {cliente[1]} anos, CPF: {cliente[2]}')
                    resultado = True
            
            arquivo.close()
            
            if resultado == True:
                return True
            else:    
                st.warning("Cliente não encontrado")
                return False

def total_clientes():
    """ Retorna o total de clientes cadastrados no arquivo clientes.txt

    Returns:
        int: Total de clientes cadastrados
    """
    arquivo = open('cliente/clientes.txt', 'r', encoding= 'latin-1')
    
    clientes = []
    
    if arquivoVazio('cliente/clientes.txt'):
        return 0
    
    for linha in arquivo:
        cliente = linha.split('\t')
        
        if len(cliente) == 3:
            clientes.append(cliente)
    
    arquivo.close()
    return len(clientes)