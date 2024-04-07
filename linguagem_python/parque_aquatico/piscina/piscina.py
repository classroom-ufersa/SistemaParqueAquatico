import streamlit as st
from utils.validations import validInteger

class Piscina():
    def __init__(self):
        self.identificacao = ''
        self.capacidade = ''
        self.profundidade = ''
        self.clientes = '' 
        
    def __str__(self):
        return f'Identificação: {self.identificacao}, Capacidade: {self.capacidade}, Profundidade: {self.profundidade}, Clientes: {self.clientes}'
    
    def adiciona_piscina(self):
        self.capacidade = st.text_input("Capacidade Máxima de Pessoas:")
        self.profundidade = st.text_input("Profundidade:")
        
        if '' in [self.capacidade, self.profundidade]:
            st.warning("Por favor, preencha todos os campos")
            return False
        
        if validInteger(self.capacidade) == False or validInteger(self.profundidade) == False:
            error = True
        else:
            error = False
            capacidade = int(self.capacidade)
            profundidade = int(self.profundidade)
        
        if st.button("Adicionar"):
            if error or (capacidade < 0) or (profundidade < 0):
                st.warning("Por favor insira informações válidas")
            else:
                self.cria_identificacao()
                self.salva_piscina()
                st.success("Piscina cadastrada com sucesso!")
    
    def cria_identificacao(self):
        arquivo = open('linguagem_python/parque_aquatico/piscina/piscinas.txt', 'r', encoding='latin-1')
        index = 0
        for linha in arquivo:
            piscina = linha.split('\t')
            
            if len(piscina) == 4:
                index = int(piscina[0]) + 1
        
        self.identificacao = index
        arquivo.close()
    
    def salva_piscina(self):
        arquivo = open('linguagem_python/parque_aquatico/piscina/piscinas.txt', 'a', encoding= 'latin-1')
        self.clientes = 0
        arquivo.write(f'{self.identificacao}\t{self.capacidade}\t{self.profundidade}\t{self.clientes}\n')
        arquivo.close()
    