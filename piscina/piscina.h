/* Definição do tipo estruturado Piscina */
typedef struct piscina Piscina;

/* Função que calcula a quantidade máxima de usuários na piscina */
int usuarios_max(float comprimento, float largura, float profundidade);

/* Função que adiciona uma nova piscina */
void adicona_piscina(Piscina* piscina);

/* Função que lista as piscinas cadastradas */
void listar_piscinas();

/* Função que remove uma piscina cadastrada */
void remover_piscina(Piscina* piscina);