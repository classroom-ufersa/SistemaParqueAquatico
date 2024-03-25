class Cliente:
    def __init__(self):
        self.nome = ''
        self.idade = ''
        self.documento = ''

    def __str__(self):
        return f'Nome: {self.nome}, Idade: {self.idade}, Documento: {self.documento}'
    
    def adiciona_cliente(self):
        self.nome = input('Nome: ')
        self.idade = input('Idade: ')
        self.documento = input('Documento: ')
