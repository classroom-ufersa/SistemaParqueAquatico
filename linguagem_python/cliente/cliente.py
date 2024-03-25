import streamlit as st

class Cliente:
    def __init__(self):
        self.nome = ''
        self.idade = ''
        self.documento = ''

    def __str__(self):
        return f'Nome: {self.nome}, Idade: {self.idade}, Documento: {self.documento}'
    
    def adiciona_cliente(self):
        self.nome = (st.text_input("Nome:")).title()
        self.idade = st.text_input("Idade:", value="0")
        self.documento = st.text_input("CPF (somente números):", value="0")
        
        if '' in [self.nome, self.idade, self.documento]:
            st.warning("Por favor preencha todos os campos")
            return False
        
        try:
            idade = int(self.idade)
            documento = int(self.documento)
            error = False
        except ValueError:
            error = True
        
        if st.button("Adicionar"):
            if error:
                st.warning("Por favor insira um número inteiro")
            else:
                print(self.documento)
                if len((self.documento)) != 11:
                    st.warning("CPF inválido!")
                elif self.verifica_documento(self.documento):
                    st.warning("Cliente já cadastrado!")
                else:
                    self.salva_cliente()
                    st.success("Cliente cadastrado com sucesso!")
        
    def verifica_documento(self, documento):
        arquivo = open('cliente/clientes.txt', 'r')
    
        
        for linha in arquivo:
            cliente = linha.split('\t')

            if len(cliente) == 0:
                return False
            
            #retirando o \n do documento
            cliente[2] = cliente[2].replace('\n', '')
            
            if cliente[2] == f"{documento}":
                print('Cliente já cadastrado!')
                return True
            
        return False
    
    def salva_cliente(self):
        arquivo = open('cliente/clientes.txt', 'a', encoding= 'latin-1')
        arquivo.write(f'{self.nome}\t{self.idade}\t{self.documento}\n')
        arquivo.close()
        
        print('Cliente cadastrado com sucesso!')
        
teste = Cliente()
teste.adiciona_cliente()
