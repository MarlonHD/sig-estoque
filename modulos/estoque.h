typedef struct estoque Estoque;

struct estoque{
    int idProduto;
    int quantidade;
};

void moduloEstoque(void);

void telaCadastrarEstoque(void);
void telaProcurarEstoque(void);
void telaEditarEstoque(void);
void telaDeletarEstoque(void);

//Funções módulo estoque
void cadastrarEstoque(void);
void editarEstoque(void);
void procurarEstoque(void);
void deletarEstoque(void);