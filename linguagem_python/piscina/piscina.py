import streamlit as st

class Piscina():
    def __init__(self):
        self.identificacao = ''
        self.capacidade = ''
        self.profundidade = ''
        self.clientes = '' # duvida se os clientes são uma lista dos clientes que estão na piscina ou se são o número de clientes que estão na piscina
        
    def __str__(self):
        return f'Identificação: {self.identificacao}, Capacidade: {self.capacidade}, Profundidade: {self.profundidade}, Clientes: {self.clientes}'
    
    def adiciona_piscina(self):
        self.capacidade = st.text_input("Capacidade:")
        self.profundidade = st.text_input("Profundidade:")
        
        if '' in [self.capacidade, self.profundidade]:
            st.warning("Por favor, preencha todos os campos")
            return False
        
        try:
            capacidade = int(self.capacidade)
            profundidade = int(self.profundidade)
            error = False
        except ValueError:
            error = True
        
        if st.button("Adicionar"):
            if error or (capacidade < 0) or (profundidade < 0):
                st.warning("Por favor insira informações válidas")
            else:
                self.cria_identificacao()
                self.salva_piscina()
                st.success("Piscina cadastrada com sucesso!")
    
    def cria_identificacao(self):
        arquivo = open('linguagem_python/piscina/piscinas.txt', 'r', encoding='latin-1')
        index = 0
        for linha in arquivo:
            piscina = linha.split('\t')
            
            if len(piscina) == 4:
                index = int(piscina[0]) + 1
        
        self.identificacao = index
        arquivo.close()
    
    def salva_piscina(self):
        arquivo = open('linguagem_python/piscina/piscinas.txt', 'a', encoding= 'latin-1')
        self.clientes = 0
        arquivo.write(f'{self.identificacao}\t{self.capacidade}\t{self.profundidade}\t{self.clientes}\n')
        arquivo.close()
    