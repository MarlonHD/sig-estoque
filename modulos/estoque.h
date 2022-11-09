typedef struct estoque Estoque;

struct estoque{
    char codProduto[20];
    int quantidade;
};

void moduloEstoque(void);

void telaCadastrarEstoque(void);
void telaProcurarEstoque(void);
void telaEditarEstoque(void);
void telaDeletarEstoque(void);

Estoque* preencheEstoque(void);
void gravaEstoque(Estoque*);
void exibeEstoque(Estoque*);

//Funções módulo estoque
void cadastrarEstoque(void);
void editarEstoque(void);
void procurarEstoque(void);
void deletarEstoque(void);