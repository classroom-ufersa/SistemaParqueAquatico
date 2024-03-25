import streamlit as st
import pandas as pd

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
    
    for linha in arquivo:
        cliente = linha.split('\t')
        
        if len(cliente) == 3:
            cliente[2] = cliente[2].replace('\n', '')
            clientes.append(cliente)
        else: 
            print("Arquivo vazio")
            st.warning("O arquivo está vazio")
            return None
    
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
    
    try:
        cliente_id = int(st.text_input("Digite o ID do cliente que deseja remover:", value='0'))
        error = False
    except:
        error = True
    
    if st.button("Deletar cliente"):
        if error:
            st.warning("Por favor insira um ID válido")
        else:
            if (cliente_id > len(clientes)) or (cliente_id <= 0) or (cliente_id == ""):
                st.warning("ID inválido")
            else:
                arquivo = open('cliente/clientes.txt', 'w', encoding= 'latin-1')
                
                for index, cliente in enumerate(clientes):
                    if index + 1 != cliente_id:
                        arquivo.write(f'{cliente[0]}\t{cliente[1]}\t{cliente[2]}\n')
                
                arquivo.close()
                st.success("Cliente removido com sucesso!")
                st.rerun()

def editar_cliente():
    """ Edita as informações de um cliente do arquivo clientes.txt

    Returns:
        Boolean: Retorna False caso haja erro na edição.
    """
    
    clientes = listar_clientes()
    
    st.header("Editar informações do cliente")
    
    cliente_id = st.text_input("Digite o ID do cliente que deseja editar:", value='0')
    nome_editado = st.text_input("Nome:", value="")
    idade_editada = st.text_input("Idade:", value="")
    documento_editado = st.text_input("CPF (somente números):", value="")
    
    if '' in [cliente_id, nome_editado, idade_editada, documento_editado]:
        st.warning("Por favor preencha todos os campos")
        return False
    
    try:
        num_id = int(cliente_id)
        idade = int(idade_editada)
        documento = int(documento_editado)
        error = False
    except:
        error = True
    
    if st.button("Editar cliente"):
        if error or nome_editado.isnumeric():
            st.warning("Por favor insira Informações válidas")
        else:
            if (num_id > len(clientes)) or (num_id <= 0) or (num_id == ""):
                st.warning("ID inválido")
            else:
                if len(documento_editado) != 11:
                    st.warning("CPF inválido!")
                else:
                    arquivo = open('cliente/clientes.txt', 'w', encoding= 'latin-1')
                
                    for index, cliente in enumerate(clientes):
                        if index + 1 == num_id:
                            arquivo.write(f'{nome_editado}\t{idade_editada}\t{documento_editado}\n')
                        else:
                            arquivo.write(f'{cliente[0]}\t{cliente[1]}\t{cliente[2]}\n')
                    
                    arquivo.close()
                    st.success("Cliente editado com sucesso!")
                    st.rerun()
    