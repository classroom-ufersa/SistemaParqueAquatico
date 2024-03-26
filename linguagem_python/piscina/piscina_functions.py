import streamlit as st 
import pandas as pd

def listar_piscinas():
    
    arquivo = open('piscina/piscinas.txt', 'r', encoding= 'latin-1')
    
    piscinas = []
    st.header("Piscinas cadastradas")
    
    for linha in arquivo:
        piscina = linha.split('\t')
        
        if len(piscina) == 4:
            piscina[3] = piscina[3].replace('\n', '')
            piscinas.append(piscina)
        else: 
            print("Arquivo vazio")
            st.warning("O arquivo está vazio")
            return None
    
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
    
    try:
        identificacao = int(st.text_input("Digite o ID do cliente que deseja remover:", value='0'))
        error = False
    except:
        error = True
    
    if st.button("Deletar piscina"):
        if error:
            st.warning("Por favor insira um ID válido")
        else:
            if (identificacao > len(piscinas)) or (identificacao <= 0) or (identificacao == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('piscina/piscinas.txt', 'w', encoding= 'latin-1')
                
                for index, piscina in enumerate(piscinas):
                    if index + 1 != identificacao:
                        arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                
                arquivo.close()
                st.success("Cliente removido com sucesso!")
                st.rerun()

def adicionar_banhistas():
    piscinas = listar_piscinas()
    
    st.header("Adicionar banhistas")
    
    try:
        identificacao = int(st.text_input("Digite o ID da piscina que deseja adicionar banhistas:", value='0'))
        error = False
    except:
        error = True
    
    if st.button("Adicionar banhista"):
        if error:
            st.warning("Por favor insira um ID válido")
        else:
            if (identificacao > len(piscinas)) or (identificacao < 0) or (identificacao == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('piscina/piscinas.txt', 'w', encoding= 'latin-1')
                if len(piscinas) == 0:
                    st.warning("Não há piscinas cadastradas")
                    return None
                else:
                    for piscina in piscinas:
                        if piscina[0] == str(identificacao):
                            piscina[3] = int(piscina[3]) + 1
                            arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                        else:
                            arquivo.write(f'{piscina[0]}\t{piscina[1]}\t{piscina[2]}\t{piscina[3]}\n')
                
                arquivo.close()
                st.success("Banhistas adicionados com sucesso!")
                st.rerun()