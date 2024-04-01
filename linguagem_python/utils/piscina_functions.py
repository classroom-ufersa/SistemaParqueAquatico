import streamlit as st 
import pandas as pd
from time import sleep
from .validations import *
from .cliente_functions import total_clientes

def listar_piscinas():
    
    arquivo = open('piscina/piscinas.txt', 'r', encoding= 'latin-1')
    
    piscinas = []
    st.header("Piscinas cadastradas")
    
    if arquivoVazio('piscina/piscinas.txt'):
        st.warning("O arquivo está vazio")
        return None
    
    for linha in arquivo:
        piscina = linha.split('\t')
        
        if len(piscina) == 4:
            piscina[3] = piscina[3].replace('\n', '')
            piscinas.append(piscina)

    
    identificacao = [piscinas[0] for piscinas in piscinas]
    capacidade = [piscinas[1] for piscinas in piscinas]
    profundidade = [piscinas[2] for piscinas in piscinas]
    clientes = [piscinas[3] for piscinas in piscinas]

    data = {'Identificação': identificacao, 'Capacidade': capacidade, 'Profundidade': profundidade, 'Clientes': clientes}
    
    df = pd.DataFrame(data)
    
    html = df.reset_index(drop=True).to_html(index=False).replace('<th>', '<th style="text-align: center;">')
    st.write(html, unsafe_allow_html=True)
    
    arquivo.close()
    return piscinas

def remover_piscina():
    piscinas = listar_piscinas()
    
    st.header("Remover piscina")
    
    if piscinas == None:
        st.warning("Não há piscinas cadastradas")
        return None
    
    identificacao = st.text_input("Digite o ID da piscina que deseja remover:", value='0')
    
    identificacoes = [index[0] for index in piscinas]
    
    if st.button("Deletar piscina"):
        if validInteger(identificacao) == False:
            st.warning("Por favor insira um ID válido")
        else:
            if (identificacao not in identificacoes) or (int(identificacao) < 0) or (identificacao == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('piscina/piscinas.txt', 'w', encoding= 'latin-1')
                
                for index, piscina in enumerate(piscinas):
                    if piscina[0] != identificacao:
                        arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                
                arquivo.close()
                st.success("Piscina removida com sucesso!")
                sleep(0.5)
                st.rerun()

def adicionar_banhistas():
    
    """ Adiciona banhistas a uma piscina

    Returns:
        None: Caso não haja piscinas cadastradas
        Bool: True se banhistas foram adicionados com sucesso e False caso contrário
        
    """
    
    piscinas = listar_piscinas()
    
    st.header("Adicionar banhistas")
    
    if piscinas == None:
        st.warning("Não há piscinas cadastradas")
        return None
    
    banhistas = [int(piscina[3]) for piscina in piscinas]
    total_banhistas = sum(banhistas)
    
    identificacao = st.text_input("Digite o ID da piscina que deseja adicionar banhistas:", value='0')

    
    if st.button("Adicionar banhista"):
        if validInteger(identificacao) == False:
            st.warning("Por favor insira um ID válido")
        else:
            existentes = [index[0] for index in piscinas]
            
            if (str(identificacao) not in existentes) or (int(identificacao) < 0) or (identificacao == ""):
                st.warning("ID inválido")
            else:
                if total_banhistas < total_clientes():
                    arquivo = open('piscina/piscinas.txt', 'w', encoding= 'latin-1')
                    for piscina in piscinas:
                        if piscina[0] == str(identificacao):
                            if int(piscina[1]) <= int(piscina[3]):
                                st.warning("A piscina está cheia")
                            else:
                                piscina[3] = int(piscina[3]) + 1
                                st.success("Banhistas adicionados com sucesso!")
                        
                        arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                    arquivo.close()
                else:
                    st.warning("Não há banhistas suficientes, pois todos os clientes já estão em uma piscina")
                
                sleep(0.5)
                st.rerun()

def remover_banhista():
    """ Remove banhistas de uma piscina

    Returns:
        None: Caso não haja piscinas cadastradas
        Bool: True se banhistas foram removidos com sucesso e False caso contrário
    """
    
    piscinas = listar_piscinas()
    
    st.header("Remover banhista")
    
    if piscinas == None:
        st.warning("Não há piscinas cadastradas")
        return None
    
    identificacao = st.text_input("Digite o ID da piscina que deseja remover banhistas:", value='0')
    
    if st.button("Remover banhista"):
        if validInteger(identificacao) == False:
            st.warning("Por favor insira um ID válido")
        else:
            existentes = [index[0] for index in piscinas]
            
            if (str(identificacao) not in existentes) or (int(identificacao) < 0) or (identificacao == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('piscina/piscinas.txt', 'w', encoding= 'latin-1')
                
                for piscina in piscinas:
                    if piscina[0] == str(identificacao):
                        if int(piscina[3]) == 0:
                            st.warning("A piscina está vazia")
                        else:
                            piscina[3] = int(piscina[3]) - 1
                            st.success("Banhistas removidos com sucesso!")
                    
                    arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                
                arquivo.close()
                sleep(0.5)
                st.rerun()