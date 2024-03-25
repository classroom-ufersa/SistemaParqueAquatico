import streamlit as st

class Cliente:
    def __init__(self):
        self.nome = ''
        self.idade = ''
        self.documento = ''

    def __str__(self):
        return f'Nome: {self.nome}, Idade: {self.idade}, Documento: {self.documento}'
    
    def adiciona_cliente(self):
        self.nome = st.text_input("Nome")
        self.idade = st.text_input("Idade")
        self.documento = st.text_input("Documento")
        
        if st.button("Adicionar"):
            if self.verifica_documento(self.documento):
                st.warning("Cliente já cadastrado!")
            else:
                self.salva_cliente()
                st.write("Cliente cadastrado com sucesso!")
    
    def verifica_documento(self, documento):
        arquivo = open('cliente/clientes.txt', 'r')
        
        for linha in arquivo:
            cliente = linha.split('\t')
            
            #retirando o \n do documento
            cliente[2] = cliente[2].replace('\n', '')
            
            if cliente[2] == documento:
                print('Cliente já cadastrado!')
                return True
            
        return False
    
    def salva_cliente(self):
        arquivo = open('cliente/clientes.txt', 'a')
        arquivo.write(f'{self.nome}\t{self.idade}\t{self.documento}\n')
        arquivo.close()
        
        print('Cliente cadastrado com sucesso!')
        
    def editar_cliente(self):
        pass
teste = Cliente()
teste.adiciona_cliente()
