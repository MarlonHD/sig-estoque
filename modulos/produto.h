typedef struct produto Produto;

struct produto{
    char codProduto[20];
    char nomeProduto[50];
    char categoria[30];
    char cnpjFornecedor[20];
    char sit;
};

void moduloProdutos(void);

void telaCatalogarProduto(void);
void telaBuscarProduto(void);
void telaEditarProduto(void);
void telaDeletarProduto(void);

Produto* preencheProduto(char); // parametro char == 'c' para cadastro || 'e' para edição
void gravaProduto(Produto*);
void exibeProduto(Produto*);
void buscarProdutoNome(char*);
int  isProdutoCad(char*);
void atualizaProduto(char*);
void excluirProduto(char*);

void cadastrarProduto(void);
void editarProduto(void);
void procurarProduto(void);
void deletarProduto(void);