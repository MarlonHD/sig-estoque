typedef struct fornecedor Fornecedor;

struct fornecedor{
    char nome[30];
    char email[50];
    char cnpj[20];
    char telefone[20];
    char status;
};

void moduloFornecedor(void);

void telaCadastrarFornecedor(void);
void telaProcurarFornecedor(void);
void telaEditarFornecedor(void);
void telaDeletarFornecedor(void);

Fornecedor* preencheFornecedor(void);
void gravaFornecedor(Fornecedor*);
void exibeFornecedor(Fornecedor*);
void buscarFornecedorNome(char*);
int  isFornecedorCad(char*);
void atualizaFornecedor(char*);
void excluirFornecedor(char*);

//Funções de entrada de dados do fornecedor
void cadastrarFornecedor(void); 
void editarFornecedor(void);
void procurarFornecedor(void);
void deletarFornecedor(void);

char* getNomeFornByCNPJ(char*);