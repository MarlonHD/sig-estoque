void moduloRelatorios(void);
void estoqueCompleto(void);
void histRegistros(void);
void produtosCat(void);
void fornecedoresCad(void);

char* getFiltro(int);
void prod_filtro(int);

void forneAlfab(void);
void prodAlfab(void);

void estoqueCompletoDinamico(void);

typedef struct estoqueDinamico EstoqueDin;

struct estoqueDinamico{
    char *codProduto;
    char *nomeProduto;
    char *categoria;
    char *cnpjFornecedor;
    char *nomeFornecedor;
    int quantidade;
    EstoqueDin *prox;
};

EstoqueDin* preencheEstDin(EstoqueDin*);

void rela_ordem_alfa_ass(void);

NoFornecedor* listaOrdenadaForne(void);
void exibeLista(NoFornecedor*);