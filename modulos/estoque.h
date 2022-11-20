typedef struct estoque Estoque;

struct estoque{
    char codProduto[20];
    int quantidade;
};

typedef struct registro Registro;

struct registro{
    Estoque* conteudo;
    time_t tempo;
    char tipo;  // 'i' = entrada(input) 'o' = saida(output) || 1, 0 respectivamente
};

void moduloEstoque(void);

void telaCadastrarEstoque(void);
void telaProcurarEstoque(void);
void telaRetirarEstoque(void);

Estoque* preencheEstoque(void);
int gravaEstoque(Registro*);
void exibeEstoque(Estoque*);
int quantidade(char*);
int isOnEstoque(char*);

Registro* preencheRegistro(char);
int gravaRegistro(Registro*);
void exibeRegistro(Registro*);

//Funções módulo estoque
void alterarEstoque(char);
void procurarEstoque(void);