import streamlit as st
from utils.validations import validString, validInteger

class Cliente:
    def __init__(self):
        self.nome = ''
        self.idade = ''
        self.documento = ''

    def __str__(self):
        return f'Nome: {self.nome}, Idade: {self.idade}, Documento: {self.documento}'
    
    def adiciona_cliente(self):
        st.header("Adicionar Cliente")
        self.nome = (st.text_input("Nome:")).title()
        self.idade = st.text_input("Idade:", value="0")
        self.documento = st.text_input("CPF (somente números):", value="0")
        
        if '' in [self.nome, self.idade, self.documento]:
            st.warning("Por favor preencha todos os campos")
            return False
        
        if validInteger(self.idade) == False or validInteger(self.documento) == False:
            error = True
        else:
            error = False
            idade = int(self.idade)
        
        if st.button("Adicionar"):
            if error or (idade>110) or (idade < 0):
                st.warning("Por favor insira informações válidas")
            else:
                if len((self.documento)) != 11:
                    st.warning("CPF inválido!")
                elif self.verifica_documento(self.documento):
                    st.warning("Cliente já cadastrado!")
                elif validString(self.nome) == False:
                    st.warning("Nome inválido!")
                else:
                    self.salva_cliente()
                    st.success("Cliente cadastrado com sucesso!")
        
    def verifica_documento(self, documento):
        arquivo = open('linguagem_python/parque_aquatico/cliente/clientes.txt', 'r', encoding='latin-1')
        
        
        for linha in arquivo:
            cliente = linha.split('\t')

            if len(cliente) == 0:
                return False
            
            cliente[2] = cliente[2].replace('\n', '')
            
            if cliente[2] == f"{documento}":
                arquivo.close()
                return True
            
        arquivo.close()
        return False
    
    def salva_cliente(self):
        arquivo = open('linguagem_python/parque_aquatico/cliente/clientes.txt', 'a', encoding= 'latin-1')
        arquivo.write(f'{self.nome}\t{self.idade}\t{self.documento}\n')
        arquivo.close()

