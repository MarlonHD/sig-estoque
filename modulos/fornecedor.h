typedef struct fornecedor Fornecedor;

struct fornecedor{
    char nome[30];
    char email[50];
    char cnpj[14];
    char numero[20];
};

void moduloFornecedor(void);

void telaCadastrarFornecedor(void);
void telaProcurarFornecedor(void);
void telaEditarFornecedor(void);
void telaDeletarFornecedor(void);

//Funções de entrada de dados do fornecedor
void cadastrarFornecedor(void); 
void editarFornecedor(void);
void procurarFornecedor(void);
void deletarFornecedor(void);
