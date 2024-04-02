def validInteger(item):
    """ Função que valida se o valor informado é um número inteiro
    
    Args:
        item (str): Valor a ser validado
        
    Returns:
        bool: Retorna True se o valor é um número inteiro e False caso contrário
    """
   
    try:
        int(item)
        return True
    except ValueError:
        return False
    

def validString(item):
    """ Função que valida se a string informada é composta apenas por letras
    
    Args:
        item (str): String a ser validada
    
    Returns:
        bool: Retorna True se a string é composta apenas por letras e False caso contrário
    """
    
    return item.isalpha()

def arquivoVazio(arquivo):
    """ Função que verifica se um arquivo está vazio
    
    Args:
        arquivo (str): Caminho do arquivo a ser verificado
        
    Returns:
        bool: Retorna True se o arquivo está vazio e False caso contrário
    """
    
    try:
        with open(arquivo, 'r', encoding='latin-1') as file:
            if len(file.readlines()) == 0:
                return True
            else:
                return False
    except FileNotFoundError:
        return True