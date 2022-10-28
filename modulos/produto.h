typedef struct produto Produto;

struct produto{
    char codProduto[20];
    char nomeProduto[50];
    char categoria[30];
    char cnpjFornecedor[20];
};

void moduloProdutos(void);

void telaCatalogarProduto(void);
void telaBuscarProduto(void);
void telaEditarProduto(void);
void telaDeletarProduto(void);

void cadastrarProduto(void);
void editarProduto(void);
void procurarProduto(void);
void deletarProduto(void);

void preencheProduto(Produto*);
void exibirProduto(Produto*);