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

Produto* preencheProduto(void);
void gravaProduto(Produto*);
void exibeProduto(Produto*);
void buscarProdutoNome(char*);
void buscarProdutoCod(char*);
void atualizaProduto(char*);

void cadastrarProduto(void);
void editarProduto(void);
void procurarProduto(void);
void deletarProduto(void);